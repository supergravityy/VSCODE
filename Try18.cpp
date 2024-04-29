#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> myVec = {10, 20, 30, 20, 40, 10, 50};

    sort(myVec.begin(), myVec.end());

    myVec.erase(unique(myVec.begin(),myVec.end()), myVec.end());

    cout << "result of erased overlapping element" << endl;
    for (int i = 0; i < myVec.size(); i++) {
        cout << myVec[i] << " ";
    }
    cout << endl;

    return 0;
}


int* UNIQUE(int* first, int* last)
{
    if(first == last)
        return last;

    int* result = first;

    while(++first != last)
        if(!(*result != *first))
            *(++result) = *first;

    return ++result;
}