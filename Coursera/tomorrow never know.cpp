/*
����
�׿ǳ�ġ�A day in the life���͡�Tomorrow never knows�������˿ڣ����������a day in the life,��Ļ���tomorrow never knows?����ѧ�˼Ƹ�֮��������������⣬���ھ���ʵ�ְɡ�

����һ����ʽΪyyyy-mm-dd�����ڣ����꣭�£��գ���������������һ������ڡ����Լٶ���������ڲ�����1600-01-01��Ҳ������2999-12-30��

����
�����һ�У���ʽΪyyyy-mm-dd�����ڡ�

���
���Ҳ��һ�У���ʽΪyyyy-mm-dd������
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

// ͨ���ַ�������-�Ե�����������������char�ַ�����������
int main() {
	int year, month, day;
	char m, n;
	cin >> year >> m >> month >> n >> day;

	//���濪ʼ�ж��Ƿ�Ϊ����
	bool leap = 0;
	bool special = 0;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		leap = 1;
	}
	// �ȴ������⣺�����Լ�����������
	// ͨ��һ��boolֵ������ʾ�Ƿ�������������������
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
	//Ȼ���Ǵ�������
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

		// ����ʹ��else������
		//�����2000-00-00���2000-00-01
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
