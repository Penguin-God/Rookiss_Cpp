#include <iostream> // iostream 파일을 복붙함
#include <algorithm>
#include <iterator>
#include <windows.h>
#include "Snail.h"
using namespace std;
// using std::string; using std::reverse;

// min부터 max-1까지의 랜덤 정수값 가져오는 함수
int Random(int min, int max) {
    // rand()는 0 ~ 32767사이의 값을 가져오는 %연산을 써서 원하는 범위의 값을 가져옴
    return min + (rand() % (max - min));
}

// 프로그래밍을 단순하게 생각하면 데이터를 저장하고 가공하는 것. (사실상 모든 것이 데이터니까)
// 가공 부분이 로직인 느낌

int global = 2;

void Hi(int a) {
    a++;
}

#pragma region TextRPG .h

enum JobType {
    Knight = 1,
    Archer,
    Mage,
};

enum MonsterType {
    Slime = 1,
    Orc,
    Skeleton,
};

struct StatInfo
{
    int hp;
    int attack;
    int defence;
};

void EnterLobby();

StatInfo SelectJob();
StatInfo CreateJob(int jobNumber);
StatInfo SetStat(int hp, int attack, int defence);
const char* GetJobText(JobType type);

void EnterField(StatInfo* player);
void CreateRandomMonster(StatInfo* monsterStat);
void CreateRandomMonsters(StatInfo monsters[], int count);
void SetStat(StatInfo* stat, int hp, int attack, int defence);
const char* GetMonsterText(MonsterType type);

bool EnterBattle(StatInfo* player, StatInfo* monster);

void PrintStatInfo(const char* name, const StatInfo& stat);
void PrintMessage(const char* msg);
int InputNumber(const char* msg);
#pragma endregion


StatInfo* ReturnStat() {
    StatInfo stat;
    stat.hp = 0x11111111;
    stat.attack = 200;
    stat.defence = 200;
    return &stat;
}

void ArrayTask() {
    int aa[300] = {};
    // 배열가지고 어떤 작업을 함
}

void SetMessage(const char** msg) {
    *msg = "Bye"; // Bye를 메모리 어딘가에 만들고 시작 주소를 msg에 대입함
}

void 기초문법() {
    // 어셈블리어 관점에서 보면 초깃값이 있다면 .data영역으로
    // 초깃값이 0이거나 없다면 .bss영역에서 저장함
    // 근데 몰라도 됨. 거의 다 모름
    int a = 100;

    // bool의 내부는 1바이트 정수.
    // 사실 1bit만 쓰기는 하는데 최소 연산 단위가 1바이트라서 그냥 1바이트로 잡은거
    bool isCpp = true;

    // 컴퓨터에서 실수를 표현할 때는 부동소수점이라는 방법을 사용함
    // 부동 소수점 : .을 유동적으로 움직여서 숫자를 표현하는 방법
    // 1) 정규화 3.1415926535 * 10
    // 2) 유효숫자와 지수로 구분. 31415926535(유효 숫자), 1(지수)
    // 부동소수점은 '근사값'이다.
    // 실수 2개를 비교할때는 2개가 '같다'고 가정하고 비교하면 안되고 오차값을 고려해야 한다.
    float b = 3.14f;

    // 영어 말고 전 세계 언어를 나타내기 위한 규약이 유니코드
    // UTF-8
    // 영어 숫자는 아스키코드로 표현(1바이트)
    // 유럽 지역의 문자는 2바이트
    // 한글, 한자는 3바이트
    // UTF-16
    // 대부분의 글자가 2바이트 고정
    // UTF-8은 영어권에서 사용 시 강점이 있고 UTF-16은 아시아권이나 문자 크기 비교시 강점이 있음
    char c = 'c';

    // 문자열의 끝은 NULL (0) 이어야 함
    char str[] = { 'c', 'p', 'p', '\0' };
    char str2[] = "cpp"; // \0을 자동으로 넣어줌
    //cout << "Hello Int : " << str << endl;
    //cout << "Hello Int : " << str2 << endl;

    // a++연산
    int test1 = 1;
    test1++;
    // ++a 연산
    ++test1;

    // 대입 ++연산 비교
    int test2 = 1;
    test2 = test1++;
    test2 = ++test1;

    // << 그냥 왼쪽으로 미는거. 이때 비트연산 맨 왼쪽에 1이 있으면 절벽으로 밀어서 떨어뜨리는 것처럼 없애버림
    // >> 그냥 오른쪽으로 미는거. 맨 끝쪽에 있는애 없애는건 똑같음. 허나 2의 보수를 사용 중이라면 걔를 1로 남겨두고 옮긴만큼 복사함 ㅋㅋㅋㅋ.
    // ex) 1000'0000 >>^2 = 1110'0000. ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ
    // 이거 때문에 bitflag할떄는 unsigned를 써서 음의 보수를 지워서 사용함
    int bit = 0;
    const int stun = 3;
    bit = 1 << stun;

    // input 받기 : cin >> 받을 변수
    // endl : 줄바꿈

    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    for (size_t i = 0; i < 1000000; i++)
    {
        int randNum = Random(1, 4);
        if (randNum == 1) count1++;
        else if (randNum == 2) count2++;
        else if (randNum == 3) count3++;
    }

    // 함수1([매개변수][반환주소값][지역변수])함수2([매개변수][반환주소값][지역변수])
    int local = 2;
    Hi(local);
}

