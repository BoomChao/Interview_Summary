


//Leetcode第23题 : Merge k Sorted Lists
//合并k个有序链表


// 解法一:
// 思路:假设给出4个链表,先比较list[0]和list[1]将其合并成一个链表记做new[0],并且将其置于list向量尾部
// 删除掉已经比较过的两个链表,此时向量list中只剩下list[2],list[3]和new[0]
// 比较list[2]和list[3],合并成一个新的链表new[1]置于尾部,删除掉list[2]和list[3],此时向量list中只剩下new[0]和new[1]
// 比较new[0]和new[1],将其合并成一个新的链表置于尾部,删除new[0]和new[1],最后向量只剩一个元素,这时size()=1,退出循环



// 解法二:
// 提取出每个链表节点的元素,存储起来排序,再生成一个新链表



struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};




//解法一:

ListNode *mergeKLists(std::vector<ListNode*> &lists)
{
    if(lists.empty()) return nullptr;

    while(lists.size()>1){
        lists.push_back(mergeTwoLists(lists[0], lists[1]));    //合并两个链表的函数mergeTwoLists的代码在21题中 
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }

    return lists.front();

}



//解法二:解法一的合并太慢了,改进如下,首尾开始合并

ListNode *mergeKLists(std::vector<ListNode*> &lists)
{
    if(lists.empty()) return nullptr;

    int len = lists.size();
    while(len > 1)
    {
        for(int i = 0; i < len/2; i++){
            lists[i] = mergeKLists(lists[i], lists[len-1-i]);
        }

        len = (len + 1)/2;      //每次将范围减半
    }

    return lists.front();       //返回向量首元素,就是合并后的完整的链表

}






//解法三:提取出每个链表节点的元素,存储起来排序,再生成一个新链表

ListNode* mergeKLists(std::vector<ListNode*>& lists)
{
    if(list.size() == 0) return nullptr;
    std::vector<int> res;

    for(int i = 0; i < lists.size(); i++)
    {
        ListNode* temp = lists[i];
        while(temp != nullptr){
            res.push_back(temp->val);
            temp = temp->next;
        }
    }

    if(res.size()==0)  return nullptr;

    sort(res.begin(), res.end());

    ListNode *base = new ListNode(0);
    ListNode *l3 = base;
    for(int i = 0; i < res.size(); i++)
    {
        l3->next = new ListNode(res[i]);
        l3 = l3->next;
    }

    return base->next;

}



