/*
����
ħ������������Ǻ�ħ����˾�����������ħ����˾�������˾�֮�����������е����ɳ��С�

��˾���City 1��City 2��������City n����˾�

������˾�����������ʿ����ʿһ���� dragon ��ninja��iceman��lion��wolf ���֡�ÿ����ʿ���б�š�����ֵ���������ԡ�

�е���ʿ����ӵ�����������������֣�sword, bomb,��arrow����ŷֱ�Ϊ0,1,2��

˫������ʿ��Ŷ��Ǵ�1��ʼ���㡣�췽��������ĵ� n ����ʿ����ž���n��ͬ����������������ĵ� n ����ʿ�����Ҳ��n��

��ͬ����ʿ�в�ͬ���ص㡣

dragon ����ӵ��һ�����������Ϊn��dragon����ʱ����ñ��Ϊ n%3 ��������dragon���С�ʿ����������ԣ��Ǹ�����������ֵΪ����������˾�ʣ������Ԫ������������dragon���������Ԫ������

ninjia����ӵ���������������Ϊn��ninjia����ʱ����ñ��Ϊ n%3 �� (n+1)%3��������

iceman��һ�����������Ϊn��iceman����ʱ����ñ��Ϊ n%3 ��������

lion �С��ҳ϶ȡ�������ԣ���ֵ��������������˾�ʣ������Ԫ����Ŀ��

wolfû�ص㡣

��ע�⣬���Ժ����Ŀ���ʿ��ʿ��������ֵ���ҳ϶����������ڼ䶼���ܷ����仯���������ã���ʿ���е���������ʹ�ù�����Ҳ�ᷢ���仯��

��ʿ�ڸս�����ʱ����һ������ֵ��

��ÿ�����㣬˫����˾��и���һ����ʿ������

�췽˾����� iceman��lion��wolf��ninja��dragon ��˳��ѭ��������ʿ��

����˾����� lion��dragon��ninja��iceman��wolf ��˳��ѭ��������ʿ��

������ʿ��Ҫ����Ԫ��

����һ����ʼ����ֵΪ m ����ʿ��˾��е�����Ԫ��Ҫ���� m ����

���˾��е�����Ԫ����������ĳ����˳��Ӧ���������ʿ����ô˾�����ͼ������һ�������������ʿ�����������ˣ���˾�ֹͣ������ʿ��

����һ��ʱ�䣬��˫��˾��ĳ�ʼ����Ԫ��Ŀ��Ҫ���㽫��0��0�ֿ�ʼ��˫��˾�ֹͣ������ʿΪֹ�������¼���˳�������

һ���������¼������Ӧ������������£�

1) ��ʿ����

��������� 004 blue lion 5 born with strength 5,2 lion in red headquarter

��ʾ�� 4���������Ϊ5����ħlion��ʿ������������ʱ����ֵΪ5,��������ħ˾��ﹲ��2��lion��ʿ��(Ϊ������������ǵ��ʵĸ�����ʽ)ע�⣬ÿ�����һ���µ���ʿ����Ҫ�����ʱ˾��ﹲ�ж��ٸ�������ʿ��

����������dragon����ô��Ҫ���һ�У�����

It has a arrow,and it's morale is 23.34

��ʾ��dragon����ʱ�õ���arrow,��ʿ����23.34��Ϊ�������������arrowǰ��Ĺڴ���a,����an��ʿ����ȷ��С�������2λ���������룩

����������ninjia����ô��Ҫ���һ�У�����

It has a bomb and a arrow

��ʾ��ninjia����ʱ�õ���bomb��arrow��

����������iceman����ô��Ҫ���һ�У�����

It has a sword

��ʾ��iceman����ʱ�õ���sword��

����������lion����ô��Ҫ���һ�У�����

It's loyalty is 24

��ʾ��lion����ʱ���ҳ϶���24��

2) ˾�ֹͣ������ʿ

��������� 010 red headquarter stops making warriors

��ʾ�� 10�������췽˾�ֹͣ������ʿ

����¼�ʱ��

���Ȱ�ʱ��˳�������

ͬһʱ�䷢�����¼����������˾��ģ��������˾��ġ�

����
��һ����һ������,�����������������

ÿ��������ݹ����С�

��һ�У�һ������M���京��Ϊ�� ÿ��˾�һ��ʼ����M������Ԫ( 1 <= M <= 10000)

�ڶ��У���������������� dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ�����Ƕ�����0С�ڵ���10000

���
��ÿ��������ݣ�Ҫ�������0ʱ0�ֿ�ʼ����˫��˾���ֹͣ������ʿΪֹ�������¼���

��ÿ��������ݣ����������Case:n" n�ǲ������ݵı�ţ���1��ʼ

��������ǡ����˳��͸�ʽ��������¼���ÿ���¼������¼�������ʱ�俪ͷ��ʱ����СʱΪ��λ������λ��
*/ 

