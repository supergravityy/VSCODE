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

    for(int i=0; i<3; i++) // 컴퓨터 먼저 숫자 정하기
    {
        while(1)
        {
            num = rand()%9+1; //1~9까지

            if(is_unique(comNum,num,'c')) // 중복체크
                break;
        }

        comNum.push_back(num); // 3개의 숫자가 저장됨
    }

    printf("Computer has selected nums!\n ");
    // for(int i =0; i<3;i++)
    // {
    //     printf("%d\t",comNum[i]);
    // }

    int strike = 0;
    int ball = 0;

    // 유저 슷지 하나하나 입력받기

    while(1)
    {
        printf("\nnew input ARR\n");
        userNum.clear();

        for(int i = 0; i<3;i++) // 기본적으로 숫자를 하나씩 3번 입력받아서 벡터를 완성
        {
            while(1)
            {
                printf("\ninput number (%d) : ",i);
                cin >> num;

                if(!(num >= 1 && num < 10)) // 이외의 값을 입력하면 종료
                {   
                    printf("invalid number turn off\n");
                    return 0;
                }

                if(is_unique(userNum,num,'u')) // 중복체크 + 1~9까지의 숫자 입력받음
                    break;

                else
                    printf("\ninvalid input");
            }

            userNum.push_back(num);
        }   

        // 입력 벡터를 전부 입력받으면, 스트라이크 볼 검사
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