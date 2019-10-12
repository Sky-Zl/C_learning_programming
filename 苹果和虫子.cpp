#include<iostream> 
using namespace std;
int main()
{
	int n;//苹果的数量
	int x,y;
	cin >> n >> x >> y;
	int num;
    if(y%x!=0)
    {
    	num=n-(int)(y/x)-1;
    }
    else
    {
    	num=n-(int)(y/x);
    }
	if(num<0)
	num=0;
	cout << num;
}
