#include <iostream>
#include <string>
using namespace std;

int ISDIGIT(string str1, string str2)
{
    int str1_digit = 0, str2_digit = 0;
    int i;

    // 널 전까지만 카운트
    for( i =0; i<str1.size()-1; i++)
        if(!isdigit(str1[i]))
            break;
    

    if(i == str1.size())
        str1_digit = 1;

    for( i =0; i<str2.size()-1; i++)
        if(!isdigit(str2[i]))
            break;

    if(i == str1.size())
        str1_digit = 1;
    
    if(str1_digit && str2_digit)
        return 0;

    return 1;
}

int main()
{
    string str1, str2;
    
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