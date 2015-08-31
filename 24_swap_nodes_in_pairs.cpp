#include <iostream>
#include <vector>
using namespace std;

ListNode * swapPairs(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;

	ListNode dummy(-1);
	dummy.next = head;

	ListNode *pre = &dummy;

	ListNode *p = head;
	ListNode *q = head->next;

	while (p && q) {
		pre->next = q;
		p->next = q->next;
		q->next = p;

		pre = p;
		p = p->next;
		q = p ? p->next : NULL;
	}

	return dummy.next;
}
