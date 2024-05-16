#include<iostream>
#include<string>

using namespace std;

class Shape
{
    public:

    Shape(int w,int n) 
    : width(w), sideNum(n) {} // 생성자

    void print_Info() // 내용출력
    {
        printf("Number of Side : %d, Width : %d\n",this->sideNum, this->width);
    }

    protected: // 변수
    int sideNum = 0;
    int width = 0;

};

class Rect : public Shape
{
    public : 
    Rect(int w, int h) : Shape(this-> width,this-> sideNum) 
    {
        this->sideNum = 4;
        this->width = w;
        this->height = h;
    }

    double Area()
    {
        return (double)(width * height);
    }

    protected:

    int height = 0;
};

class Trig : public Shape
{
    public : 
    Trig(int w, int h) : Shape(this-> width,this-> sideNum) 
    {
        this->sideNum = 4;
        this->width = w;
        this->height = h;
    }

    double Area()
    {
        return (double)(width * height)/2;
    }

    protected:

    int height = 0;
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