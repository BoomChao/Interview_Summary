
/*
    链表题型总结
*/

////////////////////////////////////
//
//  删除链表中的指定节点
//  <剑指>面试题18
//  第19题 : 删除链表中倒数第n个节点
//  第83题 : 在排序链表中删除重复的节点
//  第82题 : 在排序链表中删除所有重复出现的节点

//  第23题 : 合并k个链表


//  第114题: 将树转换成链表 (这两题出的非常好)
//  第430题: 将双链表转换成单链表
//
////////////////////////////////////

//<剑指>面试题18

//1.两个指针,prev指针指向要删除节点的前一个节点,cur指向要删除的节点
// 当cur到达要删除的节点时,将prev指针指向cur的下一个节点

//方法一:使用base
ListNode* deleteNode(ListNode *head, ListNode *pDelete)
{
    if(head == nullptr) return head;

    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *slow = base, *fast = head;
    while(fast != pDelete) {
        fast = fast->next;
        slow = slow->next;
        if(fast == nullptr) return nullptr;
    }

    slow->next = fast->next;

    return base->next;

    if(head == nullptr) return head;
}



//方法二:不使用base
ListNode* deleteNode(ListNode *head, ListNode *pDelete)
{
    if(head == nullptr) return head;

    //要删除的节点是头节点
    if(head == pDelete) return head->next;

    ListNode *pre = head, *cur = head->next;

    while(pre && cur && cur != pDelete) {
        pre = cur;
        cur = cur->next;
    }

    if(cur == nullptr) return head;     //链表中没有要删除的节点pDelte

    pre->next = pre->next->next;

    return head;
}


//Leetcode第19题:删除链表中倒数第n个节点
//快慢指针

//方法一:使用base

//1.快指针先走n步,走完n步后,慢指针出发,直到快指针到达最后一个节点
//2.将慢指针next指向下下一个节点

ListNode* removeNthFromEnd(ListNode *head, int n)
{
    ListNode *base = new ListNode(-1);
    base->next = head;                  //删除的可能是头结点

    ListNode *fast = base, *slow = base;
    for(int i = 0; i < n; i++) {
        fast = fast->next;
    } 

    while(fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
    
    return base->next;
}

//方法二:不使用base
ListNode* removeNthFromEnd(ListNode *head, int n)
{
    ListNode *fast = head, *slow = head;

    for(int i = 0; i < n; i++) {
        if(fast)
            fast = fast->next;
    }

    if(fast == nullptr) return head->next;

    while(fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;

    return head;
}



//Leetcode第83题:删除链表中多余的重复元素

ListNode* deleteDuplicate(ListNode *head)
{
    if(head == nullptr) return head;

    ListNode *cur = head;
    while(cur && cur->next) 
    {
        if(cur->val == cur->next->val) {
            cur->next = cur->next->next;
        }
        else {
            cur = cur->next;
        }
    }

    return head;
}


//Leetcode第82题:删除链表中重复的所有元素

ListNode* deleteDuplicates(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *base = new ListNode(-1);  //头节点可能被删除,另外定义一个base节点指向头结点(这一题必须定义一个base)
    base->next = head;
    ListNode *cur = base;

    while(cur->next && cur->next->next) 
    {
        //存在相同的节点
        if(cur->next->val == cur->next->next->val) 
        {
            int value = cur->next->val;
            ListNode *pNode = cur->next;          //找到第一个元素不等于value的节点
            while(pNode && pNode->val == value) {
                pNode = pNode->next;
            }
            cur->next = pNode;
        }
        else 
        {
            cur = cur->next;
        }
    }

    return base->next;
}


//Leetcode第23题:　合并k个链表

// 解法一：两两合并
// 时间复杂度分析 :　假设初始k个链表的初始平均长度为n,则第一次合并时间复杂度为(k/2)*(2n), 第二次合并时间复杂度为 (k/4)*(4n), ...
// 所以总的时间复杂度为 (k/2)*(2n) + (k/4)*(4n) + ... + (k/(2^logk))*(2^logk*n) = (logk)(kn)
// 空间复杂度:需要一个递归大小为nk的栈空间,空间复杂度为O(nk)

ListNode* mergeKLists(std::vector<ListNode*> &lists)
{
    if(lists.empty()) return nullptr;

    int len = lists.size();

    while(len > 1)
    {
        for(int i = 0; i < len/2; i++) {
            lists[i] = mergeTwoLists(lists[i], lists[len-1-i]);
        }

        len = ((len + 1) >> 1);
    }

    return lists.front();
}

ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr) return l2;
    else if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

}


