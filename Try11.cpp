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
        return 0; // ���� �ڵ� ��ȯ
    }
    
    cin.ignore(); // ���� cin���� ���� ���� ���� ����

    char** list = new char*[number]; // ������ �迭�� ���� �Ҵ�

    // ����ڷκ��� ���� �̸��� �Է¹޾� �������� �Ҵ�� �޸𸮿� ����
    for (int i = 0; i < number; i++) {
        string str;
        cout << "Input country's name: ";
        getline(cin, str); // ������ ������ ���ڿ� �Է� ó��
        list[i] = strdup(str.c_str()); // strdup�� �޸� �Ҵ� �� ����
    }

    string mode;
    cout << "Input mode you want (list or country name): ";
    getline(cin, mode);

    if (mode == "list") {
        // list ��ɾ� ó��
        for (int i = 0; i < number; i++) {
            cout << list[i] << endl;
        }
    } 
    else {
        // Ư�� ���� �̸� �˻�
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

    // �Ҵ�� �޸� ����
    for (int i = 0; i < number; i++) {
        free(list[i]);
    }
    delete[] list;

    return 0;
}