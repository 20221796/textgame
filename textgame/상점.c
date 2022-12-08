#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "소스.h"
#include "상점.h"

#define true 1
#define false 0
#define and &&
#define or ||

extern Player player;

void goto_shop(void) //상점으로 이동하는 함수
{
	int menu = 0;
	title();
	print_profile();

	printf("상점으로 이동했습니다. \n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	Sleep(500);
	printf("짤랑~ 짤랑~ (동전을 누군가 세고 있다) \n\n");
	Sleep(500);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("상점 주인");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf(" : 뭐가 필요해서 찾아왔지? \n");
	Sleep(500);

	do
	{
		printf("\n1. 골드 충전 \t 2. 상점에서 나가기 \n");
		printf("1 2 중 선택 : ");
		scanf("%d", &menu);

		if (menu == 1)
		{
			charge_cash();
		}
		else if (menu != 2) printf("잘못된 메뉴를 선택했습니다. 다시 선택해주세요. \n\n");
	} while (menu != 2);

	Sleep(500);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("\n상점 주인");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf(" : 잘가게. \n\n");
	Sleep(500);
	printf("상점에서 나갑니다... \n");
	Sleep(500);
	printf("슉슈 슉슈 슉슈");
	Sleep(500);
}

void charge_cash() //골드 충전 함수
{
	printf("\n10000골드를 충전했습니다\t 골드 %d -> %d \n", player.gold, player.gold + 10000);
	player.gold += 10000;
}