ListNode* mergeTwoLists(ListNode *l1, ListNode *l2)
{
    ListNode *head = new ListNode(-1);
    ListNode *base = head;

    while(l1 && l2)
    {
        if(l1->val < l2->val) {
            base->next = l1;
            l1 = l1->next;
        }
        else{
            base->next = l2;
            l2 = l2->next;
        }

        base = base->next;
    }

    if(l1) base->next = l1;
    else if(l2) base->next = l2;

    return head->next;
}


// 方法二 : 存入优先队列
// 时间复杂度 : 假设每个链表的平均长度为n,则构建一个k个元素的优先队列(初始堆)的时间复杂度为O(k)
// 之后插入nk个元素的时间复杂度为 O(knlogk)
// 空间复杂度: O(nk)

struct Cmp {
    bool operator()(const ListNode *node1, const ListNode *node2) {
        return node1->val > node2->val;
    }
};

ListNode* mergeKLists(std::vector<ListNode*> &lists)
{
    std::prioriry_queue<ListNode*, std::vector<ListNode*>, Cmp> pq;

    /*
    for(int i = 0; i < lists.size(); i++) {
        if(lists[i])            //注意:这里一定要判断,空的节点不能加入到队列中
            pq.push(lists[i]);
    }
    */
    
    for(auto &node : lists) {
        if(node) pq.push(node);         //需要判断一下元素是否为空
    }

    ListNode *base = new ListNode(-1);
    ListNode *cur = base;

    while(!pq.empty())
    {
        ListNode *pNode = pq.top(); pq.pop();
        cur->next = pNode;
        cur = cur->next;

        if(pNode->next) pq.push(pNode->next);
    }

    return base->next;
}




//Leetcode第114题:将树转换成链表

void flattern(TreeNode *root)
{
    if(root == nullptr) return;

    //这两个递归函数的顺序无所谓
    flattern(root->left);
    flattern(root->right);

    TreeNode *pNode = root->right;
    root->right = root->left;
    root->left = nullptr;

    //找到最右端的节点接上之前保存的右子节点
    while(root->right) {
        root = root->right;
    }

    root->right = pNode;
}


//Leetcode第430题:转换成单链表(题目出的非常好)

Node* flattern(Node *head)
{
    if(head == nullptr) return head;

    Node *pNode = head;
    while(pNode)
    {
        //不存在子孩子
        if(pNode->child == nullptr) {
            pNode = pNode->next;
            continue;
        }   

        //存在子孩子,找到子孩子的尾节点连接到当前节点的下一个节点
        //将下一个节点的pre指针指向尾节点(如果下一个节点存在)
        //将当前节点的子孩子置空
        Node *pTemp = pNode->child;
        while(pTemp->next) {
            pTemp = pTemp->next;
        }
        pTemp->next = pNode->next;

        if(pNode->next) pNode->next->prev = pTemp;   //设置prev指针时得先判断一下pNode->next是否存在

        pNode->next = pNode->child;
        pNode->child->prev = pNode;
        pNode->child = nullptr;
    }

    return head;
}




/////////////////////////////////
//      翻转链表
//
//      第25题: K个节点一组翻转链表
//     第206题: 翻转链表(递归写法)
//      第92题: 翻转链表II(链表区间翻转)
//
/////////////////////////////////


//Leetcode第25题 : K个一组翻转链表

ListNode* reverseKGroup(ListNode *head, int k)
{
    ListNode *base = new ListNode(-1);
    base->next = head;

    ListNode *pNode = base;

    while(pNode)
    {
        ListNode *prev = pNode;

        for(int i = 0; i < k; i++) {
            // if(pNode == nullptr) break;      //这表示当前节点不为空,但是下一个节点可能为空
            pNode = pNode->next;
            if(pNode == nullptr) return base->next;         //易错:这表示移动后的下一个节点不能为空
        }

        //前面是pNode为空是return语句，所以这里不写 if(i==k) 也可以
        if(i == k) {
            ListNode *tail = pNode->next;

            ListNode *reverseList = reverse(prev->next, tail);    //易错:prev->next
            
            //将翻转后的链表链接起来
            pNode = prev->next;
            prev->next = reverseList;
            pNode->next = tail;
        }
    }

    return base->next;
}

ListNode* reverse(ListNode *head, ListNode *tail)
{
    ListNode *prev = nullptr;

    while(head && head != tail)
    {
        ListNode *pNode = head->next;
        head->next = prev;
        prev = head;
        head = pNode;
    }

    return prev;
}


