#include <cstdlib>
#include <cstdio>

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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
	{
		ListNode* l3 = new ListNode(0);
		ListNode *pl1 = l1, *pl2 = l2, *pl3 = l3, *pre = NULL;

		while(pl1 || pl2)
		{
			if(pl3 == NULL)
				pl3 = pre->next = new ListNode(0);
			if(pl1)
			{
				pl3->val += pl1->val;
				pl1 = pl1->next;
			}
			if(pl2)
			{
				pl3->val += pl2->val;
				pl2 = pl2->next;
			}

			if(pl3->val >= 10)
			{
				pl3->next = new ListNode(pl3->val / 10);
				pl3->val %= 10;
			}

			pre = pl3;
			pl3 = pl3->next;
		}
		return l3;
    }

	void test()
	{
		ListNode *l1 = new ListNode(1);
		l1->next = new ListNode(8);

		ListNode *l2 = new ListNode(0);

		ListNode *l3 = addTwoNumbers(l1, l2);
		ListNode *pl3 = l3;
		while(pl3)
		{
			printf("%d", pl3->val);
			pl3 = pl3->next;
		}
		printf("\n");
	}
};
