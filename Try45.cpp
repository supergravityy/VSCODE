#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

class Snack
{
public:
    Snack() {}

    int price;
    string name;
    string made_in;

    virtual void print_identitiy() = 0; // 순수 가상 함수로 만듭니다.
};

class Candy : public Snack
{
public:
    Candy(string flavor)
    {
        this-> flavor = flavor;
    }

    void print_identitiy() override
    {
        printf("%s Candy\n", this->flavor.c_str());
    }

    string flavor;
};

class Choco : public Snack
{
public:
    Choco(string shape)
    {
        this->shape = shape;
    }

    void print_identitiy() override
    {
        printf("%s Chocolate\n", this->shape.c_str());
    }

    string shape;
};

int main()
{
    
    vector<Snack*> basket;
    vector<int> sequence;
    int num; string choice;

    while(1)
    {
        printf("Choose a snack to add to your basket\n");
        printf("(1. Candy, 2. Choco, 0. Quit) : ");
        cin >> num;

        if(num == 0)
            break;

        else if(num == 1)
        {
            printf("\nInput your flavor : ");
            cin >> choice;
            Candy* candy = new Candy(choice);
            basket.push_back(candy);
            sequence.push_back(num);
        }

        else if(num == 2)
        {
            printf("\nInput your shape : ");
            cin >> choice;
            Choco* choco = new Choco(choice);
            basket.push_back(choco);
            sequence.push_back(num);
        }
    }

    printf("printf basket\n");
    for(int idx = 0; idx < basket.size(); idx++)
    {
        if(sequence[idx] == 1)
        {
            Candy* candy = (Candy*)basket[idx];
            candy->print_identitiy();
        }

        else
        {
            Choco* choco = (Choco*)basket[idx];
            choco->print_identitiy();
        }
    }

    for (Snack* snack : basket) 
        delete snack;
    

    return 0;
}