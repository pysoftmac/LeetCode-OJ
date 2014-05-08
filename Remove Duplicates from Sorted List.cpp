#include "util.h"

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* p = head, *q;
		if(p != NULL)
		{
			q = p->next;
		}

		while(q != NULL)
		{
			if(p->val == q->val)
			{
				p->next = q->next;
				delete q;
				q = p->next;
				continue;
			}
			else
			{
				p = p->next;
				q = q->next;
			}
		}
		return head;
    }
};