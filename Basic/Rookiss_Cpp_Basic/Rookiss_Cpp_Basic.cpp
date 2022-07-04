#include <iostream> // iostream 파일을 복붙함
#include <algorithm>
#include <iterator>
using namespace std;
using std::string; using std::reverse;

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

struct ObjectInfo // 구조체는 별 거 없음
{

};

void EnterLobby();

void SelectJob();
bool CreateJob();
void SetPlayerInfo(int hp, int attack, int defence);
string GetJobText(JobType type);

void EnterField();
void ShowPlayerInfo();
void PrintMonsterInfo();
void CreateRandomMonster();
void SetMonsterInfo(int hp, int attack, int defence);
string GetMonsterText(MonsterType type);

void EnterBattle();

void PrintLine();


int _hp;
int _attack;
int _defence;

MonsterType monsterType;
int _monsterHp;
int _monsterAttack;
int _monsterDefence;

int main()
{
#pragma region 기초 문법
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
#pragma endregion

    // 함수1([매개변수][반환주소값][지역변수])함수2([매개변수][반환주소값][지역변수])
    int local = 2;
    Hi(local);

    srand(time(0)); // 진짜 랜덤값을 얻기 위한 시드값 설정
    // TextRPG
    // EnterLobby();
}

#pragma region TextRPG
void EnterLobby() {
    while (true)
    {
        PrintLine();
        cout << "로비에 오신 것을 환영합니다" << endl;
        SelectJob();

        PrintLine();
        cout << "(1) 필드 입장 (2) 게임 종료" << endl;
        PrintLine();
        int input;
        cin >> input;
        if (input == 1) EnterField();
        else return;
    }
}

void EnterField() {
    while (true)
    {
        PrintLine();
        cout << "필드에 입장했습니다." << endl;
        ShowPlayerInfo();
        CreateRandomMonster();

        cout << "싸우시겠습니까?" << endl;
        cout << "(1) 싸움 (2) 도망" << endl;
        int input;
        cin >> input;
        cout << ">>";

        if (input == 1) {
            EnterBattle();
            if (_hp <= 0) return;
        }
        else return;
    }
}

void EnterBattle() {
    while (true)
    {
        int playerDamage = (_attack > _monsterDefence) ? _attack - _monsterDefence : 0;
        _monsterHp = (_monsterHp > playerDamage) ? _monsterHp - playerDamage : 0;

        cout << "몬스터 남은 체력" << _monsterHp << endl;
        if (_monsterHp <= 0) {
            cout << "몬스터를 처치했습니다." << endl;
            return;
        }

        int monsterDamage = (_monsterAttack > _defence) ? _monsterAttack - _defence : 0;
        _hp = (_hp > monsterDamage) ? _hp - monsterDamage : 0;

        cout << "플레이어 남은 체력" << _monsterHp << endl;
        if (_hp <= 0) {
            cout << "사망했습니다." << endl;
            return;
        }
    }
}

void SelectJob() {
    PrintLine();

    while (true) {
        cout << "직업을 골라주세요" << endl;
        cout << "(1) 기사 (2) 궁수 (3) 법사" << endl;
        cout << ">>";

        if (CreateJob())
            break;
    }
}

bool CreateJob() {
    int jobNumber;
    cin >> jobNumber;
    if (jobNumber < 1 || jobNumber > 3) return false;
    JobType type = (JobType)jobNumber;

    cout << GetJobText(type) << " 생성 중...." << endl;
    switch (type)
    {
    case Knight: SetPlayerInfo(150, 10, 5); return true;
    case Archer: SetPlayerInfo(100, 15, 3); return true;
    case Mage: SetPlayerInfo(80, 25, 0); return true;
    }
    return false;
}

void SetPlayerInfo(int hp, int attack, int defence) {
    _hp = hp;
    _attack = attack;
    _defence = defence;
}

string GetJobText(JobType type) {
    switch (type)
    {
    case Knight: return "기사";
    case Archer: return "궁수";
    case Mage: return "법사";
    }
}

void ShowPlayerInfo() {
    cout << "Hp : " << _hp << " / Attack : " << _attack << " / Defence : " << _defence << endl;
}

void PrintMonsterInfo() {
    cout << "Hp : " << _monsterHp << " / Attack : " << _monsterAttack << " / Defence : " << _monsterDefence << endl;
}

void CreateRandomMonster() {
    monsterType = (MonsterType)Random(1, 4);
    cout << GetMonsterText(monsterType) << " 생성 중....";
    switch (monsterType)
    {
    case Slime: SetMonsterInfo(15, 5, 0); break;
    case Orc: SetMonsterInfo(40, 10, 3); break;
    case Skeleton: SetMonsterInfo(80, 15, 5); break;
    }
    PrintMonsterInfo();
}

void SetMonsterInfo(int hp, int attack, int defence) {
    _monsterHp = hp;
    _monsterAttack = attack;
    _monsterDefence = defence;
}

string GetMonsterText(MonsterType type) {
    switch (type)
    {
    case Slime: return "슬라임";
    case Orc: return "오크";
    case Skeleton: return "스켈레톤";
    }
}

void PrintLine() {
    cout << "====================" << endl;
}
#pragma endregion
