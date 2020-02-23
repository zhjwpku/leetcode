#include <iostream>
#include <vector>

using namespace std;

ListNode *reverseBetween(ListNode *head, int m, int n) {
	ListNode dummy(-1);
	dummy.next = head;

	ListNode *prev = &dummy;
	for (int i = 0; i < m-1; i++)
		prev = prev->next;

	ListNode *s = prev->next;
	ListNode *p = s;
	ListNode *q = s->next;

	for (int i = m; i < n; i++) {
		ListNode *r = q->next;
		q->next = p;
		p = q;
		q = r;
	}

	s->next = q;
	prev->next = p;

	return dummy.next;
}
