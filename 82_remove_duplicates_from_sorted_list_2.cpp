#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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
		delete q;	// this drive me crazy
	}

	return dummy.next;
}

int main() {
	ListNode *head = new ListNode(1);
	ListNode *abc = new ListNode(1);

	head->next = abc;

	ListNode *p;
	ListNode *q;

	q = head;
	while (q) {
		cout << q->val << endl;
		q = q->next;
	}

	p = deleteDuplicates(head);

	q = p;
	while (q) {
		cout << q->val << endl;
		q = q->next;
	}

	return 0;
}
