#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> myVec = {10, 20, 30, 20, 40, 10, 50};

    sort(myVec.begin(), myVec.end());
    // �� ���� ���� ������ ���� �������ٰ� ��

    myVec.erase(unique(myVec.begin(),myVec.end()), myVec.end());
    // ������ end�� ������ ������ ������ �����Ⱚ �ּҸ� ����Ų��. (�߰��Ҵ��� ������ �ϱ�����)

    cout << "result of erased overlapping element" << endl;
    for (int i = 0; i < myVec.size(); i++) 
    {
        cout << myVec[i] << " ";
    }
    cout << endl;

    return 0;
}


int* UNIQUE(int* first, int* last)
{
    if(first == last) // ���Ͱ� ��������� ����
        return last;

    int* result = first; // ù��° ���Ҵ� ������ �ߺ����� �ʴ´�. 
    // result : ���� ���� ������ ������ ������ �ε������� �������� ��Ÿ�� (���)
    // result �� �� seeker 

    // first : ���� ������ ������, result�� ���� ��¥ seeker -> last == first �� ���μ��� ����
    // last : Ž�� seeker�� ���������� ��Ÿ��

    while(++first != last) // Ž�� seeker �� ��� ������Ų��.
 
        if(*result != *first) // �� seeker �� Ž�� seeker�� �ٸ��ٸ�!
            *(++result) = *first; // �� seeker�� ���� �ε����� �Ѿ ��, �� �ε����� �������� ����

        // ������������ ���ĵǾ��ִٴ� ������
        // ���� �� seeker �� Ž�� seeker�� ���ٸ�, Ž�� seeker�� �ּҰ��� �������Ѽ�, �������� ��� ã�Ƴ���

    return ++result;
    // ������ ������ �����ּҸ� �����Ѽ�, erase�� ������ �۾� ������ �����ϱ� ����.
}