void Pointer() {
    // 포인터
    int number = 0;
    int* ptr = &number;

    // 참조
    int& numberRef = number;
    // 어셈블리어 관전에서는 그냥 포인터랑 토씨하나 한틀리고 똑같음.
    // C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것
    numberRef = 3; // number에 3을 대입함
    // 값 전달처럼 사용하되 내부는 주소 전달처럼 사용되는 2개의 중간점에 있는 방식

    ptr = nullptr;
    // 포인터는 nullptr 즉 빈 값을 가질 수 있어서 특정 값을 찾지 못하는 등의 실패를 정의할 수 있음
    // 참조는 무조건 가르키는 값이 유효해야 하기에 null체크를 하지 못함
    // null체크를 해야 할 때는 포인터 아니면 참조를 쓰는 등, 상황에 따라 쓰는 게 좋은 듯.


    // 배열
    // .data 주소[H][e][l][l][o][][W][o][r][l][d][\0]
    // string1 에는 8바이트짜리 주소만 들어감
    const char* string1 = "Hello Wolrd";

    // [][][][][][[][][][][][]
    // [H][e][l][l][o][][W][r][][][][]
    // [H][e][l][l][o][][W][o][r][l][d][\0]
    // 배열은 바구니가 아니라 닭장. 그 자체로 같은 데이터끼리 붙어있는 바구니의 모음임
    // 다만 배열 이름은 '바구니 모음'의 시작 주소
    const char string2[] = "Hello Wolrd";


    // 다중 포인터
    // main([매개변수][반환주소][지역변수(msg<-Hello World의 시작 주소)]) SetMessage([매개변수(a<-Hello World의 시작 주소)][반환주소][지역변수])
    // SetMessage([매개변수(a <-Bye의 주소가 들어감)][반환주소][지역변수])
    // 포인터도 변수이므로 값 전달이 됨. 즉, 포인터가 가지고 있는 주솟값이 바꿘다고 아무 일도 일어나지 않음
    const char* msg = "Hello Wolrd";

    // 주소가 2겹으로 있는 느낌. 1번 주소를 타고 가면 2번 주소가 있고 2번 주소를 타고가야 값이 있는
    // *이 없어질때까지 까야하는 양파같은 느낌?으로 이해하면 된다고 루키스가 말함
    //const char** pp = &msg;
    //*pp = "Bye";

    // msg의 주소 즉, 포인터 변수의 주소를 줌.
    // 원래는 포인터 변수를 값 전달해서 원본에 접근하지 못한 건데 그럼 포인터 변수의 주소를 주면?
    // 그럼 그 주소로 포인터 변수에 접근해서 새로운 문자열의 주소를 넣으면?
    // 깔끔하게 문자열이 바뀜
    // 즉. 포인터를 변수로 바라보면 이해가 좀 더 쉬움. 다중 포인터는 양파고
    SetMessage(&msg);
    cout << msg << endl;

    // 다차원 배열
    // 메모리 상에서는 다차원이나 일차원이나 똑같다.
    int arrays[2][5] = {};
    int test_array[10] = {};

    // 포인터 정리
    // 포인터란? : 주소를 담는 바구니. 진퉁은 저 멀리 어딘가 있는데 그 곳으로 워프하기 위한 포탈 역할
    // 배열 : 진짜임. 이름이 시작주소긴 하지만 찐퉁을 들고 있음.
    // 포인터와 배열은 문법이 서로 호환이 잘 되지만 그냥 서로 다른 놈들임.
    // 포인터는 크기가 고정이고 배열은 끝도 없이 커질 수 있음.

    /*int* ptrA = ReturnPointer();
    PointerTest();
    cout << *ptrA << endl;*/
}


