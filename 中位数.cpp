/*
描述
中位数定义：一组数据按从小到大的顺序依次排列，处在中间位置的一个数或最中间两个数据的平均值（如果这组数的个数为奇数，则中位数为位于中间位置的那个数；如果这组数的个数为偶数，则中位数是位于中间位置的两个数的平均值）.

给出一组无序整数，求出中位数，如果求最中间两个数的平均数，向下取整即可（不需要使用浮点数）

输入
该程序包含多组测试数据，每一组测试数据的第一行为N，代表该组测试数据包含的数据个数，1 <= N <= 15000.

接着N行为N个数据的输入，N=0时结束输入

输出
输出中位数，每一组测试数据输出一行
*/
#include<iostream>
using namespace std;
#define max 30 
int main(){
	while(1)
	{
		int n,num[max]={0},temp;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> num[i];
		for(int i=0;i<n-1;i++)
			for(int j=i;j<n-1;j++)
			{
				if(num[j]>num[j+1])
				{
					temp=num[j];
					num[j]=num[j+1];
					num[j+1]=temp;
				}	
			}
	if(n%2==0) 
		cout <<(num[n/2-1]+num[n/2])/2<<endl;
	else
		cout << num[n/2] <<endl;
	}

}

//#include<iostream>
//using namespace std;
//#define max 30 
//int main(){
//	int n,a[max]={0};
//	cin >> n;
//	for(int i=0;i<n;i++)
//		cin >> a[i];
//    //遍历整个数组
//    for(int i=0;i<n;i++)
//    {
//        int num=0;//记录有几个数比所选的这个数大
//        for(int j=0;j<n;j++)
//        {
//            if(a[i]<a[j])
//                num++;
//        }
//        if(num==n/2)
//        {
//        	cout << a[i] << endl;
//    	    break; 
//		}
//
//	}
//}
