#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int is_unique(vector<int>& numVec, int num,char mode)
{
    if(mode == 'u')
    {
        for(int i =0; i<numVec.size();i++)
        {
            if(numVec[i] == num)
            {
                printf("not unique! try again\n");
                return 0;
            }
        }
        return 1;
    }
    
    else if(mode == 'c')
    {
        for(int i =0; i<numVec.size();i++)
            if(numVec[i] == num)
                return 0;
        return 1;
    }
}

int main()
{
    printf("number can be inputted 1~25\n");

    vector<int> userInput;
    vector<int> computerInput;

    int num;

    // 사용자 입력받기
    for(int i=0; i<6; i++)
    {
        while(1)
        {
            printf("input number %dth : ",i);
            cin >> num;

            if(is_unique(userInput,num,'u') && (num < 26) && (num > 0))
                break;
        }

        userInput.push_back(num);
    }

    // 컴퓨터 입력받기

    srand(time(NULL));

    for(int i=0; i<6; i++)
    {
        while(1)
        {
            num = rand()%25+1;

            if(is_unique(computerInput,num,'c'))
                break;
        }

        computerInput.push_back(num);
    }

    printf("\ncomputers number\n");
    for(int i =0; i<6;i++)
        printf("%d\t",computerInput[i]);

    printf("\n");

    // 맞는지 집계
    int count;

    for(int computerIDX = 0; computerIDX < 6; computerIDX++) // 컴퓨터의 입력 하나하나를 유저 벡터와 비교하며 순회
    {   
        for(int userIDX = 0; userIDX <6; userIDX++)
        {
            if(computerInput[computerIDX] == userInput[userIDX])
            {
                count++;
                break;
            }
        }
    }

    // count == 7일경우 1등
    switch (count)
    {
    case 7:
        printf("you are 1st\n");
        break;

    case 6:
        printf("you are 2nd\n");
        break;

    case 5:
        printf("you are 3rd\n");
        break;
    
    default:
        printf("nothing\n");
        break;
    }


    return 0;
}