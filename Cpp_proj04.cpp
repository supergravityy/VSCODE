#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int iss_empty(int* RECT, int nextX, int nextY, int side);
void Wrapping(int* nextY, int* nextX, int side);

int main()
{
    int side;

    // 홀수 입력받기
    while (true)
    {
        printf("Please input an odd number: ");
        cin >> side;

        if (side % 2)
            break;
    }

    // 마방진 생성
    int* RECT = (int*)calloc(side * side, sizeof(int));
    if (RECT == nullptr) {
        cerr << "Memory allocation failed" << endl;
        return 1;
    }

    int rectY = 0;
    int rectX = side / 2;
    RECT[rectY * side + rectX] = 1; // 1은 첫행의 가운데에 위치
    int count = 1;

    while (count < side * side)
    {
        // 우상단으로 이동하는 방향
        int nextX = rectX + 1;
        int nextY = rectY - 1;

        Wrapping(&nextY, &nextX, side);

        if (!iss_empty(RECT, nextX, nextY, side))
        {
            nextX = rectX;
            nextY = rectY + 1;
            Wrapping(&nextY, &nextX, side); // 경계 처리를 위해 Rule 함수 다시 호출
        }

        rectX = nextX;
        rectY = nextY;

        RECT[rectY * side + rectX] = ++count;
    }

    // 마방진 출력
    for (int y = 0; y < side; y++)
    {
        for (int x = 0; x < side; x++)
            printf("%d\t", RECT[y * side + x]);
        printf("\n");
    }

    free(RECT);

    return 0;
}

int iss_empty(int* RECT, int nextX, int nextY, int side)
{
    // 배열 경계 처리 래핑기법
    if (nextX >= side) nextX -= side; 
    if (nextX < 0) nextX += side;
    if (nextY >= side) nextY -= side;
    if (nextY < 0) nextY += side;

    return (RECT[nextY * side + nextX] == 0);
}

void Wrapping(int* nextY, int* nextX, int side)
{
    // 그냥 경계값 처리

    if (*nextX >= side) *nextX -= side;
    if (*nextX < 0) *nextX += side;
    if (*nextY >= side) *nextY -= side;
    if (*nextY < 0) *nextY += side;
}