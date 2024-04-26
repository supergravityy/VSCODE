#include <iostream>
#define ARR_MAX 5

using namespace std;

void reverse(int *arr)
{
    int *p = arr + ARR_MAX -1;

    for (; p >= arr; p--)
    {
        cout << *p << " ";
    }
}

int main()
{
    int list[ARR_MAX] = {10,20,30,40,50};

    reverse(list);

    return 0;
}