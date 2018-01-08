/*
用二分方法查找
首先。。。。。。
再。。。。。
最后。。。。


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
