#include<iostream>

using namespace std;

class Rectangle
{
    public:

    Rectangle(int width, int height) : m_width(width), m_height(height){}
    // ������

    double Area();

    private:

    double m_width =0 ; // �ʱ�ȭ
    double m_height =0 ;
};

double Rectangle::Area(/*�����̺� ���� ����� ����ϱ⿡ �Ƚᵵ �������*/)
{
    return m_width * m_height;
}

int main()
{
    double width, height;

    cout << "input your rectange spec : ";
    cin >> width >> height;
    cout << endl;

    Rectangle myRect(width, height);

    cout << "The Area :" << myRect.Area();

    return 0;
}