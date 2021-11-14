

//Leetcode第203题: 删除链表元素

type ListNode struct {
	Val int
	Next *ListNode
}

func removeElements(head *ListNode, val int) *ListNode {
	if head == nil {
		return head
	}

	base := &ListNode{-1, head}

	cur := base

	for cur != nil {
		if cur.Next != nil && cur.Next.Val === val {
			cur.Next = cur.Next.Next
		} else {
			cur = cur.Next
		}
	}

	return base.Next
}


