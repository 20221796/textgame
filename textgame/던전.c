#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "소스.h"
#include "던전.h"

#define true 1
#define false 0
#define and &&
#define or ||

int end_battle = false;
int floor = 1;

extern Monster monster;
extern Player player;

void goto_dungeon(void) //던전에 입장하는 함수
{
	int menu = 0;

	title();
	print_profile();

	printf("던전에 지하 %d층에 들어왔습니다. \n\n", floor);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	Sleep(500);
	printf("키약! 쿠웨ㅔㅔ엑!! (몬스터들의 울음소리가 들린다) \n\n");
	Sleep(500);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	Sleep(500);

	do
	{
		if (!summon_monster()) //만약 summon_monster 반환값이 false이면 던전 클리어
		{
			printf("던전을 모두 클리어했습니다 \n");
			printf("축하합니다 \n던전에서 탈출합니다 \n");
			break;
		}
		printf("1. 싸운다 2. 도망간다 \n");
		printf("1 2 중 선택 : ");
		scanf("%d", &menu);

		if (menu == 1)
		{
			end_battle = false;
			start_battle();
			if (end_battle) break;
		}
		else if (menu != 2) printf("몬스터에게 겁에 질려 판단력이 흐려졌군요... 선택지는 1과 2뿐입니다. \n\n");
	} while (menu != 2);


	Sleep(500);
	printf("던전에서 탈출합니다... \n");
	Sleep(500);
	printf("슉슈 슉슈 슉슈");
	Sleep(500);
}

int summon_monster(void) //층수에 맞는 몬스터를 설정하는 함수
{
	monster.is_boss = false;

	if (floor > 99) return false; //99층 이상이면 몬스터를 소환하지 않음
	else
	{
		if (floor % 10 == 9) summon_boss();
		else summon_common();
		return true;
	}
}

void summon_boss(void)
{
	monster.is_boss = true;
	monster.level = floor;
	monster.hp = floor * 800;
	monster.ad = floor * 50;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	Sleep(500);
	printf("[경고] 지하 %d층까지 와 보스 몬스터가 출현합니다. \n", floor);
	printf("보스 몬스터와의 전투에서는 중간에 도망가는 것이 불가능하며 죽으면 레벨이 1이 됩니다. \n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	switch (floor / 10)
	{
	case 0:
		strcpy(monster.name, "거대 슬라임");
		break;
	case 1:
		strcpy(monster.name, "키메라 엔트");
		break;
	case 2:
		strcpy(monster.name, "엘리스");
		break;
	case 3:
		strcpy(monster.name, "하이 워울프");
		break;
	case 4:
		strcpy(monster.name, "리자드킹");
		break;
	case 5:
		strcpy(monster.name, "미노타우르스");
		break;
	case 6:
		strcpy(monster.name, "하이 언데드");
		break;
	case 7:
		strcpy(monster.name, "셰이드");
		break;
	case 8:
		strcpy(monster.name, "가디언 골렘");
		break;
	case 9:
		strcpy(monster.name, "츄파");
		break;
	}

	printf("지하 %d층 보스 %s가 출현합니다. \n", floor, monster.name);
}

void summon_common(void)
{
	monster.is_boss = false;
	monster.level = floor;
	monster.hp = floor * 300;
	monster.ad = floor * 30;

	switch (floor / 10)
	{
	case 0:
		strcpy(monster.name, "슬라임");
		break;
	case 1:
		strcpy(monster.name, "병정 개미");
		break;
	case 2:
		strcpy(monster.name, "엘리스");
		break;
	case 3:
		strcpy(monster.name, "회색 늑대");
		break;
	case 4:
		strcpy(monster.name, "리자드맨");
		break;
	case 5:
		strcpy(monster.name, "타우");
		break;
	case 6:
		strcpy(monster.name, "스켈레톤");
		break;
	case 7:
		strcpy(monster.name, "레이스");
		break;
	case 8:
		strcpy(monster.name, "골렘");
		break;
	case 9:
		strcpy(monster.name, "이무기");
		break;
	}

	printf("지하 %d층 몬스터 %s가 출현합니다. \n", floor, monster.name);
}

void start_battle(void)
{
	printf("\n선빵 필승! 플레이어의 선공으로 전투가 시작됩니다. \n");

	while (1) //monster.hp > 0 and player.hp > 0
	{
		Sleep(400);
		printf("%s에게 공격을 날렸다. 몬스터 체력 %d -> %d \n", monster.name, monster.hp, monster.hp - player.ad);

		monster.hp -= player.ad;

		if (monster.hp <= 0)
		{
			Sleep(500);
			printf("\n몬스터를 쓰러트렸습니다. 다음 층으로 이동합니다. \n");
			printf("지하 던전 %d층 -> %d층 \n\n", floor, floor + 1);
			floor++;
			break;
		}

		Sleep(400);
		printf("%s에게 공격받았다! 내 체력 %d -> %d \n", monster.name, player.hp, player.hp - monster.ad);
		player.hp -= monster.ad;

		if (player.hp <= 0)
		{
			Sleep(500);
			if (monster.is_boss)
			{
				printf("보스에게 죽어 소지품을 모두 잃고 레벨이 1이 됩니다. 저런.... \n\n");
				player.level = 1;
				player.hp = player.level * 1000;
				player.ad = player.level * 100;
				player.gold = 0;
			}
			else
			{
				printf("몬스터의 일격에 쓰러졌습니다. 하지만 주인공 패시브 발동! 자동 귀환 마법을 사용합니다. \n\n");
				player.hp = player.level * 1000;
			}
			Sleep(500);
			end_battle = true;
			break;
		}
	}
}