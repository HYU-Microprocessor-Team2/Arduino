# include <stdio.h>

int main_printscanf() {
	// 정수형 변수
	/*printf("Hello world \n");
	*/
	
	//printf("1\n");
	//printf("2\n");
	//printf("3\n");
	

	//실수형 변수
	/*float f = 46.5f;
	printf("%.2f\n", f);// float는 f 입력
	double d = 4.428;
	printf("%.2lf\n", d);// double은 lf입력
	*/

	// 상수형 변수

	//const int YEAR = 2000;
	//printf("태어난 연도 : %d\n", YEAR);
	//YEAR = 2001;
	
	//pritnf
	// 연산
	//int add = 3 + 7;//10
	//printf("3+7=%d",add);
	//printf("%d+%d=%d\n",3, 7, 3 + 7);

	//scanf
	//키보드 입력을 받아 저장

	/*int input;
	printf("값을 입력하세요 : ");
	scanf_s("%d", &input);
	printf("입력값 : %d\n", input);*/

	/*int one, two, three;
	printf("3개의 정수를 입력하세요 : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("첫번째 값 : %d\n", one);
	printf("두번째 값 : %d\n", two);
	printf("세번째 값 : %d\n", three);*/
	
	// 문자(한 글자) 문자열(한 글자 이상의 여러 글자)

	//char c = 'A';
	//printf("%c\n", c);

	//문자열

	//char str[256];
	//scanf_s("%s", str,sizeof(str));
	//printf("%s\n", str);

	//프로젝트

	char name[256];
	printf("이름이 뭐에요?");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("몇살이에요?");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게는 몇 kg이에요?");
	scanf_s("%f", &weight);

	double height;
	printf("키가 몇이에요?");
	scanf_s("%lf", &height);
	
	char what[256];
	printf("범죄명이 뭐에요?");
	scanf_s("%s", what, sizeof(what));
	

	//조서내용 출력

	/*printf("\n\n-----범죄자 정보------\n\n");
	printf("이름      : %s\n", name);
	printf("나이      : %d\n", age);
	printf("몸무게      : %.2f\n", weight);
	printf("키      : %.2lf\n", height);
	printf("범죄명      : %s\n", what);
	*/





	
	
	
	
	return 0;
}