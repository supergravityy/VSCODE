#include <iostream>

using namespace std;

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
    Rectangle rec1{4,5};
    Rectangle rec2 = rec1; // rec1�� ������ rec2�� ����

    cout << "Rec2\'s Area : " << rec2.Area() << endl;

    Rectangle rec3;
    rec3 = rec1; // �����ϴ� �뵵

    cout << "Rec3\'s Area : " << rec3.Area() <<endl;
    return 0;
}