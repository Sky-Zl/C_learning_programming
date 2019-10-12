/*
描述
甲壳虫的《A day in the life》和《Tomorrow never knows》脍炙人口，如果告诉你a day in the life,真的会是tomorrow never knows?相信学了计概之后这个不会是难题，现在就来实现吧。

读入一个格式为yyyy-mm-dd的日期（即年－月－日），输出这个日期下一天的日期。可以假定输入的日期不早于1600-01-01，也不晚于2999-12-30。

输入
输入仅一行，格式为yyyy-mm-dd的日期。

输出
输出也仅一行，格式为yyyy-mm-dd的日期
*/

//#include<iostream>
//#include<cstdio>
//using namespace std;
//int main(){
//	int year, month, day;
//	int dayTable[2][13] = {
//	  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
//	  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
//	};
//	int isLeapYear, daysOfMonth;
//	scanf("%d-%d-%d", &year, &month, &day);
//	isLeapYear = (year % 4 == 0 && year % 100 != 0)|| (year %400 == 0);
//	daysOfMonth = dayTable[isLeapYear][month];
//	++day;
//	if(day > daysOfMonth) {
//	  day = 1;
//	  ++month;
//	}
//	if(month > 12) {
//	  month = 1;
//	  ++year;
//	}
//	printf("%d-%02d-%02d\n", year, month, day);
//  return 0;
// }
//	
#include<iostream>
#include<iomanip>
using namespace std;

// 通过字符变量将-吃掉，即：在输入是用char字符变量来接收
int main() {
	int year, month, day;
	char m, n;
	cin >> year >> m >> month >> n >> day;

	//下面开始判断是否为闰年
	bool leap = 0;
	bool special = 0;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		leap = 1;
	}
	// 先处理特殊：闰年以及月增和年增
	// 通过一个bool值，来表示是否发生了月增或者年增？
	if (month == 2) {
		if (leap == 1 && day == 29) {
			month += 1;
			day = 1;
			special = 1;
		}
		if (leap == 0 && day == 28) {
			month += 1;
			day = 1;
			special = 1;
		}
	}
	//然后是处理年增
	if (0 < month <= 12) {

		if (month == 12 && day == 31) {
			year += 1;
			month = 1;
			day = 1;
			special = 1;
		}
		if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) && day == 31) {
			month += 1;
			day = 1;
			special = 1;
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) {
			month += 1;
			day = 1;
			special = 1;
		}

		// 这里使用else并不好
		//会出现2000-00-00变成2000-00-01
		//else {
		//	day += 1;
		//}
		if (special == 0) {
			day += 1;
		}
	}
	cout << year << '-' << setw(2) << setfill('0') << month << '-' << setw(2) << setfill('0') << day << endl;

	return 0;

}
