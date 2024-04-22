#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    std::cout << "이름을 입력하세요\n";

    std::string name;
    std::cin>>name;

    std::cout << "나이를 입력하세요\n";
    int age;
    std::cin>>age;

    printf("안녕하세요! %s님(%d세)",name,age);

    return 0;
}