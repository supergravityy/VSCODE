#include<iostream>

using namespace std;

int main()
{
    int row,col;
    cout << "input a number of rows and colums : ";
    cin >> row >> col;
    cout <<endl;

    int ** list = new int*[row];
    // ���� ������ �迭�� ���� �������ٰ�

    for(int i =0; i<row; i++)
        list[i] = new int[col];
    // �࿡�ٰ� ��¥ �迭�� ���� ����Ű�� �ϳ��ϳ� ����

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