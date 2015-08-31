#include <iostream>
#include <vector>
using namespace std;

ListNode * rotateRight(ListNode *head, int k) {
	if (k == 0 || head == NULL)
		return head;

	int len = 1;
	ListNode *p = head;
	while (p->next) {
		len ++;
		p = p->next;
	}

	k = len - k % len;

	p->next = head;

	for (int i = 0; i < k; i++) {
		p = p->next;
	}

	head = p->next;
	p->next = NULL;
	return head;
}
