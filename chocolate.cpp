/*
要求：
有n段巧克力，每段有a[i]块，连成整体一根巧克力棒，要求将其分成k部分，要求分出来的k部分中最多的那部分的块数，是所有分法中最多块数最小值。求这个最小值。

方法：
用二分方法查找，这个最小值肯定在块数的最大值和所有块数求和的值之间。在这两个值之间取一个值作为这个最小值来试。
如果前部分和超过了这个最小值，那么说明此处应该切一刀，并且再从此处开始求部分和。否则继续求和。
如果用这种方法求出来的次数要大于这个假设的最小值，说明假设的这个值不够大。就增大左边界。否则缩小右边界，直到右边界值小于等于左边界位置。
输出这个反复寻觅得到的数。
*/
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a[101];            // a[i]表示第i段有多少块
    int n, k;              // n表示有多少段，k表示分成多少部分
    int partsum, count;    // 局部和 计数
    int max = 0;           // 求数组中最大的元素
    int sum = 0;
    int left = 0;          // 左边范围边界
    int right = 0;      
    int mid;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        sum += a[i];
        if (max < a[i])
            max = a[i];
    }
    left = max;
    right = sum;
    while (left < right)
    {
        partsum = 0;
        count = 1;
        mid = (left + right)/2;
	for (int i = 1; i <= n; ++i)
        {
            if (partsum + a[i] > mid) 
            {
		partsum = a[i];
                count++;
            }
            else
            {
		partsum += a[i];
	    }
        }
        if (count > k)
	    left = mid + 1;
        else
            right = mid;
    }// while( left < right)
    cout << right << endl;
    return 0;
}
