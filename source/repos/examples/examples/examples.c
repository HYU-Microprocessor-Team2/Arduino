#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
int main(void)
{
	/*int i, j;
	for (i = 2; i < 10; i++)
	{
		printf("%d단 계산", i);
		for (j = 1; j < 10; j++)
		{
			printf("%d X %d = %d\n", i, j, i * j);

		}
	}*/

	/*int i, j,floor,k;
	printf("몇 층을 입력하시오:");
	scanf_s("%d", &floor);
	for ( i = 0; i < floor ; i++)
	{
		for (j = i; j < floor - 1; j++)
		{
			printf(" ");
		}
		for ( k = 0; k < 2*i+1; k++)
		{
			printf("*");
		}
		printf("\n");
	}*/
	
	/*int age;
	printf("나이를 입력하십시오.");
	scanf_s("%d", &age);
	if (age>=8 && age<=13)
	{
		printf("어린이입니다.");
	}
	else if (age>=14 && age<=19)
	{
		printf("학생입니다.");
	}
	else
	{
		printf("어른입니다.");
	}
	
	int i;
	for ( i = 1; i <=30; i++)
	{
		if (i >= 6)
		{
			printf("나머지 학생은 집에 가세요\n");
			break;
		}
		printf("%d번 학생은 발표준비하세요.\n", i);
	
	}
	// continue문 
	
	int i;
	for(i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10) {
			if (i == 7) {
				printf("%d번 학생은 결석입니다\n", i);
				continue;
			}
			printf("%d번 학생은 발표하세요\n", i);

		}
	}*/

	// Random
	/*srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		printf("%d", rand() % 10);
	}
	//srand = 난수초기화
	//여기서 for의 i범위 = 표현하고 싶은 글자 수
	//rand()%10 = 여기서 10은 랜덤범위 (0-9)
	*/

	/*char ch1, ch2;

	printf("문자를 두 개를 입력하세요");
	scanf_s("%c %c", &ch1,1, &ch2,2);
	printf("입력받은 문자는 %c와 %c입니다.", ch1, ch2);*/

	//char ch = 'a';
	//ch=getchar(); // getchar()함수의 리턴값인 키보드로 입력받은 문자를 ch에 저장
	//printf("%c", ch);

	/*char name[10];
	printf("당신의 이름을 입력하세요");
	scanf_s("%s", &name,sizeof(name));
	printf("당신의 이름은 %s입니다\n", name);*/

	//char name[10];

	//puts("당신의 이름을 입력하세요=");
	//gets_s(name, sizeof(name)); //scanf("%s",name);//scanf_s("%s",name,sizeof(name));
	////온라인 컴파일러에서는 gets(name);을 사용

	//puts("당신의 이름은");
	//puts(name);

//char ch;
//printf("getchar()함수\n");
//ch = getchar(); //getchar()함수를 실행한 후 그 결과값(리턴값)을 ch에 대입
//putchar(ch); putchar("\n");
//
//printf("_getch()함수\n");
//ch = _getch();
//putchar(ch); putchar('\n');
//
//printf("_getche()함수\n");
//ch = _getche();
//putchar(ch); putchar('\n');

//int kor, eng;
//double avg;
//printf("총점과 평균을 구하는 프로그램입니다\n");
//printf("국어 점수를 입력하고 ENTER을 누르세요");
//scanf("%d", &kor);
//printf("영어 점수를 입력하고 ENTER을 누르세요");
//scanf("%d", &eng);
//double	total = kor + eng;
//avg = total / 2.0;
//printf("당신의 총점은 ""%.1lf""이고 평균은 ""%.1lf""입니다.", total, avg);





	return 0;

}