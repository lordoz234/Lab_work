#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>

//heroes
struct heroes {
	char* name;
	double hp;
	double resistance;
	int mana;
	char* element;
	char* skill1;
	char* skill2;
	char* skill3;
	char* skill4;
	int xp;
	double vamp;
	int level;
	int block;
};

//monsters
struct monsters {
	char* name;
	double hp;
	double resistance;
	int mana;
	int xp;
	int damager;
	int block;
};

void shrift(int x, int y) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(CONSOLE_FONT_INFOEX);

	GetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);  // Получаем текущий размер шрифта

	// Устанавливаем новый размер шрифта
	fontInfo.dwFontSize.X = x;  // Ширина шрифта
	fontInfo.dwFontSize.Y = y;  // Высота шрифта

	SetCurrentConsoleFontEx(hConsole, FALSE, &fontInfo);  // Устанавливаем новый размер шрифта
}

void menu() {
	Sleep(1000);
	printf("\n\n	Main menu");
	printf("\n 1. Start the tournament.\n 2. Information about the participants.\n 3. View the characteristics.\n 4. Train.\n 5. Sleep.\n\n\n");
}

void lvl(int levels[27], struct heroes *ti) {
	//proverka na new level
	int a = ti->level;
	if (levels[a] - ti->xp < 0) {
		printf(" To get the next level, you have to accumulate 0 xp. To the next level: %d.\n", levels[a]);
	}
	else {
		printf(" To get the next level, you have to accumulate %d xp. To the next level: %d.\n", ti->xp, levels[a] - ti->xp);
	}
	Sleep(1000);
	if (levels[a] - ti->xp <= 0) {
		printf("\n\n NEW LEVEL!!!!\n\n");
		Sleep(2000);
		printf(" You hp increased, you mana increased on 1000, you resistance increased\n");
		ti->level += 1;
		ti->hp += 110;
		ti->mana += 1000;
		ti->resistance += 0.01;
		if (ti->level > 14) {
			ti->hp += 500;
			ti->mana += 750;
		}
	}
	ti->xp = abs(levels[ti->level] - ti->xp);
}

