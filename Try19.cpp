#include<iostream>

using namespace std;

int main()
{
    int row,col;
    cout << "input a number of rows and colums : ";
    cin >> row >> col;
    cout <<endl;

    int ** list = new int*[row];
    // 먼저 포인터 배열인 행을 선언해줄것

    for(int i =0; i<row; i++)
        list[i] = new int[col];
    // 행에다가 진짜 배열인 열을 가리키게 하나하나 선언

    cout << "input elements :  ";
    for(int y =0; y < row; y++)
        for(int x = 0; x<col; x++)
            cin >> list[y][x]; 

    int sum = 0;

    for(int y =0; y < row; y++)
    {
        for(int x = 0; x<col; x++)
        {
            cout << "row : "<< y << " col : " << x;
            sum += list[y][x];
            cout << " cumulated : " << sum << endl;
        }
    }
        


    for(int i =0; i<row; i++)
        delete[] list[i];

    delete[] list;

    return 0;
}   