#include <iostream>
using namespace std;

ListNode *deleteDuplicates(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;

	ListNode *p = head;
	ListNode *q = head->next;

	while (q) {
		ListNode *r = q->next;
		if (p->val == q->val) {
			p->next = r;
			delete q;
			q = r;
		} else {
			p = q;
			q = r;
		}
	}

	return head;
}
