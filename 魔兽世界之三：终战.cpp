/*
����
ħ������������Ǻ�ħ����˾�����������ħ����˾�������˾�֮�����������е����ɳ��У����д��������α��Ϊ1,2,3 .... N ( N <= 20 )����ħ����˾��������Ϊ0�ĳ��У���ħ����˾��������ΪN+1�ĳ��С�˾�������Ԫ������������ʿ��

������˾�����������ʿ����ʿһ���� dragon ��ninja��iceman��lion��wolf ���֡�ÿ����ʿ���б�š�����ֵ�����������������ԡ�

˫������ʿ��Ŷ��Ǵ�1��ʼ���㡣�췽��������ĵ� n ����ʿ����ž���n��ͬ����������������ĵ� n ����ʿ�����Ҳ��n��

��ʿ�ڸս�����ʱ����һ����ʼ������ֵ������ֵ��ս���лᷢ���仯���������ֵ���ٵ�0������ֵ��Ϊ����ʱӦ������Ϊ0����������ʿ��������ʧ����

�е���ʿ����ӵ�����������������֣�sword, bomb,��arrow����ŷֱ�Ϊ0,1,2��

��ʿ������ͳ��Է�˾��ߣ��ھ����ĳ�������������ˣ�ͬһʱ��ÿ���������ֻ������1������ʿ��һ������ʿ�����ͻᷢ��ս����ÿ��ս��ֻ��һ��������������һ�Ρ�������������ֵ���ȥ�����ߵĹ�����ֵ�ͽ���������sword�Ĺ�����ֵ������������û�����ͻᷢ�𷴻����������ߵ�����ֵҪ��ȥ�����߹�����ֵ��һ��(ȥβȡ��)�ͷ���������sword�Ĺ�����ֵ�����������µ��������ء�

�����ʿ��ս����ɱ�����ˣ���������������ɱ�����Ƿ���ɱ����������˾����������䷢��8������Ԫ��Ϊ������ʹ������ֵ����8����Ȼǰ����˾�����8������Ԫ�����˾�������Ԫ�����Խ������е���ʿ�������Ƚ�������з�˾�������ʿ��

���ĳ��ʿ��ĳ���е�ս����ɱ���˵��ˣ������ʿ��˾�����ȡ�øó��������е�����Ԫ��ע�⣬˾����������ȫ������������Ȼ��ſ�ʼ�Ӹ�������ʤ�̵ĳ��л�������Ԫ��������˾�����Ԫ������첻����������ʿ��˾�Ҳ������ȡ��ս��Ʒ����Ԫ��Ϊ�䲹��������

���һ��ս���Ľ����˫�����Ҵ�(ƽ��)����˫�����������߷���ս���ĳ��е�����Ԫ��

���п��Բ����ӣ�һ��ʼ���г��ж�û�����ӡ��ڲ����ĳ��У��Լ����Ϊ������������У��ɺ���ʿ��������������ڲ�����ĳ��У��Լ����Ϊż����������У�������ʿ�������������

��ĳ����������������ս������ͬһ������ʿɱ������(����ս��֮����������ɸ�ս��ʱ�̲�û�з���ս������������ս����Ȼ���������ģ�������м���ƽ�ֵ�ս�����Ͳ���������) ����ô�ó��оͻ����ʤ�������ģ���ԭ�����Űܷ������ģ���ܷ��������¡�����һ�����ϣ���һֱ���ţ�ֱ�������˸�����һ���������ֻ�ܲ�һ�����ģ�����û�����˸���ǰ��Ҳ�����ٴβ�ͬ��ɫ���졣

�������������ص㣺

sword�����ĳ�ʼ������Ϊӵ��������ʿ�Ĺ�������20%��ȥβȡ����������swordÿ����һ��ս��(�����������������Ƿ���)���ͻ��ۣ���������Ϊ����ս��ǰ��80% (ȥβȡ��)��sword��������Ϊ0ʱ����Ϊ��ʿʧȥ��sword�������ʿ����ʱ�õ���һ����ʼ������Ϊ0��sword������Ϊ��ʿû��sword.

arrow��һ��������ֵR�������һ��Ҫ�ߵ��ĳ����е��ˣ���ôӵ��arrow����ʿ�ͻ�ż�������һ�����еĵ��ˣ����ܹ����Է�˾���ĵ��ˣ�������������arrowʹ���˵�����ֵ����R��������С�ڵ���0������˱�ɱ����arrowʹ��3�κ󼴱��ľ�����ʿʧȥarrow���������ڵ���ʿ����ͬʱ�ż��ѶԷ�������

ӵ��bomb����ʿ����ս����ʼǰ����ж��Լ�����ɱ�������������������ˣ����߱������������������ܵ����Լ���ɱ�������Ҽ�����ʿ����֪�����˵Ĺ�����������ֵ������ô�ͻ�ʹ��bomb�͵���ͬ���ھ�����ʿ��Ԥ��Է��Ƿ��ʹ��bomb��

��ʿʹ��bomb�͵���ͬ���ھ�������£�������һ��ս����˫�����������߳��е�����Ԫ��Ҳ��Ӱ����е����ġ�

��ͬ����ʿ�в�ͬ���ص㡣

dragon����ӵ��һ�����������Ϊn��dragon����ʱ����ñ��Ϊ n%3 ��������dragon���С�ʿ����������ԣ��Ǹ�����������ֵΪ����������˾�ʣ������Ԫ������������dragon���������Ԫ������dragon ��һ����������������ս�������������û��ս��������ʿ��ֵ����0.8���ͻỶ����dragonÿȡ��һ��ս����ʤ��(���˱�ɱ��)��ʿ���ͻ�����0.2��ÿ����һ��δ�ܻ�ʤ��ս����ʿ��ֵ�ͻ����0.2��ʿ�����������ڻ���֮ǰ��

ninjia����ӵ���������������Ϊn��ninjia����ʱ����ñ��Ϊ n%3 �� (n+1)%3��������ninja ������Ҳ�Ӳ��������ˡ�

iceman��һ�����������Ϊn��iceman����ʱ����ñ��Ϊ n%3 ��������iceman ÿǰ���������ڵ�2����ɵ�ʱ������ֵ�����9��������������20������������ֵ��9���С�ڵ���0��������ֵ����9,���Ǳ�Ϊ1����iceman�������߶��˶�����

lion �С��ҳ϶ȡ�������ԣ����ʼֵ����������֮����˾�ʣ������Ԫ����Ŀ��ÿ����һ��δ��ɱ�����˵�ս�����ҳ϶Ⱦͽ���K���ҳ϶Ƚ���0��0���£����lion����ս��,��Զ��ʧ�������Ѿ��������˾���lion�������ܡ�Lion�ڼ���˾��������ܡ�lion ����ս��������ս��ǰ������ֵ�ͻ�ת�Ƶ��������ϡ���ν��ս��ǰ��������ÿ��Сʱ��40��ǰ��һ˲�䡣

wolf����ʱû��������������ս���������ʤ��ɱ�����ˣ����ͻ�ɻ���˵����������Լ����е������Ͳ��ɻ��ˡ����ɻ��������Ȼ�������µģ��Ѿ����õ�ʲô���ˣ�����ʲô���ġ�

�����ǲ�ͬʱ��ᷢ���Ĳ�ͬ�¼���

��ÿ�����㣬��ÿ��Сʱ�ĵ�0�֣� ˫����˾��и���һ����ʿ������

�췽˾����� iceman��lion��wolf��ninja��dragon ��˳��������ʿ��

����˾����� lion��dragon��ninja��iceman��wolf ��˳��������ʿ��

������ʿ��Ҫ����Ԫ��

����һ����ʼ����ֵΪ m ����ʿ��˾��е�����Ԫ��Ҫ���� m ����

���˾��е�����Ԫ����������ĳ��ʿ����ô˾��͵ȴ���ֱ������㹻����Ԫ��ĵ�һ�����㣬���������ʿ�����磬��2:00���췽˾���������һ�� wolf �������ʱ����Ԫ���㣬��ô�ͻ�ȴ���ֱ������Ԫ�㹻�����һ�����㣬������һ�� wolf��

��ÿ��Сʱ�ĵ�5�֣������ܵ�lion������һʱ�������ˡ�

��ÿ��Сʱ�ĵ�10�֣����е���ʿ������˾�����ǰ��һ�������Ӽ���˾��ߵ����ڳ��У����һ�������ߵ���һ�����С���Ӻ͵о�˾����ڵĳ��е���о�˾���

��ÿ��Сʱ�ĵ�20�֣�ÿ�����в���10������Ԫ������Ԫ���ڳ��У�ֱ������ʿȡ�ߡ�

��ÿ��Сʱ�ĵ�30�֣����ĳ��������ֻ��һ����ʿ����ô����ʿȡ�߸ó����е���������Ԫ������������Щ����Ԫ���͵���������˾���

��ÿ��Сʱ�ĵ�35�֣�ӵ��arrow����ʿ�ż����Ե�������˺����ż��¼�Ӧ�㷢���ڼ������ĳ��С�ע�⣬�ż�������ս������˷ż�����ʿ����õ��κκô�����ʿ��û�е��˵ĳ��б�������Ҳ��Ӱ�������ڳ��е����ĸ��������

��ÿ��Сʱ�ĵ�38�֣�ӵ��bomb����ʿ�����Ƿ�Ӧ��ʹ��bomb������ǣ�����bomb�͵���ͬ���ھ���

��ÿ��Сʱ�ĵ�40�֣�����������ʿ�ĳ��У��ᷢ��ս���� ���������5����ǰ�Ѿ���������arrow��������ô��Ȼ��Ϊ������һ��ս�������Ҵ������Ϊ�����ս����ʤ����������²����С���ʿ����������������ʿ������������ʿս�������¼���������ս��ʤ����Ӧ�÷��������鶼�ᷢ������Wolfһ���ܽɻ�����������Ҳ���ܸ������ȵȡ��ڴ������,Dragonͬ����ͨ���ж��Ƿ�Ӧ���ֵ��Լ����������������Ƿ񻶺���

��ÿ��Сʱ�ĵ�50�֣�˾�������ӵ�е�����Ԫ������

��ÿ��Сʱ�ĵ�55�֣�ÿ����ʿ������ӵ�е����������

��ʿ����Է�˾��������������ˣ��Ӵ˾ʹ��������������¡�

�κ�һ����˾������ǳ�����2�����ˣ�����Ϊ��˾��ѱ�����ռ�졣

�κ�һ����˾�������ռ�죬��ս��������ս������֮��Ͳ��ᷢ���κ������ˡ�

����һ��ʱ�䣬Ҫ���㽫��0��0�ֿ�ʼ����ʱ��Ϊֹ�������¼���˳��������¼������Ӧ������������£�

1) ��ʿ����
��������� 000:00 blue lion 1 born

��ʾ�� 0��0�֣����Ϊ1����ħlion��ʿ����

����������dragon����ô��Ҫ�����һ�У�����

000:00 blue dragon 1 born

Its morale is 23.34

��ʾ�ø�dragon����ʱʿ����23. 34(�������뵽С�������λ)

����������lion����ô��Ҫ�����һ�У���:

000:00 blue lion 1 born

Its loyalty is 24

��ʾ��lion����ʱ���ҳ϶���24

2) lion����
��������� 000:05 blue lion 1 ran away

��ʾ�� 0��5�֣����Ϊ1����ħlion��ʿ����

3) ��ʿǰ����ĳһ����
��������� 000:10 red iceman 1 marched to city 1 with 20 elements and force 30

��ʾ�� 0��10�֣���ħ1����ʿicemanǰ����1�ų��У���ʱ������ֵΪ20,������Ϊ30

����iceman,���������ֵ�͹�����Ӧ���Ǳ仯�����ֵ

4)��ʿ�ż�
��������� 000:35 blue dragon 1 shot

��ʾ�� 0��35�֣����Ϊ1����ħdragon��ʿ���һ֧�����������ļ�ɱ���˵��ˣ���Ӧ���������

000:35 blue dragon 1 shot and killed red lion 4

��ʾ�� 0��35�֣����Ϊ1����ħdragon��ʿ���һ֧����ɱ���˱��Ϊ4�ĺ�ħlion��

5)��ʿʹ��bomb
��������� 000:38 blue dragon 1 used a bomb and killed red lion 7

��ʾ�� 0��38�֣����Ϊ1����ħdragon��ʿ��ը���ͱ��Ϊ7�ĺ�ħlionͬ���ھ���

6) ��ʿ��������
���������000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30

��ʾ��0��40�֣�1�ų����У���ħ1����ʿiceman ������ħ1����ʿlion,�ڷ������ǰ����ħ1����ʿiceman����ֵΪ20��������Ϊ 30

7) ��ʿ����
���������001:40 blue dragon 2 fought back against red lion 2 in city 1

��ʾ��1��40�֣�1�ų����У���ħ2����ʿdragon������ħ2����ʿlion

8) ��ʿս��
���������001:40 red lion 2 was killed in city 1

������������ʿ�Ͳ�������һ�������

9) ��ʿ����
���������003:40 blue dragon 2 yelled in city 4

10) ��ʿ��ȡ����Ԫ( elements )
���������001:40 blue dragon 2 earned 10 elements for his headquarter

11) ��������
���������004:40 blue flag raised in city 4

12) ��ʿ�ִ�о�˾�
���������001:10 red iceman 1 reached blue headquarter with 20 elements and force 30

(��ʱ������ֵΪ20,������Ϊ30������iceman,���������ֵ�͹�����Ӧ���Ǳ仯�����ֵ

13) ˾���ռ��
���������003:10 blue headquarter was taken

14)˾���������Ԫ����
000:50 100 elements in red headquarter

000:50 120 elements in blue headquarter

��ʾ��0��50�֣��췽˾���100������Ԫ��������120��

15)��ʿ�����������
000:55 blue wolf 2 has arrow(2),bomb,sword(23)

000:55 blue wolf 4 has no weapon

000:55 blue wolf 5 has sword(20)

��ʾ��0��55�֣���ħ2����ʿwolf��һ֧arrow����֧arrow��������2�Σ���һ��bomb������һ֧������Ϊ23��sword��

��ħ4����ʿwolfû������

��ħ5����ʿwolf��һ֧������Ϊ20��sword��

�����������ʱ�����������ǣ�arrow,bomb,sword�����û��ĳ��������ĳ�������Ͳ����ᡣ����ʱ���Ȱ������򶫵�˳�����еĺ���ʿ���棬Ȼ���ٴ��������е�����ʿ���档

����¼�ʱ��

���Ȱ�ʱ��˳�������

ͬһʱ�䷢�����¼����������ص�������������. ��ʿǰ�����¼�, ���Ƿ�����Ŀ�ĵء�

��һ��ս�����п��ܷ�������� 6 �� 11 ���¼�����Щ�¼�����ͬʱ��������ʱ�����ս����ʼʱ�䡣һ��ս���е���Щ�¼������С��Ӧ���������

������ʿͬʱ�ִ�ͬһ���У������������ʿ��ǰ���¼������������ʿ�ġ�

��Ȼ��13���¼�����֮ǰ��һ˲��һ��������12���¼������ʱ������������ͬһʱ�䷢��������Ӧ�����12���¼�

��Ȼ�κ�һ����˾���ռ��֮�󣬾Ͳ������κ����鷢���ˡ�����˾���ռ��ͬʱ�������¼���ȫ��Ҫ�����

����
��һ����t,���������������

ÿ�����������С�

��һ�У�������� M,N,R,K, T���京��Ϊ��

ÿ��˾�һ��ʼ����M������Ԫ( 1 <= M <= 10000)

����˾�֮��һ����N������( 1 <= N <= 20 )

arrow�Ĺ�������R

lionÿ����һ��δ��ɱ�����˵�ս�����ҳ϶Ⱦͽ���K��

Ҫ�������0ʱ0�ֿ�ʼ����ʱ��TΪֹ(����T) �������¼���T�Է���Ϊ��λ��0 <= T <= 5000

�ڶ��У���������������� dragon ��ninja��iceman��lion��wolf �ĳ�ʼ����ֵ�����Ƕ�����0С�ڵ���10000

�����У���������������� dragon ��ninja��iceman��lion��wolf �Ĺ����������Ƕ�����0С�ڵ���10000

���
��ÿ�����ݣ������һ�У�

Case n:

��Ե�һ�����ݾ���� Case1:

Ȼ��ǡ����˳��͸�ʽ�����ʱ��TΪֹ�����������¼���ÿ���¼������¼�������ʱ�俪ͷ��ʱ���ʽ�ǡ�ʱ: �֡�����ʱ������λ�����֡�����λ��
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <map>

using namespace std;

//������ֱ���
int M, N, R, K, T;//ÿ��˾��ĳ�ʼ����Ԫ����,����������arrow���������ҳ�˥��������ֹʱ����
map<string, int> hp;
map<string,int>atk;
int hour, minute,_hour,_minute;
int arrowwin[25],endflag,headtaken[2];
class warrior*(cities[25][2]);
int flag[25];
string headname[2] = { "red","blue" };
string warriorcreateline[2][5] = { { "iceman", "lion", "wolf", "ninja", "dragon" },
{ "lion", "dragon", "ninja", "iceman", "wolf" }, };
string weaponname[3] = { "sword","bomb","arrow" };
int winner[25],givereward[25];
int firstflag[25];
warrior *redreached, *bluereached;


//����
class weapon {
public:
    int atk;
    weapon(int type, int _atk) {
        if (type == 0)atk = _atk * 2 / 10;
        if (type == 1)atk = 10000;
        if (type == 2)atk = 3;
    }
};

//˾�
class base
{
public:
    string type;
    int warriors;
    int locat;//������
    int source;//����Ԫ
    int id;
    base(){}
    base(string _type) :type(_type){
        if (type == "red") { locat = 0; id = 0; }
        else { locat = N + 1; id = 1; }
        source = M;
        warriors = 0;
    }
};

base head[2];//head[0]�� head[1]��

//��ʿ
class warrior {
public:
    int str;//����ֵ
    int id;//���
    string type;//����
    weapon*weapons[3];
    int force;//ս��
    int step;
    string mast;//˾�
    int loyalty;//�ҳ�ֵ
    double morale;
    string namae() {
        return mast + " " + type + " " + to_string(id);
    }
    warrior(string _mast, int _id, string _type,double headsource) :mast(_mast), id(_id), type(_type){
        step = 0; loyalty = 0; morale = 0;
        str = hp[type]; force = atk[type];
        for (int i = 0; i < 3; i++)
        {
            weapons[i] = NULL;
        }
        weapon* w1 = new weapon(id % 3, force), *w2=new weapon((id + 1) % 3, force);
        if (!(w1->atk))
            w1 = NULL;
        if (!(w2->atk))
            w2 = NULL;
        if (type == "dragon") 
        { 
            weapons[id % 3] = w1;
            morale = headsource / (double)hp[type];
        }
        else if(type=="ninja")
        { 
            weapons[id % 3] = w1; 
            weapons[(id + 1) % 3] = w2;
        }
        else if (type == "lion")
            loyalty = headsource; 
        else if (type == "iceman")
            weapons[id % 3] = w1;
    }
    int sumatk(int defense) {
        if (defense)return force / 2 + usesword(0);
        return force + usesword(0);
    }
    int usesword(int mode) {
        if (weapons[0]) {
            if (!mode)return weapons[0]->atk;
            else {
                weapons[0]->atk = weapons[0]->atk * 8 / 10;
                if (weapons[0]->atk == 0)
                    weapons[0] = NULL;
                return 0;
            }
        }
        else
            return 0;
    }
    void rob(warrior*sb) {
        for (int i = 0; i < 3; i++) {
            if (!weapons[i]) 
                weapons[i] = sb->weapons[i];
        }
    }
    string outweapon() {
        bool pt[3];
        int sum=0;
        for (int i = 0; i < 3; i++) 
        {
            pt[i] = weapons[i];
            sum += pt[i];
        }
        string all="";
        int count = 0;
        for (int i = 2; i >=0; i--) 
        {
            if (weapons[i])
            {
                count++;
                all += weaponname[i];
                if(weaponname[i]!="bomb")
                    all += "(" + to_string(weapons[i]->atk) + ")";
                if (count != sum)
                    all += ",";
            }
        }
        return all;
    }
};

//����
class city {
public:
    int soldier_n;
    int wintime[2];
    int source;
}allcity[25];

//��ʼ��
void clear() {
    endflag = 0;
    hour = 0; minute = 0;
    _hour = T / 60, _minute = T % 60;
    head[0] = base("red");
    head[1] = base("blue");
    for (int i = 0; i <= N + 1; i++)
    {
        cities[i][0] = NULL; cities[i][1] = NULL;
        allcity[i].soldier_n = 0; allcity[i].wintime[0] = allcity[i].wintime[1] = 0;
        if (!(i % 2))flag[i] = 1;
        else flag[i] = 0;
        allcity[i].source = 0;
        allcity[i].wintime[0] = 0;
        allcity[i].wintime[1] = 0;
    }
    memset(firstflag, 0, sizeof(int) * 25);
    memset(winner, 0, sizeof(int) * 25);
    memset(givereward, 0, sizeof(int) * 25);
    memset(arrowwin, 0, sizeof(int) * 25);
    bluereached = NULL, redreached = NULL;
    headtaken[0] = 0;
    headtaken[1] = 0;
}

//����
void init() {
    cin >> M >> N >>R>> K >> T;
    cin >> hp["dragon"] >> hp["ninja"] >> hp["iceman"] >> hp["lion"] >> hp["wolf"];
    cin >> atk["dragon"] >> atk["ninja"] >> atk["iceman"] >> atk["lion"] >> atk["wolf"];
}

//������ʿ
void createwarriors() {
    for (int i = 0; i <= 1; i++) {
        string wtype = warriorcreateline[i][(head[i].warriors % 5)];
        if (hp[wtype] <= head[i].source)
        {
            head[i].warriors++;
            head[i].source -= hp[wtype];
            warrior*newone = new warrior(headname[i], head[i].warriors, wtype, head[i].source);
            cities[head[i].locat][head[i].id] = newone;
            printf("%03d:00 %s %s %d born\n", hour,head[i].type.c_str(), wtype.c_str(),newone->id);
            if (wtype == "dragon")printf("Its morale is %.2lf\n", newone->morale);
            if (wtype == "lion")printf("Its loyalty is %d\n", newone->loyalty);
        }
    }
}

//ʨ������
void lionsescape() {
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j < 2; j++) {
            if (cities[i][j] && cities[i][j]->type == "lion"&&cities[i][j]->loyalty <= 0) {
                printf("%03d:05 %s ran away\n", hour, cities[i][j]->namae().c_str());
                cities[i][j] = NULL;
            }
        }
    }
}

//�о�
void marching() {
    warrior*tmp[25][2];
    for (int i = 0; i <= N + 1; i++)
    {
        tmp[i][0] = cities[i][0];
        tmp[i][1] = cities[i][1];
    }
    for (int i = 0; i <= N + 1; i++) {
        cities[i][0] = cities[i][1] = NULL;
    }
    for (int i = 0; i <= N + 1; i++) {
        if (tmp[i][0]) {
            cities[i + 1][0] = tmp[i][0]; tmp[i][0]->step++;
            if (tmp[i][0]->type == "iceman"&&tmp[i][0]->step % 2 == 0) {
                tmp[i][0]->force += 20; tmp[i][0]->str -= 9;
                if (tmp[i][0]->str <= 0)tmp[i][0]->str = 1;
            }
        }
        if (tmp[i][1]) {
            cities[i - 1][1] = tmp[i][1]; tmp[i][1]->step++;
            if (tmp[i][1]->type == "iceman"&&tmp[i][1]->step % 2 == 0) {
                tmp[i][1]->force += 20; tmp[i][1]->str -= 9;
                if (tmp[i][1]->str <= 0)tmp[i][1]->str = 1;
            }
        }
    }
    for (int i = 0; i <= N + 1; i++) {
        for (int j = 0; j < 2; j++) {
            if (cities[i][j])
            {
                if (i == 0)
                {
                    printf("%03d:10 %s reached red headquarter with %d elements and force %d\n", 
                        hour, cities[i][j]->namae().c_str(), cities[i][j]->str, cities[i][j]->force);
                    headtaken[0]++;
                    if (headtaken[0] == 2)
                    {
                        printf("%03d:10 red headquarter was taken\n", hour);
                        endflag = 1;
                    }
                    redreached = cities[i][j];
                }
                else if (i == N + 1) {
                    printf("%03d:10 %s reached blue headquarter with %d elements and force %d\n", 
                        hour, cities[i][j]->namae().c_str(), cities[i][j]->str, cities[i][j]->force);
                    headtaken[1]++;
                    if (headtaken[1] == 2)
                    {
                        printf("%03d:10 blue headquarter was taken\n", hour);
                        endflag = 1;
                    }
                    bluereached = cities[i][j];
                }
                else printf("%03d:10 %s marched to city %d with %d elements and force %d\n", 
                    hour, cities[i][j]->namae().c_str(),i, cities[i][j]->str, cities[i][j]->force);
            }
        }
    }
}

//��������Ԫ
void sourceproduce() {
    for (int i = 1; i <= N; i++)
        allcity[i].source += 10;
}

//ȡ������Ԫ
void getsource() {
    for (int i = 1; i <= N; i++) 
        for (int j = 0; j < 2; j++) {
            if(cities[i][j]&&!cities[i][j^1]&&allcity[i].source)
            {
                printf("%03d:30 %s earned %d elements for his headquarter\n", hour, cities[i][j]->namae().c_str(), allcity[i].source);
                head[j].source += allcity[i].source;
                allcity[i].source = 0;
            }
        }
}

//�ż�
void arrowreleased() {
    for (int i = 1; i <= N; i++) {
        if (cities[i][0]&&cities[i+1][1]&&cities[i][0]->weapons[2]) {
            cities[i + 1][1]->str -= R ;
            cities[i][0]->weapons[2]->atk--;
            if (!cities[i][0]->weapons[2]->atk)
                cities[i][0]->weapons[2] = NULL;
            if (cities[i + 1][1]->str <= 0) {
                printf("%03d:35 %s shot and killed %s\n", hour, cities[i][0]->namae().c_str(), cities[i + 1][1]->namae().c_str());
                arrowwin[i + 1] = 1;
            }
            else printf("%03d:35 %s shot\n", hour,cities[i][0]->namae().c_str());
        }
        if (cities[i][1] && cities[i - 1][0] && cities[i][1]->weapons[2]) {
            cities[i - 1][0]->str -= R ;
            cities[i][1]->weapons[2]->atk--;
            if (!cities[i][1]->weapons[2]->atk)
                cities[i][1]->weapons[2] = NULL;
            if (cities[i - 1][0]->str <= 0) {
                printf("%03d:35 %s shot and killed %s\n", hour, cities[i][1]->namae().c_str(), cities[i - 1][0]->namae().c_str());
                arrowwin[i - 1] = 1;
            }
            else printf("%03d:35 %s shot\n", hour,cities[i][1]->namae().c_str());
        }
    }
}

//�Ա�
void bombused() {
    for(int i=1;i<=N;i++){
        int j = flag[i];
            if (cities[i][j] &&cities[i][j ^1] && cities[i][j]->str>0 && cities[i][j ^ 1]->str>0) {
                if (cities[i][j ^ 1]->type != "ninja"&&cities[i][j]->weapons[1]&&cities[i][j ^ 1]->str > cities[i][j]->sumatk(0) && (cities[i][j ^ 1]->sumatk(1)) >= (cities[i][j]->str)) {
                    printf("%03d:38 %s used a bomb and killed %s\n", hour, cities[i][j]->namae().c_str(), cities[i][j ^ 1]->namae().c_str());
                    cities[i][j] = cities[i][j ^ 1] = NULL;
                }
                else if (cities[i][j ^ 1]->weapons[1] && cities[i][j]->sumatk(0) >= cities[i][j ^ 1]->str) {
                    printf("%03d:38 %s used a bomb and killed %s\n", hour, cities[i][j^1]->namae().c_str(), cities[i][j]->namae().c_str());
                    cities[i][j] = cities[i][j ^ 1] = NULL;
                }
            }
        }
}

//�ж�ʤ��
void judge() {
    memset(givereward, 0, sizeof(int) * 25);
    for (int i = 1; i <= N; i++)
    {
        if (cities[i][0] && cities[i][1])
        {
            if (cities[i][flag[i]]->sumatk(0) >= cities[i][flag[i] ^ 1]->str)
                winner[i] = flag[i];
            else if (cities[i][flag[i] ^ 1]->type!="ninja"&&cities[i][flag[i] ^ 1]->sumatk(1) >= cities[i][flag[i]]->str)
                winner[i] = flag[i] ^ 1;
        }
        if (arrowwin[i])
        {
            for (int j = 0; j < 2; j++)
                if (cities[i][j])
                    winner[i] = j;
        }
    }
    int r_reward = head[0].source / 8, b_reward = head[1].source / 8;
    for (int i = 1; i <= N; i++)
    {
        if (winner[i] == 0)
        {
            if (r_reward)
            {
                givereward[i] = 1;
                r_reward--;
            }
        }
        if (winner[N + 1 - i] == 1)
        {
            if (b_reward)
            {
                givereward[i] = 1;
                b_reward--;
            }
        }
    }
}

//ս��
void battle() {
    judge();
    for (int i = 1; i <= N; i++) {
            if (arrowwin[i]) {
                for (int j = 0; j < 2; j++)
                {
                    if (cities[i][j] && cities[i][j ^ 1] && cities[i][j ^ 1]->str <= 0 && cities[i][j]->str <= 0)
                    {
                        cities[i][j] = NULL;
                        cities[i][j ^ 1] = NULL;
                    }
                    else if (cities[i][j] && cities[i][j ^ 1] && cities[i][j ^ 1]->str <= 0)
                    {
                        if (cities[i][j]->type == "wolf")
                            cities[i][j]->rob(cities[i][j ^ 1]);
                        cities[i][j ^ 1] = NULL;
                    }
                    else if (cities[i][j] && !cities[i][j ^ 1])
                        cities[i][j] = NULL;
                }
            }
        if (cities[i][0] && cities[i][1])
        {
            arrowwin[i] = 1;
            {
                int hp_atk = cities[i][flag[i]]->str, hp_rcp = cities[i][flag[i] ^ 1]->str;
                cities[i][flag[i] ^ 1]->str -= cities[i][flag[i]]->sumatk(0);
                cities[i][flag[i]]->usesword(1);
                printf("%03d:40 %s attacked %s in city %d with %d elements and force %d\n", hour,
                    cities[i][flag[i]]->namae().c_str(), cities[i][flag[i] ^ 1]->namae().c_str(), i, cities[i][flag[i]]->str, cities[i][flag[i]]->force);
                if (cities[i][flag[i] ^ 1]->str > 0&&cities[i][flag[i]^1]->type!="ninja") {
                    cities[i][flag[i]]->str -= cities[i][flag[i] ^ 1]->sumatk(1);
                    cities[i][flag[i] ^ 1]->usesword(1);
                    printf("%03d:40 %s fought back against %s in city %d\n", hour, cities[i][flag[i] ^ 1]->namae().c_str(), cities[i][flag[i]]->namae().c_str(), i);
                    if (cities[i][flag[i]]->str <= 0) {
                        printf("%03d:40 %s was killed in city %d\n", hour, cities[i][flag[i]]->namae().c_str(), i);
                        if (cities[i][flag[i]^1]->type == "wolf") 
                            cities[i][flag[i]^1]->rob(cities[i][flag[i] ]);
                        if (cities[i][flag[i]]->type == "lion")
                            cities[i][flag[i] ^ 1]->str += hp_atk;
                        cities[i][flag[i]] = NULL;
                    }
                }
                else if (cities[i][flag[i] ^ 1]->str <= 0) {
                    printf("%03d:40 %s was killed in city %d\n", hour, cities[i][flag[i] ^ 1]->namae().c_str(),i);
                    if (cities[i][flag[i]]->type == "wolf") 
                        cities[i][flag[i]]->rob(cities[i][flag[i] ^ 1]);
                    if (cities[i][flag[i] ^ 1]->type == "lion")
                        cities[i][flag[i]]->str += hp_rcp;
                    cities[i][flag[i] ^ 1] = NULL;
                }
            }
            if (cities[i][0] && cities[i][1])
            {
                allcity[i].wintime[0] = allcity[i].wintime[1]=0;
            }
        }
        if (arrowwin[i]) {
            for (int j = 0; j < 2; j++) {
                if (cities[i][j]) {
                    if (cities[i][j]->type == "dragon" && !cities[i][j ^ 1])
                        cities[i][j]->morale += 0.2;
                    if (cities[i][j]->type == "dragon" && cities[i][j ^ 1])
                        cities[i][j]->morale -= 0.2;
                    if (j == flag[i] && cities[i][j]->type == "dragon"&&cities[i][j]->morale>0.8)
                        printf("%03d:40 %s yelled in city %d\n", hour, cities[i][j]->namae().c_str(), i);
                    if (cities[i][j ^ 1] && cities[i][j]->type == "lion")
                        cities[i][j]->loyalty -= K;
                    if (!cities[i][j^1]) 
                    {
                        if (givereward)
                        {
                            cities[i][j]->str += 8;
                            head[j].source -= 8;
                        }
                        printf("%03d:40 %s earned %d elements for his headquarter\n",
                            hour, cities[i][j]->namae().c_str(), allcity[i].source);
                        head[j].source += allcity[i].source;
                        allcity[i].source = 0;
                        allcity[i].wintime[j]++;
                        allcity[i].wintime[j ^ 1] = 0;
                        if (allcity[i].wintime[j] == 2&&(flag[i]!=j||firstflag[i]==0))
                        {
                            firstflag[i] = 1;
                            flag[i] = j;
                            printf("%03d:40 %s flag raised in city %d\n", hour, head[j].type.c_str(), i);
                        }
                    }
                }
            }
        }
    }
}

//��������Ԫ��
void reportsource() {
    printf("%03d:%02d %d elements in red headquarter\n", hour, minute, head[0].source);
    printf("%03d:%02d %d elements in blue headquarter\n", hour, minute, head[1].source);
}

//��ʿ����
void reportwaror() {
    for (int i = 0; i <= N ; i++) 
    {
        if (cities[i][0])
        {
            if (!cities[i][0]->weapons[0] && !cities[i][0]->weapons[1] && !cities[i][0]->weapons[2])
                printf("%03d:55 %s has no weapon\n", hour, cities[i][0]->namae().c_str());
            else
            {
                printf("%03d:55 %s has %s\n", hour, cities[i][0]->namae().c_str(), cities[i][0]->outweapon().c_str());
            }
        }
    }
    if (bluereached) 
    {
        if (!bluereached->weapons[0] && !bluereached->weapons[1] && !bluereached->weapons[2])
            printf("%03d:55 %s has no weapon\n", hour, bluereached->namae().c_str());
        else
        {
            printf("%03d:55 %s has %s\n", hour, bluereached->namae().c_str(), bluereached->outweapon().c_str());
        }
    }
    if (redreached)
    {
        if (!redreached->weapons[0] && !redreached->weapons[1] && !redreached->weapons[2])
            printf("%03d:55 %s has no weapon\n", hour, redreached->namae().c_str());
        else
        {
            printf("%03d:55 %s has %s\n", hour, redreached->namae().c_str(), redreached->outweapon().c_str());
        }
    }
    for (int i = 1; i <= N + 1; i++)
    {
        if (cities[i][1])
        {
            if (!cities[i][1]->weapons[0] && !cities[i][1]->weapons[1] && !cities[i][1]->weapons[2])
                printf("%03d:55 %s has no weapon\n", hour, cities[i][1]->namae().c_str());
            else
            {
                printf("%03d:55 %s has %s\n", hour, cities[i][1]->namae().c_str(), cities[i][1]->outweapon().c_str());
            }
        }
    }
}

int main()
{
    int n;//case��
    cin >> n;
    for (int c = 1; c <= n; c++) {
        int a = 1;
        init();
        clear();
        printf("Case %d:\n", c);
        while (1) {
            //0min
            minute = 0;
            if (hour == _hour && minute > _minute)
                break;
            createwarriors();
            //5min
            minute = 5;
            if (hour == _hour && minute > _minute)
                break;
            lionsescape();
            //10min
            minute = 10;
            if (hour == _hour && minute > _minute)
                break;
            marching();
            if (endflag)
                break;
            //20min
            minute = 20;
            if (hour == _hour && minute > _minute)
                break;
            sourceproduce();
            //30min
            minute = 30;
            if (hour == _hour && minute > _minute)
                break;
            getsource();
            //35min
            minute = 35;
            if (hour == _hour && minute > _minute)
                break;
            arrowreleased();
            //38min
            minute = 38;
            if (hour == _hour && minute > _minute)
                break;
            bombused();
            //40min
            minute = 40;
            if (hour == _hour && minute > _minute)
                break;
            for (int i = 1; i <= N; i++)
                winner[i] = -1;
            battle();
            memset(arrowwin, 0, sizeof(int) * 25);
            //50min
            minute = 50;
            if (hour == _hour && minute > _minute)
                break;
            reportsource();
            //55min
            minute = 55;
            if (hour == _hour && minute > _minute)
                break;
            reportwaror();
            hour++;
        }
    }
    return 0;
}
