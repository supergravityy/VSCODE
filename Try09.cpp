#include<iostream>

using namespace std;

int add(int,int);
int sub(int,int);
int mul(int,int);
double div(double, double);

int main(int cnt, char* args[])
{
    int A,B;
    cout << "type your two intger!" << endl;
    cin >> A; cin >> B;

    cout << "result : " << endl;
    cout << add(A,B) << endl;
    cout << sub(A,B) << endl;
    cout << mul(A,B) << endl;
    cout << div((double)A,(double)B) << endl;

    return 0;
}

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

double div(double a, double b)
{
    return a/b;
}