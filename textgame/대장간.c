#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "소스.h"
#include "대장간.h"

#define true 1
#define false 0
#define and &&
#define or ||

extern Player player;

void goto_smithy(void) //대장간으로 이동하는 함수
{
	int menu = 0;
	title();
	print_profile();

	printf("대장간으로 이동했습니다. \n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	Sleep(500);
	printf("깡! 깡! 깡! (뜨거운 열기가 느껴진다) \n\n");
	Sleep(500);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("대장장이");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf(" : 모험가 친구 무엇을 하려고? \n");
	Sleep(500);

	do
	{
		printf(" \n1. 장비 재련 2. 대장간에서 나가기 \n");
		printf("1 2 중 선택 : ");
		scanf("%d", &menu);

		if (menu == 1)
		{
			upgrade_equipment();
		}
		else if (menu != 2) printf("잘못된 메뉴를 선택했습니다. 다시 선택해주세요. \n\n");
	} while (menu != 2);

	Sleep(500);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("\n대장장이");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf(" : 다음에 또 오라고! \n\n");
	Sleep(500);
	printf("대장간에서 나갑니다... \n");
	Sleep(500);
	printf("슉슈 슉슈 슉슈");
	Sleep(500);
}

void upgrade_equipment(void) //장비 업그레이드 함수
{
	Sleep(200);
	if (player.level >= 99) printf("\n최대 레벨입니다 \n");
	else if (player.gold - 100 * player.level < 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\n대장장이");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf(" : 하하하 골드가 부족하군! 아쉽게도 무료봉사는 아니라네. \n");
	}
	else
	{
		printf("\n골드를 소모합니다\t 골드 %d -> %d \n", player.gold, player.gold - 100 * player.level);
		player.gold -= 100 * player.level;
		int success_rate = rand() % player.level + 1; //레벨이 1 오를 때마다 강화 확률을 낮춤

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		Sleep(500);
		printf("투쾅 투쾅 투쾅!\n");

		if (success_rate == player.level || success_rate == player.level / 2) //(1÷레벨)의 확률로 강화가 성공하도록 설정
		{
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("\n대장장이");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf(" : 음하하핳하 나같은 대장장이를 만난 걸 행운으로 알라고 친구!\n\n");
			Sleep(500);
			printf("(장비 제련에 성공했습니다  레벨 %d -> %d) \n", player.level, player.level + 1);

			player.level += 1;
		}
		else
		{
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("\n대장장이");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf(" : 어이쿠! 허허허... 원래 원숭이도 나무에서 떨어지는 법이라네\n\n");
			Sleep(500);
			printf("(장비 제련에 실패했습니다 레벨이 그대로 유지됩니다.) \n");
		}
	}
}