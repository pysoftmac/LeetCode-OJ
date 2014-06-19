#include "util.h"

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *newHead = new ListNode(0);
		newHead->next = head;
		ListNode *pre = newHead;
		ListNode *p = pre->next;

		while(p)
		{
			if(p->val < x)
			{
				pre = pre->next;
				p = p->next;
			}
			else
				break;
		}

		if(p)
		{
			ListNode *q = p->next;
			while (q)
			{
				if(q->val < x)
				{
					p->next = q->next;
					q->next = pre->next;
					pre->next = q;
					pre = q;
					q = p->next;
				}
				else
				{
					p = p->next;
					q = q->next;
				}
			}
		}

		return newHead->next;
    }
};