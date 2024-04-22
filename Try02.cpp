// 24.04.22 19:50 류성수
#include <iostream>

using namespace std;

int main()
{
    std::cout<<"나이를 입력하시오 : ";

    int age;
    std::cin>>age;

    if(1<age && age <=7) std::cout<<"유아\n";
    else if(7<age && age <=13) std::cout<<"초딩\n";
    else if(13<age && age <=16) std::cout<<"중딩\n";
    else if(16<age && age <=19) std::cout<<"고딩\n";
    else if(age > 19) 
    {
        if(age >= 200) std::cout<<"나이가 너무 많아요\n";
        else std::cout<< "성인\n";
    }
}
