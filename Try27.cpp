#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int check_dupli(int * arr, int num)
{
    int ok = 0;
    for(int i =0; i< 6; i++)
    {
        if(num == arr[i])
            return ok;
    }
    ok = 1;

    return ok;
}

int main()
{
    srand(time(NULL));

    int count = 0;
    int Num;
    int lotto[6] = {-1} ; 

    while(1)
    {
        Num = rand()%45;

        if(check_dupli(lotto,Num))
            lotto[count++] = Num;

        if(count == 6)
            break;
    }

    for(int i =0; i<6; i++)
    {
        cout << lotto[i] << "\t";
    }
    cout << endl;
}