/*
����
��һ������Ϊn(n < 1000)�����������У��ж��Ƿ����ĳ����Ԫ��֮��Ϊk��

����
��һ���������еĳ���n��k���ÿո�ֿ���

�ڶ������������е�n���������ÿո�ֿ���

���
�������ĳ����Ԫ�صĺ�Ϊk�������yes���������no��
*/
#include<iostream>
using namespace std;
int main(){
	int n,k,x,element[1000],flag=0;
	cin >>n>>k;
	for(int i=0;i<n;i++){
		cin>>x;
		element[i]=x;
	}
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++){
			if(element[i]==element[j]){
				cout<< "yes" <<endl;
				return 0; 
			} 
		}
	cout << "no" <<endl; 

} 