//Leetcode第206: 翻转链表(递归写法)

ListNode *reverseList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    return dfs(head, nullptr);
}

ListNode* dfs(ListNode *head, ListNode *prev)
{
    if(head == nullptr) return prev;

    ListNode *pNext = head->next;

    head->next = prev;

    return dfs(pNext, head);
}



//Leetcode第92题: 翻转链表II
//找到前一个节点prev和后一个节点tail, 翻转(prev->next,tail)之间的部分再合并即可

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if(head == nullptr || head->next == nullptr || left == right) return head;

    ListNode *base = new ListNode(-1);
    base->next = head;
    ListNode *cur = base;

    ListNode *prev = nullptr, *tail = nullptr;

    for(int i = 0; i < right; i++) {
        if(i == left - 1) prev = cur;
        cur = cur->next;
    }

    tail = cur->next;

    ListNode *reverseList = reverse(prev->next, tail);

    ListNode *pNode = prev->next;
    prev->next = reverseList;
    pNode->next = tail;

    return base->next;
}

ListNode *reverse(ListNode *head, ListNode *tail)
{
    ListNode *prev = nullptr;

    while(head && head != tail) {
        ListNode *pNext = head->next;
        head->next = prev;
        prev = head;
        head = pNext;
    }

    return prev;
}






///////////////////////////
//
//      链表旋转操作
//      第61题 : 旋转链表前k个节点
//      第234题: 判断回文链表
//
///////////////////////////


// Leetcode第61题:旋转链表 (快慢指针)
// 1.利用快指针tail将链表首尾相连
// 2.慢指针指针prev移动(len-k-1)步
// 3.返回prev指针的下一个指针,将prev->next置为空

ListNode* rotateRight(ListNode *head, int k)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *tail = head;
    int len = 1;
    while(tail->next) {
        tail = tail->next;
        len++;
    }

    k %= len;
    if(k == 0) return head;  //判断移动长度是否为链表的整数倍

    tail->next = head;      //将链表首尾连接

    // 找到打破环形链表的节点
    for(int i = 0; i < len-k; i++) {
        tail = tail->next;
    }

    ListNode *res = tail->next;
    tail->next = nullptr;
    
    return res;
}


//Leetcode第234题: 判断回文链表

//思路:双指针找到中点,慢指针边移动边翻转链表之后与中点开始的链表做比较

bool isPalindrome(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *slow = head, *fast = head;
    ListNode *prev = nullptr;

    while(fast && fast->next)
    {
        fast = fast->next->next;    //先将快指针移动

        ListNode *pNext = slow->next;
        slow->next = prev;
        prev = slow;
        slow = pNext;
    }

    if(fast != nullptr) {   //表示链表个数为奇数个,奇数个节点则需要跳过正中间节点
        slow = slow->next;
    }

    while(prev && slow) {
        if(prev->val != slow->val) return false;
        prev = prev->next;
        slow = slow->next;
    }

    return true;
}





///////////////////////////////
//
//  第148题:排序链表
//  注意题目要求时间复杂度为O(nlogn),空间复杂度为O(1)
//

//思路(利用归并排序):找到中间节点后再拆成两个链表后排序合并,这样时间复杂度为O(n),空间复杂度为O(n),因为最后返回的是一个长度为n的新链表,不是在原来的链表上做的修改

//时间复杂度为O(nlogn),空间复杂度为O(1), 但是由于使用了递归,导致栈空间使用为O(logn)
//为什么空间复杂度不是O(1)?
//如果归并排序是对数组排序,空间复杂度确实是O(n),但是对链表,可以做到O(1),参看mergeList函数,实际上我们只是申请了一个节点而已

ListNode *sortList(ListNode *head)
{
    //这里如果节点为空或者只有一个节点直接返回
    if(head == nullptr || head->next == nullptr) return head;    

    ListNode *fast = head, *slow = head;
    while(fast->next && fast->next->next) {     //注意:这里偶数节点必须找的是左中节点
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode *head2 = slow->next;
    slow->next = nullptr;

    // ListNode *l1 = sortList(head);
    // ListNode *l2 = sortList(head2);

    // return mergeList(l1, l2);
    return mergeList(sort(head), sort(head2));
}

ListNode *mergeList(ListNode *head1, ListNode *head2)
{
    ListNode *base = new ListNode(-1);
    ListNode *pNode = base;

    while(head1 && head2)
    {
        if(head1->val < head2->val) {
            pNode->next = head1;
            head1 = head1->next;
        }
        else {
            pNode->next = head2;
            head2 = head2->next;
        }

        pNode = pNode->next;
    }

    if(head1) pNode->next = head1;      //或者 if(head2 == nullptr) pNode->next = head1;
    if(head2) pNode->next = head2;     

    return base->next;
}

//这种方法不需要申请空间
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    if(l1 == nullptr) return l2;
    else if(l2 == nullptr) return l1;

    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}



