#include "util.h"

// Definition for an interval.
struct Interval {
	int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> res;
		int pos = binarySearch(intervals, newInterval);

		for(int i = 0; i < pos; i++)
			res.push_back(intervals[i]);
		
		merge(res, newInterval);
		for(int i = pos; i < (int)intervals.size(); i++)
			merge(res, intervals[i]);

		return res;
    }

	void merge(vector<Interval> &intervals, Interval newInterval)
	{
		int size = intervals.size();
		if(size == 0)
			intervals.push_back(newInterval);
		else
		{
			if(intervals[size - 1].end >= newInterval.start)
			{
				if(intervals[size - 1].end <= newInterval.end)
					intervals[size - 1].end = newInterval.end;
			}
			else
				intervals.push_back(newInterval);
		}
	}

	int binarySearch(vector<Interval> &intervals, const Interval& newInterval)
	{
		int l = 0, r = (int)intervals.size() - 1, mid;

		while(l <= r)
		{
			mid = (l + r) / 2;
			if(intervals[mid].start < newInterval.start)
				l = mid + 1;
			else
				r = mid - 1;
		}
		
		return l;
	}

	void test()
	{
		vector<Interval> intervals;
		intervals.push_back(Interval(1,5));
		vector<Interval> res = insert(intervals, Interval(0,3));
		for(int i = 0; i < (int)res.size(); i++)
			cout << res[i].start << " " << res[i].end << endl;
	}
};