#include "Try25_func1.h"

void Check_Birth_Input(vector<stdINFO>& stdInfoVec, int i)
{
    while (1)
    {
        bool birthCheck = true;

        if (stdInfoVec[i].stdBirth.size() != 8)
        {
            cout << endl << "Please enter 8 digits of your birth date " << endl
                << "[RETRY]" << endl;
            cin >> stdInfoVec[i].stdBirth;
        }
        else
        {
            for (int j = 0; j < stdInfoVec[i].stdBirth.size(); j++)
            {
                if (!isdigit(stdInfoVec[i].stdBirth[j])) //문자가 검출될 경우
                {
                    cout << endl << "Only input number" << endl
                        << "[RETRY]" << endl;
                    cin >> stdInfoVec[i].stdBirth;

                    birthCheck = false;
                    break;
                }
            }

            if (birthCheck == true)
                break;

        }

    }
}

void CalAge_and_Input(vector<stdINFO>& stdInfoVec, int i)
{
    time_t timer = time(NULL);
    struct  tm* t = localtime(&timer);
    int age, year, month, date, c_year, c_month, c_date;


    year = stoi(stdInfoVec[i].stdBirth.substr(0, 4));
    month = stoi(stdInfoVec[i].stdBirth.substr(4, 2));
    date = stoi(stdInfoVec[i].stdBirth.substr(6, 2));

    c_year = t->tm_year + 1900;
    c_month = t->tm_mon + 1;
    c_date = t->tm_mday;

    age = c_year - year;
    stdInfoVec[i].stdAge_ko = age + 1;

    if (month - c_month > 0)
        age--;

    else if (month - c_month == 0)
    {
        if (date - c_date > 0)
            age--;
    }

    stdInfoVec[i].stdAge = age;
}

void Select_StudentInfo(int i, vector<stdINFO>& stdInfoVec)
{
    string stdName;

    switch (i)
    {
    case 1:
        for (int i = 0; i < stdInfoVec.size(); i++)
            Print_Student_Info(stdInfoVec, i);
        break;

    case 2:
        cout << endl << "Name :";
        cin >> stdName;

        for (int i = 0; i < stdInfoVec.size(); i++)
            if(stdInfoVec[i].stdName == stdName) 
            //벡터 내 검색 이름 존재
                Print_Student_Info(stdInfoVec, i);
        break;


    default:
        break;
    }
}


void Select_StudentAVG(int i, vector<stdINFO>& stdInfoVec)
{
    bool useKoreanAge;

    switch (i)
    {
    case 1:
        cout << endl << "AVG age is : "
            << Cal_Student_AgeAVG(stdInfoVec, useKoreanAge = false) << endl;
        break;

    case 2:
        cout << endl << "AVG age is : "
            << Cal_Student_AgeAVG(stdInfoVec, useKoreanAge = true)  << endl;
        break;
    }
}

void Select_StudentBirthDay(int i, vector<stdINFO>& stdInfoVec)
{
    bool useYear;

    switch (i)
    {
    case 1: 
        cout << endl << "생일이 가장 빠른 학생은.. " << endl;
        Print_EarlyBirth_Student(stdInfoVec, useYear = false);
        break;
    case 2: 
        cout << endl << "나이가 가장 많은 학생은.. " << endl;
        Print_EarlyBirth_Student(stdInfoVec, useYear = true);
        break;
    }
}

void Select_editing(int i, int Num, vector<stdINFO>& stdInfoVec)
{
    for (int i = 0; i < stdInfoVec.size(); i++)
    {
        if (stdInfoVec[i].stdNo == Num)
        {
            switch (i)
            {
            case 1:
                cout << endl << "Name : ";
                cin >> stdInfoVec[i].stdName;
                break;

            case 2:
                cout << endl << "생년월일은.. ";
                cin >> stdInfoVec[i].stdBirth;

                //생년월일 자리수 및 숫자 여부 확인
                Check_Birth_Input(stdInfoVec, i);
                //나이 계산 후 벡터에 저장
                CalAge_and_Input (stdInfoVec, i);
                break;
            }
        }
    }
}

void Print_Student_Info(vector<stdINFO> stdInfoVec, int i)
{
    cout << endl << stdInfoVec[i].stdNo << "\'s student" << endl
        << "Name : " << stdInfoVec[i].stdName << endl
        << "Korean age : " << stdInfoVec[i].stdAge_ko << endl
        << "American age : "   << stdInfoVec[i].stdAge << endl
        << "Birth day : " << stdInfoVec[i].stdBirth << endl;
}

double Cal_Student_AgeAVG(vector<stdINFO> stdInfoVec, bool useKoreanAge)
{
    float ageSum = 0;

    for (int i = 0; i < stdInfoVec.size(); i++)
        ageSum += useKoreanAge ? stdInfoVec[i].stdAge_ko : stdInfoVec[i].stdAge;

    return ageSum / stdInfoVec.size();
}

void Print_EarlyBirth_Student(vector<stdINFO> stdInfoVec, bool useYear)
{
    int birth, minBirth = useYear ? 99991231 : 1231;

    for (int i = 0; i < stdInfoVec.size(); i++)
    {
        birth = useYear ? stoi(stdInfoVec[i].stdBirth) : stoi(stdInfoVec[i].stdBirth.substr(4));

        if (birth < minBirth)
        {
            minBirth = birth;
        }
    }

    for (int i = 0; i < stdInfoVec.size(); i++)
    {
        birth = useYear ? stoi(stdInfoVec[i].stdBirth) : stoi(stdInfoVec[i].stdBirth.substr(4));

        if (birth == minBirth)
        {
            Print_Student_Info(stdInfoVec, i);
        }
    }
}