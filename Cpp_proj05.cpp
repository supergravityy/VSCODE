#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

void is_strike(vector<int> &comVec, vector<int> &userVec, int& strike)
{
    for(int i = 0; i<3;i++)
        if(userVec[i] == comVec[i])
            strike++;
}

void is_ball(vector<int> &comVec, vector<int> &userVec, int& ball)
{
    for(int i = 0; i<3;i++)
    {
        for(int j=0; j<3; j++)
        {
            if(i != j && userVec[j] == comVec[i])
                ball ++;
        }
    }
}

int main()
{
    vector<int> userNum;
    vector<int> comNum;

    int num;

    srand(time(NULL));

    for(int i=0; i<3; i++) // ��ǻ�� ���� ���� ���ϱ�
    {
        while(1)
        {
            num = rand()%9+1; //1~9����

            if(is_unique(comNum,num,'c')) // �ߺ�üũ
                break;
        }

        comNum.push_back(num); // 3���� ���ڰ� �����
    }

    printf("Computer has selected nums!\n ");
    // for(int i =0; i<3;i++)
    // {
    //     printf("%d\t",comNum[i]);
    // }

    int strike = 0;
    int ball = 0;

    // ���� ���� �ϳ��ϳ� �Է¹ޱ�

    while(1)
    {
        printf("\nnew input ARR\n");
        userNum.clear();

        for(int i = 0; i<3;i++) // �⺻������ ���ڸ� �ϳ��� 3�� �Է¹޾Ƽ� ���͸� �ϼ�
        {
            while(1)
            {
                printf("\ninput number (%d) : ",i);
                cin >> num;

                if(!(num >= 1 && num < 10)) // �̿��� ���� �Է��ϸ� ����
                {   
                    printf("invalid number turn off\n");
                    return 0;
                }

                if(is_unique(userNum,num,'u')) // �ߺ�üũ + 1~9������ ���� �Է¹���
                    break;

                else
                    printf("\ninvalid input");
            }

            userNum.push_back(num);
        }   

        // �Է� ���͸� ���� �Է¹�����, ��Ʈ����ũ �� �˻�
        is_strike(comNum,userNum,strike);

        is_ball(comNum,userNum,ball);

        printf("--------------------------------------------------");
        printf("strike : %d, ball : %d", strike, ball);
        printf("--------------------------------------------------");

        if(strike >= 3)
        {
            printf("\n3 strike game over!\n");
            return 0;
        }
    }
}