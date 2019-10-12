#include<iostream>
using namespace std;
int main()
{
	int n,score,max=0;
	cin >> n;
	for(int i=0;i<n;i++) 
	{
		cin >> score;
		if(score>max)
			max=score;
	}
	cout << max <<endl;
	return 0;
} 
