#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

using namespace std;

class Calculator
{
    protected:
    double X;
    double Y;
    char mode;

    public:
    Calculator() {}

    void inputX(double front)
    {
        this->X = front;
    }

    void inputMode(char ch)
    {
        this->mode = ch;
    }

    void inputY(double back)
    {
        this->Y = back;
    }

    virtual double Add() = 0;
    virtual double Sub() = 0;
    virtual double Mul() = 0;
    virtual double Div() = 0;

    double select()
    {
        double result;

        switch (this->mode)
        {
        case '+':
            result = Add();
            break;

        case '-':
            result = Sub();
            break;

        case '*':
            result = Mul();
            break;

        case '/':
            result = Div();
            break;
        
        default:
            break;
        }

        return result;
    }
};

class Real: public Calculator
{
    public:

    double Add() override
    {
        return this->X + this->Y;
    }

    double Sub() override
    {
        return this->X - this->Y;
    }

    double Mul() override
    {
        return this->X * this->Y;
    }

    double Div() override
    {
        return this->X / this->Y;
    }
};

int main()
{
    double X,Y;
    char mode;
    Real calculator;

    printf("\ninput number : ");
    cin >> X;
    calculator.inputX(X);
    printf("\ninput mode : ");
    cin >> mode;
    calculator.inputMode(mode);
    printf("\ninput number : ");
    cin >> Y;
    calculator.inputY(Y);

    double result = calculator.select();

    printf("\n-------------------------------\n");
    cout << result << endl;
    printf("-------------------------------\n");

    string nextDO;

    while(1)
    {
        X = 0;
        Y = 0; // ÃÊ±âÈ­

        printf("wanna continue ? (Y : continue, AC : initialize, EXIT : quit) : ");
        cin >> nextDO;

        if(nextDO == "Y")
        {
            X = result;
        }

        else if(nextDO == "EXIT")
        {
            return 0;
        }

        if(X != 0)
        {
            calculator.inputX(X);
            printf("\ninput mode : ");
            cin >> mode;
            calculator.inputMode(mode);
            printf("\ninput number : ");
            cin >> Y;
            calculator.inputY(Y);
        }

        else
        {
        printf("\ninput number : ");
        cin >> X;
        calculator.inputX(X);
        printf("\ninput mode : ");
        cin >> mode;
        calculator.inputMode(mode);
        printf("\ninput number : ");
        cin >> Y;
        calculator.inputY(Y);
        }

        double result = calculator.select();

        printf("\n-------------------------------\n");
        cout << result << endl;
        printf("-------------------------------\n");

    }
}