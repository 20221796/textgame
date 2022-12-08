//test case code
// 
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//#define and &&
//
//int level = 5;
//
//void a(void);
//
//
//int main(void)
//{
//	srand(time(0));
//	a();
//	return 0;
//}
//
//void a(void)
//{
//	int scnt = 0;
//	int fcnt = 0;
//
//	for (int i = 0; i < 1000; i++)
//	{
//		int success_rate = rand() % level + 1; //·¹º§ÀÌ 1 ¿À¸¦ ¶§¸¶´Ù °­È­ È®·üÀ» ³·Ãã
//
//		if (success_rate == level) scnt++;
//		else fcnt++;
//	}
//
//	printf("¼º°ø È®·ü: %.1f% \n", float(scnt)/10);
//	printf("½ÇÆÐ È®·ü: %.1f% \n", float(fcnt)/10);
//}