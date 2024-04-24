#include <iostream>

using namespace std;

int main()
{
    string list[5] = {"usa","korea","japan","russia","china"};
    string mode;

    cin >> mode;

    if(mode == "list")
    {
        for(int i=0; i<5; i++)
        {
            cout << list[i]<<endl;
        }
    }
    int i = 0;

    for(; i<5;i++)
    {
        if(list[i]==mode)
        {
            cout << list[i] << i <<endl;
            break;
        }    
    }

    if(i>=5)
        cout << "nothing\n";

    return 0;
}