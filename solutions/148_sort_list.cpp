#include <iostream>
#include <vector>
using namespace std;

ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;

	ListNode dummy(-1);
	ListNode *p = &dummy;

	while (l1 && l2) {
		if (l1->val > l2->val) {
			p->next = l2;
			l2 = l2->next;
		} else {
			p->next = l1;
			l1 = l1->next;
		}

		p = p->next;
	}

	if (l1)
		p->next = l1;
	else
		p->next = l2;

	return dummy.next;
}

ListNode * sortList(ListNode *head) {
	if (head == NULL || head->next == NULL) return head;

	ListNode *fast = head, *slow = head;

	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}

	fast = slow;
	slow = slow->next;
	fast->next = NULL;

	ListNode *l1 = sortList(head);
	ListNode *l2 = sortList(slow);

	return merge2Lists(l1, l2);
}
