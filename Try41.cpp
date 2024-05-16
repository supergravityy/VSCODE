#include<iostream>
#include<string>

using namespace std;
class Shape
{
    
    public:
    Shape() {}
    virtual void draw() = 0; // �߻�Ŭ���� : ��ӹ����� �̰��� �ϼ����Ѷ�

};

class Rect : public Shape
{
    public:
    Rect() : Shape() {}
    void draw()
    {
        printf("This is Rectangle\n");
    }

};

class Trig : public Shape
{
    public: // protect�� �ϸ� �ܺο��� ������ �Ұ����ϴ�
    Trig() : Shape() {}
    void draw()
    {
        printf("This is Triangle\n");
    }

};

class Circle : public Shape
{
    public: 
    Circle() : Shape() {}
    void draw()
    {
        printf("This is Circle\n");
    }
};

int main()
{
    Trig tri;
    Rect rect;
    Circle cir;

    tri.draw();
    rect.draw();
    cir.draw();

    return 0;
}