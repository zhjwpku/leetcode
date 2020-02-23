#include <iostream>
#include <vector>

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	if (l1 == NULL) return l2;
	if (l2 == NULL) return l1;
	ListNode dummy(-1);
	ListNode *p = &dummy;

	while (l1 != NULL && l2 != NULL) {
		if (l1->val > l2->val) {
			p->next = l2;
			l2 = l2->next;
		} else {
			p->next = l1;
			l1 = l1->next;
		}

		p = p->next;
	}

	if (l1) {
		p->next = l1;
	} else {
		p->next = l2;
	}

	return dummy.next;
}
