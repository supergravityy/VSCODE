#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int chekc_mems(vector<string>& LOG,string id, string pw);

int main(char argv, char** args)
{
    string id;
    string pw;
    cout << "Type your name : ";
    cin >> id;

    cout << "\nType your pw : ";
    cin >> pw;

    cout << endl;

    ifstream file("Try29.txt");

    if(file.fail())
    {
        cout << "where is logs?\n";
        return 1;
    }

    vector<string> logs;
    string line;

    while(getline(file,line))
    {
        logs.push_back(line);
    }

    switch (chekc_mems(logs,id,pw))
    {
    case 1:
    cout << "login success!" << endl;
        break;

    case 2:
    cout << "login fail!"<<endl;
    break;
    
    default:
        break;
    }

    return 0;
}

int chekc_mems(vector<string>& LOG,string id, string pw)
{
    string cmp_id; string cmp_pw;
    for(int idx = 0; idx < LOG.size(); idx++)
    {
        istringstream iss(LOG[idx]);
        iss >> cmp_id >> cmp_pw;

        if(cmp_id == id)
            if(cmp_pw== pw )
                return 1;
    }
    return 2;
}