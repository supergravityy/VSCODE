#include <iostream>
#include <string>

using namespace std;

int main()
{
    int x,y;
    do
    {
        cout << "you must input nature number! "<< endl;
        cout << "input integer 1 : ";
        cin >> x;
        cout << "input integer 2 : ";
        cin >> y;
    }while(x <= 0 && y <= 0);

    int* list = new int[y*x];

    for(int row =0; row < y; row++)
    {
        for(int col = 0; col < x;col++)
        {
            cin >> list[y*row+col];
        }
    }
    
    for(int row =0; row < y; row++)
    {
        for(int col = 0; col < x;col++)
        {
            cout << list[y*row+col] << " ";
        }
    }

}