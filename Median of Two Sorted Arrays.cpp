#include <cstdio>
class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
	{
		int total = m + n;
		if (total & 0x1)
		{
			return findKth(A, m, B, n, total / 2 + 1);
		}
		else
		{
			return (findKth(A, m, B, n, total / 2) + findKth(A, m, B, n, total / 2 + 1)) * 0.5;
		}
    }

	int findKth(int A[], int m, int B[], int n, int k)
	{
		if(m > n)
			return findKth(B, n, A, m, k);
		if(m == 0)
			return B[k-1];
		if(k == 1)
			return min(A[0], B[0]);

		int pa = min(m, k/2), pb = k - pa;
		if(A[pa - 1] < B[pb - 1])
			return findKth(A + pa, m - pa, B, n, k - pa);
		else if(A[pa-1] > B[pb-1])
			return findKth(A, m, B + pb, n - pb, k - pb);
		else
			return A[pa-1];
	}

	int min(int a, int b)
	{
		return a < b ? a : b;
	}

	void test()
	{
		int A[] = {1, 2, 3}, m = 3;
		int B[] = {1, 2, 3}, n = 3;

		printf("%f\n", findMedianSortedArrays(A, m, B, n));
	}
};