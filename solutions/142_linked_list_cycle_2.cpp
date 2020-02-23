#include <iostream>
#include <vector>

using namespace std;

ListNode *detectCycle(ListNode *head) {
	if (head == NULL)
		return NULL;
	ListNode *fast = head;
	ListNode *slow = head;

	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;

		if (fast == slow) {
			ListNode *slow2 = head;
			while (slow2 != slow) {
				slow2 = slow2->next;
				slow = slow->next;
			}

			return slow;
		}
	}

	return nullptr;
}
