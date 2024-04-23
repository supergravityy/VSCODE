#include<iostream>

using namespace std;

int main()
{
    double A,B;
    char ch;

    std::cin>>A;
    std::cin>>B;
    getchar();
    puts("덧셈 : +, 뺄셈 : -, 곱셈 : *, 나눗셈 : /, 나머지연산 : %");
    ch=getchar();

    switch (ch)
    {
    case '+':
        std::cout<<A+B;
        break;
    case '-':
        std::cout<<A-B;
        break;
    case '*':
        std::cout<<A*B;
        break;
    case '/':
        std::cout<<A/B;
        break;
    case '%':
        std::cout<<(int)A%(int)B;
        break;
    default:
        std::cout<<"올바른 연산자가 아닙니다.";
        break;
    }
}