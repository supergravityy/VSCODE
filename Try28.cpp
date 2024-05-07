#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main (int argv, char *args[])
{
    ifstream src;
    ofstream dst;

    src.open("Try28.txt");
    dst.open("Try28_out.txt");
    
    if(! src.is_open())
    {
        cout << "Cannot open src file!!"<<endl;
        return 0;
    }

    vector<string> myVec;
    // 담을 벡터 선언
    string temp_line;

    while(getline(src,temp_line)) 
    // 엔터 전까지 읽어서 temp_line에 저장
    {
        myVec.push_back(temp_line);
    }
    // temp_line을 벡터에 하나씩 저장

    for(string str : myVec)
    {
        cout << str << endl;
    }

    // 벡터의 마지막부터 하나씩 쓰기
    for(int i = myVec.size()-1; i >=0 ; i--)
    {
        dst << myVec[i] << "\n";
    }

    src.close();
    dst.close();
    return 0;
}