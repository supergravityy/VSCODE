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
    // .data�� ������ ù��° ��Ҹ� ����Ű�� �ּҸ� ��ȯ.
    // �⺻������ C�� C++�� ������ ���� ���̰� ���⿡, �̷��� ������ �ʿ�

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
    // �׳� �޸𸮷� �����ؼ� ����, ������ �߾, ������ ��ȿ�� ������������ �������� ��, �޸𸮿��� �״���̴�.
    // ���� �ε��� ������ ���� ����Ǿ� ���� �߰��Ǿ� ���δ�.
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