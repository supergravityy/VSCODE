// 24.04.22 14:39 류성수

#include <iostream>
#include <string.h>
#include <string.h>
#include <stdio.h>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    std::cout << "숫자를 입력해주세요\n";

    int num;
    std::cin >> num;
    fflush(stdin);
    
    std::cout << "\n";
    std::cout << "입력된 숫자: " << num << std::endl;

    char ch = 'A';
    std::string myname = "Ryu";

    std::cout << myname;

    std::string ch1 = "1";
    std::string ch2 = "2\n";

    std::cout << ch1+ch2;
    // C++은 문자열을 +기호로 합칠수가 있다.

    std::string test3 = "포스코";
    std::string test4 = test3;

    test3 = "코딩온";

    std::cout << "내가 할 말은" << test3 + test4 << " 입니다.\n";

    return 0;
}