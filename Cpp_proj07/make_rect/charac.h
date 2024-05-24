#pragma once

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Monster; // Ŭ���� ���� ����

class Weapon
{
protected:
    int Dam = 0;
    int Num = 0;

public:
    Weapon() {} // ������

    virtual ~Weapon()
    {
        printf("Your existing weapon has been abandoned!\n");
    }

    virtual int attack(Monster* monster) = 0;
    virtual void change() = 0;
    virtual int printNum() = 0;
};

class Knife : public Weapon
{
public:
    Knife() { change(); }

    void change() override
    {
        this->Dam = 5;
        this->Num = 3;
    }

    int attack(Monster* monster) override;

    int printNum() override
    {
        return this->Num;
    }
};

class Gun : public Weapon
{
public:
    Gun() { change(); }

    void change() override
    {
        this->Dam = 20;
        this->Num = 1;
    }

    int attack(Monster* monster) override;

    int printNum() override
    {
        return this->Num;
    }
};

class User
{
protected:
    int HP = 100;
    int Lv = 1;
    Weapon* user_weapon = nullptr;
    string weaponName = "";

public:
    User() {}

    ~User()
    {
        delete user_weapon;
    }

    void getweapon()
    {
        srand(time(NULL));

        int randVal = rand() % 3;
        if (randVal == 0)
        {
            printf("Nothing\n");
            weaponName = "";
        }
        else if (randVal == 1)
        {
            printf("You got a knife!\n");
            this->weaponName = "knife";
            delete user_weapon; // �������� ����
            this->user_weapon = new Knife();
        }
        else if(randVal == 2)
        {
            printf("You got a gun!\n");
            this->weaponName = "gun";
            delete user_weapon; // ���� ���� ����
            user_weapon = new Gun();
        }
    }

    int userHP()
    {
        return this->HP;
    }

    int attack(Monster* monster);

    void print_stat()
    {
        printf("\nHp : %d, Lv : %d, weaponName : %s, weaponDurability : %d\n", this->HP, this->Lv,
            this->weaponName.c_str(), user_weapon ? this->user_weapon->printNum() : 0);
    }

    int damaged(int oppo_dam)
    {
        

        this->HP -= oppo_dam;
        printf("You have been damaged! %d\n", oppo_dam);

        if (this->HP <= 0)
        {
            printf("You are dead\n");
            return 0;
        }

        return this->HP;
    }
};

class Monster
{
protected:
    int HP;
    int Dam;
    bool isAlive = true;

public:
    Monster()
    {
        printf("\n\nA monster has appeared\n");
    }

    ~Monster()
    {
        printf("\nYour opponent has been killed!\n");
    }

    void init_Monster(int hp, int damage)
    {
        this->HP = hp;
        this->Dam = damage;
    }

    void attack(User& user)
    {
        int oppo_hp = user.damaged(this->Dam);

        printf("Your HP = %d\n", oppo_hp);
    }

    int damaged(int oppo_dam)
    {
        this->HP -= oppo_dam;
        return this->HP;
    }
};

// Knife�� attack �Լ� ���� -> Monster �� �������;� �ϱ� ����
int Knife::attack(Monster* monster)
{
    int oppo_hp = monster->damaged(this->Dam);
    int oppo_death = 0;

    if (oppo_hp <= 0)
    {
        delete monster; // ����� ������Ŵ
        oppo_death = 1; // ����� ������������ �ݷ��� �������� ����� �˷��ִ� �ñ׳�
    }
        
    this->Num--;

    if (this->Num <= 0)
        printf("Knife is broken!\n");

    if (oppo_death == 1)
        return 1;
    else
        return 0;
}

int Gun::attack(Monster* monster)
{
    int oppo_hp = monster->damaged(this->Dam);
    int oppo_death = 0;

    if (oppo_hp <= 0)
    {
        delete monster; // ����� ������Ŵ
        oppo_death = 1; // ����� ������������ �ݷ��� �������� ����� �˷��ִ� �ñ׳�
    }
    this->Num--;

    if (this->Num <= 0)
        printf("Gun is out of ammo!\n");

    if (oppo_death == 1)
        return 1;
    else
        return 0;
}

int User::attack(Monster* monster)
{
    if(monster == nullptr)
    {
        printf("Nothing to attack!\n");
        return 1;
    }

    if (user_weapon != nullptr) // ���Ⱑ ����
    {
        int isKilled = 0;
        isKilled = user_weapon->attack(monster); // ���� ���� ����

        if (this->user_weapon->printNum() <= 0)
        {
            this->weaponName = "";
            delete user_weapon;
            this->user_weapon = nullptr;
        }

        if (isKilled)
            return 1;

        if (!isKilled && this->weaponName == "knife")
        {
            monster->attack(*this); // ������ �� ������, �� �ڽ��� �Ѱ���
        }
    }
    else
    {
        printf("No weapon to attack!\n");
        return 0;
    }

    return 0;
}