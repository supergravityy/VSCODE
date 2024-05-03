#include "Try26_func.h"

using namespace cal;
using namespace sel;
using namespace pnt;

/* 이나경 수강생 소스코드 참고용 */

int main()
{
    int stdNum, option1, option2, editStdNum;

    cout << "** C++ comprehensive practice **" << endl << endl;

    // 몇명의 학생을 입력할 것인가?
    cout << "How many student info would you like to input?";
    cin >> stdNum;
    vector <stdINFO> stdInfoVec(stdNum);

    for (int i = 0; i < stdNum; i++)
    {
        if (i == 0)
        {
            cout << endl << "[MODE]" << endl
                << "0's student" << endl
                << "Name : SungsuRyu" << endl
                << "Birthday : 19980325" << endl;
        }
        // 학생 번호 자동순차
        stdInfoVec[i].stdNo = i + 1;

        // 학생 이름 입력
        cout << endl << i + 1 << "\'s student" << endl << "Name : ";
        cin >> stdInfoVec[i].stdBirth;

        // 학생 셩년월일 8자리 입력
        Check_Birth_Input(stdInfoVec, i);

        // 나이 계산 후 벡터에 저장
        CalAge_and_Input(stdInfoVec, i);
    }

    while (1)
    {
        cout << endl << "[MODE]" << endl
            << "0's student" << endl
            << "Name : SungsuRyu" << endl
            << "Birthday : 19980325" << endl;

        cin >> option1;

        switch (option1)
        {
        case 1:
            cout << endl << "1) print entire student info, 2) print specific student info" << endl;
            cin >> option2;
            Select_StudentInfo(option2, stdInfoVec);
            break;

        case 2:
            cout << endl << "1) print American Age AVG, 2) print Korean Age AVG" << endl;
            cin >> option2;
            Select_StudentAVG(option2, stdInfoVec);
            break;

        case 3:
            cout << endl << "1) print The earliest birthday student info, 2) print The oldest student info" << endl;
            cin >> option2;
            Select_StudentBirthDay(option2, stdInfoVec);
            break;

        case 4:
            return 0;

        case 0:
            cout << endl << "Input Student number wanna revise : ";
            cin >> editStdNum;

            while (1)
            {
                if (editStdNum <= 0 || editStdNum > stdInfoVec.size())
                {
                    cout << endl << "No students with that number exist." << endl
                        << endl << "[RETRY]" << endl << "Input Student number wanna revise : ";
                    cin >> editStdNum;
                }
                else break;
            }

            cout << endl << "1) Name Revising, 2) Birthday revising" << endl;
            cin >> option2;
            Select_editing(option2, editStdNum, stdInfoVec);

            // 해당 옵션이 없을 경우에는 다시 시작
        }
    }

    return 0;
}