
void intro(void); //게임 시작 전 인트로 띄우고 이름 입력받기
void start_game(void); //게임 시작
void title(void);
void prologue(void);
void print_profile(void); //플레이어 정보를 맨 윗줄에 띄움

void display_menu(void); //메뉴 띄우기
int select_menu(void); //메뉴 선택

void printT(int x, int y);
void printE(int x, int y);
void printX(int x, int y);
void printG(int x, int y);
void printA(int x, int y);
void printM(int x, int y);
void gotoxy(int x, int y);//화면에 박스로 이뤄진 문자들을 배열해 출력하기위한 함수