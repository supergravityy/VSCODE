#include <iostream>

using namespace std;

class Rectangle
{
    public:

    Rectangle(int width, int height) : m_width(width), m_height(height){}
    // 생성자

    double Area();

    private:

    double m_width {0} ; // 초기화
    double m_height {0} ;
};

double Rectangle::Area(/*프라이빗 안의 멤버를 사용하기에 안써도 상관없다*/)
{
    return m_width * m_height;
}

int main()
{
    double width,height;

    cout << "input width and height : ";
    cin >> width >> height;

    Rectangle rec(width,height); // 생성자가 실행됨

    cout << "Area is : " << rec.Area(/*안의 멤버들을 갖고 계산하기에 상관이 없다*/) << endl;

    return 0;
}