#include "charac.h"

int main()
{
	User* user = new User;
	int mode;
	int round = 1;
	Monster* monster = nullptr;

	int mons_hp;
	int mons_dam;
	int mons_dead = 1;

	srand(time(NULL));

	while (1)
	{
		if (rand() % 2 && monster==nullptr)
		{
			monster = new Monster;
			mons_hp = rand() % 20 + 20;
			mons_dam = rand() % 20 + 1;
			mons_dead = 0;

			monster->init_Monster(mons_hp, mons_dam);
		}
			

		printf("\n\n\n-----------------------------------\n");
		printf("1. get weapon\n");
		printf("\n2. attack\n");
		printf("\n3. printStat\n");
		printf("\n0. Quit\n");
		printf("-----------------------------------\n\n\n");

		printf("Choose your action(%d) : ", round);
		cin >> mode;

		switch (mode)
		{
		case 1:
			user->getweapon();
			break;

		case 2:
			mons_dead = user->attack(monster); // 괴물의 주소를 넘김

			if (mons_dead)
				monster = nullptr; // 유저.attack->무기.attack() 에서 기존 몬스터를 삭제시킴
			break;

		case 3:
			user->print_stat();
			break;

		case 0:
			printf("Quit\n");
			delete user;
			delete monster;
			return 0;


		default:
			printf("Invalid action\n");
			break;
		}

		if (user->userHP() <= 0)
		{
			printf("\nGame Over\n");
			delete user;
			delete monster;
			return 0;
		}
			

		round++;
	}
}