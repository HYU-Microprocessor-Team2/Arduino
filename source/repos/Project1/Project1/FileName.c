#include <stdio.h>
#include <stdbool.h> //bool 정의됨
int main()
{
	/*float i ;
	printf("오늘의 수익률을 입력하십시오.");
	scanf_s("%f", &i);
	printf("오늘의 \"수익률\"은 %.2f입니다.", i);*/
	/*int i;
	for ( i = 0; i < 128; i++)
	{
		printf("%d=%c\t", i, i);
	}*/

	/*printf("%c\n", 'a');
	printf("%d\n", 'a');
	printf("%d\n", 7);
	printf("%c\n", '7');
	printf("%d\n", '7');*/

	//_Bool b1, b2;
	//b1 = 0;
	//b2 = 2; //0이 아니면 모두 1로 저장됨
	//
	//bool b3, b4;
	//b3 = false;
	//b4 = true;
	//printf("%d %d %d %d", b1, b2, b3, b4);
	//					// 0  0   1   1	 


	enum days{sun,mon,tue,wed,thur=7,fri,sat}a1,a2,a6;
	enum days a8;
	a8 = sun;
	a1 = sun;
	a2 = mon;
	a6 = fri;
	printf("a1=%d,  a6=%d,  a8=%d\n", a1, a6, a8);


	




	return 0;
	
}