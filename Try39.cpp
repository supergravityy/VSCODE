#include<iostream>
#include<string>


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

    void print_Info()
    {
        printf("Number of Side : %d, Width : %d, Rect\'s Area : %lf\n",this->sideNum, this->width, this->Area());
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

    void print_Info() // 오버라이딩
    {
        printf("Number of Side : %d, Width : %d, Tri\'s Area : %lf\n",this->sideNum, this->width, this->Area());
    }

    protected:

    int height = 0;
};

int main()
{
    Rect rect(10,20);
    Trig tri(10,20);

    printf("Rect info : ");
    rect.Shape::print_Info(); // 오버로딩 되기전의 메소드 출력
    putchar('\n');
    rect.print_Info();

    printf("\nTri info :");
    rect.Shape::print_Info();
    putchar('\n');
    tri.print_Info();

    return 0;
}