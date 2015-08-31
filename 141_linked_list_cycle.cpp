#include <iostream>
using namespace std;

bool hasCycle(ListNode *head) {
	if (head == NULL || head->next == NULL)
		return false;

	ListNode *fast = head->next;
	ListNode *slow = head;
	while (fast) {
		if (fast == slow)
			return true;

		fast = fast->next ? fast->next->next : nullptr;
		slow = slow->next;
	}

	return false;
}
