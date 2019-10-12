#include <iostream>
using namespace std;
int main()
{
	int n ;
	cin >> n;
	int ge=0,shi=0,bai=0;
	bai = n / 100;
	shi = (n - 100 * bai) / 10;
	ge = n - 100 * bai - 10 * shi;
	cout << bai << endl;
	cout << shi << endl;
	cout << ge << endl;
    return 0;
}

