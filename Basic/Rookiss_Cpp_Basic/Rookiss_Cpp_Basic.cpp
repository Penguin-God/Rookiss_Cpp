#include <iostream> // iostream 파일을 복붙함
#include <algorithm>
#include <iterator>
#include <windows.h>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <algorithm>

#include "Snail.h"
#include "Game.h"

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


// 바인딩(Binding) = 묶는다
// 정적 바인딩(Static Binding) : 컴파일 시점에 결정
// 동적 바인딩(Dynamic Binding) : 실행 시점에 결정
// 일반 함수는 정적 바인딩 사용
// 가상 함수는 동적 바인딩 사용 : 가상 함수들의 주소의 시작점을 가리키는 vftable이라는 게 있고 거기 가서 원하는 함수를 찾아서 실행시킴
// cpp는 class도 그냥 넘기면 복사됨. 꼬우면 포인터로 보내셈
class Knights {
public:
    Knights()
    {
        x = 0;
    }

    int _hp;
    int x;

    // 명시적 사용
    // 가끔 암시적으로 컴파일러가 난리를 쳐서 선언하는 키워드
    //explicit Knight(int hp) : _hp(100) // 만약 포함하는 클래스일 경우 선처리 영역에 넣어야 됨
    //{
    //    x = 0;
    //}

    // ~붙이면 소멸자. 메모리에서 사라질 때 호출
    //~Knight() {
    //
    //}

    void Move() {

    }
};

class Item {
public:
    Item() {
        cout << "Item 탄생일" << endl;
    }

    Item(int a)
    {
        cout << "Item 탄생일" << a << endl;
    }

    ~Item() {
        cout << "Item 사망일" << endl;
    }

public:
    int type = 0;
    int id = 0;
    char dummy[4096] = {};
};

class Weapon : public Item
{
public:
    Weapon()
    {
        damage = 0;
        cout << "Weapon 탄생일" << endl;
    }

    ~Weapon()
    {
        cout << "Weapon 사망일" << endl;
    }
public:
    int damage;

};

class 동적할당 {
public:
    // 최근 운영체제는 유저 영역과 커널 영역이 나누어져 있음
    // 유저 영역 [메모장] [유튜브] [롤]...
    // ----------------------------------
    // 커널 영역 (Windows등의 핵심 코드)

    // 메모리 할당 과정
    // 유저) API(함수)를 이용해 커널에 요청
    // 커널) 메모리를 할당해서 갖다 줌
    // 유저) 잘 갖다가 씀

    void Malloc() {
        // 사이즈를 주면 그 크기만큼 메모리 잡은 후에 시작 주소를 void형 포인터로 반환함
        void* p = malloc(1);
        // void*란? malloc은 메모리를 잡아주는 역할이지 메모리 무슨 목적으로 쓸지는 모르기 때문에 void로 반환하고 그걸 잘 바꿔서 쓰면 됨.
        int* p2 = (int*)malloc(sizeof(int));
        *p2 = 3;
        cout << *p2 << endl;
        p2 = nullptr;
        // free : 다 쓰면 포인터는 자유에요~
        free(p2);
        // free가 포인터도 날린건 아니기 때문에 free후에도 포인터에 접근할 수 있다.
        // 놀랍게도 크래쉬가 안나고 스무스하게 넘어가기 때문에 사실상 재앙과도 같은 수준의 버그다.
        // 그럼 free를 하지말자! -> 이지랄하면 메모리 누수남
        // 그냥 주의해서 써야 함. 아님 nullptr로 밀거나
        cout << *p2 << endl;
    }

    // cpp에서 추가된 문법. malloc()처럼 함수가 아니라 연산자 취급임
    // 또한 클래스일 경우 생성자와 소멸자를 호출해 줌.
    void New() {
        Knights* info = new Knights;
        info->x = 2;
        delete info;

        Knights* infos = new Knights[3];
        Knights* info2 = (infos + 1);
        info2->x = 1;
        delete[] infos;
    }

    void Casting() {
        int a = 123;
        float b = (float)a;
        cout << b << endl;
        // 스택 메모리에 생성
        // Item item;

        // 스택에는 메모리 주소만 저장하고 본체는 힙 메모리에 생성
        // Item* item2 = new Item();
        
        // Weapon weapon;
        //Weapon* weapon2 = new Weapon();
        //delete weapon2;

        Item item3(1);
    }

    void IncreaseId(Item item)
    {
        item.id++;
    }
};


class LamdaItem
{
public:
    int id = 0;
};

template<typename T> // 그냥 제네릭이었누 ㅋㅋ
class 콜백함수
{
public:
    int Add(int a, int b)
    {
        return a + b;
    }

    void Callback()
    {
        // 함수는 어셈블리어 관점으로 보면 함수가 들고있는 주소로 점프해서 코드 실행하는거임
        // 반환형(*변수명)(인자값)
        // 대입할 때는 &함수명
        // 사용할 때는 일반 함수처럼
        
        // 멤버 함수는 class명::*변수명 식으로 선언해야 함
        // 대입할 때는 &클래스명::함수명
        // 사용할때는 class인스턴스.*변수명() 식으로 사용

        // ()연산자 오버로딩
        using Func = int(콜백함수::*)(int, int);
        int(콜백함수::*fn)(int, int);
        fn = &콜백함수::Add;
        Func a;
        a = &콜백함수::Add;
        콜백함수 call;
        int aResult = (call.*a)(1, 2);
        int result = (call.*fn)(1, 2);
        cout << result << endl;
        cout << aResult << endl;
    }

    void 템플릿()
    {
        // 템플릿 : 함수나 클래스를 찍어내는 틀
    }

