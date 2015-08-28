#include <iostream>

using namespace std;

ListNode* deleteDuplicates(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return head;
	
	int val = head->val - 1;

	ListNode dummy(val);
	dummy.next = head;

	ListNode *p = &dummy;
	ListNode *q = head;

	while (q && q->next) {
		if (q->val == val || q->val == q->next->val) {
			p->next = q->next;
			val = q->val;
			delete q;
			q = p->next;
		} else {
			p = q;
			q = q->next;
			val = p->val;
		}
	}

	if (q->val == val) {
		p->next = q->next;
		delete p;
	}

	return dummy.next;
}
