#include<iostream>

using namespace std;

class Shape
{
    public:

    Shape(int w,int n) 
    : width(w), sideNum(n) {} // ������

    void print_Info() // �������
    {
        printf("Number of Side : %d, Width : %d\n",this->sideNum, this->width);
    }

    protected: // ����
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

    void print_Info(int W, int H)
    {
        printf("Rect\'s Area : %d",W*H);
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

    void print_Info(int W, int H) // �����ε� : �Լ� �̸��� �Ȱ����� �޴� �Ķ������ ������ �ٸ��� �ٸ��� ó�� 
    {
        printf("Tri\'s Area : %d",W*H/2);
    }

    void print_Info() // override
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
    rect.Shape::print_Info(); // �����ε� �Ǳ����� �޼ҵ� ���
    putchar('\n');
    rect.print_Info();
    putchar('\n');
    rect.print_Info(5,10);

    printf("\nTri info :");
    rect.Shape::print_Info();
    putchar('\n');
    tri.print_Info();
    putchar('\n');
    tri.print_Info(5,10);

    return 0;
}