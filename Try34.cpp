#include<iostream>

using namespace std;

class Rectangle
{
    public:

    Rectangle(int width, int height) : m_width(width), m_height(height){}
    // 생성자

    double Area();

    private:

    double m_width =0 ; // 초기화
    double m_height =0 ;
};

double Rectangle::Area(/*프라이빗 안의 멤버를 사용하기에 안써도 상관없다*/)
{
    return m_width * m_height;
}

int main()
{

}