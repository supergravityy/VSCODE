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
    // ���� ���� ����
    string temp_line;

    while(getline(src,temp_line)) 
    // ���� ������ �о temp_line�� ����
    {
        myVec.push_back(temp_line);
    }
    // temp_line�� ���Ϳ� �ϳ��� ����

    for(string str : myVec)
    {
        cout << str << endl;
    }

    // ������ ���������� �ϳ��� ����
    for(int i = myVec.size()-1; i >=0 ; i--)
    {
        dst << myVec[i] << "\n";
    }

    src.close();
    dst.close();
    return 0;
}