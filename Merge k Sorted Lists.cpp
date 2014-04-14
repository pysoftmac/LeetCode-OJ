#include "util.h"

// Definition for singly-linked list
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		vector<ListNode *>::iterator it = lists.begin(), temp;
		while(it != lists.end())
		{
			if(*it == NULL)
				it = lists.erase(it);
			else
				it++;
		}
		if(lists.size() == 0)
			return NULL;

		make_heap(lists.begin(), lists.end(), comp());

		ListNode *head = NULL, *cur = NULL;
		while(lists.size() > 0)
		{
			if(head == NULL)
				head = cur = lists[0];
			else
				cur = cur->next = lists[0];

			pop_heap(lists.begin(), lists.end(), comp());
			int last = lists.size() - 1;
			if(lists[last]->next != NULL)
			{
				lists[last] = lists[last]->next;
				push_heap(lists.begin(), lists.end(), comp());
			}
			else
				lists.pop_back();
		}

		return head;
    }

	class comp
	{
	public:
		bool operator()(const ListNode *l, const ListNode *r)
		{
			return l->val > r->val;
		}
	};

	void test()
	{
		vector<ListNode *> lists;
		lists.push_back(NULL);
		mergeKLists(lists);
	}
};