#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    vector<int> vec1(1);

    /*-------------------*/
    // ������ ���� ���¿��� Ǫ�ù�(+�����Ҵ�)
    /*-------------------*/

    clock_t start = clock();
    // ���� pushback �� ���!
    for(int i =1; i<=100000000; i++)
        vec1.push_back(i);

    clock_t end = clock();

    double elapsed =((double)(end-start))/CLOCKS_PER_SEC;

    cout << "test1 only pushback : " << elapsed << "sec" << endl;

    vec1.clear(); // ���͸� ����
    vec1.shrink_to_fit(); // �޸𸮸� �Ҵ����� -> �޸� �Ҵ��̽� �ذ�!

    /*-------------------*/
    // ������ �̸� �Ҵ��� ���� ���¿��� Ǫ�ù�
    /*-------------------*/

    vector<int> vec2(1);
    vec2.reserve(100000000); // �̸� ���� �����Ҵ�

    start = clock();

    for(int i =1; i<=100000000; i++) // �� �Ŀ� Ǫ�ù�
        vec2.push_back(i);

    end = clock();

    elapsed = ((double)(end-start))/CLOCKS_PER_SEC;

    cout << "test2 first reserve and pushback : " << elapsed << "sec" << endl;
}