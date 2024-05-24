#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int main()
{
    int num;
    int start;
    int n;
    int current=0;
    int player_lose=0;
    int computer_lose = 0;

    srand(time(NULL));

    
    while(1)
    {
        while(1)
        // 사용자가 몇번을 입력할것인가?
        {
            printf("\ninput your num of input : ");
            cin >> num;

            if(num < 4 && num >=0)
                break;
        }

        if(current == 0)
        {
            // 첫 시작시, 스타팅 포인트를 입력시, 그 위치서 부터 자동으로 횟수만큼 ++됨
            printf("\ninput your starting num : ");
            cin >> start;
            current = start;

            // 시작점부터 횟수만큼 연속된 숫자 출력 
            printf("\nthe numbers you called!\n");
            printf("%d\t",current);

            for(n=0; n<num-1; n++)
                printf("%d\t",++current);

            printf("\n");
        }
            
       else
       // 첫 시작이 아니라면, 횟수만 입력받고 바로 current에 더하기
       {
            printf("\nthe numbers you called!\n");

            for(n=0; n<num; n++)
                printf("%d\t",++current);

            printf("\n");
       }

        if(current >= 31)
        // 여기서 31 이상의 조건을 넘어버리면, 게임종료
        {
            player_lose++;
            break;
        }
        

        //컴퓨터의 턴
        num = rand()%3+1;

        printf("\nA number computer will input : %d", num);
        
        printf("\nthe numbers computer called!\n");

        for(n=0; n<num; n++)
            printf("%d\t",++current);

        

        if(current >= 31)
        // 여기서 31 이상의 조건을 넘어버리면, 게임종료
        {
            computer_lose++;
            break;
        }

    }

    if(computer_lose && (!player_lose))
    {
        printf("\nplayer wins!\n");
    }

    else if(player_lose && (!computer_lose))
    {
        printf("\ncomputer wins\n");
    }
    
    

    return 0;
}