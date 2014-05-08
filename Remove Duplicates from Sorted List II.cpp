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
		if(head == NULL)
			return head;
        ListNode *newHead = new ListNode(0);

		newHead->next = head;
		ListNode *p = newHead, *q = head->next;
		
		int dupCount = 1;
		while(q)
		{
			if(p->next->val == q->val)
			{
				dupCount++;
				q = q->next;
			}
			else
			{
				if(dupCount > 1)
				{
					p->next = q;
					q = q->next;
					dupCount = 1;
				}
				else
				{
					p = p->next;
					q = q->next;
				}
			}
		}
		if(dupCount > 1)
			p->next = q;
		return newHead->next;
    }
};