    void Lamda()
    {
        vector<LamdaItem> v;
        LamdaItem item;
        item.id = 7;
        v.push_back(item);

        LamdaItem item2;
        item2.id = 3;
        v.push_back(item2);

        LamdaItem item3;
        item3.id = 5;
        v.push_back(item3);
        // 클로저 = 람다에 의해 만들어진 실행시점 객체
        // [] 캡처 : 외부에 변수를 갖다 씀
        // 쓰려는 변수명 하나하나 적는게 좋음.
        // 기본은 복사 &붙이면 참조
        int findId = 5;
        auto items = std::find_if(v.begin(), v.end(), [findId](LamdaItem item) { return item.id == findId; });
        //[](int a){}
    }
};


class STL
{
public:
    void Vector()
    {
        // 백터의 특징
        // capacity(총 용량)만큼 메모리를 할당함. 이때 실제 메모리보다 좀 더 여유분을 가진다. 여유분이 다 차면 메모리를 증설한다.
        // capacity는 다 차면 1.5배 정도 증가한다.
        // 하나씩 늘리지 굳이굳이 힘들게 1.5배씩 늘리는 이유는 당연히 이거 만든 개발자들이 심심해서 그런게 아니다.
        // 기본적으로 배열이다 보니 데이터가 쭉 있어야 되는데 뒷자리가 먹혀 있으면 넓은 집으로 이사를 간다.
        // 크면 클수록 이사 비용이 오지게 드므로 어느 정도 절충을 한 결과 1.5배 정도가 적당하다고 판단한 것.
        // 이때 복사가 많이 되는게 싫으면 초반에 capacity를 정의하고 시작할 수도 있다.
        
        vector<int> v;
        for (size_t i = 0; i < 10; i++)
            v.push_back(i);

        // iterator : pointer랑 비슷하나 특정 컨테이너를 가르킴
        vector<int>::iterator itStart = v.begin();
        vector<int>::iterator itEnd = v.end();

        // v.end()는 쓰레기 값을 뱉음 즉 배열의 마지막 값 바로 다음의 메모리 주소로 저게 나오기 전까지 돌면 백터를 처음부터 끝까지 다 도는 것임
        // 쓰는 이유 : iterator가 C#의 IEnumerable처럼 모든 템플릿이 가지고 있어서 foreach처럼 범용적인 문범임
        // C#에서 일반 배열이나 list는 for문이 나을 수 있지만 딕셔너리같은 자료구조는 foreach를 쓰는 것과 같음.
        for (auto i = v.begin(); i != v.end(); i++)
            cout << *i << endl;

        // 중간 or 처음 삽입, 삭제 : 다른 데이터들을 다 옮겨야하므로 느림
        // 마지막 삽입, 삭제 : 끝에 데이터 하나 추가하므로 빠름
        // 임의 접근 : []로 접근
    }

    void List()
    {
        // 애는 걍 링크드 리스트임 ㅋㅋ
        // 근데 단일이 아니라 이중임 앞, 뒤 노드 주소를 가지고 있다는 뜻.
        // [1] <-> [2] <-> [3] <-> [4] <-> [5]

        // 삽입 : 데이터 복사 없이 앞, 뒤 노드의 주소만 바꾸면 됨.
        // [1] <-> [2] <-> [3] <-> [4] <-> [5] => [1] <-> [2] <-> [20000] <-> [3] <-> [4] <-> [5]
        // 삭제도 마찬가지로 훌륭하게 동작함

        // 임의접근 : But 이게 장점만 있었으면 List나 vector 안쓰지 ㅋㅋㅋ
        // 임의접근하려면 처음부터 꾸준히 원하는 index까지 포인터 타고 찾아가야 되서 비용 겁나 듬. 애초에 지원도 안함.

        // 그래서 사실 삽입, 삭제도 주소를 알고 있을때만 빠르지 처음부터 뺑뺑이 돌리면 느림.
        
        list<int> li;
        for (size_t i = 0; i < 6; i++)
            li.push_back(i);

        li.remove(3);
        li.insert(++li.begin(), 20031);

        for (auto i = li.begin(); i != li.end(); i++)
            cout << *i << endl;
    }

    void Deque()
    {
        // 발음이 디큐가 아니라 데크임
        // vector와 list의 반반 : 메모리가 서로 일열로 있다는 보장은 없지만 임의접근 가능
        // vector는 여유분을 가지고 큰 집으로 이사하는 개념이라면 얘는 그딴거 없이 그냥 아무데나 data를 놔둠
        // 그래서 push_front()를 하면 0번째 값이 어디 이상한 곳에 혼자 외롭게 떨어져 있을 수도 있음
        // vector가 전원주택 원툴이라면 얘는 아파트 몇동 몇호처럼 찾아가는 느낌
        // [1,1,1,1] [1,1,1,1] [1,1,1,1] [1,1,1,1] (다 다른 어딘가에 있음)
        // 몇동 몇호처럼 찾아가는 개념이라 임의접근은 빠름
        // 대신 작은 집끼리는 나름의 규칙이 있어서 삽입, 삭제는 느림
        // 근데 웃긴게 몇 앞에 넣는건 맨 앞에 아파트 새로 지으면 되서 그건 빠름
        // 앞뒤에서 밀어넣을 수 있다고 해서 더블 큐를 줄여서 deque가 된 거다.
    }

    void Map() // 이새기는 걍 딕셔너리임 ㅋㅋ
    {
        // 균형 이진트리 사용
    }
};

int main()
{
    srand(time(0)); // 진짜 랜덤값을 얻기 위한 시드값 설정

    //Snail();

    //Game game;
    //game.Init();
    //while (true)
    //{
    //    game.Update();
    //}
    
    /*콜백함수<int> call;
    call.Lamda();*/

    STL stl;
    //stl.Vector();
    stl.List();
}