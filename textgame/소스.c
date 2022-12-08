//textgame 개발
//20221796 서진배
//https://github.com/scienceNH/tetris
//인트로화면 띄우는 코드는 위 코드를 참고했습니다.

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#include "소스.h"
#include "대장간.h"
#include "던전.h"
#include "상점.h"
#include "인트로 및 메인화면.h"

#define true 1
#define false 0
#define and &&
#define or ||

//플레이어와 몬스터를 구조체를 통해 생성

extern Player player = { "무명의 모험가", 1, 1000, 100, 100 };

extern Monster monster = { "몬스터", 0, 0, 0, 0 };

//게임에 활용될 함수

void ending(void); //게임 클리어시 게임 끝내기

//void exit(void); //메인 화면으로 이동
//void end_game(void); //게임 종료
//반복문으로 탈출을 구현해서 따로 필요 x


int main(void)
{
	srand(time(0));
	intro();
	start_game();
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