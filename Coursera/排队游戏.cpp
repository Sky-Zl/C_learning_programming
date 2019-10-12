#include<iostream>
using namespace std;
char line[100];
char boy;
// ((()(())())(()))
int reline(int i) {
	int j = i + 1;//1
	//需要有两个记录
	while (line[j] == boy) {
		j = reline(j);//2 6
	}
	if (line[j] != boy && line[j] != '\0') {
		cout << i << ' ' << j << endl;//3
		return j + 1;//4
	}
	else {
		return j;//5
	}
}
 
int main() {
	cin.getline(line, 100);
	boy = line[0];
	reline(0);
 
	return 0;
 
}

