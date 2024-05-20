#include<iostream>

using namespace std;

class Person
{
    public:
    virtual void intro() // ��ӹ��� �ڽ� Ŭ�������� ������ ����
    {
        cout << "its person" << endl;
    }
};

class Student : public Person
{
    string name;

    public:
    Student(string Name)
    {
        this->name = Name;
    }

    void intro()
    {
        cout << this->name << " is student." << endl;
    }

    void learn()
    {
        cout << this->name << " is learning." << endl;
    }
};

class Teacher : public Person
{
    string name;

    public:
    Teacher(string Name) 
    {
        this->name = Name;
    }

    void intro()
    {
        cout << this->name << " is teacher." << endl;
    }

    void teach()
    {
        cout << this->name << " is teaching." << endl;
    }
};

int main()
{
    Person *plist[3];
    string names[3];

    cout << "just type 3 person's name(teacher, student, student) : " << endl;
    cin >> names[0] >> names[1] >> names[2];

    Teacher teacher = Teacher(names[0]);
    Student student1 = Student(names[1]);
    Student student2 = Student(names[2]); // Ŭ������ �����Ͽ�, ������ �ν��Ͻ��� ����

    // ��ĳ����

    plist[0] = &teacher;
    plist[1] = &student1;
    plist[2] = &student2; // �ν��Ͻ��� ����Ǿ��ִ� �ּҸ� ��ȯ

    for (auto p : plist) 
    	p->intro();	
        // �θ� Ŭ������ �ϴ� Ʋ�� �ֱ⿡, �����Լ��� ���� �κп� �����ϸ�, �ڿ����� �ڽ��� ������ �κп� ����
	
    // �ٿ�ĳ����

    Teacher *t = (Teacher*)plist[0]; 
    t->teach();
    Student* s1 = (Student*)plist[1];
    s1->learn();
    Student* s2 = (Student*)plist[2];
    s2->learn();

    // ���� plist�� person Ŭ������ŭ�� �д´�
    // ���������� �θ�Ŭ������ŭ�� �ƴ� ���ϴ� �ڽ�Ŭ������ŭ�� �а��Ѵ�

    return 0;
}