#include<iostream>

using namespace std;

class Person
{
    public:
    virtual void intro() // 상속받을 자식 클래스에게 숙제를 내줌
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
    Student student2 = Student(names[2]); // 클래스를 생성하여, 선언한 인스턴스에 복사

    // 업캐스팅

    plist[0] = &teacher;
    plist[1] = &student1;
    plist[2] = &student2; // 인스턴스가 저장되어있는 주소를 반환

    for (auto p : plist) 
    	p->intro();	
        // 부모 클래스에 일단 틀이 있기에, 가상함수로 만든 부분에 접근하면, 자연스레 자식이 선언한 부분에 접근
	
    // 다운캐스팅

    Teacher *t = (Teacher*)plist[0]; 
    t->teach();
    Student* s1 = (Student*)plist[1];
    s1->learn();
    Student* s2 = (Student*)plist[2];
    s2->learn();

    // 현재 plist는 person 클래스만큼을 읽는다
    // 강제적으로 부모클래스만큼이 아닌 원하는 자식클래스만큼을 읽게한다

    return 0;
}