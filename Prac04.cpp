#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>

using namespace std;

void test_malloc(int C_Arr[])
{
    cout << "The Size of C Array : "<< sizeof(C_Arr) << endl;
    cout << "The size of allocated memory size in C : " << _msize(C_Arr) <<endl;
    printf("The Array starting address is in C : %X\n", C_Arr);
    
    free(C_Arr);
    cout << "The allocated memory has been freed!"<<endl;
    // free�� �Ҵ�� �޸� �����ּҸ� �Ҵ������Ͽ�, ���� �޸� �����̿� ������ �ּ��� ������踦 ���´�.
    // �Ҵ�� ���ó����� sizeof()�Լ��� �۵��� ������ ���� �������Ϳ� �ش� ������ ������ �Ǳ� ����.
    // �⺻������ �������� ������ auto ��� Ű����� �ۼ��Ǿ�, ���ú����� OS�� ���� ������ �����ȴ�.
    // �ش� ���ú����� ����Ǿ���, ������ �����, ���ѵ� �������� ���⿡, ��¿ �� ����.
}

void test_new(int Cpp_Arr[])
{
    cout << "The Size of Cpp Array : " << sizeof(Cpp_Arr) << endl;
    printf("The Array starting address is in Cpp : %X\n", Cpp_Arr);
    // ���ð� �ٸ��� �� ���������� load �Ǹ�, �޸��ּҿ��� + �������� load �ǰ� �ȴ�.
    cout << "The size of allocated memory size in Cpp : " << _msize(Cpp_Arr) <<endl;

    free(Cpp_Arr);
    //delete[] Cpp_Arr;
    cout << "The allocated memory has been deleted!"<<endl;
    // delete[]�� ����ϴ� ������ �Ҵ�� �޸� �ּҸ� �ƴ�, �Ҵ�� �޸� �ּ��� ũ�⸸ŭ ���� ����(�Ҵ�����?)�Ѵ�.
    // �׷��ٴ°�, ��򰡿� �Ҵ�� �޸��� ũ�� or �ε����� ���ڰ� ����Ǿ��ִٴ� ��.
    // �׷���, sizeof �Լ��� �� �� �Ҵ�Ǿ��� ���ÿ���ó�� �۵����� �ʴ´�.

    /*-----------------------------*/
    // ��???????????????????????????
    /*-----------------------------*/
}

int main()
{
    int Arr_size ;

    cout << "input Array size! : ";
    cin >> Arr_size;

    int *C_Arr = (int *)malloc(sizeof(int) * Arr_size);
    cout << "memory allocation has been completed in C"<< endl;
    cout << "The Size of C Array : "<< sizeof(C_Arr) << endl;
    // �Ҵ�� ���� ������ sizeof �Լ��� �迭�� �����ּҸ� �Է��ϸ�, �ε����� ������ ���´�.
    cout << "The size of allocated memory size in C : " << _msize(C_Arr) <<endl;

    int *Cpp_Arr = new int[Arr_size];
    cout << "memory allocation has been completed in C++"<< endl;
    cout << "The Size of Cpp Array : " << sizeof(Cpp_Arr) << endl;
    cout << "The size of allocated memory size in Cpp : " << _msize(Cpp_Arr) <<endl;

    test_malloc(C_Arr);
    test_new(Cpp_Arr);

    return 0;
}