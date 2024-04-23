#include<iostream>

int main()
{
    int num,count=0;
    puts("정수를 입력하시오");
    std::cin >> num;

    for(int i = 0; i < num ; i++)
        count += i;

    std::cout << "입력수까지의 총합은 " << count+num << " 입니다!\n";
}