/*
����
��main�����У� ����һ��5*5�ľ�������������ݣ�������n��m��ֵ���ж�n��m�Ƿ������鷶Χ�ڣ�������ڣ������error������ڷ�Χ�ڣ���n�к�m�н������������n��m����¾���

����
5*5��������ݣ��Լ�n��m��ֵ��

���
������ɽ����������error

����ɽ�����������¾���
*/ 
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
	int t,num[5][5],n,m;
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
		{
			cin>>t;
			num[i][j]=t;
		}
	cin >> n >> m;
	if(n<5&&n>=0&&m<5&&m>=0)
	{
		for(int i=0;i<5;i++){
		
			for(int j=0;j<5;j++)
			{
				if(i==n)
					cout<<setw(3) <<num[m][j];
				else if(i==m)
					cout<<setw(3) <<num[n][j];
				else
					cout<<setw(3) << num[i][j];
			}
			cout <<endl;
		}
	}
	else 
		cout << "error" <<endl;
	return 0;		
}

