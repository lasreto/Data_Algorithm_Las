#include<iostream>

int MaxSubseqSum2(int A[], int N)//O(n)
{
	int NowSum=0, MaxSum=0;
	for (int i = 0; i < N; i++)
	{
		NowSum += A[i];//ÏòÓÒ
		if (NowSum > MaxSum)
			MaxSum = NowSum;
		else if (NowSum < 0)
			NowSum = 0;
	}
	return MaxSum;
}
int main()
{
	int a[8]{ 1,3,-1,6,-2,4,1,3 };
	int s = MaxSubseqSum2(a, 8);
	std::cout << s;
	return 0;
}