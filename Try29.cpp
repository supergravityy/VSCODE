#include<iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

typedef struct 
{
    string name;
    string pw;
}info;


int main()
{
    vector<info> INFOS;
    info temp;
    string mode1 = "q"; string mode2 = "Q";
    int idx = 0;

    // 입력단
    while(1)
    {
        cout << endl << "if you wanna quit, press \'q\'" <<endl;
        cout << "Type your name :";
        cin >> temp.name;
        
        if(temp.name == mode1 || temp.name == mode2)
            break;
        cout << endl << "Type your PW : ";
        cin >> temp.pw;
        

        
        INFOS.push_back(temp);
    }
    // 쓰기단

    ofstream file("Try29.txt");

    for(int i =0; i<INFOS.size(); i++)
    {
        file << INFOS[i].name << " " << INFOS[i].pw << "\n";
    }
    
    file.close();

    // 읽기단

    ifstream file_("Try29.txt");

    string str;

    while(getline(file_,str))
    {
        cout << str << endl;
    }

    file_.close();
}