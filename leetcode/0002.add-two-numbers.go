// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	dummpyHead := &ListNode{}
	p := dummpyHead
	var divide, sum, v1, v2 int
	for l1 != nil || l2 != nil {
		v1, v2 = 0, 0
		if l1 != nil {
			v1 = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			v2 = l2.Val
			l2 = l2.Next
		}
		sum = v1 + v2 + divide
		p.Next = &ListNode{Val: sum % 10}
		divide = sum / 10
		p = p.Next
	}

	if divide > 0 {
		p.Next = &ListNode{Val: divide}
	}

	return dummpyHead.Next
}
