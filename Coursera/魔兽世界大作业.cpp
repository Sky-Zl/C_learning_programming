#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<iterator>
using namespace std;
string RedOrder[5]={"iceman","lion","wolf","ninja","dragon"};
string BlueOrder[5]={"lion","dragon","ninja","iceman","wolf"};
int DragonLife,NinjaLife,IcemanLife,LionLife,WolfLife;
int DragonAttack,NinjaAttack,IcemanAttack,LionAttack,WolfAttack;
int M,N,R,K,T;
int nTime;										//��ʾ��ǰʱ��
int hour;										//ʱ�䣬�ڼ��غ�
int IsOver;										//��¼��Ϸ�Ƿ���������Ƿ���һ�����ر�ռ��
int IsArrowRed[25];								//IsArrow[i]��ʾ��i�����е���ʿ�Ƿ��ѱ�����
int IsArrowBlue[25];
int IsChangeRed[25];							//�ж��Ƿ����
int IsChangeBlue[25];
int IsRedWin[25];								//�ж���j�ų��еĺ���ʿ�Ƿ�ʤ����֮��Ҫ���Ž�����
int IsBlueWin[25];
class sword
{
private:
	int attack;
public:
	sword(int warriorattack)
	{
		attack=warriorattack*0.2;
	}
	void blunt()
	{
		attack=attack*0.8;
	}
	int getattack()
	{
		return attack;
	}
};
class warrior
{
protected:
	int num;
	int kind;							//��ʾ��ʿ����
	string name;
public:
	warrior(int num,int element,int attack)
	{
		this->num=num;
		this->element=element;
		this->attack=attack;
		IsSword=NULL;IsArrow=0;IsBomb=0;										//��ʼ����
	}
	int usetime;									//arrow��ʣ��ʹ�ô���
	int element;
	int attack;
	sword* IsSword;									//�Ƿ�����������
	int IsArrow,IsBomb;
	int getnum()
	{
		return this->num;
	}
	int getelement()
	{
		return this->element;
	}
	int getkind()
	{
		return this->kind;
	}
	string getname()
	{
		return name;
	}
	int getattack()
	{
		return attack;
	}
	virtual int Fight(warrior *p)
	{
		p->element-=attack;
		if(IsSword!=NULL)
		{
			p->element-=IsSword->getattack();
			IsSword->blunt();
			if(IsSword->getattack()==0)
			{
				IsSword==NULL;
			}
		}
		if(p->element<=0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	virtual int FightBack(warrior *p);
	virtual void result(char r,int j,int base,warrior *p,int temp,string flag)						//rΪ�����jΪ���б��,baseΪ�������࣬1����췽��2��������,pΪ��������
	{}
};
int warrior::FightBack(warrior *p)
{
	int temp=attack*0.5;
	p->element-=temp;
	if(IsSword!=NULL)
	{
		p->element-=IsSword->getattack();
		IsSword->blunt();
		if(IsSword->getattack()==0)
		{
			this->IsSword=NULL;
		}
	}
	if(p->element<=0){return 1;}
	else{return 0;}
}
class iceman:public warrior
{
private:
	int WeaponNum;
public:
	int step;						//icemanÿǰ������������ֵ��9����������20��
	iceman(int num,int iceman,int attack):warrior(num,iceman,attack)
	{
		name="iceman";
		kind=2;
		step=0;
		WeaponNum=num%3;
		if(WeaponNum==0)
		{
			IsSword=new sword(attack);
		}
		else if(WeaponNum==2)
		{
			IsArrow=1;
			usetime=3;
		}
		else
		{
			IsBomb=1;
		}
	}
};
class dragon:public warrior
{
private:
	double morale;
	int WeaponNum;
public:
	dragon(int num,int dragon,int attack,int leftelement):warrior(num,dragon,attack)
	{
		name="dragon";
		morale=(double)leftelement/DragonLife;
		kind=0;
		WeaponNum=num%3;
		if(WeaponNum==0)
		{
			IsSword=new sword(attack);
		}
		else if(WeaponNum==2)
		{
			IsArrow=1;
			usetime=3;
		}
		else
		{
			IsBomb=1;
		}
	}
	double getmorale()
	{
		return morale;
	}
	virtual void result(char r,int j,int base,warrior *p,int temp,string flag)
	{
		string b,fb;
		if(base==1){b="red";fb="blue";}
		else{b="blue";fb="red";}
		if(r=='w')
		{
			morale+=0.2;
		}
		if(r=='d')
		{
			morale-=0.2;
		}
		if(r=='w'||r=='d')
		{
			if(base==1)
			{
				if(flag=="red"||j%2==1&&flag!="blue")
				{
					if(this->element>0&&this->morale>0.8)
					{
						cout<<setw(3)<<setfill('0')<<hour<<":40 "<<b<<" dragon "<<this->getnum()<<" yelled in city "<<j<<endl;
					}	
				}
			}
			else
			{
				if(flag=="blue"||j%2==0&&flag!="red")
				{
					if(this-element>0&&this->morale>0.8)
					{
						cout<<setw(3)<<setfill('0')<<hour<<":40 "<<b<<" dragon "<<this->getnum()<<" yelled in city "<<j<<endl;
					}
				}
			}
		}
	}
};
class lion:public warrior
{
private:
	int loyalty;
	int k;
public:
	lion(int num,int lion,int attack,int leftelement):warrior(num,lion,attack)
	{
		name="lion";
		loyalty=leftelement;
		this->k=K;
		kind=3;
	}
	int getloyalty()
	{
		return loyalty;
	}
	void result(char r,int j,int base,warrior *p,int temp,string flag)
	{
		if(r=='l')
		{
			p->element+=temp;
		}
		if(r=='d')
		{
			this->loyalty-=K;
		}
	}
};
class wolf:public warrior
{
private:
	int weapon;
public:
	wolf(int num,int wolf,int attack):warrior(num,wolf,attack)
	{
		name="wolf";
		kind=4;
	}
	void result(char r,int j,int base,warrior *p,int temp,string flag)
	{
		if(r=='w')
		{
			if(p->IsArrow&&!this->IsArrow)
			{
				this->IsArrow=p->IsArrow;
				this->usetime=p->usetime;
			}
			if(p->IsBomb&&!this->IsBomb)
			{
				this->IsBomb=p->IsBomb;
			}
			if(p->IsSword!=NULL&&this->IsSword==NULL)
			{
				this->IsSword=p->IsSword;
			}
		}
	}
};
class ninja:public warrior
{
private:
	int weapon1,weapon2;
public:
	ninja(int num,int ninja,int attack):warrior(num,ninja,attack)
	{
		name="ninja";
		kind=1;
		weapon1=num%3;
		weapon2=(num+1)%3;
		if(weapon1==0)
		{
			IsSword=new sword(attack);
		}
		else if(weapon1==2)
		{
			IsArrow=1;
			usetime=3;
		}
		else
		{
			IsBomb=1;
		}
		if(weapon2==0)
		{
			IsSword=new sword(attack);
		}
		else if(weapon2==2)
		{
			IsArrow=1;
			usetime=3;
		}
		else
		{
			IsBomb=1;
		}
	}
	int FightBack(warrior *p)
	{
		return 0;
	}
};
class city
{
protected:
	int num;									//���
public:
	warrior *rednow;
	warrior *rednext;
	warrior *blue;
	int element;								//����Ԫ
	string flag;								//����
	city(){}
	city(int element,int num,string flag)
	{
		this->element=element;
		this->num=num;
		this->flag=flag;
		rednow=NULL;rednext=NULL;blue=NULL;
	}
	string getflag()
	{
		return this->flag;
	}
	int getelement()
	{
		return this->element;
	}
	int getnum()
	{
		return num;
	}
	int reviseelement(char a,int m)								//a��Ϊ'+'�͡�-��
	{
		if(a=='+')
		{
			element+=m;
		}
		else
		{
			element-=m;
		}
		return element;
	}
	void Escape()
	{
		if(rednow!=NULL)
		{
			if(rednow->getkind()==3&&((lion*)rednow)->getloyalty()<=0)
			{
				cout<<setw(3)<<setfill('0')<<hour<<":05 "<<"red lion "<<rednow->getnum()<<" ran away"<<endl;
				delete rednow;
				rednow=NULL;
			}
		}
		if(blue!=NULL&&blue->getkind()==3)
		{
			if(((lion*)blue)->getloyalty()<=0)
			{
				cout<<setw(3)<<setfill('0')<<hour<<":05 "<<"blue lion "<<blue->getnum()<<" ran away"<<endl;
				delete blue;
				blue=NULL;
			}
		}
	}
	void March(city &east)
	{
		if(east.blue!=NULL)
		{
			this->blue=east.blue;
			if(east.blue->getkind()==2)
			{
				((iceman*)east.blue)->step++;
				if(((iceman*)east.blue)->step==2)
				{
					((iceman*)east.blue)->step-=2;
					east.blue->attack+=20;
					east.blue->element-=9;
					if(east.blue->element<=0)
					{
						east.blue->element=1;
					}
				}
			}
			cout<<setw(3)<<setfill('0')<<hour<<":10 blue "<<east.blue->getname()<<" "<<east.blue->getnum()<<" marched to city "<<this->getnum()<<" with "<<east.blue->getelement()<<" elements and force "<<east.blue->getattack()<<endl;
			east.blue=NULL;
		}
		if(this->rednow!=NULL)
		{
			east.rednext=this->rednow;
			if(east.rednext->getkind()==2)
			{
				((iceman*)east.rednext)->step++;
				if(((iceman*)east.rednext)->step==2)
				{
					((iceman*)east.rednext)->step-=2;
					east.rednext->attack+=20;
					east.rednext->element-=9;
					if(east.rednext->element<=0)
					{
						east.rednext->element=1;
					}
				}
			}
			cout<<setw(3)<<setfill('0')<<hour<<":10 red "<<east.rednext->getname()<<" "<<east.rednext->getnum()<<" marched to city "<<east.getnum()<<" with "<<east.rednext->getelement()<<" elements and force "<<east.rednext->getattack()<<endl;
			this->rednow=NULL;
		}
		this->rednow=this->rednext;									//next��ʾ��һ�����ƶ�
		this->rednext=NULL;
	}
	friend void Arrow(int j);
};city WowCity[25];
void Arrow(int j)
{
	if(j==1)
	{
		if(WowCity[j].rednow!=NULL&&WowCity[j].rednow->IsArrow)
		{
			if(WowCity[j+1].blue!=NULL)
			{
				WowCity[j+1].blue->element-=R;
				cout<<setw(3)<<setfill('0')<<hour<<":35 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" shot";
				if(WowCity[j+1].blue->element<=0)
				{
					cout<<" and killed blue "<<WowCity[j+1].blue->getname()<<" "<<WowCity[j+1].blue->getnum();
					IsArrowBlue[j+1]=1;
				}
				cout<<endl;
				WowCity[j].rednow->usetime--;
				if(WowCity[j].rednow->usetime==0)
				{
					WowCity[j].rednow->IsArrow=0;
				}
			}
		}
	}
	else if(j==N)
	{
		if(WowCity[j].blue!=NULL&&WowCity[j].blue->IsArrow)
		{
			if(WowCity[j-1].rednow!=NULL)
			{
				WowCity[j-1].rednow->element-=R;
				cout<<setw(3)<<setfill('0')<<hour<<":35 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" shot";
				if(WowCity[j-1].rednow->element<=0)
				{
					cout<<" and killed red "<<WowCity[j-1].rednow->getname()<<" "<<WowCity[j-1].rednow->getnum();
					IsArrowRed[j-1]=1;
				}
				cout<<endl;
				WowCity[j].blue->usetime--;
				if(WowCity[j].blue->usetime==0)
				{
					WowCity[j].blue->IsArrow=0;
				}
			}
		}
	}
	else
	{
		if(WowCity[j].rednow!=NULL&&WowCity[j].rednow->IsArrow)
		{
			if(WowCity[j+1].blue!=NULL)
			{
				WowCity[j+1].blue->element-=R;
				cout<<setw(3)<<setfill('0')<<hour<<":35 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" shot";
				if(WowCity[j+1].blue->element<=0)
				{
					cout<<" and killed blue "<<WowCity[j+1].blue->getname()<<" "<<WowCity[j+1].blue->getnum();
					IsArrowBlue[j+1]=1;
				}
				cout<<endl;
				WowCity[j].rednow->usetime--;
				if(WowCity[j].rednow->usetime==0)
				{
					WowCity[j].rednow->IsArrow=0;
				}
			}
		}
		if(WowCity[j].blue!=NULL&&WowCity[j].blue->IsArrow)
		{
			if(WowCity[j-1].rednow!=NULL)
			{
				WowCity[j-1].rednow->element-=R;
				cout<<setw(3)<<setfill('0')<<hour<<":35 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" shot";
				if(WowCity[j-1].rednow->element<=0)
				{
					cout<<" and killed red "<<WowCity[j-1].rednow->getname()<<" "<<WowCity[j-1].rednow->getnum();
					IsArrowRed[j-1]=1;
				}
				cout<<endl;
				WowCity[j].blue->usetime--;
				if(WowCity[j].blue->usetime==0)
				{
					WowCity[j].blue->IsArrow=0;
				}
			}
		}
	}
}
void Bomb(int j)
{
	if(WowCity[j].blue!=NULL&&WowCity[j].rednow!=NULL&&WowCity[j].blue->element>0&&WowCity[j].rednow->element>0)
	{
		int redattack=WowCity[j].rednow->attack;
		int redelement=WowCity[j].rednow->element;
		int redkind=WowCity[j].rednow->getkind();
		int blueattack=WowCity[j].blue->attack;
		int blueelement=WowCity[j].blue->element;
		int bluekind=WowCity[j].blue->getkind();
		int redsword=0,bluesword=0;
		if(WowCity[j].rednow->IsSword!=NULL)
		{
			redsword=WowCity[j].rednow->IsSword->getattack();
		}
		if(WowCity[j].blue->IsSword!=NULL)
		{
			bluesword=WowCity[j].blue->IsSword->getattack();
		}
		if(WowCity[j].getflag()=="red"||(WowCity[j].getnum()%2==1&&WowCity[j].getflag()!="blue"))				//�췽�Ƚ���
		{
			blueelement-=(redattack+redsword);
			if(blueelement<=0)
			{
				if(WowCity[j].blue->IsBomb)
				{
					cout<<setw(3)<<setfill('0')<<hour<<":38 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" used a bomb and killed red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<endl;
					delete WowCity[j].blue;
					WowCity[j].blue=NULL;
					delete WowCity[j].rednow;
					WowCity[j].rednow=NULL;
				}
			}
			else
			{
				if(bluekind!=1)
				{
					int temp=0.5*blueattack;
					redelement-=(temp+bluesword);
					if(redelement<=0)
					{
						if(WowCity[j].rednow->IsBomb)
						{
							cout<<setw(3)<<setfill('0')<<hour<<":38 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" used a bomb and killed blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<endl;
							delete WowCity[j].blue;
							WowCity[j].blue=NULL;
							delete WowCity[j].rednow;
							WowCity[j].rednow=NULL;
						}
					}
				}
			}
		}
		else						//�����ȹ�
		{
			redelement-=(blueattack+bluesword);
			if(redelement<=0)
			{
				if(WowCity[j].rednow->IsBomb)
				{
					cout<<setw(3)<<setfill('0')<<hour<<":38 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" used a bomb and killed blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<endl;
					delete WowCity[j].blue;
					WowCity[j].blue=NULL;
					delete WowCity[j].rednow;
					WowCity[j].rednow=NULL;
				}
			}
			else
			{
				if(redkind!=1)
				{
					int temp=0.5*redattack;
					blueelement-=(temp+redsword);
					if(blueelement<=0)
					{
						if(WowCity[j].blue->IsBomb)
						{
							cout<<setw(3)<<setfill('0')<<hour<<":38 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" used a bomb and killed red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<endl;
							delete WowCity[j].blue;
							WowCity[j].blue=NULL;
							delete WowCity[j].rednow;
							WowCity[j].rednow=NULL;
						}
					}
				}
			}
		}
	}
}
class base:public city
{
private:
	string *ManuOrder;
	int order;													//����˳��
	int WarriorNum;
	int IsEnemy;
public:
	warrior *p;													//�ո������������ʿ
	warrior *enemy;
	base(){}
	base(int M,string *ManuOrder,int num,string flag,int order):city(M,num,flag)
	{
		this->ManuOrder=ManuOrder;
		this->order=order;
		WarriorNum=0;
		p=NULL;IsEnemy=0;enemy=NULL;
	}
	void Manufacture()
	{
		int IsManu=0;									//��¼�Ƿ�����
		int IsDragon=0;									//��¼�Ƿ�����
		int IsLion=0;									//��¼�Ƿ���ʨ��
		if(getflag()=="red")
		{
			switch(order)
			{
			case 0:if(IcemanLife<=getelement())
					{
						p=new iceman(++WarriorNum,IcemanLife,IcemanAttack);
						reviseelement('-',IcemanLife);
						IsManu=1;
					}break;
			case 1:if(LionLife<=getelement())
				   {
					   reviseelement('-',LionLife);
					   p=new lion(++WarriorNum,LionLife,LionAttack,getelement());
					   IsManu=1;IsLion=1;
				   }break;
			case 2:if(WolfLife<=getelement())
				   {
					   reviseelement('-',WolfLife);
					   p=new wolf(++WarriorNum,WolfLife,WolfAttack);
					   IsManu=1;
				   }break;
			case 3:if(NinjaLife<=getelement())
				   {
					   reviseelement('-',NinjaLife);
					   p=new ninja(++WarriorNum,NinjaLife,NinjaAttack);
					   IsManu=1;
				   }break;
			case 4:if(DragonLife<=getelement())
				   {
					   reviseelement('-',DragonLife);
					   p=new dragon(++WarriorNum,DragonLife,DragonAttack,getelement());
					   IsManu=1;IsDragon=1;
				   }break;
			}
		}
		else
		{
			switch(order)
			{
			case 0:if(LionLife<=getelement())
				{
					reviseelement('-',LionLife);
					p=new lion(++WarriorNum,LionLife,LionAttack,getelement());
					IsManu=1;IsLion=1;
				}break;
			case 1:if(DragonLife<=getelement())
				   {
					   reviseelement('-',DragonLife);
					   p=new dragon(++WarriorNum,DragonLife,DragonAttack,getelement());
					   IsManu=1;IsDragon=1;
				   }break;
			case 2:if(NinjaLife<=getelement())
				   {
					   reviseelement('-',NinjaLife);
					   p=new ninja(++WarriorNum,NinjaLife,NinjaAttack);
					   IsManu=1;
				   }break;
			case 3:if(IcemanLife<=getelement())
					{
						p=new iceman(++WarriorNum,IcemanLife,IcemanAttack);
						reviseelement('-',IcemanLife);
						IsManu=1;
					}break;
			case 4:if(WolfLife<=getelement())
				   {
					   reviseelement('-',WolfLife);
					   p=new wolf(++WarriorNum,WolfLife,WolfAttack);
					   IsManu=1;
				   }break;
			}
		}
		//�˴�����˺ܳ����������
		if(IsManu)
		{
			cout<<setw(3)<<setfill('0')<<hour<<":00 "<<getflag()<<" "<<ManuOrder[order]<<" "<<WarriorNum<<" born"<<endl;
			if(IsDragon)
			{
				cout<<"Its morale is "<<fixed<<setprecision(2)<<((dragon*)p)->getmorale()<<endl;
			}
			if(IsLion)
			{
				cout<<"Its loyalty is "<<((lion*)p)->getloyalty()<<endl;
			}
			order=(order+1)%5;
		}
	}
	void Escape()
	{
		if(p!=NULL&&p->getkind()==3)
		{
			if(((lion*)p)->getloyalty()<=0)
			{
				cout<<setw(3)<<setfill('0')<<hour<<":05 "<<this->getflag()<<" lion "<<p->getnum()<<" ran away"<<endl;
				delete p;
				p=NULL;
			}
		}
	}
	void March(city &p)
	{
		if(flag=="red")
		{
			if(p.blue!=NULL)
			{
				if(p.blue->getkind()==2)
				{
					((iceman*)p.blue)->step++;
					if(((iceman*)p.blue)->step==2)
					{
						((iceman*)p.blue)->step-=2;
						p.blue->attack+=20;
						p.blue->element-=9;
						if(p.blue->element<=0)
						{
							p.blue->element=1;
						}
					}
				}
				cout<<setw(3)<<setfill('0')<<hour<<":10 blue "<<p.blue->getname()<<" "<<p.blue->getnum()<<" reached red headquarter with "<<p.blue->getelement()<<" elements and force "<<p.blue->getattack()<<endl;
				this->enemy=p.blue;
				p.blue=NULL;
				if(IsEnemy)
				{
					cout<<setw(3)<<setfill('0')<<hour<<":10 red headquarter was taken"<<endl;
					IsOver=1;
				}
				IsEnemy=1;
			}
			if(this->p!=NULL)
			{
				p.rednext=this->p;
				if(p.rednext->getkind()==2)
				{
					((iceman*)p.rednext)->step++;
					if(((iceman*)p.rednext)->step==2)
					{
						((iceman*)p.rednext)->step-=2;
						p.rednext->attack+=20;
						p.rednext->element-=9;
						if(p.rednext->element<=0)
						{
							p.rednext->element=1;
						}
					}
				}
				cout<<setw(3)<<setfill('0')<<hour<<":10 red "<<p.rednext->getname()<<" "<<p.rednext->getnum()<<" marched to city "<<p.getnum()<<" with "<<p.rednext->getelement()<<" elements and force "<<p.rednext->getattack()<<endl;
				this->p=NULL;
			}
		}
		else if(flag=="blue")
		{
			if(this->p!=NULL)
			{
				p.blue=this->p;
				this->p=NULL;
				if(p.blue->getkind()==2)
				{
					((iceman*)p.blue)->step++;
					if(((iceman*)p.blue)->step==2)
					{
						((iceman*)p.blue)->step-=2;
						p.blue->attack+=20;
						p.blue->element-=9;
						if(p.blue->element<=0)
						{
							p.blue->element=1;
						}
					}
				}
				cout<<setw(3)<<setfill('0')<<hour<<":10 blue "<<p.blue->getname()<<" "<<p.blue->getnum()<<" marched to city "<<p.getnum()<<" with "<<p.blue->getelement()<<" elements and force "<<p.blue->getattack()<<endl;
			} 
			if(p.rednow!=NULL)
			{
				if(p.rednow->getkind()==2)
				{
					((iceman*)p.rednow)->step++;
					if(((iceman*)p.rednow)->step==2)
					{
						((iceman*)p.rednow)->step-=2;
						p.rednow->attack+=20;
						p.rednow->element-=9;
						if(p.rednow->element<=0)
						{
							p.rednow->element=1;
						}
					}
				}
				cout<<setw(3)<<setfill('0')<<hour<<":10 red "<<p.rednow->getname()<<" "<<p.rednow->getnum()<<" reached blue headquarter with "<<p.rednow->getelement()<<" elements and force "<<p.rednow->getattack()<<endl;
				this->enemy=p.rednow;
				p.rednow=NULL;
				if(IsEnemy)
				{
					cout<<setw(3)<<setfill('0')<<hour<<":10 blue headquarter was taken"<<endl;
					IsOver=1;
				}
				IsEnemy=1;
			}
			p.rednow=p.rednext;
			p.rednext=NULL;
		}
	}
};base RedBase,BlueBase;
void report(warrior *p,string base)
{
	if(p!=NULL)
	{
		int a=0;
		cout<<setw(3)<<setfill('0')<<hour<<":55 "<<base<<" "<<p->getname()<<" "<<p->getnum()<<" has ";
		if(p->IsArrow)
		{
			a=1;
			cout<<"arrow("<<p->usetime<<")";
		}
		if(p->IsBomb)
		{
			if(a==1)
			{
				cout<<",bomb";
			}
			else
			{
				cout<<"bomb";
			}
			a=1;
		}
		if(p->IsSword!=NULL)
		{
			if(p->IsSword->getattack()>0)
			{
				if(a==1)
				{
					cout<<",sword("<<p->IsSword->getattack()<<")";
				}
				else
				{
					cout<<"sword("<<p->IsSword->getattack()<<")";
				}
			}
		}
		if(!(p->IsArrow)&&!(p->IsBomb)&&((p->IsSword==NULL)||p->IsSword->getattack()==0))
		{
			cout<<"no weapon";
		}
		cout<<endl;
	}
	return;
}

int main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>M>>N>>R>>K>>T;
		cin>>DragonLife>>NinjaLife>>IcemanLife>>LionLife>>WolfLife;
		cin>>DragonAttack>>NinjaAttack>>IcemanAttack>>LionAttack>>WolfAttack;
		RedBase=base(M,RedOrder,0,"red",0),BlueBase=base(M,BlueOrder,N+1,"blue",0);
		for(int j=1;j<=N;j++)								//��ʼ������
		{
			WowCity[j]=city(0,j,"Blank");
		}
		cout<<"Case "<<i<<":"<<endl;
		nTime=0;hour=0;IsOver=0;
		memset(IsChangeRed,0,sizeof(IsChangeRed));
		memset(IsChangeBlue,0,sizeof(IsChangeBlue));
		while(1)
		{
			memset(IsArrowRed,0,sizeof(IsArrowRed));
			memset(IsArrowBlue,0,sizeof(IsArrowBlue));
			memset(IsRedWin,0,sizeof(IsRedWin));
			memset(IsBlueWin,0,sizeof(IsRedWin));
			//��0���ӣ�����һ����ʿ
			RedBase.Manufacture();
			BlueBase.Manufacture();
			nTime+=5;if(nTime>T){break;}
			//��5���ӣ�lion����
			RedBase.Escape();
			for(int j=1;j<=N;j++)
			{
				WowCity[j].Escape();
			}
			BlueBase.Escape();
			nTime+=5;if(nTime>T){break;}
			//��ʮ���ӣ���ʿǰ����ĳһ����
			RedBase.March(WowCity[1]);
			for(int j=1;j<=N-1;j++)
			{
				WowCity[j].March(WowCity[j+1]);
			}
			BlueBase.March(WowCity[N]);
			if(IsOver){break;}//��һ��˾���ռ�죬�������������
			nTime+=10;if(nTime>T){break;}
			//�ڶ�ʮ���ӣ�ÿ�����в���10������Ԫ��elements��
			for(int j=1;j<=N;j++)
			{
				WowCity[j].reviseelement('+',10);
			}
			nTime+=10;if(nTime>T){break;}
			//����ʮ���ӣ���������ֻ��һ����ʿ����ȡ������Ԫ��������Ԫ����˾�
			for(int j=1;j<=N;j++)
			{
				if(WowCity[j].rednow==NULL&&WowCity[j].blue!=NULL&&WowCity[j].element>0)
				{
					BlueBase.reviseelement('+',WowCity[j].getelement());
					cout<<setw(3)<<setfill('0')<<hour<<":30 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" earned "<<WowCity[j].getelement()<<" elements for his headquarter"<<endl;
					WowCity[j].reviseelement('-',WowCity[j].getelement());
				}
				if(WowCity[j].rednow!=NULL&&WowCity[j].blue==NULL&&WowCity[j].element>0)
				{
					RedBase.reviseelement('+',WowCity[j].getelement());
					cout<<setw(3)<<setfill('0')<<hour<<":30 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" earned "<<WowCity[j].getelement()<<" elements for his headquarter"<<endl;
					WowCity[j].reviseelement('-',WowCity[j].getelement());
				}
			}
			nTime+=5;if(nTime>T){break;}
			//��35���ӣ���arrow����ʿ�ż�
			for(int j=1;j<=N;j++)
			{
				Arrow(j);
			}
			nTime+=3;if(nTime>T){break;}
			//��38���ӣ�ӵ��bomb����ʿ�����Ƿ�ʹ��bomb
			for(int j=1;j<=N;j++)
			{
				Bomb(j);
			}
			nTime+=2;if(nTime>T){break;}
			//��40���ӣ�������ʿ�ĳ��з���ս��
			for(int j=1;j<=N;j++)
			{
				int temp1=0;
				if(WowCity[j].rednow!=NULL)
				{
					temp1=WowCity[j].rednow->element;
				}
				int temp2=0;
				if(WowCity[j].blue!=NULL)
				{
					temp2=WowCity[j].blue->element;
				}
				//�Ƿ�5����ǰ��������
				if(IsArrowRed[j]&&IsArrowBlue[j])							//�Ƿ�ͬʱ������
				{
					WowCity[j].rednow=NULL;
					WowCity[j].blue=NULL;
				}
				else
				{
					if(IsArrowRed[j])
					{
						if(WowCity[j].blue!=NULL)
						{
							IsChangeBlue[j]++;
							IsChangeRed[j]=0;
							WowCity[j].blue->result('w',j,2,WowCity[j].rednow,temp1,WowCity[j].getflag());
							IsBlueWin[j]=1;
						}
						delete WowCity[j].rednow;
						WowCity[j].rednow=NULL;
					}
					if(IsArrowBlue[j])
					{
						if(WowCity[j].rednow!=NULL)
						{
							IsChangeRed[j]++;
							IsChangeBlue[j]=0;
							WowCity[j].rednow->result('w',j,1,WowCity[j].blue,temp1,WowCity[j].getflag());
							IsRedWin[j]=1;
						}
						delete WowCity[j].blue;
						WowCity[j].blue=NULL;
					}
				}
				//����Ϊ����
				if(WowCity[j].blue!=NULL&&WowCity[j].rednow!=NULL)
				{	
					//���Ƚ���
					if(WowCity[j].getflag()=="red"||(WowCity[j].getnum()%2==1&&WowCity[j].getflag()!="blue"))
					{
						WowCity[j].rednow->Fight(WowCity[j].blue);
						cout<<setw(3)<<setfill('0')<<hour<<":40 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" attacked blue "<<
							WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" in city "<<j<<" with "<<WowCity[j].rednow->element<<" elements and force "<<WowCity[j].rednow->getattack()<<endl;
						if(WowCity[j].blue->element>0)
						{
							if(WowCity[j].blue->getkind()!=1)
							{
								WowCity[j].blue->FightBack(WowCity[j].rednow);
								cout<<setw(3)<<setfill('0')<<hour<<":40 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" fought back against red "<<
									WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" in city "<<j<<endl;
							}
							if(WowCity[j].rednow->element<=0)
							{
								IsChangeBlue[j]++;
								IsChangeRed[j]=0;
								cout<<setw(3)<<setfill('0')<<hour<<":40 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" was killed in city "<<j<<endl;
								WowCity[j].blue->result('w',j,2,WowCity[j].rednow,temp1,WowCity[j].getflag());
								WowCity[j].rednow->result('l',j,1,WowCity[j].blue,temp1,WowCity[j].getflag());
								IsBlueWin[j]=1;
								delete WowCity[j].rednow;
								WowCity[j].rednow=NULL;
							}
							else
							{
								IsChangeRed[j]=0;IsChangeBlue[j]=0;
								WowCity[j].rednow->result('d',j,1,WowCity[j].blue,temp2,WowCity[j].getflag());
								WowCity[j].blue->result('d',j,2,WowCity[j].rednow,temp2,WowCity[j].getflag());
							}
						}
						else
						{
							IsChangeRed[j]++;
							IsChangeBlue[j]=0;
							cout<<setw(3)<<setfill('0')<<hour<<":40 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" was killed in city "<<j<<endl; 
							WowCity[j].rednow->result('w',j,1,WowCity[j].blue,temp2,WowCity[j].getflag());
							WowCity[j].blue->result('l',j,2,WowCity[j].rednow,temp2,WowCity[j].getflag());
							IsRedWin[j]=1;
							delete WowCity[j].blue;
							WowCity[j].blue=NULL;
						}
					}
					//���Ƚ���
					else
					{
						WowCity[j].blue->Fight(WowCity[j].rednow);
						cout<<setw(3)<<setfill('0')<<hour<<":40 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" attacked red "<<
							WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" in city "<<j<<" with "<<WowCity[j].blue->element<<" elements and force "<<WowCity[j].blue->getattack()<<endl;
						if(WowCity[j].rednow->element>0)
						{
							if(WowCity[j].rednow->getkind()!=1)
							{
								WowCity[j].rednow->FightBack(WowCity[j].blue);
								cout<<setw(3)<<setfill('0')<<hour<<":40 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" fought back against blue "<<
									WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" in city "<<j<<endl;
							}
							if(WowCity[j].blue->element<=0)
							{
								IsChangeRed[j]++;
								IsChangeBlue[j]=0;
								cout<<setw(3)<<setfill('0')<<hour<<":40 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" was killed in city "<<j<<endl; 
								WowCity[j].rednow->result('w',j,1,WowCity[j].blue,temp1,WowCity[j].getflag());
								WowCity[j].blue->result('l',j,2,WowCity[j].rednow,temp2,WowCity[j].getflag());
								IsRedWin[j]=1;
								delete WowCity[j].blue;
								WowCity[j].blue=NULL;
							}
							else
							{
								IsChangeRed[j]=0;IsChangeBlue[j]=0;
								WowCity[j].rednow->result('d',j,1,WowCity[j].blue,temp2,WowCity[j].getflag());
								WowCity[j].blue->result('d',j,2,WowCity[j].rednow,temp1,WowCity[j].getflag());
							}
						}
						else
						{
							IsChangeBlue[j]++;
							IsChangeRed[j]=0;
							cout<<setw(3)<<setfill('0')<<hour<<":40 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" was killed in city "<<j<<endl;
							WowCity[j].blue->result('w',j,2,WowCity[j].rednow,temp2,WowCity[j].getflag());
							WowCity[j].rednow->result('l',j,1,WowCity[j].blue,temp1,WowCity[j].getflag());
							IsBlueWin[j]=1;
							delete WowCity[j].rednow;
							WowCity[j].rednow=NULL;
						}
					}
				}
				//����
				if(WowCity[j].rednow==NULL&&WowCity[j].blue!=NULL&&WowCity[j].element>0)
				{
					cout<<setw(3)<<setfill('0')<<hour<<":40 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" earned "<<WowCity[j].getelement()<<" elements for his headquarter"<<endl;
				}
				if(WowCity[j].rednow!=NULL&&WowCity[j].blue==NULL&&WowCity[j].element>0)
				{
					cout<<setw(3)<<setfill('0')<<hour<<":40 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" earned "<<WowCity[j].getelement()<<" elements for his headquarter"<<endl;
				}
				//�Ļ�����
				if(IsChangeRed[j]==2)
				{
					if(WowCity[j].getflag()!="red")
					{
						WowCity[j].flag="red";
						IsChangeRed[j]=0;
						cout<<setw(3)<<setfill('0')<<hour<<":40 red flag raised in city "<<WowCity[j].getnum()<<endl;
					}
				}
				if(IsChangeBlue[j]==2)
				{
					if(WowCity[j].flag!="blue")
					{
						WowCity[j].flag="blue";
						IsChangeBlue[j]=0;
						cout<<setw(3)<<setfill('0')<<hour<<":40 blue flag raised in city "<<WowCity[j].getnum()<<endl;
					}
				}
			}
			//����������
			for(int j=N;j>=1;j--)
			{
				if(IsRedWin[j])
				{
					if(RedBase.element>=8)
					{
						if(WowCity[j].rednow!=NULL)
						{
							WowCity[j].rednow->element+=8;
							RedBase.element-=8;
						}
					}
				}
			}
			for(int j=1;j<=N;j++)
			{
				if(IsBlueWin[j])
				{
					if(BlueBase.element>=8)
					{
						if(WowCity[j].blue!=NULL)
						{
							WowCity[j].blue->element+=8;
							BlueBase.element-=8;
						}
					}
				}
			}
			//�ռ�����Ԫ
			for(int j=1;j<=N;j++)
			{
				if(WowCity[j].rednow==NULL&&WowCity[j].blue!=NULL&&WowCity[j].element>0)
				{
					BlueBase.reviseelement('+',WowCity[j].getelement());
//					cout<<setw(3)<<setfill('0')<<hour<<":30 blue "<<WowCity[j].blue->getname()<<" "<<WowCity[j].blue->getnum()<<" earned "<<WowCity[j].getelement()<<" elements for his headquarter"<<endl;
					WowCity[j].reviseelement('-',WowCity[j].getelement());
				}
				if(WowCity[j].rednow!=NULL&&WowCity[j].blue==NULL&&WowCity[j].element>0)
				{
					RedBase.reviseelement('+',WowCity[j].getelement());
//					cout<<setw(3)<<setfill('0')<<hour<<":30 red "<<WowCity[j].rednow->getname()<<" "<<WowCity[j].rednow->getnum()<<" earned "<<WowCity[j].getelement()<<" elements for his headquarter"<<endl;
					WowCity[j].reviseelement('-',WowCity[j].getelement());
				}
			}
			nTime+=10;if(nTime>T){break;}
			//��50���ӣ�˾�����ʣ������Ԫ
			cout<<setw(3)<<setfill('0')<<hour<<":50 "<<RedBase.getelement()<<" elements in red headquarter"<<endl;
			cout<<setw(3)<<setfill('0')<<hour<<":50 "<<BlueBase.getelement()<<" elements in blue headquarter"<<endl;
			nTime+=5;if(nTime>T){break;}
			//��55���ӣ�ÿ����ʿ�����������
			for(int j=1;j<=N;j++)
			{
				report(WowCity[j].rednow,"red");
			}
			report(BlueBase.enemy,"red");
			report(RedBase.enemy,"blue");
			for(int j=1;j<=N;j++)
			{
				report(WowCity[j].blue,"blue");
			}
			nTime+=5;if(nTime>T){break;}
			hour++;
		}
	}
	return 0;
}
