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
    
    // str.find("~")�� str ���ڿ����� ~�� �����ּҸ� ��ȯ�Ѵ�.
    // �ι�° ���ڿ��� ã�� �ʹٸ�, ~�� ���̸�ŭ �����־�� �Ѵ�. (�ߺ�����) 
    return 0; 
}