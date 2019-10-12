/*
描述
在main函数中， 生成一个5*5的矩阵，输入矩阵数据，并输入n，m的值。判断n，m是否在数组范围内，如果不在，则输出error；如果在范围内，则将n行和m行交换，输出交换n，m后的新矩阵。

输入
5*5矩阵的数据，以及n和m的值。

输出
如果不可交换，则输出error

如果可交换，则输出新矩阵
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

