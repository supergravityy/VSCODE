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
        // ����ڰ� ����� �Է��Ұ��ΰ�?
        {
            printf("\ninput your num of input : ");
            cin >> num;

            if(num < 4 && num >=0)
                break;
        }

        if(current == 0)
        {
            // ù ���۽�, ��Ÿ�� ����Ʈ�� �Է½�, �� ��ġ�� ���� �ڵ����� Ƚ����ŭ ++��
            printf("\ninput your starting num : ");
            cin >> start;
            current = start;

            // ���������� Ƚ����ŭ ���ӵ� ���� ��� 
            printf("\nthe numbers you called!\n");
            printf("%d\t",current);

            for(n=0; n<num-1; n++)
                printf("%d\t",++current);

            printf("\n");
        }
            
       else
       // ù ������ �ƴ϶��, Ƚ���� �Է¹ް� �ٷ� current�� ���ϱ�
       {
            printf("\nthe numbers you called!\n");

            for(n=0; n<num; n++)
                printf("%d\t",++current);

            printf("\n");
       }

        if(current >= 31)
        // ���⼭ 31 �̻��� ������ �Ѿ������, ��������
        {
            player_lose++;
            break;
        }
        

        //��ǻ���� ��
        num = rand()%3+1;

        printf("\nA number computer will input : %d", num);
        
        printf("\nthe numbers computer called!\n");

        for(n=0; n<num; n++)
            printf("%d\t",++current);

        

        if(current >= 31)
        // ���⼭ 31 �̻��� ������ �Ѿ������, ��������
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