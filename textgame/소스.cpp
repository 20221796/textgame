//textgame 개발
//20221796 서진배
//https://github.com/scienceNH/tetris
//인트로화면 띄우는 코드는 위 코드를 참고했습니다.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
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
int summon_monster(int floor); //몬스터 소환
void start_battle(void); //전투 시작

void goto_smithy(void); //대장간으로 이동
void upgrade_equipment(void); //장비 강화

void goto_shop(void); //상점으로 이동
void charge_cash(void); //골드를 충전

void ending(void); //게임 클리어시 게임 끝내기

//void exit(void); //메인 화면으로 이동
//void end_game(void); //게임 종료
//반복문으로 탈출을 구현해서 따로 필요 x

void display_menu(void); //메뉴 띄우기
int select_menu(void); //메뉴 선택

void printT(int x, int y);
void printE(int x, int y);
void printX(int x, int y);
void printG(int x, int y);
void printA(int x, int y);
void printM(int x, int y);

void gotoxy(int x, int y) //화면에 박스로 이뤄진 문자들을 배열해 출력하기위한 함수
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main(void)
{
	srand(time(0));
	intro();
	start_game();
}



void intro(void) //시작화면을 출력하는 함수
{
	title();

	printf("이름을 입력해 주세요 : ");
	scanf("%s", name);

	printf("\n%s님 환영합니다. \n아무 키나 누르면 게임이 시작됩니다. ", name);
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

void start_game(void) //게임을 진행하는 함수
{
	int end_game = false;

	prologue();
	while (!end_game)
	{
		display_menu();
		end_game = select_menu();
	}
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
	hp = level * 1000;
	ad = level * 100;
	printf("이름 : %s \n", name);
	printf("Lv%d  체력: %d  공격력: %d  보유 골드: %d \n\n", level, hp, ad, gold);
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
	printf("\n10000골드를 충전했습니다\t 골드 %d -> %d \n", gold, gold + 10000);
	gold += 10000;
}

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
	if (level >= 99) printf("\n최대 레벨입니다 \n");
	else if (gold - 100 * level < 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("\n대장장이");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf(" : 하하하 골드가 부족하군! 아쉽게도 무료봉사는 아니라네. \n");
	}
	else
	{
		printf("\n골드를 소모합니다\t 골드 %d -> %d \n", gold, gold - 100 * level);
		gold -= 100 * level;
		int success_rate = rand() % level + 1; //레벨이 1 오를 때마다 강화 확률을 낮춤

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		Sleep(500);
		printf("투쾅 투쾅 투쾅!\n");

		if (success_rate == level) //(1÷레벨)의 확률로 강화가 성공하도록 설정
		{
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("\n대장장이");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf(" : 음하하핳하 나같은 대장장이를 만난 걸 행운으로 알라고 친구!\n\n");
			Sleep(500);
			printf("(장비 제련에 성공했습니다  레벨 %d -> %d) \n", level, level + 1);

			level += 1;
		}
		else
		{
			Sleep(500);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			printf("\n대장장이");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf(" : 어이쿠! 허허허... 원래 원숭이도 나무에서 떨어지는 법이라네\n");
			Sleep(500);
			printf("(장비 제련에 실패했습니다 레벨이 그대로 유지됩니다.) \n");
		}
	}
}

void goto_dungeon(void) //던전에 입장하는 함수
{
	int menu = 0;
	static int floor = 1;

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
		if (!summon_monster(floor)) //만약 summon_monster 반환값이 false이면 던전 클리어
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
			//start_battle();
		}
		else if (menu != 2) printf("몬스터에게 겁에 질려 판단력이 흐려졌군요... 선택지는 1과 2뿐입니다. \n\n");
	} while (menu != 2);

	Sleep(500);
	printf("던전에서 탈출합니다... \n");
	Sleep(500);
	printf("슉슈 슉슈 슉슈");
	Sleep(500);
}

int summon_monster(int floor) //층수에 맞는 몬스터를 설정하는 함수
{
	if (floor > 99) return false; //99층 이상이면 몬스터를 소환하지 않음
	else
	{
		if (floor % 10 == 9) summon_boss(floor);
		else summon_common(floor);
		return true;
	}
}

void summon_boss(int floor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	Sleep(500);
	printf("[경고] 지하 %d층까지 와 보스 몬스터가 출현합니다. \n", floor);
	printf("보스 몬스터와의 전투에서는 중간에 도망가는 것이 불가능하며 죽으면 레벨이 1이 됩니다.");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void summon_common(int floor)
{
	printf("지하 %d 층 몬스터 %s가 출현합니다. ");
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