#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

int check_mems(vector<string>& LOG,string id, string pw);
int finding_mems(vector<string>& telephone_LOG, string id, int* y);
void update_number(fstream &file,vector<string>& LOG,int row,string telephone,string id);

int main()
{
login:

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

    vector<string> login_LOG;
    string line;

    while(getline(file,line))
        login_LOG.push_back(line);

    int success=check_mems(login_LOG,id,pw);

    // ��ȭ��ȣ�ο� �ֳ�?

    string telephone;
    char answer;
    int found = 0;
    int row;
    fstream new_file("Try31.txt", std::ios::in); // �б���

    if (new_file.fail()) 
    {
        std::cout << "File could not be opened." << endl;
        return 1;
    }


    if(success) // �α��� ������ ��ȣ ����
    {
        cout << "Type your phone number : ";
        cin >> telephone;
        cout << endl;

        vector<string> telephone_LOG;
        string num_line;

        while(getline(new_file,num_line))
            telephone_LOG.push_back(num_line);

        found = finding_mems(telephone_LOG,id,&row); // ����� �ֳ�?

        if(found)
        {
            // ������ ����� �α��� ������, ��ȭ��ȣ ����
            cout << "Found at line: " << row << endl;
            update_number(new_file,telephone_LOG,row,telephone,id);

        }

        else
        {
            new_file.close();
            cout << "no information, adding mode" << endl;
            fstream new_file("Try31.txt",std::ios::app); // �߰����
            // ���������� �� ������ �̵�
            new_file << id << " " << telephone << endl; // 
        }
    }

    else
        cout << "login failed!" <<endl;

    file.close();
    new_file.close();

    
    while(1) // �α��� ����Ұų�?
    {
        cout << "\nIf you wanna login again? (y/n) : ";
        cin >> answer;

        if(answer == 'y'||answer == 'Y')
        goto login;

        else if(answer == 'n' || answer == 'N')
        break; cout << "OK\n\n";
    }

    
    return 0;
}

void update_number(fstream &file,vector<string>& LOG,int row,string telephone,string id)
{
    file.close();
    fstream file_("Try31.txt", ios::out); // ������ -> �ʱ�ȭ

    LOG[row] = id + " " + telephone + "\n";

    for(int idx = 0; idx < LOG.size(); idx++)
        file_ << LOG[idx];

    file_.close();
}

int finding_mems(vector<string>& telephone_LOG, string id, int* y)
{
    string cmp_id; string phone_num;
    for(int idx = 0; idx < telephone_LOG.size(); idx++) // telephone_LOG�� idx�� �� �ؽ�Ʈ�� ���ȣ
    {
        istringstream iss(telephone_LOG[idx]);
        iss >> cmp_id >> phone_num;

        if(cmp_id == id)
        {
            *y = idx;
            cout << "found!" <<endl;
            return 1;
        }  
    }
    cout << "not found!"<<endl;
    return 0;
}

int check_mems(vector<string>& LOG,string id, string pw)
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
    return 0;
}