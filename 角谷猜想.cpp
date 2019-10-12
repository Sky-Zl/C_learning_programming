#include <iostream>
#include<cstring>

using namespace std;
int f(int n){
	if(n==1)
		cout << "End" <<endl;
	else
	{
		if(n%2!=0)
		{
			cout<<n<<"*3+1="<<n*3+1<<endl;
			return f(n*3+1);
		}
		else
		{
			cout<<n<<"/2="<<n/2<<endl; 
			return f(n/2);
		}
	}
}
int main(){
	int n;
	cin >> n;
	f(n); 
}
