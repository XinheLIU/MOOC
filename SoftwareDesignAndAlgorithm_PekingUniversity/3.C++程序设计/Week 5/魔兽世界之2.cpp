/*
 魔兽世界之二：装备
 
 总时间限制:1000ms 内存限制: 65536kB
 描述
 魔兽世界的西面是红魔军的司令部，东面是蓝魔军的司令部。两个司令部之间是依次排列的若干城市。
 
 红司令部，City 1，City 2，……，City n，蓝司令部
 
 两军的司令部都会制造武士。武士一共有 dragon 、ninja、iceman、lion、wolf 五种。每种武士都有编号、生命值这两种属性。
 有的武士可以拥有武器。武器有三种，sword, bomb,和arrow，编号分别为0,1,2。
 双方的武士编号都是从1开始计算。红方制造出来的第 n 个武士，编号就是n。同样，蓝方制造出来的第 n 个武士，编号也是n。
 
 不同的武士有不同的特点。
 dragon 可以拥有一件武器。编号为n的dragon降生时即获得编号为 n%3 的武器。dragon还有“士气”这个属性，是个浮点数，其值为它降生后其司令部剩余生命元的数量除以造dragon所需的生命元数量。
 ninjia可以拥有两件武器。编号为n的ninjia降生时即获得编号为 n%3 和 (n+1)%3的武器。
 iceman有一件武器。编号为n的iceman降生时即获得编号为 n%3 的武器。
 lion 有“忠诚度”这个属性，其值等于它降生后其司令部剩余生命元的数目。
 wolf没特点。
 请注意，在以后的题目里，武士的士气，生命值，忠诚度在其生存期间都可能发生变化，都有作用，武士手中的武器随着使用攻击力也会发生变化。
 
 武士在刚降生的时候有一个生命值。
 
 在每个整点，双方的司令部中各有一个武士降生。
 
 红方司令部按照 iceman、lion、wolf、ninja、dragon 的顺序循环制造武士。
 
 蓝方司令部按照 lion、dragon、ninja、iceman、wolf 的顺序循环制造武士。
 
 制造武士需要生命元。
 
 制造一个初始生命值为 m 的武士，司令部中的生命元就要减少 m 个。
 
 如果司令部中的生命元不足以制造某个按顺序应该制造的武士，那么司令部就试图制造下一个。如果所有武士都不能制造了，则司令部停止制造武士。
 给定一个时间，和双方司令部的初始生命元数目，要求你将从0点0分开始到双方司令部停止制造武士为止的所有事件按顺序输出。
 一共有两种事件，其对应的输出样例如下：
 
 1) 武士降生
 输出样例： 004 blue lion 5 born with strength 5,2 lion in red headquarter
 表示在 4点整，编号为5的蓝魔lion武士降生，它降生时生命值为5,降生后蓝魔司令部里共有2个lion武士。(为简单起见，不考虑单词的复数形式)注意，每制造出一个新的武士，都要输出此时司令部里共有多少个该种武士。
 如果造出的是dragon，那么还要输出一行，例：
 It has a arrow,and it's morale is 23.34
 表示该dragon降生时得到了arrow,其士气是23.34（为简单起见，本题中arrow前面的冠词用a,不用an，士气精确到小数点后面2位，四舍五入）
 如果造出的是ninjia，那么还要输出一行，例：
 It has a bomb and a arrow
 表示该ninjia降生时得到了bomb和arrow。
 如果造出的是iceman，那么还要输出一行，例：
 It has a sword
 表示该iceman降生时得到了sword。
 如果造出的是lion，那么还要输出一行，例：
 It's loyalty is 24
 表示该lion降生时的忠诚度是24。
 2) 司令部停止制造武士
 输出样例： 010 red headquarter stops making warriors
 表示在 10点整，红方司令部停止制造武士
 
 输出事件时：
 
 首先按时间顺序输出；
 同一时间发生的事件，先输出红司令部的，再输出蓝司令部的。
 输入
 第一行是一个整数,代表测试数据组数。
 
 每组测试数据共两行。
 
 第一行，一个整数M。其含义为： 每个司令部一开始都有M个生命元( 1 <= M <= 10000)
 
 第二行：五个整数，依次是 dragon 、ninja、iceman、lion、wolf 的初始生命值。它们都大于0小于等于10000
 输出
 对每组测试数据，要求输出从0时0分开始，到双方司令部都停止制造武士为止的所有事件。
 对每组测试数据，首先输出“Case:n" n是测试数据的编号，从1开始
 接下来按恰当的顺序和格式输出所有事件。每个事件都以事件发生的时间开头，时间以小时为单位，有三位。
 样例输入
 1
 20
 3 4 5 6 7
 样例输出
 Case:1
 000 red iceman 1 born with strength 5,1 iceman in red headquarter
 It has a bomb
 000 blue lion 1 born with strength 6,1 lion in blue headquarter
 It's loyalty is 14
 001 red lion 2 born with strength 6,1 lion in red headquarter
 It's loyalty is 9
 001 blue dragon 2 born with strength 3,1 dragon in blue headquarter
 It has a arrow,and it's morale is 3.67
 002 red wolf 3 born with strength 7,1 wolf in red headquarter
 002 blue ninja 3 born with strength 4,1 ninja in blue headquarter
 It has a sword and a bomb
 003 red headquarter stops making warriors
 003 blue iceman 4 born with strength 5,1 iceman in blue headquarter
 It has a bomb
 004 blue headquarter stops making warriors
	
 
 新学到一点，如果把类型为string的变量用%s打出来会报错，需要在变量名后面加一个 .c_str() 才能正常打出。
 嗯，经过两周的学习，对构造函数还有成员的调用更熟练了。同时郭老师的底稿真容易扩充功能啊，更加深刻的体会到了一个好的结构设计能为之后的修改提供多少方便！
 
 */
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
const int  WARRIOR_NUM = 5;
const int  WEAPON_NUM = 3;
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
    int weaponNum;
    int weaponNo[2];
    int no;
    double morale;  //士气
    int loyalty;    //忠诚度
