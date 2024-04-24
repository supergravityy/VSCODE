#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main()
{
    int number;
    cout << "Input the number of countries: ";
    if (!(cin >> number)) {
        cout << "Please enter a valid integer." << endl;
        return 0; // 오류 코드 반환
    }
    
    cin.ignore(); // 이전 cin에서 남은 개행 문자 제거

    char** list = new char*[number]; // 포인터 배열을 동적 할당

    // 사용자로부터 국가 이름을 입력받아 동적으로 할당된 메모리에 저장
    for (int i = 0; i < number; i++) {
        string str;
        cout << "Input country's name: ";
        getline(cin, str); // 공백을 포함한 문자열 입력 처리
        list[i] = strdup(str.c_str()); // strdup로 메모리 할당 및 복사
    }

    string mode;
    cout << "Input mode you want (list or country name): ";
    getline(cin, mode);

    if (mode == "list") {
        // list 명령어 처리
        for (int i = 0; i < number; i++) {
            cout << list[i] << endl;
        }
    } 
    else {
        // 특정 국가 이름 검색
        bool found = false;
        for (int i = 0; i < number; i++) {
            if (mode == list[i]) {
                cout << "Found: " << list[i] << " at index " << i << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Nothing found." << endl;
        }
    }

    // 할당된 메모리 해제
    for (int i = 0; i < number; i++) {
        free(list[i]);
    }
    delete[] list;

    return 0;
}