#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "소스.h"
#include "인트로 및 메인화면.h"

#define true 1
#define false 0
#define and &&
#define or ||

extern Player player;

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void intro(void) //시작화면을 출력하는 함수
{
	title();

	printf("이름을 입력해 주세요 : ");
	scanf("%s", player.name);

	printf("\n%s님 환영합니다. \n아무 키나 누르면 게임이 시작됩니다. ", player.name);
	getch();
}

void title(void) //제목을 출력하는 함수
{
	int x = 14;

	system("cls");		//화면 초기화 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);  //텍스트 색상 변경
	printT(0, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //1:파랑 2:초록 3:민트 4:빨강 6:노랑 7:하양
	printE(x, 2);											      //9:연한 파랑 10:연두 11:연한 민트 12:연한 빨강 14: 연한 노랑
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printX(2 * x, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printT(3 * x, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printG(4 * x + 5, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	printA(5 * x + 5, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printM(6 * x + 5, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printE(7 * x + 5, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(96, 12);
	printf("made by 20221796 서진배 \n\n");
}

void prologue(void) //간략한 스토리의 프롤로그를 출력하는 함수
{
	title();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("???");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf(" : 당신은 미궁에 갖혔습니다. \n\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	printf("???");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf(" : 탈출하려면 던전 99층을 클리어하세요. \n\n");

	printf("아무 키나 눌러 진행하기 : ");
	getch(); //getch를 사용해 아무 문자나 입력받을 때까지 대기
}

void display_menu(void) //메인메뉴를 출력하는 함수
{
	title();
	print_profile();

	printf("무엇을 할지 선택해주세요 \n");
	printf("1. 던전으로 이동 2. 대장간으로 이동 3. 상점으로 이동 4. 게임 종료 \n\n");
}

void print_profile(void) //캐릭터의 상태를 보여주는 함수
{
	player.hp = player.level * 1000;
	player.ad = player.level * 100;
	printf("이름 : %s \n", player.name);
	printf("Lv%d  체력: %d  공격력: %d  보유 골드: %d \n\n", player.level, player.hp, player.ad, player.gold);
	//printf("치명타 확률 : %f \n\n"); //추후 구현
}

int select_menu(void) //메뉴 선택 함수
{
	int menu = 0;
	printf("1 2 3 4 중 선택 : ");
	scanf("%d", &menu);

	switch (menu)
	{
	case 1:
		printf("던전으로 이동합니다... \n");
		Sleep(500); //0.5초 대기
		printf("슈슉 슈슉 슈슉");
		Sleep(500);
		goto_dungeon();
		break;

	case 2:
		printf("대장간으로 이동합니다... \n");
		Sleep(500);
		printf("슈슉 슈슉 슈슉");
		Sleep(500);
		goto_smithy();
		break;

	case 3:
		printf("상점으로으로 이동합니다... \n");
		Sleep(500);
		printf("슈슉 슈슉 슈슉");
		Sleep(500);
		goto_shop();
		break;

	case 4:
		printf("게임을 종료합니다");
		Sleep(500);
		return true;

	default:
		printf("잘못된 메뉴를 입력했습니다, 다시 입력해주세요.");
		Sleep(500);
	}
	return false;
}

void printT(int x, int y)		//T 출력
{
	gotoxy(x, y);     printf("▣▣▣▣▣▣");
	gotoxy(x, y + 1); printf("    ▣▣    ");
	gotoxy(x, y + 2); printf("    ▣▣    ");
	gotoxy(x, y + 3); printf("    ▣▣    ");
	gotoxy(x, y + 4); printf("    ▣▣    ");
	gotoxy(x, y + 5); printf("    ▣▣    ");
	gotoxy(x, y + 6); printf("    ▣▣    ");
	gotoxy(x, y + 7); printf("    ▣▣    ");
	gotoxy(x, y + 8); printf("    ▣▣    ");
}

void printE(int x, int y)		//E 출력
{
	gotoxy(x, y);     printf("▣▣▣▣▣▣");
	gotoxy(x, y + 1); printf("▣▣        ");
	gotoxy(x, y + 2); printf("▣▣        ");
	gotoxy(x, y + 3); printf("▣▣        ");
	gotoxy(x, y + 4); printf("▣▣▣▣▣  ");
	gotoxy(x, y + 5); printf("▣▣        ");
	gotoxy(x, y + 6); printf("▣▣        ");
	gotoxy(x, y + 7); printf("▣▣        ");
	gotoxy(x, y + 8); printf("▣▣▣▣▣▣");
}

void printX(int x, int y)		//X 출력
{
	gotoxy(x, y);     printf("▣▣    ▣▣");
	gotoxy(x, y + 1); printf(" ▣▣  ▣▣ ");
	gotoxy(x, y + 2); printf("  ▣▣▣▣  ");
	gotoxy(x, y + 3); printf("    ▣▣    ");
	gotoxy(x, y + 4); printf("     ▣     ");
	gotoxy(x, y + 5); printf("    ▣▣    ");
	gotoxy(x, y + 6); printf("  ▣▣▣▣  ");
	gotoxy(x, y + 7); printf(" ▣▣  ▣▣ ");
	gotoxy(x, y + 8); printf("▣▣    ▣▣");
}

void printA(int x, int y)		//A 출력
{
	gotoxy(x, y);     printf("     ▣     ");
	gotoxy(x, y + 1); printf("    ▣▣    ");
	gotoxy(x, y + 2); printf("   ▣  ▣   ");
	gotoxy(x, y + 3); printf("  ▣    ▣  ");
	gotoxy(x, y + 4); printf("  ▣    ▣  ");
	gotoxy(x, y + 5); printf(" ▣▣▣▣▣ ");
	gotoxy(x, y + 6); printf(" ▣      ▣ ");
	gotoxy(x, y + 7); printf("▣        ▣");
	gotoxy(x, y + 8); printf("▣        ▣");
}

void printM(int x, int y)		//M 출력
{
	gotoxy(x, y);     printf("▣        ▣");
	gotoxy(x, y + 1); printf("▣▣    ▣▣");
	gotoxy(x, y + 2); printf("▣ ▣  ▣ ▣");
	gotoxy(x, y + 3); printf("▣  ▣▣  ▣");
	gotoxy(x, y + 4); printf("▣   ▣   ▣");
	gotoxy(x, y + 5); printf("▣        ▣");
	gotoxy(x, y + 6); printf("▣        ▣");
	gotoxy(x, y + 7); printf("▣        ▣");
	gotoxy(x, y + 8); printf("▣        ▣");
}

void printG(int x, int y)		//G 출력
{
	gotoxy(x, y);     printf("  ▣▣▣  ");
	gotoxy(x, y + 1); printf(" ▣    ▣  ");
	gotoxy(x, y + 2); printf("▣      ▣ ");
	gotoxy(x, y + 3); printf("▣      ▣  ");
	gotoxy(x, y + 4); printf("▣          ");
	gotoxy(x, y + 5); printf("▣  ▣▣▣▣");
	gotoxy(x, y + 6); printf("▣       ▣ ");
	gotoxy(x, y + 7); printf(" ▣    ▣▣ ");
	gotoxy(x, y + 8); printf("  ▣▣▣ ▣ ");
}