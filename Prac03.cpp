#include <iostream>
using namespace std;

int main(int cnt, char* args[])
{
    int n3;
    cout << "input number : ";
    cin >> n3;

    int **arr2 = new int *[n3];
    // 포인터 배열을 선언.

    for (int i =0; i<n3;i++)
        arr2[i] = new int[n3];
        // 해당 포인터 배열의 인덱스는 배열을 가리키게 된다.

    // 그럼 총 (n3^2)*4 크기의 메모리가 할당된다

    int count = 0;
    for (int i =0; i< n3; i++)
        for (int j =0; j < n3;j++)
            arr2[i][j] = ++count;
    // 이렇게 되면, 기존 포인터 배열의 인덱스로 들어간 후,
    // 인덱스가 가리키는 배열의 인덱스로 들어가서 값을 write

    for (int i =0; i<n3;i++)
        delete[] arr2[i];

    delete[] arr2;

    return 0;
}