#include<iostream>
#include<string>

using namespace std;
class Shape
{
    
    public:
    Shape() {}
    virtual void draw() = 0; // 추상클래스 : 상속받을때 이것을 완성시켜라

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
    public: // protect로 하면 외부에서 접근이 불가능하다
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