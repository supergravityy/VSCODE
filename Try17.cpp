#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int main()
{
    vector<int> vec1(1);

    /*-------------------*/
    // 공간이 없는 상태에서 푸시백(+공간할당)
    /*-------------------*/

    clock_t start = clock();
    // 오직 pushback 만 사용!
    for(int i =1; i<=100000000; i++)
        vec1.push_back(i);

    clock_t end = clock();

    double elapsed =((double)(end-start))/CLOCKS_PER_SEC;

    cout << "test1 only pushback : " << elapsed << "sec" << endl;

    vec1.clear(); // 벡터를 비울것
    vec1.shrink_to_fit(); // 메모리를 할당해제 -> 메모리 할당이슈 해결!

    /*-------------------*/
    // 공간을 미리 할당해 놓은 상태에서 푸시백
    /*-------------------*/

    vector<int> vec2(1);
    vec2.reserve(100000000); // 미리 벡터 공간할당

    start = clock();

    for(int i =1; i<=100000000; i++) // 그 후에 푸시백
        vec2.push_back(i);

    end = clock();

    elapsed = ((double)(end-start))/CLOCKS_PER_SEC;

    cout << "test2 first reserve and pushback : " << elapsed << "sec" << endl;
}