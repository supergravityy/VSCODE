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

    // ����� �Է¹ޱ�
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

    // ��ǻ�� �Է¹ޱ�

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

    // �´��� ����
    int count;

    for(int computerIDX = 0; computerIDX < 6; computerIDX++) // ��ǻ���� �Է� �ϳ��ϳ��� ���� ���Ϳ� ���ϸ� ��ȸ
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

    // count == 7�ϰ�� 1��
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