#include <iostream>
using namespace std;

bool isPalindrome(ListNode *head) {
	if (!head || !head->next) return true;
	ListNode *slow = head;
	ListNode *fast = head->next;

	//find the middle one
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	ListNode *prev = slow;
	ListNode *p = slow->next;
	slow->next = nullptr;

	while (p) {
		ListNode* tmp = p->next;
		p->next = prev;
		prev = p;
		p = tmp;
	}

	ListNode *l = head;
	ListNode *r = prev;
	while (l) {
		if (l->val != r->val)
			return false;
		l = l->next;
		r = r->next;
	}

	return true;
}