#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

int Cost[5],Time_Index;
int ord1[5]={2,3,4,1,0},ord2[5]={3,0,1,2,4};
string Weapon_Name[3]={"sword","bomb","arrow"};
string Warrior_Name[5]={"dragon","ninja","iceman","lion","wolf"};
string Headquarter_Name[2]={"red","blue"};

class Weapon{
    string Name;
public:
    Weapon(int n){
        Name=Weapon_Name[n];
    }
    void print(){printf("It has a %s",Name.c_str());}
    void Name_print(){printf("%s",Name.c_str());}
};

class Warrior{
protected:
    int HP;
    string Name;
    Weapon *w1,*w2;
public:
    Warrior(int HP_,string Name_){
        HP=HP_;
        Name=Name_;
        w1=w2=NULL;
    }
    virtual void get_weapon(){
        w1=new Weapon((Time_Index+1)%3);
    }
    void Name_print(){
        printf("%s",Name.c_str());
    }
    virtual void Weapon_print(){
        w1->print();
        printf("\n");
    }
    ~Warrior(){if(w1) delete w1;if(w2) delete w2;}
};
//0
class Dragon:public Warrior{
    double morale;
public:
    Dragon(int HP,double m_):Warrior(HP,Warrior_Name[0]){morale=m_;}
    virtual void Weapon_print(){
        w1->print();
        printf(",and it's morale is %.2lf\n",morale);
    }
};
//1
class Ninja:public Warrior{
public:
    Ninja(int HP):Warrior(HP,Warrior_Name[1]){}
    virtual void get_weapon(){
        w1=new Weapon((Time_Index+1)%3);
        w2=new Weapon((Time_Index+2)%3);
    }
    virtual void Weapon_print(){
        w1->print();
        printf(" and a ");
        w2->Name_print();
        putchar('\n');
    }
};
//2
class Iceman:public Warrior{
public:
    Iceman(int HP):Warrior(HP,Warrior_Name[2]){}
};
//3
class Lion:public Warrior{
    int loyalty;
public:
    Lion(int HP,int l_):Warrior(HP,Warrior_Name[3]){loyalty=l_;}
    virtual void get_weapon(){}
    virtual void Weapon_print(){
        printf("It's loyalty is %d\n",loyalty);
    }
};
//4
class Wolf:public Warrior{
public:
    Wolf(int HP):Warrior(HP,Warrior_Name[4]){}
    virtual void get_weapon(){};
    virtual void Weapon_print(){};
};

class Headquarter{
private:
    string Name;
    int HP;
    int Order[5];
    int Count[5];
    int Warrior_Index;
    Warrior *cur;
    bool STOP;
public:
    Headquarter(string Name_,int HP_,int* O_){
//        memset(Count,0,sizeof(Count));
        Name=Name_;
        HP=HP_;
        for(int i=0;i<5;i++)
            Order[i]=O_[i];
        Warrior_Index=-1;
        cur=NULL;
        STOP=0;
    }

    void Build_Warrior(){
        if(STOP) return;
        Warrior_Index=(Warrior_Index+1)%5;
        int who=Order[Warrior_Index];
        int temp=0;
        while(Cost[who]>HP && temp<5){
            Warrior_Index=(Warrior_Index+1)%5;
            who=Order[Warrior_Index];
            temp++;
        }
        if(HP>=Cost[who]){
            Count[who]++;
            HP-=Cost[who];
            switch(who){
                case 0: cur=new Dragon(Cost[0],(double)HP/Cost[0]);break;
                case 1: cur=new Ninja(Cost[1]);break;
                case 2: cur=new Iceman(Cost[2]);break;
                case 3: cur=new Lion(Cost[3],HP);break;
                case 4: cur=new Wolf(Cost[4]);break;
            };
            cur->get_weapon();
            printf("%03d %s ",Time_Index,Name.c_str());
            cur->Name_print();
            printf(" %d born with strength %d,%d ",Time_Index+1,Cost[who],Count[who]);
            cur->Name_print();
            printf(" in %s headquarter\n",Name.c_str());
            cur->Weapon_print();
            delete cur;
            cur=NULL;
        }
        else{
            printf("%03d %s headquarter stops making warriors\n",Time_Index,Name.c_str());
            STOP=true;
        }
    }
    bool Stop(){return STOP;}
};



int main(){
    int Kase,W;
    scanf("%d",&Kase);
    for(int T=1;T<=Kase;T++){
        printf("Case:%d\n",T);
        scanf("%d",&W);
        Time_Index=0;
        Headquarter r(Headquarter_Name[0],W,ord1), b(Headquarter_Name[1],W,ord2);
        for(int i=0;i<5;i++)
            scanf("%d",&Cost[i]);
        while(!r.Stop() || !b.Stop()){
            r.Build_Warrior();
            b.Build_Warrior();
            Time_Index++;
        }
    }
    return 0;
}
