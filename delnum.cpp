/**********************************************************************
 * 思路:
 * 首先看要保留多少位，首先在要保留位数减1的左边，选择最小的那个，就是未来的最高位。
 * 接下来保留位数减去1,并且把，刚才得到的最高位的右边作为起点，重复上面的过程。直到保留位数为0
 * 构造最终要的数字输出。
 * *********************************************************************/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s;		// 输入字符串
    
	int n, k, i;	// 可去掉个数，保留个数，当前查找位
	int len;	    // 输入字符串长度
	int left = 0; 	// 范围最左
	cin >> s;
    cin >> n;
    int ans = 0;
    len = s.length();
	k = len - n;      // k即为保留个数，就是原来的个数减去要去掉的个数
    while (k > 0)
	{
		int dqmin = s[left] - '0';	//当前位最小
		left++;
		for (int j = left; j < len-k+1; j++)
			if( s[j] - '0' < dqmin )
			{
				dqmin = s[j] - '0';
				left = j + 1;
			}
		ans = ans*10+dqmin;
		k--;
	}
	cout << ans << endl;
	return 0;
}
