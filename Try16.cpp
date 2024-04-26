#include <iostream>
#include <time.h>

using namespace std;
int main()
{
    clock_t start, end;
    double time;

    long count =0;

    start = clock();

    while(count < 100000000)
        count++;
    

    end = clock();

    time = ((double)(end-start))/CLOCKS_PER_SEC;

    cout << "Record : " << time << endl;
}