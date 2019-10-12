#include<iostream>
using namespace std;
#define PI 3.14159
#define SUM 20000
int main()
{
	int h,r,n;
	double total;
	cin >> h >> r;
	total=PI*r*r*h;
	n=SUM/total;
	if(SUM/total!=0)
		cout << n+1;
	else
		cout << n;
	return 0; 
} 
