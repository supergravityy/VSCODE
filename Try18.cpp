#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> myVec = {10, 20, 30, 20, 40, 10, 50};

    sort(myVec.begin(), myVec.end());
    // ★ 먼저 벡터 범위의 값을 정렬해줄것 ★

    myVec.erase(unique(myVec.begin(),myVec.end()), myVec.end());
    // 벡터의 end는 벡터의 마지막 이후의 쓰래기값 주소를 가리킨다. (추가할당을 용이케 하기위함)

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
    if(first == last) // 벡터가 비었을때를 가정
        return last;

    int* result = first; // 첫번째 원소는 무조건 중복되지 않는다. 
    // result : 현재 벡터 스코프 내에서 고유한 인덱스들의 스코프를 나타냄 (결과)
    // result 는 비교 seeker 

    // first : 벡터 스코프 내에서, result와 비교할 진짜 seeker -> last == first 면 프로세스 종료
    // last : 탐색 seeker의 종료조건을 나타냄

    while(++first != last) // 탐색 seeker 를 계속 증가시킨다.
 
        if(*result != *first) // 비교 seeker 와 탐색 seeker가 다르다면!
            *(++result) = *first; // 비교 seeker의 다음 인덱스로 넘어간 후, 그 인덱스에 고유값을 대입

        // 오름차순으로 정렬되어있다는 가정하
        // 만약 비교 seeker 와 탐색 seeker가 같다면, 탐색 seeker의 주소값만 증가시켜서, 고유값을 계속 찾아낸다

    return ++result;
    // 고유한 스코프 다음주소를 가르켜서, erase의 스코프 작업 영역을 지정하기 위함.
}