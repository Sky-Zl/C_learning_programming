/*
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。

红司令部，City 1，City 2，……，City n，蓝司令部

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第n个武士，编号就是n。同样，蓝方制造出来的第n个武士，编号也是n。

武士在刚降生的时候有一个生命值。

在每个整点，双方的司令部中各有一个武士降生。

红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。

蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士。

制造武士需要生命元。

制造一个初始生命值为m的武士，司令部中的生命元就要减少m个。

如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。

给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。

一共有两种事件，其对应的输出样例如下：

1) 武士降生

输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter

表示在4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5，降生后蓝魔司令部里共有2个lion武士。（为简单起见，不考虑单词的复数形式）注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。

2) 司令部停止制造武士

输出样例： 010 red headquarter stops making warriors

表示在10点整，红方司令部停止制造武士

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。

输入
第一行是一个整数，代表测试数据组数。

每组测试数据共两行。

第一行：一个整数M。其含义为， 每个司令部一开始都有M个生命元( 1 <= M <= 10000)。

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000。

输出
对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。

对每组测试数据，首先输出"Case:n" n是测试数据的编号，从1开始 。

接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。

*/

#include <iostream>  
#include <cstdio>  
#include <string>  
using namespace std;
const int  WARRIOR_NUM = 5;
/*
string Warrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。
蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。
*/
class Headquarter;
class Warrior
{
private:
	Headquarter * pHeadquarter;
	int kindNo; //武士的种类编号 0 dragon 1 ninja 2 iceman 3 lion 4 wolf  
	int no;
public:
	static string names[WARRIOR_NUM];
	static int initialLifeValue[WARRIOR_NUM];
	Warrior(Headquarter * p, int no_, int kindNo_);//构造函数-初始化 
	void PrintResult(int nTime);
};
 

class Headquarter
{
private:
	int totalLifeValue;
	bool stopped;
	int totalWarriorNum;
	string color; 
	int curMakingSeqIdx; //当前要制造的武士是制造序列中的第几个  
	int warriorNum[WARRIOR_NUM]; //存放每种武士的数量  
	int MakingSeq[WARRIOR_NUM];
	Warrior * pWarriors[1000];
public:
	friend class Warrior;
	static int makingSeq[2][WARRIOR_NUM]; //武士的制作顺序序列  
	void Init(int lv,string name,int* order);
	~Headquarter();
	int Produce(int nTime);
};

 
Warrior::Warrior(Headquarter * p, int no_, int kindNo_) {
	no = no_;
	kindNo = kindNo_;
	pHeadquarter = p;
}
void Warrior::PrintResult(int nTime)
{
	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
		nTime, pHeadquarter->color.c_str(), names[kindNo].c_str(), no, initialLifeValue[kindNo],
		pHeadquarter->warriorNum[kindNo], names[kindNo].c_str(), pHeadquarter->color.c_str());
}


void Headquarter::Init(int lv,string name,int * order)
{
	color=name;
	for(int i=0;i<WARRIOR_NUM;i++) 
		MakingSeq[i]=order[i];
//	for(int i=0;i<WARRIOR_NUM;i++) 
//		cout<<MakingSeq[i]<<endl;	
	totalLifeValue = lv;
	totalWarriorNum = 0;
	stopped = false;
	curMakingSeqIdx = 0;
	for (int i = 0; i < WARRIOR_NUM; i++)
		warriorNum[i] = 0;
}
 
Headquarter::~Headquarter() {
	for (int i = 0; i < totalWarriorNum; i++)
		delete pWarriors[i];
}
 
int Headquarter::Produce(int nTime)
{
 
	if (stopped)
		return 0;
	int searchingTimes = 0;
	while (Warrior::initialLifeValue[MakingSeq[curMakingSeqIdx]] > totalLifeValue &&
		searchingTimes < WARRIOR_NUM) {
		curMakingSeqIdx = ++ curMakingSeqIdx % WARRIOR_NUM;
		searchingTimes++;
	}
	
	int kindNo = MakingSeq[curMakingSeqIdx];
	if (Warrior::initialLifeValue[kindNo] > totalLifeValue) {
		stopped = true;
			printf("%03d %s red headquarter stops making warriors\n", nTime,color.c_str());
		return 0;
	}else{
		//制作士兵：  
		totalLifeValue -= Warrior::initialLifeValue[kindNo];
		curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
		pWarriors[totalWarriorNum] = new Warrior(this, totalWarriorNum+1, kindNo);
		warriorNum[kindNo]++;
		pWarriors[totalWarriorNum]->PrintResult(nTime);
		totalWarriorNum++;
		return 1;
	}

}
 
string Warrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
int Warrior::initialLifeValue[WARRIOR_NUM];
int Headquarter::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{ 3,0,1,2,4 } }; //两个司令部武士的制作顺序序列  

int main() {
	int t;
	int m;
	Headquarter RedHead, BlueHead;
	cin >> t;
	int nCaseNo = 1;
	while (t--) {
		printf("Case:%d\n", nCaseNo++);
		cin >> m;
		for (int i = 0; i < WARRIOR_NUM; i++)
			cin>>Warrior::initialLifeValue[i];
		RedHead.Init(m,"red",Headquarter::makingSeq[0]);
		BlueHead.Init(m,"blue",Headquarter::makingSeq[1]);
		int nTime = 0;
		while (true) {
			int tmp1 = RedHead.Produce(nTime);
			int tmp2 = BlueHead.Produce(nTime);
			if (tmp1 == 0 && tmp2 == 0)
				break;
			nTime++;
		}
	}
 
	return 0;
}



