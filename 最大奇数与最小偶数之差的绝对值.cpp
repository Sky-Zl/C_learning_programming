#include<iostream>
using namespace std;
int main()
{
	int num,ji,ou,result;
	int ji_m=0,ou_m=100;
	for(int i=0;i<6;i++)
	{
		cin >> num;
		if(num%2==0)
		{
			if(num<ou_m)
				ou_m=num;
		}
		else
		{	
			if(num>ji_m)
				ji_m=num;
		}
		result=ou_m-ji_m;
	}
		if( result>=0)
			cout << result <<  endl;
		else
			cout << -result << endl; 
 } 
