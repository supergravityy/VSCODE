#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>

using namespace std;

class Snack
{
public:
    Snack() {}

    int price;
    char name[100];
    string made_in;

    virtual void print_company() = 0; // 순수 가상 함수로 만듭니다.
};

class Candy : public Snack
{
public:
    Candy(string company)
    {
        made_in = company;
    }

    void print_company() override
    {
        printf("This product's made in: %s\n", this->made_in.c_str());
    }

    char flavor[100];
};

class Choco : public Snack
{
public:
    Choco(string company)
    {
        made_in = company;
    }

    void print_company() override
    {
        printf("This product's made in: %s\n", this->made_in.c_str());
    }

    char shape[100];
};

int main()
{
    string company[4];
    Snack* plist[4];  // 포인터 배열로 선언

    for (int i = 4; i > 0; i--)
    {
        cout << "\nInput company of this Snack (" << i << " times)" << endl;
        cin >> company[4 - i];
    }

    // 생성자에 알맞은 선언문
    Choco choco1 = Choco(company[0]);
    Choco choco2 = Choco(company[1]);
    Candy candy1 = Candy(company[2]);
    Candy candy2 = Candy(company[3]);

    // 업캐스팅
    plist[0] = &choco1;
    plist[1] = &choco2;
    plist[2] = &candy1;
    plist[3] = &candy2;

    // 다운캐스팅 및 출력
    Choco* ch1 = (Choco*)(plist[0]);
    ch1->print_company();
    Choco* ch2 = (Choco*)(plist[1]);
    ch2->print_company();
    Candy* ca1 = (Candy*)(plist[2]);
    ca1->print_company();
    Candy* ca2 = (Candy*)(plist[3]);
    ca2->print_company();

    return 0;
}