#include <iostream>

using namespace std;
int main(int cnt, char ** args)
{
    int number;
    int number2;
    int number3;
    int max;
    
    cout << "input a integer" << endl;
    cin >> number;
    max = number;

    if(number % 2)
    {   
        cout << "this is odd" << endl;
    }
    else 
        cout << "this is even" << endl;
    

    cout << "input three integer" << endl;
    cin >> number2;
    cin >> number3;

    if(max < number2)
        max = number2;

    if(max < number3)
        max = number3;

    cout << max << " ก็ that is the maximum number!" << endl;

    return 0;
}