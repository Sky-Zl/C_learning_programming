/*
描述
魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市，城市从西向东依次编号为1,2,3 .... N ( N <= 20 )。红魔军的司令部算作编号为0的城市，蓝魔军的司令部算作编号为N+1的城市。司令部有生命元，用于制造武士。

两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值、攻击力这三种属性。

双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。

武士在刚降生的时候有一个初始的生命值，生命值在战斗中会发生变化，如果生命值减少到0（生命值变为负数时应当做变为0处理），则武士死亡（消失）。

有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。

武士降生后就朝对方司令部走，在经过的城市如果遇到敌人（同一时刻每个城市最多只可能有1个蓝武士和一个红武士），就会发生战斗。每次战斗只有一方发起主动进攻一次。被攻击者生命值会减去进攻者的攻击力值和进攻者手中sword的攻击力值。被进攻者若没死，就会发起反击，被反击者的生命值要减去反击者攻击力值的一半(去尾取整)和反击者手中sword的攻击力值。反击可能致敌人于死地。

如果武士在战斗中杀死敌人（不论是主动进攻杀死还是反击杀死），则其司令部会立即向其发送8个生命元作为奖励，使其生命值增加8。当然前提是司令部得有8个生命元。如果司令部的生命元不足以奖励所有的武士，则优先奖励距离敌方司令部近的武士。

如果某武士在某城市的战斗中杀死了敌人，则该武士的司令部立即取得该城市中所有的生命元。注意，司令部总是先完成全部奖励工作，然后才开始从各个打了胜仗的城市回收生命元。对于因司令部生命元不足而领不到奖励的武士，司令部也不会在取得战利品生命元后为其补发奖励。

如果一次战斗的结果是双方都幸存(平局)，则双方都不能拿走发生战斗的城市的生命元。

城市可以插旗子，一开始所有城市都没有旗子。在插红旗的城市，以及编号为奇数的无旗城市，由红武士主动发起进攻。在插蓝旗的城市，以及编号为偶数的无旗城市，由蓝武士主动发起进攻。

当某个城市有连续两场战斗都是同一方的武士杀死敌人(两场战斗之间如果有若干个战斗时刻并没有发生战斗，则这两场战斗仍然算是连续的；但如果中间有平局的战斗，就不算连续了) ，那么该城市就会插上胜方的旗帜，若原来插着败方的旗帜，则败方旗帜落下。旗帜一旦插上，就一直插着，直到被敌人更换。一个城市最多只能插一面旗帜，旗帜没被敌人更换前，也不会再次插同颜色的旗。

各种武器有其特点：

sword武器的初始攻击力为拥有它的武士的攻击力的20%（去尾取整）。但是sword每经过一次战斗(不论是主动攻击还是反击)，就会变钝，攻击力变为本次战斗前的80% (去尾取整)。sword攻击力变为0时，视为武士失去了sword。如果武士降生时得到了一个初始攻击力为0的sword，则视为武士没有sword.

arrow有一个攻击力值R。如果下一步要走到的城市有敌人，那么拥有arrow的武士就会放箭攻击下一个城市的敌人（不能攻击对方司令部里的敌人）而不被还击。arrow使敌人的生命值减少R，若减至小于等于0，则敌人被杀死。arrow使用3次后即被耗尽，武士失去arrow。两个相邻的武士可能同时放箭把对方射死。

拥有bomb的武士，在战斗开始前如果判断自己将被杀死（不论主动攻击敌人，或者被敌人主动攻击都可能导致自己被杀死，而且假设武士可以知道敌人的攻击力和生命值），那么就会使用bomb和敌人同归于尽。武士不预测对方是否会使用bomb。

武士使用bomb和敌人同归于尽的情况下，不算是一场战斗，双方都不能拿走城市的生命元，也不影响城市的旗帜。

不同的武士有不同的特点。

dragon可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，而且士气值大于0.8，就会欢呼。dragon每取得一次战斗的胜利(敌人被杀死)，士气就会增加0.2，每经历一次未能获胜的战斗，士气值就会减少0.2。士气增减发生在欢呼之前。

ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。ninja 挨打了也从不反击敌人。

iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。iceman 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。但是若生命值减9后会小于等于0，则生命值不减9,而是变为1。即iceman不会因走多了而死。

lion 有“忠诚度”这个属性，其初始值等于它降生之后其司令部剩余生命元的数目。每经过一场未能杀死敌人的战斗，忠诚度就降低K。忠诚度降至0或0以下，则该lion逃离战场,永远消失。但是已经到达敌人司令部的lion不会逃跑。Lion在己方司令部可能逃跑。lion 若是战死，则其战斗前的生命值就会转移到对手身上。所谓“战斗前”，就是每个小时的40分前的一瞬间。

wolf降生时没有武器，但是在战斗中如果获胜（杀死敌人），就会缴获敌人的武器，但自己已有的武器就不缴获了。被缴获的武器当然不能算新的，已经被用到什么样了，就是什么样的。

以下是不同时间会发生的不同事件：

在每个整点，即每个小时的第0分， 双方的司令部中各有一个武士降生。

红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序制造武士。

蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序制造武士。

制造武士需要生命元。

制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。

如果司令部中的生命元不足以制造某武士，那么司令部就等待，直到获得足够生命元后的第一个整点，才制造该武士。例如，在2:00，红方司令部本该制造一个 wolf ，如果此时生命元不足，那么就会等待，直到生命元足够后的下一个整点，才制造一个 wolf。

在每个小时的第5分，该逃跑的lion就在这一时刻逃跑了。

在每个小时的第10分：所有的武士朝敌人司令部方向前进一步。即从己方司令部走到相邻城市，或从一个城市走到下一个城市。或从和敌军司令部相邻的城市到达敌军司令部。

在每个小时的第20分：每个城市产出10个生命元。生命元留在城市，直到被武士取走。

在每个小时的第30分：如果某个城市中只有一个武士，那么该武士取走该城市中的所有生命元，并立即将这些生命元传送到其所属的司令部。

在每个小时的第35分，拥有arrow的武士放箭，对敌人造成伤害。放箭事件应算发生在箭发出的城市。注意，放箭不算是战斗，因此放箭的武士不会得到任何好处。武士在没有敌人的城市被箭射死也不影响其所在城市的旗帜更换情况。

在每个小时的第38分，拥有bomb的武士评估是否应该使用bomb。如果是，就用bomb和敌人同归于尽。

在每个小时的第40分：在有两个武士的城市，会发生战斗。 如果敌人在5分钟前已经被飞来的arrow射死，那么仍然视为发生了一场战斗，而且存活者视为获得了战斗的胜利。此情况下不会有“武士主动攻击”，“武士反击”，“武士战死”的事件发生，但战斗胜利后应该发生的事情都会发生。如Wolf一样能缴获武器，旗帜也可能更换，等等。在此情况下,Dragon同样会通过判断是否应该轮到自己主动攻击来决定是否欢呼。

在每个小时的第50分，司令部报告它拥有的生命元数量。

在每个小时的第55分，每个武士报告其拥有的武器情况。

武士到达对方司令部后就算完成任务了，从此就呆在那里无所事事。

任何一方的司令部里若是出现了2个敌人，则认为该司令部已被敌人占领。

任何一方的司令部被敌人占领，则战争结束。战争结束之后就不会发生任何事情了。

给定一个时间，要求你将从0点0分开始到此时间为止的所有事件按顺序输出。事件及其对应的输出样例如下：

1) 武士降生
输出样例： 000:00 blue lion 1 born

表示在 0点0分，编号为1的蓝魔lion武士降生

如果造出的是dragon，那么还要多输出一行，例：

000:00 blue dragon 1 born

Its morale is 23.34

表示该该dragon降生时士气是23. 34(四舍五入到小数点后两位)

如果造出的是lion，那么还要多输出一行，例:

000:00 blue lion 1 born

Its loyalty is 24

表示该lion降生时的忠诚度是24

2) lion逃跑
输出样例： 000:05 blue lion 1 ran away

表示在 0点5分，编号为1的蓝魔lion武士逃走

3) 武士前进到某一城市
输出样例： 000:10 red iceman 1 marched to city 1 with 20 elements and force 30

表示在 0点10分，红魔1号武士iceman前进到1号城市，此时他生命值为20,攻击力为30

对于iceman,输出的生命值和攻击力应该是变化后的数值

4)武士放箭
输出样例： 000:35 blue dragon 1 shot

表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭。如果射出的箭杀死了敌人，则应如下输出：

000:35 blue dragon 1 shot and killed red lion 4

表示在 0点35分，编号为1的蓝魔dragon武士射出一支箭，杀死了编号为4的红魔lion。

5)武士使用bomb
输出样例： 000:38 blue dragon 1 used a bomb and killed red lion 7

表示在 0点38分，编号为1的蓝魔dragon武士用炸弹和编号为7的红魔lion同归于尽。

6) 武士主动进攻
输出样例：000:40 red iceman 1 attacked blue lion 1 in city 1 with 20 elements and force 30

表示在0点40分，1号城市中，红魔1号武士iceman 进攻蓝魔1号武士lion,在发起进攻前，红魔1号武士iceman生命值为20，攻击力为 30

7) 武士反击
输出样例：001:40 blue dragon 2 fought back against red lion 2 in city 1

表示在1点40分，1号城市中，蓝魔2号武士dragon反击红魔2号武士lion

8) 武士战死
输出样例：001:40 red lion 2 was killed in city 1

被箭射死的武士就不会有这一条输出。

9) 武士欢呼
输出样例：003:40 blue dragon 2 yelled in city 4

10) 武士获取生命元( elements )
输出样例：001:40 blue dragon 2 earned 10 elements for his headquarter

11) 旗帜升起
输出样例：004:40 blue flag raised in city 4

12) 武士抵达敌军司令部
输出样例：001:10 red iceman 1 reached blue headquarter with 20 elements and force 30

(此时他生命值为20,攻击力为30）对于iceman,输出的生命值和攻击力应该是变化后的数值

13) 司令部被占领
输出样例：003:10 blue headquarter was taken

14)司令部报告生命元数量
000:50 100 elements in red headquarter

000:50 120 elements in blue headquarter

表示在0点50分，红方司令部有100个生命元，蓝方有120个

15)武士报告武器情况
000:55 blue wolf 2 has arrow(2),bomb,sword(23)

000:55 blue wolf 4 has no weapon

000:55 blue wolf 5 has sword(20)

表示在0点55分，蓝魔2号武士wolf有一支arrow（这支arrow还可以用2次），一个bomb，还有一支攻击力为23的sword。

蓝魔4号武士wolf没武器。

蓝魔5号武士wolf有一支攻击力为20的sword。

交代武器情况时，次序依次是：arrow,bomb,sword。如果没有某种武器，某种武器就不用提。报告时，先按从西向东的顺序所有的红武士报告，然后再从西向东所有的蓝武士报告。

输出事件时：

首先按时间顺序输出；

同一时间发生的事件，按发生地点从西向东依次输出. 武士前进的事件, 算是发生在目的地。

在一次战斗中有可能发生上面的 6 至 11 号事件。这些事件都算同时发生，其时间就是战斗开始时间。一次战斗中的这些事件，序号小的应该先输出。

两个武士同时抵达同一城市，则先输出红武士的前进事件，后输出蓝武士的。

显然，13号事件发生之前的一瞬间一定发生了12号事件。输出时，这两件事算同一时间发生，但是应先输出12号事件

虽然任何一方的司令部被占领之后，就不会有任何事情发生了。但和司令部被占领同时发生的事件，全都要输出。

输入
第一行是t,代表测试数据组数

每组样例共三行。

第一行，五个整数 M,N,R,K, T。其含义为：

每个司令部一开始都有M个生命元( 1 <= M <= 10000)

两个司令部之间一共有N个城市( 1 <= N <= 20 )

arrow的攻击力是R

lion每经过一场未能杀死敌人的战斗，忠诚度就降低K。

要求输出从0时0分开始，到时间T为止(包括T) 的所有事件。T以分钟为单位，0 <= T <= 5000

第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000

第三行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的攻击力。它们都大于0小于等于10000

输出
对每组数据，先输出一行：

Case n:

如对第一组数据就输出 Case1:

然后按恰当的顺序和格式输出到时间T为止发生的所有事件。每个事件都以事件发生的时间开头，时间格式是“时: 分”，“时”有三位，“分”有两位。
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <memory.h>
#include <map>

using namespace std;

//定义各种变量
int M, N, R, K, T;//每个司令部的初始生命元数量,城市数量，arrow攻击力，忠诚衰减量，截止时间量
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


//武器
class weapon {
public:
    int atk;
    weapon(int type, int _atk) {
        if (type == 0)atk = _atk * 2 / 10;
        if (type == 1)atk = 10000;
        if (type == 2)atk = 3;
    }
};

//司令部
class base
{
public:
    string type;
    int warriors;
    int locat;//所处地
    int source;//生命元
    int id;
    base(){}
    base(string _type) :type(_type){
        if (type == "red") { locat = 0; id = 0; }
        else { locat = N + 1; id = 1; }
        source = M;
        warriors = 0;
    }
};

base head[2];//head[0]红 head[1]蓝

//武士
class warrior {
public:
    int str;//生命值
    int id;//编号
    string type;//种类
    weapon*weapons[3];
    int force;//战力
    int step;
    string mast;//司令部
    int loyalty;//忠诚值
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

//城市
class city {
public:
    int soldier_n;
    int wintime[2];
    int source;
}allcity[25];

//初始化
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

//输入
void init() {
    cin >> M >> N >>R>> K >> T;
    cin >> hp["dragon"] >> hp["ninja"] >> hp["iceman"] >> hp["lion"] >> hp["wolf"];
    cin >> atk["dragon"] >> atk["ninja"] >> atk["iceman"] >> atk["lion"] >> atk["wolf"];
}

//制造武士
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

//狮子逃跑
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

//行军
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

//产出生命元
void sourceproduce() {
    for (int i = 1; i <= N; i++)
        allcity[i].source += 10;
}

//取走生命元
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

//放箭
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

//自爆
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

//判断胜负
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

//战斗
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

//报告生命元数
void reportsource() {
    printf("%03d:%02d %d elements in red headquarter\n", hour, minute, head[0].source);
    printf("%03d:%02d %d elements in blue headquarter\n", hour, minute, head[1].source);
}

//武士报告
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
    int n;//case数
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
