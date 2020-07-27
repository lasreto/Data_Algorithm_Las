#include<iostream>
int Max3(int a, int b, int c)
{
    return a > b ? a > c ? a : c : b > c ? b : c;
}
int DivideRecursive(int list[],int left,int right)
{
//终止：问题不可再分，返回解
    if (left == right)
    {
        if (list[left] > 0)
            return list[left];
        else
            return 0;
    }

//分治
//划分对象
int center = (left + right) / 2;  

  int RightBorderSum;//存放右序列的值
  int MaxRightBorderSum;//存放右序列最大值   
//左序列,子问题1
  int LeftBorderSum = 0, //存放左序列的值
      MaxLeftBorderSum = 0;//存放左序列最大值 
for (int i = center; i >= left; i--)
{
    LeftBorderSum += list[i];
    if (LeftBorderSum > MaxLeftBorderSum)
        MaxLeftBorderSum = LeftBorderSum;
}
int MaxleftSum = DivideRecursive(list, left, center);//递归调用解决子问题1
//右序列，子问题2
RightBorderSum = 0; MaxRightBorderSum = 0;
for (int i = center+1; i <= right; i++)
{
    RightBorderSum += list[i];
    if (RightBorderSum > MaxRightBorderSum)
        MaxRightBorderSum = RightBorderSum;
}
int MaxrightSum = DivideRecursive(list, center + 1, right);//递归调用解决子问题2

//合并问题1，2
return Max3(MaxleftSum, MaxrightSum, MaxRightBorderSum + MaxLeftBorderSum);
}

int MaxSubseqSum1(int A[], int N)//O(nlogn)
{
    return DivideRecursive(A, 0, N-1);
}




