// 24.04.22 14:39 ������

#include <iostream>
#include <string.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    std::cout << "���ڸ� �Է����ּ���\n";

    int num;
    std::cin >> num;
    fflush(stdin);
    
    std::cout << "\n";
    std::cout << "�Էµ� ����: " << num << std::endl;

    char ch = 'A';
    std::string myname = "Ryu";

    std::cout << myname;

    std::string ch1 = "1";
    std::string ch2 = "2\n";

    std::cout << ch1+ch2;
    // C++�� ���ڿ��� +��ȣ�� ��ĥ���� �ִ�.

    std::string test3 = "������";
    std::string test4 = test3;

    test3 = "�ڵ���";

    std::cout << "���� �� ����" << test3 + test4 << " �Դϴ�.\n";

    return 0;
}