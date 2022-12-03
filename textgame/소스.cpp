#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define true 1
#define false 0
#define and &&
#define or ||

//게임에 활용될 전역변수
char name[30] = "무명의 모험가";
int level = 1;
int hp = level * 1000;
int ad = level * 100;
int gold = 100;

//게임에 활용될 함수
void intro(void); //게임 시작 전 인트로 띄우고 이름 입력받기
void start_game(void); //게임 시작
void title(void);
void prologue(void);
void print_profile(void); //플레이어 정보를 맨 윗줄에 띄움

void goto_dungeon(void); //던전으로 이동
void start_battle(void); //전투 시작

void goto_smithy(void); //대장간으로 이동
void upgrade_equipment(void); //장비 강화

void goto_shop(void); //상점으로 이동
void charge_cash(void); //골드를 충전

void exit(void); //메인 화면으로 이동
void end_game(void); //게임 종료

void display_menu(void); //메뉴 띄우기
int select_menu(void); //메뉴 선택

void printT(int x, int y);
void printE(int x, int y);
void printX(int x, int y);
void printG(int x, int y);
void printA(int x, int y);
void printM(int x, int y);

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(void)
{
	intro();
	start_game();
}



void intro(void)
{
	title();

	printf("이름을 입력해 주세요 : ");
	scanf("%s", name);

	printf("\n%s님 환영합니다. \n아무 키나 누르면 게임이 시작됩니다. ", name);
	getch();
}

void title(void)
{
	int x = 14;

	system("cls");		//화면 초기화 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //텍스트 색상 변경
	printT(0, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //1:파랑 2:초록 3:민트 4:빨강 6:노랑 7:하양
	printE(x, 2);													//9:연한 파랑 10:연두 11:연한 민트 12:연한 빨강 14: 연한 노랑
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

void start_game(void)
{
	int end_game = false;
	prologue();
	while (!end_game)
	{
		display_menu();
		end_game = select_menu();;
	}
}

void prologue(void)
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

void display_menu(void)
{
	title();
	print_profile();
	
	printf("무엇을 할지 선택해주세요 \n");
	printf("1. 던전으로 이동 2. 대장간으로 이동 3. 상점으로 이동 4. 게임 종료 \n\n");
}

void print_profile(void)
{
	printf("이름 : %s \n", name);
	printf("Lv%d  체력: %d  공격력: %d  보유 골드: %d \n\n", level, hp, ad, gold);
	//printf("치명타 확률 : %f \n\n"); //추후 구현
}

int select_menu(void)
{
	int menu = 0; 
	printf("1 2 3 4 중 선택 : ");
	scanf("%d", &menu);

	//if (menu == 1)
	//{
	//	printf("던전으로 이동합니다... \n");
	//	Sleep(500); //0.5초 대기
	//	printf("슈슉 슈슉 슈슉");
	//	Sleep(500);
	//	//goto_dungeon();
	//}
	//else if (menu == 2)
	//{
	//	printf("대장간으로 이동합니다... \n");
	//	Sleep(500);
	//	printf("슈슉 슈슉 슈슉");
	//	Sleep(500);
	//	goto_smithy();
	//}
	//else if (menu == 3)
	//{
	//	printf("상점으로으로 이동합니다... \n");
	//	Sleep(500);
	//	printf("슈슉 슈슉 슈슉");
	//	Sleep(500);
	//	//goto_shop();
	//}
	//else if (menu == 4)
	//{
	//	printf("게임을 종료합니다");
	//	Sleep(500);
	//	//end_game();
	//}
	//else printf("잘못된 메뉴를 선택했습니다. 다시 선택해주세요 \n");

	switch (menu)
	{
	case 1:
		printf("던전으로 이동합니다... \n");
		Sleep(500); //0.5초 대기
		printf("슈슉 슈슉 슈슉");
		Sleep(500);
		//goto_dungeon();
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
		//goto_shop();
		break;

	case 4:
		printf("게임을 종료합니다");
		Sleep(500);
		return true;

	default:
		printf("잘못된 메뉴를 입력했습니다, 다시 입력해주세요.");
	}
	return false;

}

void goto_smithy(void)
{
	int menu = 0;
	title();
	print_profile();

	printf("대장간으로 이동했습니다. \n\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("깡! 깡! 깡! (뜨거운 열기가 느껴진다) \n\n");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("대장장이");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf(" : 모험가 친구 무엇을 하려고? \n");
	
	do
	{
		printf("1. 장비 재련 2. 대장간에서 나가기 \n");
		printf("1 2 중 선택 : ");
		scanf("%d", &menu);

		if (menu == 1)
		{
			upgrade_equipment();
		}
		else printf("잘못된 메뉴를 선택했습니다. 다시 선택해주세요. \n");
	} while (menu != 2);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printf("대장장이");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	printf(" : 다음에 또 오라고! \n");

	printf("대장간에서 나갑니다... \n");
	Sleep(500);
	printf("슉슈 슉슈 슉슈");
	Sleep(500);
}

void goto_shop(void)
{

}


void goto_dungeon(void)
{

}

void end_game(void)
{

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