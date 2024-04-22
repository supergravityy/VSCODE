#include <iostream>

int main()
{
    std::cout <<"이름을 입력하시오 : ";
    std::string name;

    std::cin >> name;

    if(name == "홍길동") std::cout<<"\n남자";
    else if(name == "여자") std::cout<<"\n여자";
    else std::cout<<"\n모르겠어요";
}