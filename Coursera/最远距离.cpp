/*
描述
给定一组点(x,y)，求距离最远的两个点之间的距离。

输入
第一行是点数n（n大于等于2）

接着每一行代表一个点，由两个浮点数x y组成。

输出
输出一行是最远两点之间的距离。

使用cout << fixed << setprecision(4) << dis << endl;输出距离值并精确到小数点后4位。

fixed和setprecision是在<iomanip>头文件里定义的格式控制操作符，需要#include 
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	double x[10],y[10],DisTemp=0,DisBiggest=0;
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
		{
			DisTemp = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
            if (DisTemp > DisBiggest)
            {
                DisBiggest = DisTemp;
            }
		}
	cout << fixed << setprecision(4) << DisBiggest << endl;	 
} 
