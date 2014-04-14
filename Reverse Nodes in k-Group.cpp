#include "util.h"

// Definition for singly-linked list
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *newHead = new ListNode(0);
		newHead->next = head;

		ListNode *pre = newHead, *p = head, *q;
		int count;
		while(true)
		{
			count = 0;
			while(p && count != k)
			{
				count++;
				p = p->next;
			}

			if(count < k)
				break;

			p = pre->next;
			q = p->next;

			for(int i = 0; i < k - 1; i++)
			{
				p->next = q->next;
				q->next = pre->next;
				pre->next = q;

				q = p->next;
			}

			pre = p;
			p = pre->next;
		}
		return newHead->next;
    }

	void test()
	{
		ListNode *list = new ListNode(1);
		list->next = new ListNode(2);
		list->next->next = new ListNode(3);

		ListNode *res = reverseKGroup(list, 3);
		while(res)
		{
			cout << res->val << endl;
			res = res->next;
		}
	}
};