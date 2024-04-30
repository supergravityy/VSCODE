#include<iostream>
#include<string>
using namespace std;

int find_first_ch(char ch, string str)
{
    for(int i =0; i<str.size(); i++)
        if(str[i] == ch)
            return i;
    return -1;
}

string erase_duplicate(string str)
{
    string result;

    for(int i =0; i< str.length(); i++)
        if(str.find(str[i]) == i)
        // 현재위치가 처음 등장하는 위치면 문자열에 추가
            result += str[i];

    return result;
}

int main()
{
    string str = "Codingon";
    toupper(str[0]);

    cout << str << endl;
    
    int start,end;
    char chs[2];

    cout << "Input first ch : " ;
    cin >> chs[0];
    cout << "\nInput last ch : ";
    cin >> chs[1];

    cout << "\n\n"<<endl;

    if((start = find_first_ch(chs[0],str)) < 0 || (end = find_first_ch(chs[1],str)) < 0)
    {
        cout << "Cant find start character in str!\nTerminating process" << endl;
        return 0;
    } 

    cout <<"\n" << str.substr(start,end-start+1) << endl;

    string convert;
    int size;
    cout << "Enter the converting string! : ";
    cin >> convert;
    cout << "Input start idx : " ;
    cin >> start;
    cout << "\nInput end idx : ";
    cin >> end;
    cout << "\n\n"<<endl;

    cout << str.replace(start,end,convert)<<endl;
    tolower(str[0]);

    cout << "removed duplicate : " << erase_duplicate(str) << endl;


    return 0;
}