void bitva(int levels, int gerou, int kogo, struct heroes *You, struct monsters *Spider, struct monsters *Bear, struct monsters *Amphibian1, struct monsters *StoneBlock) {
	int damage = 0;
	int spell = 0;
	Spider->hp = 160;
	Bear->hp = 410;
	Amphibian1->hp = 300;
	StoneBlock->hp = 500;

	switch (kogo) {
	case 1:

		//bitva
		while (Spider->hp > 0 && You->hp > 0) {
			Sleep(2000);
			if (You->hp <= 0 || You->mana <= 0) {
				break;
			}
			printf("\n Spider hp: %lf     Spider mana: %d\n Your HP: %lf     Your mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				Spider->hp, Spider->mana, You->hp, You->mana, You->skill1, You->skill2, You->skill3);
			if (You->level >= 5) {
				printf(" Skill 4: %s\n", You->skill4);
			}
			scanf_s("%d", &spell);

			//hod monster
			if (Spider->block > 0) {
				printf("\n Spider in the block.\n");
				Spider->block -= 1;
			}
			else {
				printf("\n Spider attacked hero and causes damage = %d.\n", Spider->damager);
				You->hp = You->hp - (1 - You->resistance) * Spider->damager;
			}

			//hod hero
			switch (gerou) {
			case 1:
				if (spell == 1) {
					You->mana -= 30;
					damage = 0;
					Spider->block = 2;
				}
				if (spell == 2) {
					You->mana -= 75;
					damage = 100;
				}
				if (spell == 3) {
					You->mana -= 25;
					damage = 50;
					Spider->block = 1;
				}
				if (You->level>= 5 && spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			case 2:
				if (spell == 1) {
					You->mana -= 20;
					damage = 0;
					You->resistance += 0.05;
				}
				if (spell == 2) {
					You->mana -= 85;
					damage = 100;
				}
				if (spell == 3) {
					You->mana -= 25;
					damage = 60;
					Spider->resistance -= 0.02;
				}
				if (You->level >= 5 && spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			case 3:
				if (spell == 1) {
					You->mana -= 20;
					damage = 0;
					You->hp += 50;
				}
				if (spell == 2) {
					You->mana -= 25;
					damage = 30;
					Spider->block = 1;
				}
				if (spell == 3) {
					You->mana -= 100;
					damage = 200;
				}
				if (You->level >= 5 && spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			}
			Spider->hp = Spider->hp - (1 - Spider->resistance) * damage;
			You->hp = You->hp + damage * You->vamp;
		}

		//awards
		printf("\n\n The spider died, you get a little experience and mana (+20 xp; +50 mana).\n");
		You->mana += 50;
		You->xp += Spider->xp;
		You->hp += 20;

		break;
	case 2:

		//bitva
		while (Bear->hp > 0 && You->hp > 0) {
			Sleep(4000);
			if (You->hp <= 0 || You->mana <= 0) {
				break;
			}
			printf("\n Bear hp: %lf     Bear mana: %d\n Your HP: %lf     Your mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				Bear->hp, Bear->mana, You->hp, You->mana, You->skill1, You->skill2, You->skill3);
			if (You->level >= 5) {
				printf(" Skill 4: %s\n", You->skill4);
			}
			scanf_s("%d", &spell);

			//hod monster
			if (Bear->block > 0) {
				printf("\n Bear in the block.\n");
				Bear->block -= 1;
			}
			else {
				printf("\n Bear attacked hero and causes damage = %d.\n", Bear->damager);
				You->hp = You->hp - (1 - You->resistance) * Bear->damager;
			}

			//hod hero
			switch (gerou) {
			case 1:
				if (spell == 1) {
					You->mana -= 30;
					damage = 0;
					Bear->block = 2;
				}
				if (spell == 2) {
					You->mana -= 75;
					damage = 100;
				}
				if (spell == 3) {
					You->mana -= 25;
					damage = 50;
					Bear->block = 1;
				}
				if (You->level >=5 && spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			case 2:
				if (spell == 1) {
					You->mana -= 20;
					damage = 0;
					You->resistance += 0.05;
				}
				if (spell == 2) {
					You->mana -= 85;
					damage = 100;
				}
				if (spell == 3) {
					You->mana -= 25;
					damage = 60;
					Bear->resistance -= 0.02;
				}
				if (You->level >= 5 && spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			case 3:
				if (spell == 1) {
					You->mana -= 20;
					damage = 0;
					You->hp += 50;
				}
				if (spell == 2) {
					You->mana -= 25;
					damage = 30;
					Bear->block = 1;
				}
				if (spell == 3) {
					You->mana -= 100;
					damage = 200;
				}
				if (You->level >= 5 && spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			}
			Bear->hp = Bear->hp - (1 - Bear->resistance) * damage;
			You->hp = You->hp + damage * You->vamp;
		}

		//awards
		printf("\n\n The Bear died, you get a little experience and mana (+40 xp; +50 mana).\n");
		You->mana += 50;
		You->xp += Bear->xp;
		You->hp += 50;

		break;
	case 3:

		//bitva
		while (Amphibian1->hp > 0 && You->hp > 0) {
			Sleep(4000);
			if (You->hp <= 0 || You->mana <= 0) {
				break;
			}
			printf("\n Amphibian hp: %lf     Amphibian mana: %d\n Your HP: %lf     Your mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				Amphibian1->hp, Amphibian1->mana, You->hp, You->mana, You->skill1, You->skill2, You->skill3);
			if (You->level >= 5) {
				printf(" Skill 4: %s\n", You->skill4);
			}
			scanf_s("%d", &spell);

			//hod monster
			if (Amphibian1->block > 0) {
				printf("\n Amphibian in the block.\n");
				Amphibian1->block -= 1;
			}
			if (Amphibian1->hp > 0) {
				printf("\n Amphibian attacked hero and causes damage = %d.\n", Amphibian1->damager);
				You->hp = You->hp - (1 - You->resistance) * Amphibian1->damager;
			}

			//hod hero
			switch (gerou) {
			case 1:
				if (spell == 1) {
					You->mana -= 30;
					damage = 0;
					Amphibian1->block = 2;
				}
				if (spell == 2) {
					You->mana -= 75;
					damage = 100;
				}
				if (spell == 3) {
					You->mana -= 25;
					damage = 50;
					Amphibian1->block = 1;
				}
				if (spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			case 2:
				if (spell == 1) {
					You->mana -= 20;
					damage = 0;
					You->resistance += 0.05;
				}
				if (spell == 2) {
					You->mana -= 85;
					damage = 100;
				}
				if (spell == 3) {
					You->mana -= 25;
					damage = 60;
					Amphibian1->resistance -= 0.02;
				}
				if (spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}

				break;
			case 3:
				if (spell == 1) {
					You->mana -= 20;
					damage = 0;
					You->hp += 50;
				}
				if (spell == 2) {
					You->mana -= 25;
					damage = 30;
					Amphibian1->block = 1;
				}
				if (spell == 3) {
					You->mana -= 100;
					damage = 200;
				}
				if (spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			}
			Amphibian1->hp = Amphibian1->hp - (1 - Amphibian1->resistance) * damage;
			You->hp = You->hp + damage * You->vamp;
		}

		//awards
		printf("\n\n The Amphibian died, you get a little experience and mana (+%d xp; +50 mana).\n", Amphibian1->xp);
		You->mana += 50;
		You->xp += Amphibian1->xp;
		You->hp += 75;
		break;
	case 4:

		//bitva
		while (StoneBlock->hp > 0) {
			Sleep(4000);
			if (You->hp <= 0 || You->mana <= 0) {
				break;
			}
			printf("\n StoneBlock hp: %lf     StoneBlock mana: %d\n Your HP: %lf     Your mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				StoneBlock->hp, StoneBlock->mana, You->hp, You->mana, You->skill1, You->skill2, You->skill3);
			if (You->level >= 5) {
				printf(" Skill 4: %s\n", You->skill4);
			}
			scanf_s("%d", &spell);

			//hod monster
			if (StoneBlock->block > 0) {
				printf("\n StoneBlock in the block.\n");
				StoneBlock->block -= 1;
			}
			if (StoneBlock->hp > 0) {
				printf("\n StoneBlock attacked hero and causes damage = 75.\n");
				You->hp = You->hp - (1 - You->resistance) * 75;
			}

			//hod hero
			switch (gerou) {
			case 1:
				if (spell == 1) {
					You->mana -= 30;
					damage = 0;
					StoneBlock->block = 2;
				}
				if (spell == 2) {
					You->mana -= 75;
					damage = 100;
				}
				if (spell == 3) {
					You->mana -= 50;
					damage = 50;
					StoneBlock->block = 1;
				}
				if (spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			case 2:
				if (spell == 1) {
					You->mana -= 20;
					damage = 0;
					You->resistance += 0.05;
				}
				if (spell == 2) {
					You->mana -= 85;
					damage = 100;
				}
				if (spell == 3) {
					You->mana -= 60;
					damage = 60;
					StoneBlock->resistance -= 0.02;
				}
				if (spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
				break;
			case 3:
				if (spell == 1) {
					You->mana -= 20;
					damage = 0;
					You->hp += 50;
				}
				if (spell == 2) {
					You->mana -= 25;
					damage = 30;
					StoneBlock->block = 1;
				}
				if (spell == 3) {
					You->mana -= 100;
					damage = 200;
				}
				if (spell == 4) {
					damage = 0;
					You->mana -= 150;
					You->hp += 250;
				}
			}
			StoneBlock->hp = StoneBlock->hp - (1 - StoneBlock->resistance) * damage;
			You->hp = You->hp + You->vamp * damage;
		}

		//awards
		printf("\n\n The StoneBlock died, you get a little experience and mana (+%d xp; +50 mana).\n", StoneBlock->xp);
		You->mana += 50;
		You->xp += StoneBlock->xp;
		You->hp += 150;
		break;
	}
}

int main() {
	srand(time(NULL));

	int a = 0;
	int gerou = 0;
	int spell = 0;
	int spell1 = 0;
	int damage = 0;
	int quest = 0;
	int S = 0;
	int k = 0;
	int kogo = 0;
	int gem = 0;
	int rndm;
	int hp = 0;
	int mana = 0;
	int resistance = 0;

	//levels:
	const levels[27] = { 0, 20, 30, 80, 80, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 850, 900, 950, 1000 , 1000, 1000, 1000, 1000, 1000};

	//quests
	char* quests[5] = { "Kill the bear that has captured the extreme part of the city. Reward = Vampir sword. Recommended level = 2.\n",
						"Catch the thief who is hiding in the maze. Reward = magic mantle. Recommended level = 3.\n",
						"Find a lost child, he disappeared near the well. Reward = *new skill*. Recommended level = 4.\n",
						"Find gems in mines. Reward = heavenly armor. Recommended level = 5.\n",
						"Win the tournament. Reward = boundless power. Recommended level = 6.\n" };

	//mine
	char* gems[6] = {"Gem","Iron","Dirt","Stone","Slag", "Monster"};

	//You
	struct heroes You;
	You.name = "";
	You.hp = 1;
	You.mana = 0;
	You.resistance = 0;
	You.xp = 0;
	You.level = 1;
	You.vamp = 0;


	//Cobalt
	struct heroes Cobalt;
	Cobalt.name = "Cobalt";
	Cobalt.hp = 200;
	Cobalt.resistance = 0.2;
	Cobalt.mana = 300;
	Cobalt.element = "Terra+Aqua+Ice";
	Cobalt.skill1 = "Ice block. Erects an ice wall that blocks the enemy's attacks 2 moves. Damage = 0. Mana = 30.\n";
	Cobalt.skill2 = "Aqua shot. Launches a balloon created from underground waters at the enemy. Damage = 100. Mana = 75.\n";
	Cobalt.skill3 = "Slowing down. Slows down the enemy by dealing him side damage. Damage = 50. Mana = 25.\n";

	//Volt
	struct heroes Volt;
	Volt.name = "Volt";
	Volt.hp = 290;
	Volt.resistance = 0.15;
	Volt.mana = 256;
	Volt.element = "Electricity";
	Volt.skill1 = "Super speed. Gives the hero super speed, increasing his resistance. Damage = 0. Mana = 20.\n";
	Volt.skill2 = "Discharge. Calls to the sky, striking the enemy with lightning. Damage = 100. Mana = 85.\n";
	Volt.skill3 = "Quick strikes. Deals a series of quick blows to the enemy. Damage = 10 * 6. Mana = 25.\n";

	//Pyrus
	struct heroes Pyrus;
	Pyrus.name = "Pyrus";
	Pyrus.hp = 440;
	Pyrus.resistance = 0.1;
	Pyrus.mana = 120;
	Pyrus.element = "Ignis";
	Pyrus.skill1 = "Fire Armor. Creates armor on the hero's body that increases HP. Damage = 0. Mana = 20.\n";
	Pyrus.skill2 = "Fire Tornado. Creates a vortex that deals damage and throws the enemy away. Damage = 30. Mana = 25.\n";
	Pyrus.skill3 = "Lava fist. Fills his hand with lava and strikes at the enemy. Damage = 200. Mana = 100.\n";

	//Spider
	struct monsters Spider;
	Spider.name = "Spider";
	Spider.hp = 160;
	Spider.resistance = 0;
	Spider.mana = 0;
	Spider.xp = 20;
	Spider.damager = 40;
	Spider.block = 0;

	//Bear
	struct monsters Bear;
	Bear.name = "Bear";
	Bear.hp = 410;
	Bear.resistance = 0.03;
	Bear.mana = 0;
	Bear.xp = 40;
	Bear.damager = 70;
	Bear.block = 2;
	
	//Amphibian1
	struct monsters Amphibian1;
	Amphibian1.name = "Amphibian";
	Amphibian1.hp = 300;
	Amphibian1.resistance = 0.2;
	Amphibian1.mana = 100;
	Amphibian1.xp = 35;
	Amphibian1.damager = 60;
	Amphibian1.block = 0;

	//Amphibian2
	struct monsters Amphibian2;
	Amphibian2.name = "Amphibian";
	Amphibian2.hp = 300;
	Amphibian2.resistance = 0.2;
	Amphibian2.mana = 100;
	Amphibian2.xp = 35;
	Amphibian2.damager = 60;
	Amphibian2.block = 0;

	//Stone block
	struct monsters StoneBlock;
	StoneBlock.name = "Stone block";
	StoneBlock.hp = 500;
	StoneBlock.resistance = 0.5;
	StoneBlock.mana = 50;
	StoneBlock.xp = 90;
	StoneBlock.damager = 75;
	StoneBlock.block = 0;

	//For tournament

	//Vora
	struct heroes Vora;
	Vora.name = "Vora";
	Vora.hp = 2200;
	Vora.resistance = 0;
	Vora.mana = 6000;
	Vora.level = 20;
	Vora.block = 0;
	Vora.vamp = 0.1;
	Vora.skill1 = "Jump up and slash down, becoming Immune. Damage = 500. Mana = 200.";
	Vora.skill2 = "Deals 200 damage on hit and an additional 400 damage over time. Damage = 200. Mana = 0.";
	Vora.skill3 = "Manifest your will, propelling yourself towards your target with a tendril. Damage = 0. Mana = 50.";

	//Vaty
	struct heroes Vaty;
	Vaty.name = "Vaty";
	Vaty.hp = 2500;
	Vaty.resistance = 0;
	Vaty.mana = 2000;
	Vaty.level = 21;
	Vaty.block = 0;
	Vaty.skill1 = "Launch 3 Kunai in an arc from your hands, dealing 280 damage per Kunai. Damage = 280. Mana = 0.";
	Vaty.skill2 = "Teleport near your target, dealing damage in a certain area upon arrival. With a certain chance, the damage is increased. Damage = 90(333). Mana = 50";
	Vaty.skill3 = "Quickly dash in the direction of your movement input. Damage = 0. Mana = 30";

	//Rei
	struct heroes Rei;
	Rei.name = "Rei";
	Rei.hp = 2000;
	Rei.resistance = 0;
	Rei.mana = 5000;
	Rei.level = 17;
	Rei.block = 0;
	Rei.skill1 = "Healing for 600 per bounce. Damage = 0. Mana = 100.";
	Rei.skill2 = "Unleash magical energy from your hands, dealing 450 damage every 0.7s. Damage = 450. Mana = 0.";
	Rei.skill3 = "Reduce the maximum amount of damage you can take to 275 per instant of damage and increase your Movement Speed and Jump Height for 3s. Damage = 0. Mana = 100.";

	//Drogos
	struct heroes Drogos;
	Drogos.name = "Drogos";
	Drogos.hp = 1500;
	Drogos.resistance = 0.2;
	Drogos.mana = 3000;
	Drogos.level = 16;
	Drogos.block = 0;
	Drogos.skill1 = "Jet upwards into the air. Damage = 0. Mana = 100.";
	Drogos.skill2 = "Fire explosive rockets every 0.85s to decimate an area, dealing 850 damage. Damage = 850. Mana = 0.";
	Drogos.skill3 = "Spit a flammable orb. Damage = 300. Mana = 200.";

	//Vivian
	struct heroes Vivian;
	Vivian.name = "Vivian";
	Vivian.hp = 1200;
	Vivian.resistance = 0;
	Vivian.mana = 3000;
	Vivian.level = 6;
	Vivian.block = 0;
	Vivian.skill1 = "A versatile light machine gun that deals 165 damage every 0.14s. Damage = 165. Mana = 0.";
	Vivian.skill2 = "Project a shield in front of your gun. Damage = 0. Mana = 100.";
	Vivian.skill3 = "Summon 2 drones that fire energy blasts where you are shooting every 1s, dealing 150 damage. Damage = 150. Mana = 150.";

	//In
	struct heroes In;
	In.name = "In";
	In.hp = 1300;
	In.resistance = 0;
	In.mana = 6000;
	In.level = 8;
	In.block = 0;
	In.skill1 = "Fire a burst of energy every 0.5s from your mirror over a short period of time, hitting 5 times over 0.2s for 90 damage per shot. Damage = 200. Mana = 0.";
	In.skill2 = "Create a lifelike illusion that heals for 450 every 1.6s. Damage = 0. Mana = 200.";
	In.skill3 = "Shatter your mirror, restoring 600 health. Damage = 0. Mana = 300.";

	//Znak
	struct heroes Znak;
	Znak.name = "Znak";
	Znak.hp = 1300;
	Znak.resistance = 0.05;
	Znak.mana = 2000;
	Znak.level = 10;
	Znak.block = 0;
	Znak.skill1 = "A hybrid weapon that deals 500 damage every 0.3s. Damage = 500. Mana = 0.";
	Znak.skill2 = "Place a damaging pool of poison that expands over time and deals 60 damage every 0.2s. Damage = 60. Mana = 50.";
	Znak.skill3 = "Alter gravity and lift targeted enemy into the airbefore pushing them away and dealing 400 damage. Damage = 400. Mana = 200.";

	//Han
	struct heroes Han;
	Han.name = "Han";
	Han.hp = 2000;
	Han.resistance = 0.3;
	Han.mana = 6000;
	Han.level = 15;
	Han.block = 1;
	Han.skill1 = "An automatic heavy repeater that riddles enemies with high-caliber bullets, dealing 210 damage every 0.26s. Damage = 210. Mana = 0.";
	Han.skill2 = "Activate a shield that blocks up. Damage = 0. Mana = 200.";
	Han.skill3 = "Release a battle-shout, becoming immune and healing yourself. Damage = 0. Mana = 300.";

	//Inara
	struct heroes Inara;
	Inara.name = "Inara";
	Inara.hp = 2000;
	Inara.resistance = 0.3;
	Inara.mana = 3000;
	Inara.level = 13;
	Inara.block = 1;
	Inara.skill1 = "Fire a burst of 3 sharp stone projectiles across the battlefield every 1.25s that each do 225 damage. Damage = 675. Mana = 0.";
	Inara.skill2 = "Deploy a stone wall from the ground to hinder enemies and protect allies.. Damage = 0. Mana = 200.";
	Inara.skill3 = "Deploy an obelisk that channels nature's wrath in an area to slow and deal 150 damage. Damage = 150. Mana = 75.";

	//pobediteli
	struct heroes pobeda11;
	struct heroes pobeda12;
	struct heroes pobeda13;
	struct heroes pobeda14;
	struct heroes pobeda21;
	struct heroes pobeda22;

	printf(" Hello dear friend! You got into my game. To begin with, choose a hero for whom you will begin your transformations.\n");

	while (gerou != 1 || gerou != 2 || gerou != 3) {
		printf(" 3 heroes are presented to your attention: 1 - Cobalt, 2 - Volt, 3 - Pyrus.\n");
		printf(" Write the number of the selected hero. To find out information about each hero write: For Cobalt - 11; For Volt - 21; For Pyrus - 31.\n");
		scanf_s("%d", &gerou);
		switch (gerou) {
		case 1:
			printf("\n Your hero: Cobalt\n \n");
			You.name = Cobalt.name;
			You.hp = Cobalt.hp;
			You.resistance = Cobalt.resistance;
			You.mana = Cobalt.mana;
			You.element = Cobalt.element;
			You.skill1 = Cobalt.skill1;;
			You.skill2 = Cobalt.skill2;
			You.skill3 = Cobalt.skill3;
			break;
		case 2:
			printf("\n Your hero: Volt\n \n");
			You.name = Volt.name;
			You.hp = Volt.hp;
			You.resistance = Volt.resistance;
			You.mana = Volt.mana;
			You.element = Volt.element;
			You.skill1 = Volt.skill1;;
			You.skill2 = Volt.skill2;
			You.skill3 = Volt.skill3;
			break;
		case 3:
			printf("\n Your hero: Pyrus\n \n");
			You.name = Pyrus.name;
			You.hp = Pyrus.hp;
			You.resistance = Pyrus.resistance;
			You.mana = Pyrus.mana;
			You.element = Pyrus.element;
			You.skill1 = Pyrus.skill1;;
			You.skill2 = Pyrus.skill2;
			You.skill3 = Pyrus.skill3;
			break;
		case 11:
			printf(" Info about Cobalt:\n Name: %s\n Hp: %lf\n Resist: %lf\n Mana: %d\n Main element: %s\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				Cobalt.name, Cobalt.hp, Cobalt.resistance, Cobalt.mana, Cobalt.element, Cobalt.skill1, Cobalt.skill2, Cobalt.skill3);
			break;
		case 21:
			printf(" Info about Volt:\n Name: %s\n Hp: %lf\n Resist: %lf\n Mana: %d\n Main element: %s\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				Volt.name, Volt.hp, Volt.resistance, Volt.mana, Volt.element, Volt.skill1, Volt.skill2, Volt.skill3);
			break;
		case 31:
			printf(" Info about Pyrus:\n Name: %s\n Hp: %lf\n Resist: %lf\n Mana: %d\n Main element: %s\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				Pyrus.name, Pyrus.hp, Pyrus.resistance, Pyrus.mana, Pyrus.element, Pyrus.skill1, Pyrus.skill2, Pyrus.skill3);
			break;
		default: printf(" Problems have occurred, enter the correct number\n");
		}
	}

	// hero selected

	Sleep(2000);

	//Rules
	printf("\n\n You chose a hero. Now go on an adventure, you will come across monsters on your way, when you kill them, you get a little mana and experience. \n");
	printf(" REMEMBER, if you run out of health or mana, you will die. With the accumulation of a sufficient amount of experience, you will increase your level and be able to level up.\n");
	printf(" When choosing spells, write number of the spell.\n");
	printf(" Total levels: 27.\n");
	Sleep(10000);

	//start history
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 1													");
	printf("\n								Start history													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	shrift(12, 16);

	printf("\n You live in the city of Asterisk. You are an ordinary court magician who went to the forest to collect herbs.\n");
	printf(" While you're picking herbs, you hear strange noises, turn around and see that it's a demonic spider. ");
	printf(" He's slowly crawling towards you, but you don't have much time, \n THINK ABOUT WHAT TO DO...\n");
	Sleep(8000);

	kogo = 1;
	bitva(levels, gerou, kogo, &You, &Spider, &Bear, &Amphibian1, &StoneBlock);

	if (You.hp <= 0 || You.mana <= 0) {
		return printf("\n You dead. Game over.\n");
	}

	Sleep(2000);
	printf(" For completing the quest , you get a reward Vampir Sword. He'll give you a little vampirism.\n\n");
	You.vamp = 0.1;
	Sleep(2000);

	lvl(levels, &You);

	//Quests
	Sleep(6000);
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 2													");
	printf("\n								Quests													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	shrift(12, 16);

	printf(" Congratulations, you defeated your first monster, you picked up herbs and went back to the city to rest, restore mana and health.\n");
	Sleep(4000);
	You.hp += 100;
	You.mana += 90;
	printf(" You spent a couple of hours in a local tavern, recovered.");
	printf(" Now you decide to take a task on which you can earn good money. You approach the task stand.\n");
	printf(" You see several tasks, choose which one you want to go to: \n\n");
	Sleep(3000);
	while (quest != 1) {
		printf("\n Your level: %d", You.level);
		printf("\n 1. %s", quests[0]);
		printf(" 2. %s", quests[1]);
		printf(" 3. %s", quests[2]);
		scanf_s("%d", &quest);

		switch (quest) {
		case 1:
			printf("\n You have chosen a quest to kill a bear, go to it.\n\n");
			Sleep(4000);
			printf(" You go to the extreme part of the city. There you see a bear that you have to kill, It doesn't seem so weak... \n Be careful");
			printf("\n But he very slowly.\n");

			kogo = 2;
			bitva(levels, gerou, kogo, &You, &Spider, &Bear, &Amphibian1, &StoneBlock);

			if (You.hp <= 0 || You.mana <= 0) {
				return printf("\n You dead. Game over.\n");
			}

			Sleep(2000);
			printf(" For completing the quest , you get a reward Magic mantle. It will increase your mana a little.\n\n");
			You.mana += 200;
			Sleep(2000);

			lvl(levels, &You);

			break;
		default: printf(" Unavailable, a higher level is needed\n\n");
		}
	}

	//Bandit
	Sleep(6000);
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 3													");
	printf("\n								Bandit													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	shrift(12, 16);

	printf(" The beast is no more, the task is completed what do you choose to do next?\n");
	Sleep(2000);
	printf(" 1. Go take a break. \n 2. Go get a new assignment.\n");
	scanf_s("%d", &quest);
	switch (quest) {
	case 1:
		printf(" While resting, you miss a day and miss 1 task, but you restore health and mana.\n");
		You.hp += 70;
		You.mana += 200;
		printf(" After the rest, you go to the tavern.\n");
		break;
	case 2:
		printf(" You go to the tavern and you can take a new task\n");
		break;
	}
	Sleep(4000);
	printf(" Tasks have been updated in the Tavern, Choose what you like.\n");
	quest = 0;
	while (quest != 2) {
		printf("\n Your level: %d", You.level);
		printf("\n 1. %s", quests[3]);
		printf(" 2. %s", quests[1]);
		printf(" 3. %s", quests[2]);
		scanf_s("%d", &quest);
		switch (quest) {
		case 2:
			printf("\n You have chosen a quest hiding in the maze, go to it, FASTER, FASTER!\n\n");
			k = 99;
			goto maze;
			break;
		default:
			printf(" Unavailable, a higher level is needed\n\n");
		}
	}
maze:
	printf(" Point Y - its you V - bandit. Find the length of the shortest path to the criminal. If you answer correctly 3 times, the task will be counted as completed.\n\n");
	Sleep(6000);
	k = 0;
	while (S != 11) {
		char maze1[5][10] = { {'Y', '1', '1', '0', '0', '0', '0', 'V', '0', '0'},
							  {'1', '0', '1', '1', '1', '0', '1', '1', '0', '0'},
							  {'1', '0', '0', '0', '1', '1', '1', '0', '1', '1'},
							  {'1', '1', '0', '1', '1', '1', '0', '0', '0', '1'},
							  {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1'},
		};
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 10; j++) {
				printf(" %c ", maze1[i][j]);
			}
			printf("\n");
		}
		printf(" Which is the smallest path?\n");
		scanf_s("%d", &S);
		if (S != 11) {
			printf(" You are wrong, try again\n");
			k += 1;
		}
		if (k == 2) {
			return printf(" You loose. Game over.");
		}
	}
	Sleep(2000);
	k = 0;
	S = 0;
	while (S != 11) {
		printf("\n\n Well, let 1 time you are lucky, let's look further\n");
		char maze2[5][10] = { {'1', '1', '1', '0', '0', '0', '0', '1', '0', '0'},
							  {'1', '0', '1', '1', '1', '0', '1', '1', '0', '0'},
							  {'1', '0', 'V', '0', '1', '1', '1', '0', '1', '1'},
							  {'1', '1', '0', '1', '1', '1', '0', '0', '0', '1'},
							  {'1', '1', '1', '1', '0', '1', '1', '1', '1', 'Y'},
		};
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 10; j++) {
				printf(" %c ", maze2[i][j]);
			}
			printf("\n");
		}
		printf(" Which is the smallest path?\n");
		scanf_s("%d", &S);
		if (S != 11) {
			printf(" You are wrong, try again\n");
			k += 1;
		}
		if (k == 2) {
			return printf(" You loose. Game over.");
		}
	}
	Sleep(2000);
	k = 0;
	S = 0;
	while (S != 16) {
		printf("\n\n Well, let 2 time you are lucky, go one more\n");
		char maze3[5][10] = { {'1', '1', '1', '0', '0', '0', '0', '1', '0', '0'},
							  {'1', 'Y', '1', '1', '1', '0', '1', '1', '0', '0'},
							  {'1', '0', '1', '0', '1', '1', '1', '0', 'V', '1'},
							  {'1', '1', '0', '1', '1', '1', '0', '0', '0', '1'},
							  {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1'},
		};
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 10; j++) {
				printf(" %c ", maze3[i][j]);
			}
			printf("\n");
		}
		printf(" Which is the smallest path?\n");
		scanf_s("%d", &S);
		if (S != 16) {
			printf(" You are wrong, LAST CHANCE\n");
			k += 1;
		}
		if (k == 2) {
			return printf(" You loose. Game over.");
		}
	}
	Sleep(2000);
	printf("\n You did well, you were able to catch the thief, your reward: a magic mantle that will increase your mana.\n You're raising your level.\n");
	You.mana += 300;
	You.level += 1;

	//Child
	Sleep(6000);
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 4													");
	printf("\n								Child													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	shrift(12, 16);

	printf(" After catching the thief, you decide to take a little rest.\n");
	printf(" After 2 hours, you decide to look into the tavern again, because someone said on the street that there were new tasks.\n");
	printf(" Tasks have been updated in the Tavern, Choose what you like.\n");
	while (quest != 3) {
		printf("\n Your level: %d", You.level);
		printf("\n 1. %s", quests[3]);
		printf(" 2. %s", quests[4]);
		printf(" 3. %s", quests[2]);
		scanf_s("%d", &quest);
		switch (quest) {
		case 3:
			printf("\n You have to save the child who was last seen near the well.\n\n");
			break;
		default:
			printf(" Unavailable, a higher level is needed\n\n");
		}
	}

	printf(" Your task: to save a child who fell into a well, first you have to go and get yourself a potion to breathe underwater.\n");
	Sleep(3000);
	printf(" You go to the nearest potion maker and buy a potion from him.\n");
	Sleep(3000);
	printf(" You approach the well, drink a potion and dive into the water. As you swim deeper, you notice a cave. We need to go there...\n");
	Sleep(3000);
	printf(" You see two caves, Hordes of amphibians behind one, fire behind the other.\n");
	printf(" What will you choose?(1 or 2)\n");
	scanf_s("%d", &k);
	switch (k) {
	case 1:
		printf(" Slowly entering this cave, you see an amphibian and decide to go to another one after all.\n");
	case 2:
		printf(" There is a fire behind the second door, you decide to go through it after losing some health.\n");
	}
	You.hp -= 55;
	Sleep(5000);
	printf(" To get to the child you need to pass the maze without running into amphibians.\n");
	Sleep(4000);
	printf("\n In the maze, Y is you, A is amphibians, C is a child. Specify the length of the safest route (the route is safe if there is no amphibian in any neighboring cage).\n");
	Sleep(4000);
	char mazechild[5][10] = { {'Y', '1', 'A', 'A', '0', '0', '0', 'A', '0', 'C'},
						  {'1', '1', 'A', '1', '1', '1', '1', '1', '0', '1'},
						  {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
						  {'1', '1', '0', '1', '0', 'A', '0', '1', '0', '1'},
						  {'0', '1', '1', '1', '0', '1', '1', 'A', '1', '1'},
	};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			printf(" %c ", mazechild[i][j]);
		}
		printf("\n");
	}
	while (k != 19) {
		scanf_s("%d", &k);
		if (k != 19) {
			printf(" Wait, you're going to die, try another route.\n");
		}
	}
	printf(" You found and took the boy, returning back to you to meet the guards.\n\n");

	//bitva
	while ((Amphibian1.hp > 0 || Amphibian2.hp > 0) && You.hp > 0) {
		Sleep(4000);
		if (You.hp <= 0) {
			return printf("\n You dead.");
		}
		if (Amphibian1.hp > 0 && Amphibian2.hp > 0) {
			printf("\n Amphibian1 hp: %lf     Amphibian1 mana: %d\n Amphibian2 hp: %lf     Amphibian2 mana: %d\n Your HP: %lf     Your mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				Amphibian1.hp, Amphibian1.mana, Amphibian2.hp, Amphibian2.mana, You.hp, You.mana, You.skill1, You.skill2, You.skill3);
			scanf_s("%d", &spell);
			printf(" Which enemy do you want to attack (1 or 2)?\n");
			scanf_s("%d", &kogo);
		}
		if (Amphibian1.hp < 0) {
			printf("\n Amphibian1 hp: DEAD     Amphibian1 mana: DEAD\n Amphibian2 hp: %lf     Amphibian2 mana: %d\n Your HP: %lf     Your mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				Amphibian2.hp, Amphibian2.mana, You.hp, You.mana, You.skill1, You.skill2, You.skill3);
			scanf_s("%d", &spell);
			printf(" Which enemy do you want to attack (1 or 2)?\n");
			scanf_s("%d", &kogo);
		}
		if (Amphibian2.hp < 0) {
			printf("\n Amphibian1 hp: %lf      Amphibian1 mana: %d\n Amphibian2 hp: DEAD    Amphibian2 mana: DEAD\n Your HP: %lf     Your mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
				Amphibian1.hp, Amphibian1.mana, You.hp, You.mana, You.skill1, You.skill2, You.skill3);
			scanf_s("%d", &spell);
			printf(" Which enemy do you want to attack (1 or 2)?\n");
			scanf_s("%d", &kogo);
		}
		//hod monster
		if (Amphibian1.block <= 0 && Amphibian1.hp > 0) {
			printf("\n Amphibian1 attacked hero and causes damage = %d\n", Amphibian1.damager);
			You.hp = You.hp - (1 - You.resistance) * Amphibian1.damager;
			You.hp = You.hp + Amphibian1.damager * You.vamp;
		}
		if (Amphibian2.block <= 0 && Amphibian2.hp > 0) {
			printf(" Amphibian2 attacked hero and causes damage = %d\n", Amphibian2.damager);
			You.hp = You.hp - (1 - You.resistance) * Amphibian2.damager;
			You.hp = You.hp + Amphibian2.damager * You.vamp;
		}
		if (Amphibian1.block > 0) {
			printf("\n Amphibian1 in the block.\n");
			Amphibian1.block -= 1;
		}
		if (Amphibian2.block > 0) {
			printf(" Amphibian2 in the block\n");
			Amphibian2.block -= 1;
		}

		//hod hero
		switch (gerou) {
		case 1:
			if (spell == 1) {
				You.mana -= 30;
				damage = 0;
				if (kogo == 1) {
					Amphibian1.block = 2;
				}
				if (kogo == 2) {
					Amphibian2.block = 2;
				}
			}
			if (spell == 2) {
				You.mana -= 75;
				damage = 100;
				}
			if (spell == 3) {
				You.mana -= 25;
				damage = 50;
			}
			if (kogo == 1) {
				Amphibian1.block = 1;
			}
			if (kogo == 2) {
				Amphibian2.block = 1;
			}
			if (You.mana <= 0) {
				printf(" Mana is over");
				return printf("\n You dead");
			}
			break;
		case 2:
			if (spell == 1) {
				You.mana -= 20;
				damage = 0;
				You.resistance += 0.05;
			}
			if (spell == 2) {
				You.mana -= 85;
				damage = 100;
			}
			if (spell == 3) {
				You.mana -= 25;
				damage = 60;
				Amphibian1.resistance -= 0.02;
				Amphibian2.resistance -= 0.02;
			}
			if (You.mana <= 0) {
				printf(" Mana is over");
				return printf("\n You dead");
			}
			break;
		case 3:
			if (spell == 1) {
				You.mana -= 20;
				damage = 0;
				You.hp += 50;
			}
			if (spell == 2) {
				You.mana -= 25;
				damage = 30;
				if (kogo == 1) {
					Amphibian1.block = 1;
				}
				if (kogo == 2) {
					Amphibian2.block = 1;
				}
			}
			if (spell == 3) {
				You.mana -= 100;
				damage = 200;
			}
			if (You.mana <= 0) {
				printf(" Mana is over");
				return printf("\n You dead");
			}
			break;
		}
		if (kogo == 1) {
			Amphibian1.hp = Amphibian1.hp - (1 - Amphibian1.resistance) * damage;
			You.hp = You.hp + damage * You.vamp;
		}
		else if (kogo == 2) {
			Amphibian2.hp = Amphibian2.hp - (1 - Amphibian2.resistance) * damage;
			You.hp = You.hp + damage * You.vamp;
		}
	}

	//awards
	printf("\n\n The Amphibians died, you get a little experience and mana (+%d xp; +50 mana)\n", Amphibian1.xp*2);
	printf(" From the tavern as a reward you get new skill.\n");
	printf(" New skill: healing, at any time you can heal yourself a decent amount of hp and freeze the enemy for a short time.\n");
	You.mana += 50;
	You.xp += 2*Amphibian1.xp;
	You.skill4 = " Healing. At any time you can heal yourself a decent amount of hp and freeze the enemy for a short time. Damage = 0. Mana = 150.\n";

	lvl(levels, &You);

	//Mines
	Sleep(6000);
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 5													");
	printf("\n								Mines													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	shrift(12, 16);

	printf(" After catching the thief, you decide to take a little rest.\n");
	printf(" After 2 hours, you decide to look into the tavern again, because someone said on the street that there were new tasks.\n");
	printf(" Tasks have been updated in the Tavern, Choose what you like.\n");
	while (quest != 1) {
		printf("\n Your level: %d", You.level);
		printf("\n 1. %s", quests[3]);
		printf(" 2. %s", quests[4]);
		printf(" 3. Empty.\n");
		scanf_s("%d", &quest);
		switch (quest) {
		case 1:
			printf("\n Goal: to find a rare gem. Forward.\n\n");
			k = 99;
			break;
		default:
			printf(" Unavailable, a higher level is needed.\n\n");
		}
	}

	printf(" You go to the mine, they give you a pickaxe, you start digging. But keep in mind that with some chance a monster can spawn.\n");
	
	//in mines
	while (gem != 1) {
		k = 0;
		while (k != 1) {
			printf("\n What will you choose : \n 1. Dig.\n 2. Away.\n");
			scanf_s("%d", &k);
			if (k == 2) {
				printf("\n\n You haven't found the gem yet, they'll send you.\n\n");
			}
		}

		printf("\n\n Loading");
		Sleep(1000);
		printf(" .");
		Sleep(1000);
		printf(" .");
		Sleep(1000);
		printf(" .\n");

		rndm = rand() % 100;
		if (rndm >= 0 && rndm <= 12) {
			printf(" You found Gem.\n\n");
			gem = 1;
		}
		else if (rndm >= 13 && rndm <= 30) {
			printf(" You found Iron. Try again. You get some mana.\n\n");
			You.mana += 75;
		}
		else if (rndm >= 31 && rndm <= 50) {
			printf(" You found Dirt. Try again.\n\n");
		}
		else if (rndm >= 51 && rndm <=60 ) {
			printf(" You found Stone. Try again.\n\n");
		}
		else if (rndm >= 61 && rndm <= 84) {
			printf(" You found Slag. Try again.\n\n");
		}
		else if (rndm >= 85 && rndm <= 100) {
			printf(" You found Monster. Kill him.\n\n");
			Sleep(2000);
			kogo = 4;
			bitva(levels, gerou, kogo, &You, &Spider, &Bear, &Amphibian1, &StoneBlock);

			if (You.hp <= 0 || You.mana <= 0) {
				return printf("\n You dead. Game over.\n");
			}

			lvl(levels, &You);
		}
	}

	Sleep(2000);
	printf(" You have found a gem and get heavenly armor. It will increase your health and resist.\n");
	You.hp += 300;
	You.resistance += 0.2;
	Sleep(2000);

	if (You.level < 5) {
		printf(" For the successful completion of the task, you get an additional level.\n");
		You.level += 1;

	}

	printf(" There's one last task left in the tavern, hurry up before anyone picks it up.\n");

	//Tournament
	Sleep(6000);
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 6													");
	printf("\n								Tournament													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(3000);
	shrift(12, 16);

save:
	Sleep(2000);
	printf(" You have a tournament ahead of you, it won't hurt to pump up. Select an item from the menu.\n");
	while (k != 1 || k != 3) {
		menu();
		k = 0;
		scanf_s("%d", &k);
		switch (k) {
			case 1:
				Sleep(1000);
				goto tournament;
			  break;
		case 2:
			printf(" Choose who you want to find out information about. \n");
			printf(" 1. Vora.\n 2. Vaty.\n 3. Rei.\n 4. Drogos.\n 5. Vivian.\n 6. In.\n 7. Znak.\n 8. Han.\n 9. Inara.\n");
			scanf_f("%d", &kogo);
			switch (kogo) {
			case 1:
				printf(" Name: %s\n Level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
					Vora.name, Vora.level, Vora.hp, Vora.mana, Vora.resistance, Vora.skill1, Vora.skill2, Vora.skill3);
				break;
			case 2:
				printf(" Name: %s\n Level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
					Vaty.name, Vaty.level, Vaty.hp, Vaty.mana, Vaty.resistance, Vaty.skill1, Vaty.skill2, Vaty.skill3);
				break;
			case 3:
				printf(" Name: %s\n Level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
					Rei.name, Rei.level, Rei.hp, Rei.mana, Rei.resistance, Rei.skill1, Rei.skill2, Rei.skill3);
				break;
			case 4:
				printf(" Name: %s\n Level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
					Drogos.name, Drogos.level, Drogos.hp, Drogos.mana, Drogos.resistance, Drogos.skill1, Drogos.skill2, Drogos.skill3);
				break;
			case 5:
				printf(" Name: %s\n Level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
					Vivian.name, Vivian.level, Vivian.hp, Vivian.mana, Vivian.resistance, Vivian.skill1, Vivian.skill2, Vivian.skill3);
				break;
			case 6:
				printf(" Name: %s\n Level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
					In.name, In.level, In.hp, In.mana, In.resistance, In.skill1, In.skill2, In.skill3);
				break;
			case 7:
				printf(" Name: %s\n Level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
					Znak.name, Znak.level, Znak.hp, Znak.mana, Znak.resistance, Znak.skill1, Znak.skill2, Znak.skill3);
				break;
			case 8:
				printf(" Name: %s\n Level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
					Han.name, Han.level, Han.hp, Han.mana, Han.resistance, Han.skill1, Han.skill2, Han.skill3);
				break;
			case 9:
				printf(" Name: %s\n Level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n",
					Inara.name, Inara.level, Inara.hp, Inara.mana, Inara.resistance, Inara.skill1, Inara.skill2, Inara.skill3);
				break;
			}
		case 3:
			Sleep(1000);
			printf(" Name: %s\n Level: %d\n Xp: %d\n Next level: %d\n Hp: %lf\n Mana: %d\n Resistance: %lf\n Element: %s\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n Skill 4: %s \n",
				You.name, You.level, You.xp, levels[You.level]-You.xp, You.hp, You.mana, You.resistance, You.element, You.skill1, You.skill2, You.skill3, You.skill4);
				break;
		case 4:
			Sleep(1000);
			if (You.level == 27) {
				printf("\n You have reached the maximum level.\n\n");
				goto save;
			}
			printf(" Choose who to train on:\n");
			printf(" 1. Spider.\n 2. Bear.\n 3. Amphibian.\n 4. StoneBlock.\n");
			kogo = 0;
			scanf_s("%d", &kogo);
			Sleep(1000);
			bitva(levels, gerou, kogo, &You, &Spider, &Bear, &Amphibian1, &StoneBlock);
			if (You.hp <= 0 || You.mana <= 0) {
				printf(" Mana or hp is over.");
				printf("\n You are defeated, come back and recover a little.\n");
				goto save;
			}
			break;
		case 5:
			Sleep(1000);
			printf("\n\n Sleep ");
			Sleep(1000);
			k = 0;
			while (k != 20) {
				printf(". ");
				Sleep(1000);
				k += 1;
				if (k == 10) {
					printf("\n Zzz. ");
				}
			}
			printf("\n\n");
			You.hp += 75;
			You.mana += 75;
		}
	}
tournament:

	hp = You.hp;
	mana = You.mana;
	resistance = You.resistance;

	Sleep(3000);
	printf("\n\n\n List of participants.\n");
	printf(" 1. Vora(level: %d )\n 2. Vaty(level: %d )\n 3. Rei(level: %d )\n 4. Drogos(level: %d )\n 5. Vivian(level: %d )\n 6. In(level: %d )\n 7. Znak(level: %d )\n 8. Han(level: %d )\n 9. Inara(level: %d )\n 10. %s(level: %d )", 
		Vora.level, Vaty.level, Rei.level, Drogos.level, Vivian.level, In.level, Znak.level, Han.level, Inara.level, You.name, You.level);
	
	Sleep(3000);
	printf("\n\n					1 tour\n\n");
	printf(" 1. Vora(20) --- Rei(17)\n");
	printf(" 2. Vaty(21) --- Drogos(16)\n");
	printf(" 3. Han(15) --- Inara(13)\n");
	printf(" 4. In(8) --- Znak(10)\n");
	printf(" 5. %s(%d) --- Vivian(6)\n\n", You.name, You.level);
	Sleep(3000);

	printf("\n The horizontal bar has started, we welcome the first participants to the arena.\n Happy hunger games and may the odds be ever in your favor. \n\n");

	//1 tour
	Sleep(6000);
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 7													");
	printf("\n								1 tour													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	shrift(12, 16);

	printf("\n The following are invited to the arena Vora and Rei.\n\n");
	
	Sleep(5000);
	//bitva 11  (Vora x Rei)
	while (Vora.hp > 0 && Rei.hp > 0 && Vora.mana >= 0 && Rei.mana >= 0) {
		Sleep(4000);
		printf("\n Vora hp: %lf     Vora mana: %d\n Rei hp: %lf     Rei mana: %d\n\n\n",
			Vora.hp, Vora.mana, Rei.hp, Rei.mana);
		Sleep(3000);
		spell = rand() % 3;
		spell1 = rand() % 3;

		//hod Vora
		if (Vora.block <= 0){
			switch (spell) {
			case 0:
				printf(" Vora uses the skill:\n 1. %s \n", Vora.skill1);
				Vora.mana -= 200;
				damage = 500;
				break;
			case 1:
				printf(" Vora uses the skill:\n 2. %s \n", Vora.skill2);
				Vora.mana -= 100;
				damage = 200;
				break;
			case 2:
				printf(" Vora uses the skill:\n 3. %s \n", Vora.skill3);
				Vora.mana -= 50;
				damage = 0;
				Rei.block = 1;
				break;
			}
			if (spell1 == 2) {
				if (damage > 275) {
					damage = 275;
				}
			}
			Rei.hp = Rei.hp - (1 - Rei.resistance) * damage;
			Vora.hp += damage * Vora.vamp;
		}
		if (Vora.block > 0) {
			printf("\n Vora in the block\n");
			Vora.block -= 1;
		}
		
		//hod Rei
		if (Rei.block <= 0) {
			switch (spell1) {
			case 0:
				printf(" Rei uses the skill:\n 1. %s \n", Rei.skill1);
				Rei.mana -= 100;
				Rei.hp += 600;
				damage = 0;
				break;
			case 1:
				printf(" Rei uses the skill:\n 2. %s \n", Rei.skill2);
				Rei.mana -= 0;
				damage = 450;
				break;
			case 2:
				printf(" Rei uses the skill:\n 3. %s \n", Rei.skill3);
				Rei.mana -= 100;
				Vora.block = 1;
				damage = 0;
				break;
			}
			Vora.hp = Vora.hp - (1 - Vora.resistance) * damage;
		}
		if (Rei.block > 0) {
			printf("\n Rei in the block\n");
			Rei.block -= 1;
		}
	}

	if (Rei.hp <= 0 || Rei.mana <= 0) {
		printf("\n Winner: Vora.\n");
		pobeda11.name = "Vora";
		pobeda11.hp = 2200;
		pobeda11.resistance = 0;
		pobeda11.mana = 6000;
		pobeda11.level = 20;
		pobeda11.block = 0;
		pobeda11.vamp = 0.1;
	}
	if (Vora.hp <= 0 || Vora.mana <= 0) {
		printf("\n Winner: Rei.\n");
		pobeda11.name = "Rei";
		pobeda11.hp = 2000;
		pobeda11.resistance = 0;
		pobeda11.mana = 5000;
		pobeda11.level = 17;
		pobeda11.block = 0;
	}

	Sleep(5000);
	printf("\n The following are invited to the arena Vaty and Drogos.\n\n");
	Sleep(3000);
	//bitva 12   (Vaty x Drogos)
	while (Vaty.hp > 0 && Drogos.hp > 0 && Vaty.mana >= 0 && Drogos.mana >= 0) {
		Sleep(4000);
		printf("\n Vaty hp: %lf     Vaty mana: %d\n Drogos hp: %lf     Drogos mana: %d\n\n\n",
			Vaty.hp, Vaty.mana, Drogos.hp, Drogos.mana);
		Sleep(3000);
		spell = rand() % 3;
		spell1 = rand() % 3;

		//hod Vaty
		if (Vaty.block <= 0) {
			switch (spell) {
			case 0:
				printf(" Vaty uses the skill:\n 1. %s \n", Vaty.skill1);
				Vaty.mana -= 120;
				damage = 280;
				break;
			case 1:
				printf(" Vaty uses the skill:\n 2. %s \n", Vaty.skill2);
				Vaty.mana -= 50;
				damage = rand() % 10;
				if (damage >= 5) {
					damage = 333;
				}
				else {
					damage = 90;
				}
				break;
			case 2:
				printf(" Vaty uses the skill:\n 3. %s \n", Vaty.skill3);
				Vaty.mana -= 30;
				damage = 0;
				Drogos.block = 1;
				break;
			}
			Drogos.hp = Drogos.hp - (1 - Drogos.resistance) * damage;
		}
		else{
			printf("\n Vaty in the block\n");
			Vaty.block -= 1;
		}

		//hod Drogos
		if (Drogos.block <= 0) {
			switch (spell1) {
			case 0:
				printf(" Drogos uses the skill:\n 1. %s \n", Drogos.skill1);
				Drogos.mana -= 100;
				damage = 0;
				Vaty.block = 1;
				break;
			case 1:
				printf(" Drogos uses the skill:\n 2. %s \n", Drogos.skill2);
				Drogos.mana -= 0;
				damage = 850;
				Drogos.block = 1;
				break;
			case 2:
				printf(" Drogos uses the skill:\n 3. %s \n", Drogos.skill3);
				Drogos.mana -= 200;
				damage = 300;
				break;
			}
			Vaty.hp = Vaty.hp - (1 - Vaty.resistance) * damage;
		}
		else{
			printf("\n Drogos in the block\n");
			Drogos.block -= 1;
		}
	}

	if (Drogos.hp <= 0 || Drogos.mana <= 0) {
		printf("\n Winner: Vaty.\n");
		pobeda12.name = "Vaty";
		pobeda12.hp = 2500;
		pobeda12.resistance = 0;
		pobeda12.mana = 2000;
		pobeda12.level = 21;
		pobeda12.block = 0;
		pobeda12.vamp = 0;
	}
	if (Vaty.hp <= 0 || Vaty.mana <= 0) {
		printf("\n Winner: Drogos.\n");
		pobeda12.name = "Drogos";
		pobeda12.hp = 1500;
		pobeda12.resistance = 0.2;
		pobeda12.mana = 3000;
		pobeda12.level = 16;
		pobeda12.block = 0;
		pobeda12.vamp = 0;
	}

	Sleep(5000);
	printf("\n The following are invited to the arena Han and Inara.\n\n");
	Sleep(3000);
	//bitva 13   (Han x Inara)
	while (Han.hp > 0 && Inara.hp > 0 && Han.mana >= 0 && Inara.mana >= 0) {
		Sleep(4000);
		printf("\n Han hp: %lf     Han mana: %d\n Inara hp: %lf     Inara mana: %d\n\n\n",
			Han.hp, Han.mana, Inara.hp, Inara.mana);
		Sleep(3000);
		spell = rand() % 3;
		spell1 = rand() % 3;

		//hod Han
		if (Han.block <= 0) {
			switch (spell) {
			case 0:
				printf(" Han uses the skill:\n 1. %s \n", Han.skill1);
				Han.mana -= 0;
				damage = 210;
				break;
			case 1:
				printf(" Han uses the skill:\n 2. %s \n", Han.skill2);
				Han.mana -= 200;
				damage = 0;
				Inara.block = 2;
				break;
			case 2:
				printf(" Han uses the skill:\n 3. %s \n", Han.skill3);
				Han.mana -= 300;
				damage = 0;
				Han.hp += 300;
				Han.resistance += 0.01;
				break;
			}
			Inara.hp = Inara.hp - (1 - Inara.resistance) * damage;
		}
		else {
			printf("\n Han in the block\n");
			Han.block -= 1;
		}

		//hod Inara
		if (Inara.block <= 0) {
			switch (spell1) {
			case 0:
				printf(" Inara uses the skill:\n 1. %s \n", Inara.skill1);
				Inara.mana -= 0;
				damage = 675;
				break;
			case 1:
				printf(" Inara uses the skill:\n 2. %s \n", Inara.skill2);
				Inara.mana -= 200;
				damage = 0;
				Han.block = 2;
				break;
			case 2:
				printf(" Inara uses the skill:\n 3. %s \n", Inara.skill3);
				Inara.mana -= 75;
				damage = 150;
				break;
			}
			Han.hp = Han.hp - (1 - Han.resistance) * damage;
		}
		else {
			printf("\n Inara in the block\n");
			Inara.block -= 1;
		}
	}

	if (Inara.hp <= 0 || Inara.mana <= 0) {
		printf("\n Winner: Han.\n");
		pobeda13.name = "Han";
		pobeda13.hp = 2000;
		pobeda13.resistance = 0.3;
		pobeda13.mana = 6000;
		pobeda13.level = 15;
		pobeda13.block = 1;
		pobeda13.vamp = 0;
	}
	if (Han.hp <= 0 || Han.mana <= 0) {
		printf("\n Winner: Inara.\n");
		pobeda13.name = "Inara";
		pobeda13.hp = 2000;
		pobeda13.resistance = 0.3;
		pobeda13.mana = 3000;
		pobeda13.level = 13;
		pobeda13.block = 1;
		pobeda13.vamp = 0;
	}

	Sleep(5000);
	printf("\n The following are invited to the arena Znak and In.\n\n");
	Sleep(3000);
	//bitva 14   (In x Znak)
	while (Znak.hp > 0 && In.hp > 0 && Znak.mana >= 0 && In.mana >= 0) {
		Sleep(4000);
		printf("\n Znak hp: %lf     Znak mana: %d\n In hp: %lf     In mana: %d\n\n\n",
			Znak.hp, Znak.mana, In.hp, In.mana);
		Sleep(3000);
		spell = rand() % 3;
		spell1 = rand() % 3;

		//hod Znak
		if (Znak.block <= 0) {
			switch (spell) {
			case 0:
				printf(" Znak uses the skill:\n 1. %s \n", Znak.skill1);
				Znak.mana -= 0;
				damage = 500;
				break;
			case 1:
				printf(" Znak uses the skill:\n 2. %s \n", Znak.skill2);
				Znak.mana -= 50;
				damage = 60;
				break;
			case 2:
				printf(" Znak uses the skill:\n 3. %s \n", Znak.skill3);
				Znak.mana -= 200;
				damage = 400;
				In.block = 1;
				break;
			}
			In.hp = In.hp - (1 - In.resistance) * damage;
		}
		else {
			printf("\n Znak in the block\n");
			Znak.block -= 1;
		}

		//hod In
		if (In.block <= 0) {
			switch (spell1) {
			case 0:
				printf(" In uses the skill:\n 1. %s \n", In.skill1);
				In.mana -= 0;
				damage = 200;
				break;
			case 1:
				printf(" In uses the skill:\n 2. %s \n", In.skill2);
				In.mana -= 200;
				damage = 0;
				In.hp += 450;
				break;
			case 2:
				printf(" In uses the skill:\n 3. %s \n", In.skill3);
				In.mana -= 200;
				damage = 0;
				In.hp += 600;
				break;
			}
			Znak.hp = Znak.hp - (1 - Znak.resistance) * damage;
		}
		else {
			printf("\n In in the block\n");
			In.block -= 1;
		}
	}

	if (Znak.hp <= 0 || Znak.mana <= 0) {
		printf("\n Winner: In.\n");
		pobeda14.name = "In";
		pobeda14.hp = 1000;
		pobeda14.resistance = 0;
		pobeda14.mana = 6000;
		pobeda14.level = 8;
		pobeda14.block = 0;
		pobeda14.vamp = 0;
	}
	if (In.hp <= 0 || In.mana <= 0) {
		printf("\n Winner: Znak.\n");
		pobeda14.name = "Znak";
		pobeda14.hp = 1300;
		pobeda14.resistance = 0.1;
		pobeda14.mana = 2000;
		pobeda14.level = 10;
		pobeda14.block = 0;
		pobeda14.vamp = 0;
	}

	Sleep(5000);
	printf("\n The following are invited to the arena %s and Vivian.\n\n", You.name);
	Sleep(3000);
	//bitva 15   (You x Vivian)
	while (You.hp > 0 && Vivian.hp > 0 && You.mana >= 0 && Vivian.mana >= 0) {
		Sleep(4000);
		printf("\n You hp: %lf     You mana: %d\n Vivian hp: %lf     Vivian mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n Skill 4: %s\n",
			You.hp, You.mana, Vivian.hp, Vivian.mana, You.skill1, You.skill2, You.skill3, You.skill4);
		scanf_s("%d", &spell);
		spell1 = rand() % 3;

		//hod You
		if (You.block <= 0) {
			switch (gerou) {
			case 1:
				if (spell == 1) {
					You.mana -= 30;
					damage = 0;
					Vivian.block = 2;
				}
				if (spell == 2) {
					You.mana -= 75;
					damage = 100;
				}
				if (spell == 3) {
					You.mana -= 25;
					damage = 50;
					Vivian.block = 1;
				}
				if (spell == 4) {
					damage = 0;
					You.mana -= 150;
					You.hp += 250;
				}
				break;
			case 2:
				if (spell == 1) {
					You.mana -= 20;
					damage = 0;
					You.resistance += 0.05;
				}
				if (spell == 2) {
					You.mana -= 85;
					damage = 100;
				}
				if (spell == 3) {
					You.mana -= 25;
					damage = 60;
					Vivian.resistance -= 0.02;
				}
				if (spell == 4) {
					damage = 0;
					You.mana -= 150;
					You.hp += 250;
				}
				break;
			case 3:
				if (spell == 1) {
					You.mana -= 20;
					damage = 0;
					You.hp += 50;
				}
				if (spell == 2) {
					You.mana -= 25;
					damage = 30;
					Vivian.block = 1;
				}
				if (spell == 3) {
					You.mana -= 100;
					damage = 200;
				}
				if (spell == 4) {
					damage = 0;
					You.mana -= 150;
					You.hp += 250;
				}
				break;
			}
			Vivian.hp = Vivian.hp - (1 - Vivian.resistance) * damage;
			You.hp = You.hp + damage * You.vamp;
		}
		else {
			printf("\n You in the block\n");
			You.block -= 1;
		}

		//hod Vivian
		if (Vivian.block <= 0) {
			switch (spell1) {
			case 0:
				printf(" Vivian uses the skill:\n 1. %s \n", Vivian.skill1);
				Vivian.mana -= 0;
				damage = 165;
				break;
			case 1:
				printf(" Vivian uses the skill:\n 2. %s \n", Vivian.skill2);
				Vivian.mana -= 100;
				damage = 0;
				You.block = 1;
				break;
			case 2:
				printf(" Vivian uses the skill:\n 3. %s \n", Vivian.skill3);
				Vivian.mana -= 150;
				damage = 300;
				break;
			}
			You.hp = You.hp - (1 - You.resistance) * damage;
		}
		else {
			printf("\n Vivian in the block\n");
			Vivian.block -= 1;
		}
	}

	if (Vivian.hp <= 0 || Vivian.mana <= 0) {
		printf("\n Winner: You.\n");
		You.hp = hp;
		You.resistance = resistance;
		You.mana = mana;
		You.block = 0;
	}
	if (You.hp <= 0 || You.mana <= 0) {
		printf("\n Winner: Znak.\n");
		return printf("\n\n You dead. Game over.\n");
	}

	printf("\n You've won your first round. Your 3 skill now deals more damage.\n");
	switch (gerou) {
	case 1:
		You.skill3 = "Slowing down. Slows down the enemy by dealing him side damage. Damage = 250. Mana = 150.\n";
	case 2:
		You.skill3 = "Quick strikes. Deals a series of quick blows to the enemy. Damage = 50 * 6. Mana = 150.\n";
	case 3:
		You.skill3 = "Lava fist. Fills his hand with lava and strikes at the enemy. Damage = 400. Mana = 150.\n";
	}

	//2 tour
	Sleep(6000);
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 8													");
	printf("\n								2 tour													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	shrift(12, 16);

	printf("\n\n					2 tour\n\n");
	printf(" 1. %s(%d) --- %s(%d)\n", pobeda11.name, pobeda11.level, pobeda12.name, pobeda12.level);
	printf(" 2. %s(%d) --- %s(%d)\n", pobeda13.name, pobeda13.level, pobeda14.name, pobeda14.level);
	Sleep(3000);

	printf(" Since the number of participants is not even, there were not enough places for your participation, so you can rest.\n");
	Sleep(3000);

	spell = rand() % 2;
	if (spell == 1) {
		pobeda21.name = pobeda11.name;
		pobeda21.hp = pobeda11.hp;
		pobeda21.resistance = pobeda11.resistance;
		pobeda21.mana = pobeda11.mana;
		pobeda21.level = pobeda11.level;
		pobeda21.block = pobeda11.block;
		pobeda21.vamp = pobeda11.vamp;
	}
	else {
		pobeda21.name = pobeda12.name;
		pobeda21.hp = pobeda12.hp;
		pobeda21.resistance = pobeda12.resistance;
		pobeda21.mana = pobeda12.mana;
		pobeda21.level = pobeda12.level;
		pobeda21.block = pobeda12.block;
		pobeda21.vamp = pobeda12.vamp;
	}

	spell = rand() % 2;
	if (spell == 1) {
		pobeda22.name = pobeda13.name;
		pobeda22.hp = pobeda13.hp;
		pobeda22.resistance = pobeda13.resistance;
		pobeda22.mana = pobeda13.mana;
		pobeda22.level = pobeda13.level;
		pobeda22.block = pobeda13.block;
		pobeda22.vamp = pobeda13.vamp;
	}
	else {
		pobeda22.name = pobeda14.name;
		pobeda22.hp = pobeda14.hp;
		pobeda22.resistance = pobeda14.resistance;
		pobeda22.mana = pobeda14.mana;
		pobeda22.level = pobeda14.level;
		pobeda22.block = pobeda14.block;
		pobeda22.vamp = pobeda14.vamp;
	}

	//3 tour
	Sleep(6000);
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 9													");
	printf("\n								3 tour													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	shrift(12, 16);

	printf(" It's time for the 3rd round, now you won't be able to rest.\n\n");
	printf("\n\n					3 tour\n\n");
	printf(" 1. %s(%d) --- %s(%d)\n", You.name, You.level, pobeda22.name, pobeda22.level);
	Sleep(3000);

	printf("\n The following are invited to the arena %s and %s.\n\n", You.name, pobeda22.name);
	Sleep(3000);

	while (You.hp > 0 && pobeda22.hp > 0 && You.mana >= 0 && pobeda22.mana >= 0) {
		Sleep(4000);
		printf("\n You hp: %lf     You mana: %d\n %s hp: %lf     %s mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n Skill 4: %s\n",
			You.hp, You.mana, pobeda22.name, pobeda22.hp, pobeda22.name, pobeda22.mana, You.skill1, You.skill2, You.skill3, You.skill4);
		scanf_s("%d", &spell);
		spell1 = rand() % 3;

		//hod You
		if (You.block <= 0) {
			switch (gerou) {
			case 1:
				if (spell == 1) {
					You.mana -= 30;
					damage = 0;
					pobeda22.block = 2;
				}
				if (spell == 2) {
					You.mana -= 75;
					damage = 100;
				}
				if (spell == 3) {
					You.mana -= 150;
					damage = 250;
					pobeda22.block = 1;
				}
				if (spell == 4) {
					damage = 0;
					You.mana -= 150;
					You.hp += 250;
				}
				break;
			case 2:
				if (spell == 1) {
					You.mana -= 20;
					damage = 0;
					You.resistance += 0.05;
				}
				if (spell == 2) {
					You.mana -= 85;
					damage = 100;
				}
				if (spell == 3) {
					You.mana -= 150;
					damage = 300;
					pobeda22.resistance -= 0.02;
				}
				if (spell == 4) {
					damage = 0;
					You.mana -= 150;
					You.hp += 250;
				}
				break;
			case 3:
				if (spell == 1) {
					You.mana -= 20;
					damage = 0;
					You.hp += 50;
				}
				if (spell == 2) {
					You.mana -= 25;
					damage = 30;
					pobeda22.block = 1;
				}
				if (spell == 3) {
					You.mana -= 150;
					damage = 400;
				}
				if (spell == 4) {
					damage = 0;
					You.mana -= 150;
					You.hp += 250;
				}
				break;
			}
			pobeda22.hp = pobeda22.hp - (1 - pobeda22.resistance) * damage;
			You.hp = You.hp + damage * You.vamp;
		}
		else {
			printf("\n You in the block\n");
			You.block -= 1;
		}

		//hod vraga
		if (pobeda22.name == "Han") {
			if (pobeda22.block <= 0) {
				switch (spell1) {
				case 0:
					printf(" Han uses the skill:\n 1. %s \n", Han.skill1);
					pobeda22.mana -= 0;
					damage = 210;
					break;
				case 1:
					printf(" Han uses the skill:\n 2. %s \n", Han.skill2);
					pobeda22.mana -= 200;
					damage = 0;
					You.block = 2;
					break;
				case 2:
					printf(" Han uses the skill:\n 3. %s \n", Han.skill3);
					pobeda22.mana -= 300;
					damage = 0;
					pobeda22.hp += 300;
					pobeda22.resistance += 0.01;
					break;
				}
				You.hp = You.hp - (1 - You.resistance) * damage;
			}
			else {
				printf("\n Han in the block\n");
				pobeda22.block -= 1;
			}		
		}
		if (pobeda22.name == "Inara") {
			if (pobeda22.block <= 0) {
				switch (spell1) {
				case 0:
					printf(" Inara uses the skill:\n 1. %s \n", Inara.skill1);
					pobeda22.mana -= 0;
					damage = 675;
					break;
				case 1:
					printf(" Inara uses the skill:\n 2. %s \n", Inara.skill2);
					pobeda22.mana -= 200;
					damage = 0;
					You.block = 2;
					break;
				case 2:
					printf(" Inara uses the skill:\n 3. %s \n", Inara.skill3);
					pobeda22.mana -= 75;
					damage = 150;
					break;
				}
				You.hp = You.hp - (1 - You.resistance) * damage;
			}
			else {
				printf("\n Inara in the block\n");
				pobeda22.block -= 1;
			}
		}
		if (pobeda22.name == "Znak") {
			if (pobeda22.block <= 0) {
				switch (spell) {
				case 0:
					printf(" Znak uses the skill:\n 1. %s \n", Znak.skill1);
					pobeda22.mana -= 0;
					damage = 500;
					break;
				case 1:
					printf(" Znak uses the skill:\n 2. %s \n", Znak.skill2);
					pobeda22.mana -= 50;
					damage = 60;
					break;
				case 2:
					printf(" Znak uses the skill:\n 3. %s \n", Znak.skill3);
					pobeda22.mana -= 200;
					damage = 400;
					You.block = 1;
					break;
				}
				You.hp = You.hp - (1 - You.resistance) * damage;
			}
			else {
				printf("\n Znak in the block\n");
				pobeda22.block -= 1;
			}
		}
		if (pobeda22.name == "In") {
			if (pobeda22.block <= 0) {
				switch (spell1) {
				case 0:
					printf(" In uses the skill:\n 1. %s \n", In.skill1);
					pobeda22.mana -= 0;
					damage = 200;
					break;
				case 1:
					printf(" In uses the skill:\n 2. %s \n", In.skill2);
					pobeda22.mana -= 200;
					damage = 0;
					pobeda22.hp += 450;
					break;
				case 2:
					printf(" In uses the skill:\n 3. %s \n", In.skill3);
					pobeda22.mana -= 200;
					damage = 0;
					pobeda22.hp += 600;
					break;
				}
				You.hp = You.hp - (1 - You.resistance) * damage;
			}
			else {
				printf("\n In in the block\n");
				pobeda22.block -= 1;
			}
		}


	}
	if (pobeda22.hp <= 0 || pobeda22.mana <= 0) {
		printf("\n Winner: You.\n");
		You.hp = hp;
		You.resistance = resistance;
		You.mana = mana;
		You.block = 0;
		Sleep(2000);
		printf(" You have already won 2 times. For this, you get increased vampirism.\n\n");
		You.vamp += 0.4;
	}
	if (You.hp <= 0 || You.mana <= 0) {
		printf("\n Winner: %s.\n", pobeda22.name);
		return printf("\n\n You dead. Game over.\n");
	}

	//4 tour
	Sleep(6000);
	shrift(20, 22);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 10													");
	printf("\n								4 tour													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	shrift(12, 16);

	printf(" Time for the last round, let's see who wins.\n\n");
	printf("\n\n					4 tour\n\n");
	printf(" 1. %s(%d) --- %s(%d)\n", You.name, You.level, pobeda21.name, pobeda21.level);
	Sleep(3000);

	printf("\n The following are invited to the arena %s and %s.\n\n", You.name, pobeda21.name);
	Sleep(3000);

	printf(" After finding out which opponent will be waiting for you in the final, you go to a local magician who, with the help of his charms, increases your resistance.\n\n");
	You.resistance += 0.2;
	Sleep(3000);
	while (You.hp > 0 && pobeda21.hp > 0 && You.mana >= 0 && pobeda21.mana >= 0) {
		Sleep(4000);
		printf("\n You hp: %lf     You mana: %d\n %s hp: %lf     %s mana: %d\n\n\n Skill 1: %s\n Skill 2: %s\n Skill 3: %s\n Skill 4: %s\n",
			You.hp, You.mana, pobeda21.name, pobeda21.hp, pobeda21.name, pobeda21.mana, You.skill1, You.skill2, You.skill3, You.skill4);
		scanf_s("%d", &spell);
		spell1 = rand() % 3;

		//hod You
		if (You.block <= 0) {
			switch (gerou) {
			case 1:
				if (spell == 1) {
					You.mana -= 30;
					damage = 0;
					pobeda21.block = 2;
				}
				if (spell == 2) {
					You.mana -= 75;
					damage = 100;
				}
				if (spell == 3) {
					You.mana -= 150;
					damage = 250;
					pobeda21.block = 1;
				}
				if (spell == 4) {
					damage = 0;
					You.mana -= 150;
					You.hp += 250;
				}
				break;
			case 2:
				if (spell == 1) {
					You.mana -= 20;
					damage = 0;
					You.resistance += 0.05;
				}
				if (spell == 2) {
					You.mana -= 85;
					damage = 100;
				}
				if (spell == 3) {
					You.mana -= 150;
					damage = 300;
					pobeda21.resistance -= 0.02;
				}
				if (spell == 4) {
					damage = 0;
					You.mana -= 150;
					You.hp += 250;
				}
				break;
			case 3:
				if (spell == 1) {
					You.mana -= 20;
					damage = 0;
					You.hp += 50;
				}
				if (spell == 2) {
					You.mana -= 25;
					damage = 30;
					pobeda21.block = 1;
				}
				if (spell == 3) {
					You.mana -= 150;
					damage = 400;
				}
				if (spell == 4) {
					damage = 0;
					You.mana -= 150;
					You.hp += 250;
				}
				break;
			}
			if (spell1 == 2 && pobeda21.name == "Rei") {
				if (damage > 275) {
					damage = 275;
				}
			}
			pobeda21.hp = pobeda21.hp - (1 - pobeda21.resistance) * damage;
			You.hp = You.hp + damage * You.vamp;
		}
		else {
			printf("\n You in the block\n");
			You.block -= 1;
		}

		//hod vraga
		if (pobeda21.name == "Vora") {
			if (pobeda21.block <= 0) {
				switch (spell) {
				case 0:
					printf(" Vora uses the skill:\n 1. %s \n", Vora.skill1);
					pobeda21.mana -= 200;
					damage = 500;
					break;
				case 1:
					printf(" Vora uses the skill:\n 2. %s \n", Vora.skill2);
					pobeda21.mana -= 100;
					damage = 200;
					break;
				case 2:
					printf(" Vora uses the skill:\n 3. %s \n", Vora.skill3);
					pobeda21.mana -= 50;
					damage = 0;
					You.block = 1;
					break;
				}
				if (spell1 == 2) {
					damage = 275;
				}
				You.hp = You.hp - (1 - You.resistance) * damage;
				pobeda21.hp += damage * pobeda21.vamp;
			}
			else {
				printf("\n Vora in the block\n");
				pobeda21.block -= 1;
			}
		}
		if (pobeda21.name == "Rei") {
			if (pobeda21.block <= 0) {
				switch (spell1) {
				case 0:
					printf(" Rei uses the skill:\n 1. %s \n", Rei.skill1);
					pobeda21.mana -= 100;
					pobeda21.hp += 600;
					damage = 0;
					break;
				case 1:
					printf(" Rei uses the skill:\n 2. %s \n", Rei.skill2);
					pobeda21.mana -= 0;
					damage = 450;
					break;
				case 2:
					printf(" Rei uses the skill:\n 3. %s \n", Rei.skill3);
					pobeda21.mana -= 100;
					You.block = 1;
					damage = 0;
					break;
				}
				Vora.hp = Vora.hp - (1 - Vora.resistance) * damage;
			}
			if (Rei.block > 0) {
				printf("\n Rei in the block\n");
				Rei.block -= 1;
			}
		}
		if (pobeda21.name == "Vaty") {
			if (pobeda21.block <= 0) {
				switch (spell) {
				case 0:
					printf(" Vaty uses the skill:\n 1. %s \n", Vaty.skill1);
					pobeda21.mana -= 120;
					damage = 280;
					break;
				case 1:
					printf(" Vaty uses the skill:\n 2. %s \n", Vaty.skill2);
					pobeda21.mana -= 50;
					damage = rand() % 10;
					if (damage >= 5) {
						damage = 333;
					}
					else {
						damage = 90;
					}
					break;
				case 2:
					printf(" Vaty uses the skill:\n 3. %s \n", Vaty.skill3);
					pobeda21.mana -= 30;
					damage = 0;
					You.block = 1;
					break;
				}
				You.hp = You.hp - (1 - You.resistance) * damage;
			}
			else {
				printf("\n Vaty in the block\n");
				pobeda21.block -= 1;
			}
		}
		if (pobeda21.name == "Drogos") {
			if (pobeda21.block <= 0) {
				switch (spell1) {
				case 0:
					printf(" Drogos uses the skill:\n 1. %s \n", Drogos.skill1);
					pobeda21.mana -= 100;
					damage = 0;
					You.block = 1;
					break;
				case 1:
					printf(" Drogos uses the skill:\n 2. %s \n", Drogos.skill2);
					pobeda21.mana -= 0;
					damage = 850;
					pobeda21.block = 1;
					break;
				case 2:
					printf(" Drogos uses the skill:\n 3. %s \n", Drogos.skill3);
					pobeda21.mana -= 200;
					damage = 300;
					break;
				}
				You.hp = You.hp - (1 - You.resistance) * damage;
			}
			else {
				printf("\n Drogos in the block\n");
				pobeda21.block -= 1;
			}
		}
	}

	if (pobeda21.hp <= 0 || pobeda21.mana <= 0) {
		printf("\n Winner: You.\n");
		You.hp = hp;
		You.resistance = resistance;
		You.mana = mana;
		Sleep(2000);
		printf(" Congratulations, you have passed the game. Your task is done.\n");
	}
	if (You.hp <= 0 || You.mana <= 0) {
		printf("\n Winner: %s.\n", pobeda21.name);
		return printf("\n\n You dead. Game over.\n");
	}

	//end
	Sleep(6000);
	shrift(24, 26);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n								Chapter 11													");
	printf("\n								END													\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	Sleep(5000);
	k = 0;
	while (k != 20) {
		Sleep(800);
		printf("\n");
	}
}
