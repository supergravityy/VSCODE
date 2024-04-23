#include <iostream>

int main(int num, char* agrs[])
{
    int n;

    std::cin >> n;

    n/5 ? std::cout<<"5의 배수":std::cout<<"5의 배수 아님";

    return 0;
}