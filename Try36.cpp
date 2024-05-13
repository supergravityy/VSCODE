#include <iostream>

using namespace std;

// ������ : Ŭ���� �ܺο��� private ������ �����ϰ� �����ִ� �޼ҵ�
// getter : ������ ��ȯ���ִ� �޼ҵ� (Ű���尡 �ƴ�!)
// setter : ������ ���� �Ҵ��ϴ� �޼ҵ�

// ������ �Լ��̸��� �̷��� ����� �ϴ°�?

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
        // ���������
        void Copy_Rect(const Rectangle& othrerRect);

        double Area();

        double getWidth() // �����̺� ������ �������� ���� �Լ��̸���  set~���� ����
        {
            return this->m_width;
        }

        double getHeight()
        {
            return this->m_height;
        }

        void setWidth(double width) // �����̺� ������ �������� �Լ��̸��� get~���� ����
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

void Rectangle :: Copy_Rect(const Rectangle& ohterRect) // Ŭ������ ����ͼ� �׾��� ������ ����
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