int main()
{
    srand(time(0)); // 진짜 랜덤값을 얻기 위한 시드값 설정

    // TextRPG
    // EnterLobby();

    //Snail();

    StatInfo* ptr = ReturnStat();
    ArrayTask();
    cout << ptr->hp << endl;
    cout << ptr->attack << endl;
    cout << ptr->defence << endl;
}

#pragma region TextRPG .cpp
void EnterLobby() {
    while (true)
    {
        PrintMessage("로비에 오신 것을 환영합니다");
        // [result를 담을 temp를 매개변수로 push] [지역변수 result생성] [temp에 resul복사] [player에 temp복사]
        StatInfo Player = SelectJob();

        if (InputNumber("(1) 필드 입장 (2) 게임 종료") == 1) EnterField(&Player);
        else return;
    }
}

void EnterField(StatInfo* player) {
    int const MONSTER_COUNT = 2;
    while (true)
    {
        cout << "필드에 입장했습니다." << endl;
        PrintStatInfo("플레이어 상태  ", *player);
        StatInfo monsters[MONSTER_COUNT];
        CreateRandomMonsters(monsters, MONSTER_COUNT);

        cout << "싸우시겠습니까?" << endl;
        int number = InputNumber("(1) 전투 (2) 전투 (3) 도망");
        if (number != 1 && number != 2) return;

        if (EnterBattle(player, &monsters[number-1])) PrintMessage("승리");
        else {
            PrintMessage("패배");
            return;
        }
    }
}

bool EnterBattle(StatInfo* player, StatInfo* monster) {
    while (true)
    {
        int playerDamage = (player->attack > monster->defence) ? player->attack - monster->defence : 0;
        monster->hp = (monster->hp > playerDamage) ? monster->hp - playerDamage : 0;
        cout << "몬스터 남은 체력" << monster->hp << endl;
        if (monster->hp <= 0) return true;

        int monsterDamage = (monster->attack > player->defence) ? monster->attack - player->defence : 0;
        player->hp = (player->hp > monsterDamage) ? player->hp - monsterDamage : 0;
        cout << "플레이어 남은 체력" << monster->hp << endl;
        if (player->hp <= 0) return false;
    }
}

StatInfo SelectJob() {
    while (true) {
        cout << "직업을 골라주세요" << endl;
        int jobNumber = InputNumber("(1) 기사 (2) 궁수 (3) 법사");
        if (jobNumber < 1 || jobNumber > 3) continue;

        return CreateJob(jobNumber);
    }
}

StatInfo CreateJob(int jobNumber) {
    JobType type = (JobType)jobNumber;

    cout << GetJobText(type) << " 생성 중...." << endl;
    switch (type)
    {
        case Knight: return SetStat(150, 10, 5);
        case Archer: return SetStat(100, 15, 3);
        case Mage: return SetStat(80, 25, 0);
    }
    return SetStat(0, 0, 0);
}

StatInfo SetStat(int hp, int attack, int defence) {
    StatInfo result;
    result.hp = hp;
    result.attack = attack;
    result.defence = defence;
    return result;
}

const char* GetJobText(JobType type) {
    switch (type)
    {
    case Knight: return "기사";
    case Archer: return "궁수";
    case Mage: return "법사";
    }
}

void PrintStatInfo(const char* name, const StatInfo& stat) {
    cout << name << "Hp : " << stat.hp << " / Attack : " << stat.attack << " / Defence : " << stat.defence << endl;
}

void CreateRandomMonster(StatInfo* monsterStat) {
    MonsterType monsterType = (MonsterType)Random(1, 4);
    cout << GetMonsterText(monsterType) << " 생성 중....";
    switch (monsterType)
    {
        case Slime: SetStat(monsterStat, 15, 5, 0); break;
        case Orc: SetStat(monsterStat, 40, 10, 3); break;
        case Skeleton: SetStat(monsterStat, 80, 15, 5); break;
    }
    PrintStatInfo("", *monsterStat);
}

void CreateRandomMonsters(StatInfo monsters[], int count) {
    for (int i = 0; i < count; i++) {
        CreateRandomMonster(&monsters[i]);
    }
}

void SetStat(StatInfo* stat, int hp, int attack, int defence) {
    stat->hp = hp;
    stat->attack = attack;
    stat->defence = defence;
}

const char* GetMonsterText(MonsterType type) {
    switch (type)
    {
    case Slime: return "슬라임";
    case Orc: return "오크";
    case Skeleton: return "스켈레톤";
    }
}

void PrintMessage(const char* msg) {
    cout << "========================================" << endl;
    cout << msg << endl;
    cout << "========================================" << endl;
}

int InputNumber(const char* msg) {
    cout << msg << endl;
    cout << ">>";
    int result;
    cin >> result;
    return result;
}
#pragma endregion
