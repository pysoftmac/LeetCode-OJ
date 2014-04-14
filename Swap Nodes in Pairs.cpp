#include "util.h"

// Definition for singly-linked list
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	ListNode *swapPairs(ListNode *head)
	{
		ListNode *newHead = new ListNode(0);
		newHead->next = head;
		ListNode *pre = newHead, *p = head, *q;
		while(p != NULL)
		{
			q = p->next;
			if(q == NULL)
				break;

			pre->next = q;
			p->next = q->next;
			q->next = p;

			pre = p;
			p = p->next;
		}
		return newHead->next;
	}

	void test()
	{
		ListNode *list = new ListNode(1);
		list->next = new ListNode(2);
		list->next->next = new ListNode(3);

		ListNode *res = swapPairs(list);
		while(res)
		{
			cout << res->val << endl;
			res = res->next;
		}
	}
};