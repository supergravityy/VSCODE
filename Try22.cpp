#include <iostream>
#include <string>
using namespace std;

int ISDIGIT(string str1, string str2)
{
    int str1_digit = 1, str2_digit = 1; 

    
    for(int i = 0; i < str1.size(); i++)
        if(!isdigit(str1[i]))
        {
            str1_digit = 0; 
            break; 
        }

   
    for(int i = 0; i < str2.size(); i++)
        if(!isdigit(str2[i]))
        {
            str2_digit = 0; 
            break; 
        }

    return str1_digit && str2_digit;
}

int main()
{
    string str1, str2;
    // string 클래스는 문자열의 끝에 NULL이 들어가지 않고, 문자열의 길이를 동적으로 변경가능
    
    do
    {
        cout << "input numbers : ";
        cin >> str1 ;
        cout << "\ninput numbers : ";
        cin >> str2;
    }while(!ISDIGIT(str1,str2));
    
    cout <<"\n\n" << str1 + str2 << endl;

    int num1 = stoi(str1), num2 = stoi(str2);
    cout << "sum  is : " << num1+num2 << endl;

    return 0;
}