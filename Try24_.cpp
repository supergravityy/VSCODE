#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp(string **A, string **B)
{
    int yearA, monthA, dayA;
    int yearB, monthB, dayB;

    sscanf((*A)[2].c_str(), "%4d.%2d.%2d",&yearA,&monthA,&dayA);
    sscanf((*B)[2].c_str(), "%4d.%2d.%2d",&yearB,&monthB,&dayB);
    // string Ŭ������ �Ϲ� ���ڿ��̶� �ٸ��ٴ°��� �������!

    if(yearA != yearB) return yearA<yearB;
    if(monthA != monthB) return monthA<monthB;
    return dayA < dayB;
}

int main()
{
    cout << "how many students would you like to enter? : " << endl;
    int personnel;
    cin >> personnel;

    string ***students = new string**[personnel]; 
    // ���������� -> �л� �������� ���� �迭�ּ�
    // �л� �������� ���� �ε��� -> �̸�,����,������� �迭�ּ�
    
    for(int i=0; i<personnel;i++)
    {
        students[i] = new string*[3];

        cout << "input the number" << i << "\'s information (name,age,birth)" << endl;

        students[i][0]=new string; // �̸�
        students[i][1]=new string; // ����
        students[i][2]=new string; // �������

        cout << "Name : ";
        cin >> *students[i][0];
        cout << endl; // fflush(stdin) ���
        cout << "Age : ";
        cin >> *students[i][1];
        cout << endl;
        cout << "Birthday (XXXX.XX.XX) : ";
        cin >> *students[i][2];
        cout << endl;
        
        // �����δ� �� ������ �迭�鵵 ���ڿ��̱⿡, 4�������Ͷ�� �� �� �ִ�.
    }

    cout << "Total students number : " << personnel << endl;

    double cum_Age=0;

    for(int i = 0; i<personnel; i++)
    {
        cout << "\nName : " << *students[i][0] << endl;
        cout << "Age : " << *students[i][1] << endl;
        cout << "Brithday : " << *students[i][2] << endl;

        cum_Age += stoi(*students[i][1]);
    }

    cout << "Age Avg : " << cum_Age/personnel << endl;

    // �� �ð� �������� ��������� ���Ͽ� ������ ���� ���� ��������� ����
    sort(students, students + personnel, cmp);

    cout << "The oldest person is " << (*students)[personnel-1][0] << " (" << (*students)[personnel-1][2] << ")" << endl;

    for(int i =0; i<personnel; i++)
    {
        for(int j=0; j < 3; j++)
            delete students[i][j];

        delete[] students[i];
    }
    delete[] students;

    return 0;
}