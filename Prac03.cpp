#include <iostream>
using namespace std;

int main(int cnt, char* args[])
{
    int n3;
    cout << "input number : ";
    cin >> n3;

    int **arr2 = new int *[n3];
    // ������ �迭�� ����.

    for (int i =0; i<n3;i++)
        arr2[i] = new int[n3];
        // �ش� ������ �迭�� �ε����� �迭�� ����Ű�� �ȴ�.

    // �׷� �� (n3^2)*4 ũ���� �޸𸮰� �Ҵ�ȴ�

    int count = 0;
    for (int i =0; i< n3; i++)
        for (int j =0; j < n3;j++)
            arr2[i][j] = ++count;
    // �̷��� �Ǹ�, ���� ������ �迭�� �ε����� �� ��,
    // �ε����� ����Ű�� �迭�� �ε����� ���� ���� write

    for (int i =0; i<n3;i++)
        delete[] arr2[i];

    delete[] arr2;

    return 0;
}