#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    std::cout << "�̸��� �Է��ϼ���\n";

    std::string name;
    std::cin>>name;

    std::cout << "���̸� �Է��ϼ���\n";
    int age;
    std::cin>>age;

    printf("�ȳ��ϼ���! %s��(%d��)",name,age);

    return 0;
}