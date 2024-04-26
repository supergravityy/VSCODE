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
    // free는 할당된 메모리 시작주소만 할당해제하여, 실제 메모리 뭉텅이와 포인터 주소의 연결관계를 끊는다.
    // 할당된 로컬내에서 sizeof()함수가 작동이 가능한 것은 레지스터에 해당 정보가 저장이 되기 때문.
    // 기본적으로 변수들은 각각이 auto 라는 키워드로 작성되어, 로컬변수는 OS에 의해 적절히 관리된다.
    // 해당 로컬변수가 선언되었던, 로컬을 벗어나면, 제한된 정보만을 갖기에, 어쩔 수 없다.
}

void test_new(int Cpp_Arr[])
{
    cout << "The Size of Cpp Array : " << sizeof(Cpp_Arr) << endl;
    printf("The Array starting address is in Cpp : %X\n", Cpp_Arr);
    // 스택과 다르게 힙 영역에서는 load 되면, 메모리주소에서 + 방향으로 load 되게 된다.
    cout << "The size of allocated memory size in Cpp : " << _msize(Cpp_Arr) <<endl;

    free(Cpp_Arr);
    //delete[] Cpp_Arr;
    cout << "The allocated memory has been deleted!"<<endl;
    // delete[]를 사용하는 이유는 할당된 메모리 주소만 아닌, 할당된 메모리 주소의 크기만큼 전부 접근(할당해제?)한다.
    // 그렇다는건, 어딘가에 할당된 메모리의 크기 or 인덱스의 숫자가 저장되어있다는 말.
    // 그러나, sizeof 함수가 둘 다 할당되었던 로컬에서처럼 작동하지 않는다.

    /*-----------------------------*/
    // 왜???????????????????????????
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
    // 할당된 로컬 내에서 sizeof 함수에 배열의 시작주소를 입력하면, 인덱스의 갯수가 나온다.
    cout << "The size of allocated memory size in C : " << _msize(C_Arr) <<endl;

    int *Cpp_Arr = new int[Arr_size];
    cout << "memory allocation has been completed in C++"<< endl;
    cout << "The Size of Cpp Array : " << sizeof(Cpp_Arr) << endl;
    cout << "The size of allocated memory size in Cpp : " << _msize(Cpp_Arr) <<endl;

    test_malloc(C_Arr);
    test_new(Cpp_Arr);

    return 0;
}