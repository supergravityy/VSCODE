#define _CRT_SECURE_NO_WARNING

#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

class Snack
{
    public:
    Snack() {}

    int price;
    char name[100];
    char made_in[100];
};

class Candy : public Snack
{
    public:
    Candy() {}

    char flavor[100];
};

class Choco : public Snack
{
    public:
    Choco () {}

    char shape[100];
};

typedef struct 
{
    Candy can; 
    Choco cho;
}Snackbasket;


int main()
{
    Choco choco1;
    strcpy(choco1.name, "sneakers");
    Choco choco2;
    strcpy(choco2.name, "m&m");

    Candy candy1;
    strcpy(candy1.name, "chupachups");
    Candy candy2;
    strcpy(candy2.name, "haribo");

    Snackbasket basket[2] = {candy1,choco1,candy2,choco2};

    for(int i =0; i<2 ; i++)
        printf("1. choco name : %s, candy name : %s\n",basket[i].cho.name,basket[i].can.name);

    return 0;
}