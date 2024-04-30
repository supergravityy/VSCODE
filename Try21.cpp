#include<iostream>
#include<string>
#include<string.h>

using namespace std;
int main()
{
    string str = "Police say two people are suspected of trying to create a shortcut for their construction work. The two have been detained and the case is under further investigation.The 38-year-old man and 55-year-old woman were working near the affected area, the 32nd Great Wall.";

    cout << "The length of str : " << str.length();

    cout << "The character of 100th : " << str[99]<<endl;

    cout << "The first index num of \'two\' : " << str.find("two")<<endl;
    cout <<"The second index num of \'two\' : " << str.find("two",str.find("two")+strlen("two"))<<endl;
    
    // str.find("~")는 str 문자열에서 ~의 시작주소를 반환한다.
    // 두번째 문자열을 찾고 싶다면, ~의 길이만큼 더해주어야 한다. (중복방지) 
    return 0; 
}