///////////////////////////////
//
//      切分链表
//      第86题 : 重排链表
//      第328题: 奇偶链表拆分
//      第725题: 分组切割链表 (注意链表长度如果为5,k=3,则分组长度为{2,2,1})
//
///////////////////////////////



//Leetcode第86题：切分链表
//画图来理解

ListNode* partition(ListNode *head, int x)
{
    ListNode *l1 = new ListNode (-1);
    ListNode *l2 = new ListNode (-1);
    ListNode *l1Head = l1;
    ListNode *l2Head = l2;

    while(head)
    {
        if(head->val < x) {
            l1->next = head;
            l1 = l1->next;
        }
        else {
            l2->next = head;
            l2 = l2->next;
        }
        head = head->next;
    }

    l1->next = l2Head->next;
    l2->next = nullptr;         //注意这个一定不要忘记

    return l1Head->next;
}



//Leetcode第328题: 奇偶链表拆分

ListNode *oddEvenList(ListNode *head)
{
    if(head == nullptr || head->next == nullptr) return head;

    ListNode *pOdd = head, pEven = head->next;
    ListNode *pHead = pEven;

    //这个pEven->next一定要加,防止链表个数为偶数
    while(pEven && pEven->next) {
        pOdd = pOdd->next = pEven->next;
        pEven = pEven->next = pOdd->next;
    }

    pOdd->next = pHead;

    return head;
}


//第725题: 分组切割链表 (注意链表长度如果为5,k=3,则分组长度为{2,2,1})

std::vector<ListNode*> splitListToParts(ListNode* head, int k) {
    std::vector<ListNode*> res(k);
    
    //1.计算链表的长度
    ListNode *cur = head;
    int len = 0;
    while(cur) {
        cur = cur->next;
        len++;
    }
    
    //2.计算切分的每个部分的长度,以及剩余部分的长度
    int nodeLen = len/k, extra = len%k;
    
    cur = head;
    int j = 0;
    
    while(cur)
    {
        ListNode *tmp = cur;
        for(int i = 1; i < nodeLen; i++) tmp = tmp->next;
        
        if(extra-- > 0 && len > k) tmp = tmp->next;
        
        res[j++] = cur;
        cur = tmp->next;
        tmp->next = nullptr;
    }
    
    return res;
}




////////////////////////////////
//
//  <剑指> 约瑟夫环问题(自已定义链表实现)
//  
//
/////////////////////////////////


//使用链表模拟法
//1.自定义链表实现

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int m_val) : data(m_val), next(nullptr) {}
};

int lastRemaining(unsigned int n, unsigned int m)
{
    ListNode *head = new ListNode(0);

    ListNode *cur = head;

    for(int i = 1; i < n; i++) {        //注意这里是从1开始,开头的0当做头节点了
        cur->next = new ListNode(i);
        cur = cur->next;
    }

    cur->next = head;       //首尾相连构成循环链表(这一步很关键)

    int len = n;
    cur = head;

    while(len != 1)
    {
        for(int i = 0; i < m-2; i++) {  //这里只需要移动m-2步就可以了
            cur = cur->next;    
        }

        ListNode *tmp = cur->next;

        cur->next = cur->next->next;

        delete tmp;     //注意这个需要放在这里,否则上面的cur->next报段溢出

        cur = cur->next;    //cur后移到下一个起始元素

        len--;      //删除之后元素个数减1
    }

    return cur->val;
}


//2.使用STL中自带的list

// 公式法,从下往上推导
// f(n,m)表示最后一个活着的人在当前人数为n时的下标
// 则最后一次下标一定为0,因为最终只会剩余它一个人
// 最后一轮: f(1,m) = 0  记f1
// 倒数二轮: f(2,m) = (f1 + m)%2  记为f2
// 倒数三轮: f(3,m) = (f2 + m)%3  记为f3
// .....
// f(n,m) = (f(n-1,m)+m)%n 即为递推公式

int lastRemaining(int n, int m)
{
    if(n == 1) return 0;

    return (lastRemaining(n-1,m) + m) % n;
}

int lastRemaining(int n, int m)
{
    int val = 0;

    for(int i = 2; i <= n; i++) {
        val = (val + m) % i;
    }

    return val;
}

