#include <iostream>

using namespace std;

int main()
{
    int numStd;

    cout << "input number of students : ";
    cin >> numStd;

    double *stdArr = new double[numStd];
    // double *stdArr = (double *)malloc(sizeof(double) * numStd)

    for (int i =0; i < numStd; i++)
    {
        cout << i+1 << "\ntype the score of student : ";
        cin >> stdArr[i];
    } 

    double result_sum = 0;
    for(int i =0; i<numStd; i++)
    {
        result_sum +=stdArr[i];
    }

    cout << "Average : "<< result_sum / double(numStd);

    delete stdArr;
    // free(stdArr)
    return 0;
}
