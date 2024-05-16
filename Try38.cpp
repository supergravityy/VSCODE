#include<iostream>
#include<string>

using namespace std;

class Shape
{
    public:

    Shape(int w,int h) 
    : width(w), height(h) {} // ������

    void print_Info() // �������
    {
        printf("Height : %d, Width : %d\n",this->height, this->width);
    }

    protected: // ����
    int height = 0;
    int width = 0;

};

class Rect : public Shape
{
    public : 
    Rect(int w, int h) : Shape(w,h) {}

    double Area()
    {
        return (double)(width * height);
    }
};

class Trig : public Shape
{
    public : 
    Trig(int w, int h) : Shape(w,h) {}

    double Area()
    {
        return (double)(width * height)/2;
    }
};

int main()
{
    Rect rect(10,20);
    Trig tri(10,20);

    printf("Rect info : ");
    rect.print_Info();
    printf("Rect Area : %lf",rect.Area());

    printf("\nTri info :");
    tri.print_Info();
    printf("Tri Area : %lf",tri.Area());

    return 0;
}