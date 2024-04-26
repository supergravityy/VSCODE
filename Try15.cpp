#include <iostream>
#include <vector>
#include <stdlib.h>
#define MAX_ARR 5

using namespace std;

int cmp(const void* a, const void * b)
{
    return *(int*)a-*(int*)b;
}

inline void confirm(vector<int>& Vec)
{
    for(int i=0; i<Vec.size(); i++)
        std::cout << Vec[i] << " ";
    std::cout << "\n";
}

void confirm_mem(vector<int>& Vec)
{
    for(int i =0; i<MAX_ARR;i++)
        std::cout << Vec[i] << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> Vec;
    int temp;

    cout << "input 5 integer \n";
    for (int i =0;i<MAX_ARR;i++)
    {
        cin >> temp;
        Vec.push_back(temp); 
    }
        

    cout << "The size of Vec : " << Vec.size()<<endl;
    
    for (int i = 0; i<Vec.size(); i++)
        cout << Vec[i] << " "<<endl;

    confirm(Vec);

    qsort(Vec.data(),Vec.size(),sizeof(int), cmp);
    // .data는 벡터의 첫번째 요소를 가리키는 주소를 반환.
    // 기본적으로 C와 C++의 개념이 많이 차이가 나기에, 이러한 도움이 필요

    cout << "The biggest idx is : " << Vec[Vec.size()-1] << endl;

    confirm(Vec);
    getchar();

    for (int i = 0; i<Vec.size(); i++)
        Vec[i] *= 2;

    confirm(Vec);
    getchar();

    cout << "input index number you wanna erase \n (The first idx is 1) : ";
    
    int idx; cin >> idx;

    Vec.erase(Vec.begin()+idx-1);

    cout << "This process is using Mem\n"<< endl;
    // 그냥 메모리로 접근해서 보면, 삭제를 했어도, 벡터의 유효한 스코프내에서 삭제됬을 뿐, 메모리에는 그대로이다.
    // 또한 인덱스 마지막 값이 복사되어 끝에 추가되어 보인다.
    confirm_mem(Vec);

    cout << "This process is using vec_method\n" << endl;
    confirm(Vec);
    getchar();

    cout << "input index number you wanna duplicate and adding \n (The first idx is 1) : ";

    cin >> idx;

    Vec.push_back(Vec[idx]);

    confirm(Vec);

    return 0;
}