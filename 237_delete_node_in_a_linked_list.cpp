/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
		void deleteNode(ListNode* node) {
				if (node->next == NULL) {
						delete node;
						node = NULL;
						return;
				}

				node->val = node->next->val;
				ListNode *tmp = node->next;
				node->next = node->next->next;
				delete tmp;
		}
};