public:
    static string names[WARRIOR_NUM];
    static string weapons[WEAPON_NUM];
    static int initialLifeValue [WARRIOR_NUM];
    Warrior( Headquarter * p,int no_,int kindNo_ );
    void PrintResult(int nTime);
    void PrintInfomation();
};

class Headquarter
{
private:
    int totalLifeValue;
    bool stopped;
    int totalWarriorNum;
    int color;
    int curMakingSeqIdx; //当前要制造的武士是制造序列中的第几个
    int warriorNum[WARRIOR_NUM]; //存放每种武士的数量
    Warrior * pWarriors[1000];
public:
    friend class Warrior;
    static int makingSeq[2][WARRIOR_NUM]; //武士的制作顺序序列
    void Init(int color_, int lv);
    ~Headquarter () ;
    int Produce(int nTime);
    string GetColor();
    
};


Warrior::Warrior( Headquarter * p,int no_,int kindNo_ ) {
    no = no_;
    kindNo = kindNo_;
    pHeadquarter = p;
    
    if( kindNo != 3 && kindNo != 4){
        if(kindNo == 1) weaponNum = 2;
        else weaponNum = 1;
    }
    else weaponNum = 0;
    for( int i = 0;i < weaponNum;i++ ) weaponNo[i] = (no + i) % 3;
    
    if( kindNo == 0 ) morale = (double)p->totalLifeValue/initialLifeValue[0];
    else morale = 0;
    if( kindNo == 3 ) loyalty = p->totalLifeValue;
    else loyalty = 0;
}

void Warrior::PrintResult(int nTime)
{
    string color =  pHeadquarter->GetColor();
    printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n"  ,
           nTime, color.c_str(), names[kindNo].c_str(), no, initialLifeValue[kindNo],
           pHeadquarter->warriorNum[kindNo],names[kindNo].c_str(),color.c_str());
}

void Warrior::PrintInfomation()
{
    if(kindNo == 0) printf("It has a %s,and it's morale is %.2f\n",weapons[weaponNo[0]].c_str(),morale);
    if(kindNo == 1) printf("It has a %s and a %s\n",weapons[weaponNo[0]].c_str(),weapons[weaponNo[1]].c_str());
    if(kindNo == 2) printf("It has a %s\n",weapons[weaponNo[0]].c_str());
    if(kindNo == 3) printf("It's loyalty is %d\n",loyalty);
}

void Headquarter::Init(int color_, int lv)
{
    color = color_;
    totalLifeValue = lv;
    totalWarriorNum = 0;
    stopped = false;
    curMakingSeqIdx = 0;
    for( int i = 0;i < WARRIOR_NUM;i++ )
        warriorNum[i] = 0;
}

Headquarter::~Headquarter () {
    for( int i = 0;i < totalWarriorNum;i++ )
        delete pWarriors[i];
}

int Headquarter::Produce(int nTime)
{
    
    if( stopped )
        return 0;
    int searchingTimes = 0;
    while( Warrior::initialLifeValue[makingSeq[color][curMakingSeqIdx]] > totalLifeValue &&
          searchingTimes < WARRIOR_NUM ) {
        curMakingSeqIdx = ( curMakingSeqIdx + 1 ) % WARRIOR_NUM;
        searchingTimes++;
    }
    int kindNo = makingSeq[color][curMakingSeqIdx];
    if( Warrior::initialLifeValue[kindNo] > totalLifeValue ) {
        stopped = true;
        if( color == 0)
            printf("%03d red headquarter stops making warriors\n",nTime);
        else
            printf("%03d blue headquarter stops making warriors\n",nTime);
        return 0;
    }
    //制作士兵：
    totalLifeValue -= Warrior::initialLifeValue[kindNo];
    curMakingSeqIdx = ( curMakingSeqIdx + 1 ) % WARRIOR_NUM;
    pWarriors[totalWarriorNum] = new Warrior( this,totalWarriorNum+1,kindNo);
    warriorNum[kindNo]++;
    pWarriors[totalWarriorNum]->PrintResult(nTime);
    pWarriors[totalWarriorNum]->PrintInfomation();
    totalWarriorNum++;
    return 1;
}

string Headquarter::GetColor()
{
    if( color == 0)
        return "red";
    else
        return "blue";
}

string Warrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
string Warrior::weapons[WEAPON_NUM] = { "sword","bomb","arrow" };
int Warrior::initialLifeValue [WARRIOR_NUM];
int Headquarter::makingSeq[2][WARRIOR_NUM] = { { 2,3,4,1,0 },{3,0,1,2,4} }; //两个司令部武士的制作顺序序列

int main()
{
    int t;
    int m;
    Headquarter RedHead,BlueHead;
    scanf("%d",&t);
    int nCaseNo = 1;
    while ( t-- ) {
        printf("Case:%d\n",nCaseNo++);
        scanf("%d",&m);
        for( int i = 0;i < WARRIOR_NUM;i++ )
            scanf("%d", & Warrior::initialLifeValue[i]);
        RedHead.Init(0,m);
        BlueHead.Init(1,m);
        int nTime = 0;
        while(true) {
            int tmp1 = RedHead.Produce(nTime);
            int tmp2 = BlueHead.Produce(nTime);
            if( tmp1 == 0 && tmp2 == 0)
                break;
            nTime++;
        }
    }
    return 0;
}