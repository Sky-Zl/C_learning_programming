/*
����
ħ������������Ǻ�ħ����˾�����������ħ����˾�������˾�֮�����������е����ɳ��С�

��˾���City 1��City 2��������City n����˾�

������˾�����������ʿ����ʿһ���� dragon ��ninja��iceman��lion��wolf ���֡�ÿ����ʿ���б�š�����ֵ�����������������ԡ�

˫������ʿ��Ŷ��Ǵ�1��ʼ���㡣�췽��������ĵ�n����ʿ����ž���n��ͬ����������������ĵ�n����ʿ�����Ҳ��n��

��ʿ�ڸս�����ʱ����һ������ֵ��

��ÿ�����㣬˫����˾��и���һ����ʿ������

�췽˾�����iceman��lion��wolf��ninja��dragon��˳��ѭ��������ʿ��

����˾�����lion��dragon��ninja��iceman��wolf��˳��ѭ��������ʿ��

������ʿ��Ҫ����Ԫ��

����һ����ʼ����ֵΪm����ʿ��˾��е�����Ԫ��Ҫ����m����

���˾��е�����Ԫ����������ĳ����˳��Ӧ���������ʿ����ô˾�����ͼ������һ�������������ʿ�����������ˣ���˾�ֹͣ������ʿ��

����һ��ʱ�䣬��˫��˾��ĳ�ʼ����Ԫ��Ŀ��Ҫ���㽫��0��0�ֿ�ʼ��˫��˾�ֹͣ������ʿΪֹ�������¼���˳�������

һ���������¼������Ӧ������������£�

1) ��ʿ����

��������� 004 blue lion 5 born with strength 5,2 lion in red headquarter

��ʾ��4���������Ϊ5����ħlion��ʿ������������ʱ����ֵΪ5����������ħ˾��ﹲ��2��lion��ʿ����Ϊ������������ǵ��ʵĸ�����ʽ��ע�⣬ÿ�����һ���µ���ʿ����Ҫ�����ʱ˾��ﹲ�ж��ٸ�������ʿ��

2) ˾�ֹͣ������ʿ

��������� 010 red headquarter stops making warriors

��ʾ��10�������췽˾�ֹͣ������ʿ

����¼�ʱ��

���Ȱ�ʱ��˳�������

ͬһʱ�䷢�����¼����������˾��ģ��������˾��ġ�

����
��һ����һ�������������������������

ÿ��������ݹ����С�

��һ�У�һ������M���京��Ϊ�� ÿ��˾�һ��ʼ����M������Ԫ( 1 <= M <= 10000)��

�ڶ��У���������������� dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ�����Ƕ�����0С�ڵ���10000��

���
��ÿ��������ݣ�Ҫ�������0ʱ0�ֿ�ʼ����˫��˾���ֹͣ������ʿΪֹ�������¼���

��ÿ��������ݣ��������"Case:n" n�ǲ������ݵı�ţ���1��ʼ ��

��������ǡ����˳��͸�ʽ��������¼���ÿ���¼������¼�������ʱ�俪ͷ��ʱ����СʱΪ��λ������λ��

*/

#include <iostream>  
#include <cstdio>  
#include <string>  
using namespace std;
const int  WARRIOR_NUM = 5;
/*
string Warrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
�췽˾����� iceman��lion��wolf��ninja��dragon ��˳��������ʿ��
����˾����� lion��dragon��ninja��iceman��wolf ��˳��������ʿ��
*/
class Headquarter;
class Warrior
{
private:
	Headquarter * pHeadquarter;
	int kindNo; //��ʿ�������� 0 dragon 1 ninja 2 iceman 3 lion 4 wolf  
	int no;
public:
	static string names[WARRIOR_NUM];
	static int initialLifeValue[WARRIOR_NUM];
	Warrior(Headquarter * p, int no_, int kindNo_);//���캯��-��ʼ�� 
	void PrintResult(int nTime);
};
 

class Headquarter
{
private:
	int totalLifeValue;
	bool stopped;
	int totalWarriorNum;
	string color; 
	int curMakingSeqIdx; //��ǰҪ�������ʿ�����������еĵڼ���  
	int warriorNum[WARRIOR_NUM]; //���ÿ����ʿ������  
	int MakingSeq[WARRIOR_NUM];
	Warrior * pWarriors[1000];
public:
	friend class Warrior;
	static int makingSeq[2][WARRIOR_NUM]; //��ʿ������˳������  
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
		//����ʿ����  
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
int Headquarter::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{ 3,0,1,2,4 } }; //����˾���ʿ������˳������  

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



