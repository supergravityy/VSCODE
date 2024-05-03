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
    // string 클래스는 일반 문자열이랑 다르다는것을 명심하자!

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
    // 삼중포인터 -> 학생 개개인의 정보 배열주소
    // 학생 개개인의 정보 인덱스 -> 이름,나이,생년월일 배열주소
    
    for(int i=0; i<personnel;i++)
    {
        students[i] = new string*[3];

        cout << "input the number" << i << "\'s information (name,age,birth)" << endl;

        students[i][0]=new string; // 이름
        students[i][1]=new string; // 나이
        students[i][2]=new string; // 생년월일

        cout << "Name : ";
        cin >> *students[i][0];
        cout << endl; // fflush(stdin) 기능
        cout << "Age : ";
        cin >> *students[i][1];
        cout << endl;
        cout << "Birthday (XXXX.XX.XX) : ";
        cin >> *students[i][2];
        cout << endl;
        
        // 실제로는 각 정보의 배열들도 문자열이기에, 4중포인터라고 볼 수 있다.
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

    // 현 시각 기준으로 생년월일을 비교하여 생일이 가장 많은 사람순으로 정렬
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