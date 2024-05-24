#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int iss_empty(int* RECT, int nextX, int nextY, int side);
void Wrapping(int* nextY, int* nextX, int side);

int main()
{
    int side;

    // Ȧ�� �Է¹ޱ�
    while (true)
    {
        printf("Please input an odd number: ");
        cin >> side;

        if (side % 2)
            break;
    }

    // ������ ����
    int* RECT = (int*)calloc(side * side, sizeof(int));
    if (RECT == nullptr) {
        cerr << "Memory allocation failed" << endl;
        return 1;
    }

    int rectY = 0;
    int rectX = side / 2;
    RECT[rectY * side + rectX] = 1; // 1�� ù���� ����� ��ġ
    int count = 1;

    while (count < side * side)
    {
        // �������� �̵��ϴ� ����
        int nextX = rectX + 1;
        int nextY = rectY - 1;

        Wrapping(&nextY, &nextX, side);

        if (!iss_empty(RECT, nextX, nextY, side))
        {
            nextX = rectX;
            nextY = rectY + 1;
            Wrapping(&nextY, &nextX, side); // ��� ó���� ���� Rule �Լ� �ٽ� ȣ��
        }

        rectX = nextX;
        rectY = nextY;

        RECT[rectY * side + rectX] = ++count;
    }

    // ������ ���
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
    // �迭 ��� ó�� ���α��
    if (nextX >= side) nextX -= side; 
    if (nextX < 0) nextX += side;
    if (nextY >= side) nextY -= side;
    if (nextY < 0) nextY += side;

    return (RECT[nextY * side + nextX] == 0);
}

void Wrapping(int* nextY, int* nextX, int side)
{
    // �׳� ��谪 ó��

    if (*nextX >= side) *nextX -= side;
    if (*nextX < 0) *nextX += side;
    if (*nextY >= side) *nextY -= side;
    if (*nextY < 0) *nextY += side;
}