/*
����
����һ���(x,y)���������Զ��������֮��ľ��롣

����
��һ���ǵ���n��n���ڵ���2��

����ÿһ�д���һ���㣬������������x y��ɡ�

���
���һ������Զ����֮��ľ��롣

ʹ��cout << fixed << setprecision(4) << dis << endl;�������ֵ����ȷ��С�����4λ��

fixed��setprecision����<iomanip>ͷ�ļ��ﶨ��ĸ�ʽ���Ʋ���������Ҫ#include 
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
