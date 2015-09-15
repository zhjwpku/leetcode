#include <iostream>
#include <vector>
using namespace std;

ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
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

	if (l1 == NULL)
		p->next = l2;
	else
		p->next = l1;

	return dummy.next;
}

class comp {
public:
	bool operator() (const ListNode* l, const ListNode* r) const {
		return (l->val > r->val);
	}
};

ListNode *mergeKLists(vector<ListNode *>& lists) {
	vector<ListNode*>::iterator it = lists.begin();
	while (it != lists.end()) {
		if (*it == NULL) lists.erase(it);
		else it++;
	}

	if (lists.size() < 1) return NULL;

	ListNode *head = NULL, *cur = NULL;
	make_heap(lists.begin(), lists.end(), comp());

	while(lists.size() > 0) {
		if (head == NULL) head = cur = lists[0];
		else cur = cur->next = lists[0];

		pop_heap(lists.begin(), lists.end(), comp());
		int last = lists.size() - 1;
		if (lists[last]->next != NULL) {
			lists[last] = lists[last]->next;
			push_heap(lists.begin(), lists.end(), comp());
		}
		else lists.pop_back();
	}

	return head;
}
