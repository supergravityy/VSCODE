#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

typedef struct 
{
    char name[100];
    int age;
    char birth[12]; //XXXX.XX.XX ����
}A_person;

bool birthCMP(const A_person& A, const A_person& B)
{
    int yearA, monthA, dayA;
    int yearB, monthB, dayB;

    sscanf(A.birth, "%4d.%2d.%2d",&yearA,&monthA,&dayA);
    sscanf(B.birth, "%4d.%2d.%2d",&yearB,&monthB,&dayB);

    if(yearA != yearB) return yearA>yearB;
    if(monthA != monthB) return monthB>monthB;
    return dayA >= dayB;
}

int main()
{
    FILE* fp;
    string fileName;

    printf("You can only access with \'.csv\',\'txt\' file extension");
    printf("Please enter the file name! : ");
    cin >> fileName;
    putchar('\n');


    fp=fopen(fileName.c_str(),"r");
    // c_str() �Լ��� ����Ͽ� char* Ÿ������ �ӽú�ȯ

    if(fp == NULL)
    {
        printf("File could not be opend ! ");
        return 1;
    }

    vector<A_person> students;
    A_person temp;
    int size = 0;
    int ret_val=0;

    printf("The Information of students\n\n");

    while(1)
    {
        ret_val=fscanf(fp, "%99[^,],%d,%11[^\n]\n",temp.name,&temp.age,temp.birth); //��ȯ�� ��� ������Ʈ�ϱ�

        if(ret_val == EOF || ret_val !=3)
            break; //Eof�� �����ϰų�, �ʿ��� ��� �ʵ带 ���� ���Ͽ�����

        printf("Name : %s, age : %d, birth : %s\n",temp.name,temp.age,temp.birth);
        students.push_back(temp);
        size++;
    }

    if(size == 0) // ���Ͽ��� �о���ΰ� ������
    {
        printf("\nYour file doesnt have contents!\n");
        fclose(fp);
        return 1;
    }


    double avg=0;

    for(int i =0; i<size; i++)
        avg+=students[i].age;

    printf("The average age of students : %.3f\n\n",avg/size);


    sort(students.begin(),students.end(),birthCMP); // �������� ����

    printf("This is the information of the students arranged in order of birth date.\n\n");

    for(int i =0; i<size;i++)
        printf("Name : %s, age : %d, birth : %s\n",students[i].name,students[i].age,students[i].birth);

    printf("\n\nThe oldest students is '%s'\n",students[size-1].name);

    fclose(fp);

    return 0;
}