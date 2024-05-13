#include <iostream>

using namespace std;

// 접근자 : 클래스 외부에서 private 변수에 접근하게 도와주는 메소드
// getter : 변수를 반환해주는 메소드 (키워드가 아님!)
// setter : 변수에 값을 할당하는 메소드

// 무조건 함수이름을 이렇게 지어야 하는가?

class Rectangle
{
    public:

    Rectangle() {}

        Rectangle(double width, double height)
        {
            cout << "General constructor" << endl;
            this -> m_width = width;
            this -> m_height = height;
        }
        // 복사생성자
        void Copy_Rect(const Rectangle& othrerRect);

        double Area();

        double getWidth() // 프라이빗 변수를 가져오기 위해 함수이름을  set~으로 짓기
        {
            return this->m_width;
        }

        double getHeight()
        {
            return this->m_height;
        }

        void setWidth(double width) // 프라이빗 변수에 쓰기위해 함수이름을 get~으로 짓기
        {
            this->m_width = width;
        }

        void setHeight(double height)
        {
            this->m_height = height;
        }

    private:

        double m_width = 0;
        double m_height = 0;
};

double Rectangle::Area()
{
    return m_width*m_height;
}

void Rectangle :: Copy_Rect(const Rectangle& ohterRect) // 클래스를 갖고와서 그안의 정보를 취함
{
    cout << "Copy constructor" << endl;
    this -> m_width = ohterRect.m_width;
    this -> m_height = ohterRect.m_height;
}

int main()
{
    double width, height;

    Rectangle Myrect1{1,2};
    cout << "Myrect1\'s Area : " << Myrect1.Area()<< endl;

    cout << "input your rect\'s spec : ";
    cin >> width >> height;

    Myrect1.setWidth(width);
    Myrect1.setHeight(height);

    cout << "Revised Area : " << Myrect1.Area() << endl;
    cout << "Revised your spec : (width)" << Myrect1.getWidth() << ", (height)" << Myrect1.getHeight() << endl;

    return 0;
}