/*
����
��λ�����壺һ�����ݰ���С�����˳���������У������м�λ�õ�һ���������м��������ݵ�ƽ��ֵ������������ĸ���Ϊ����������λ��Ϊλ���м�λ�õ��Ǹ���������������ĸ���Ϊż��������λ����λ���м�λ�õ���������ƽ��ֵ��.

����һ�����������������λ������������м���������ƽ����������ȡ�����ɣ�����Ҫʹ�ø�������

����
�ó����������������ݣ�ÿһ��������ݵĵ�һ��ΪN���������������ݰ��������ݸ�����1 <= N <= 15000.

����N��ΪN�����ݵ����룬N=0ʱ��������

���
�����λ����ÿһ������������һ��
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
//    //������������
//    for(int i=0;i<n;i++)
//    {
//        int num=0;//��¼�м���������ѡ���������
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
