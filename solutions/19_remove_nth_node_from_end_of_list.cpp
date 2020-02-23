#include <iostream>
#include <vector>
using namespace std;

ListNode *removeNthFromEnd(ListNode *head, int n) {
	if (head == NULL || n == 0)
		return head;

	ListNode dummy(-1);
	dummy.next = head;
	ListNode *fast;
	ListNode *slow;

	fast = &dummy;
	slow = &dummy;

	for (int i = 0; i < n; i++) {
		fast = fast -> next;
	}

	while (fast->next) {
		fast = fast -> next;
		slow = slow -> next;
	}

	ListNode *tmp = slow->next;
	slow->next = tmp->next;
	delete tmp;
	tmp = NULL;

	return dummy.next;
}
