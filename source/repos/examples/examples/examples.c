#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
int main(void)
{
	/*int i, j;
	for (i = 2; i < 10; i++)
	{
		printf("%d�� ���", i);
		for (j = 1; j < 10; j++)
		{
			printf("%d X %d = %d\n", i, j, i * j);

		}
	}*/

	/*int i, j,floor,k;
	printf("�� ���� �Է��Ͻÿ�:");
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
	printf("���̸� �Է��Ͻʽÿ�.");
	scanf_s("%d", &age);
	if (age>=8 && age<=13)
	{
		printf("����Դϴ�.");
	}
	else if (age>=14 && age<=19)
	{
		printf("�л��Դϴ�.");
	}
	else
	{
		printf("��Դϴ�.");
	}
	
	int i;
	for ( i = 1; i <=30; i++)
	{
		if (i >= 6)
		{
			printf("������ �л��� ���� ������\n");
			break;
		}
		printf("%d�� �л��� ��ǥ�غ��ϼ���.\n", i);
	
	}
	// continue�� 
	
	int i;
	for(i = 1; i <= 30; i++)
	{
		if (i >= 6 && i <= 10) {
			if (i == 7) {
				printf("%d�� �л��� �Ἦ�Դϴ�\n", i);
				continue;
			}
			printf("%d�� �л��� ��ǥ�ϼ���\n", i);

		}
	}*/

	// Random
	/*srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		printf("%d", rand() % 10);
	}
	//srand = �����ʱ�ȭ
	//���⼭ for�� i���� = ǥ���ϰ� ���� ���� ��
	//rand()%10 = ���⼭ 10�� �������� (0-9)
	*/

	/*char ch1, ch2;

	printf("���ڸ� �� ���� �Է��ϼ���");
	scanf_s("%c %c", &ch1,1, &ch2,2);
	printf("�Է¹��� ���ڴ� %c�� %c�Դϴ�.", ch1, ch2);*/

	//char ch = 'a';
	//ch=getchar(); // getchar()�Լ��� ���ϰ��� Ű����� �Է¹��� ���ڸ� ch�� ����
	//printf("%c", ch);

	/*char name[10];
	printf("����� �̸��� �Է��ϼ���");
	scanf_s("%s", &name,sizeof(name));
	printf("����� �̸��� %s�Դϴ�\n", name);*/

	//char name[10];

	//puts("����� �̸��� �Է��ϼ���=");
	//gets_s(name, sizeof(name)); //scanf("%s",name);//scanf_s("%s",name,sizeof(name));
	////�¶��� �����Ϸ������� gets(name);�� ���

	//puts("����� �̸���");
	//puts(name);

//char ch;
//printf("getchar()�Լ�\n");
//ch = getchar(); //getchar()�Լ��� ������ �� �� �����(���ϰ�)�� ch�� ����
//putchar(ch); putchar("\n");
//
//printf("_getch()�Լ�\n");
//ch = _getch();
//putchar(ch); putchar('\n');
//
//printf("_getche()�Լ�\n");
//ch = _getche();
//putchar(ch); putchar('\n');

//int kor, eng;
//double avg;
//printf("������ ����� ���ϴ� ���α׷��Դϴ�\n");
//printf("���� ������ �Է��ϰ� ENTER�� ��������");
//scanf("%d", &kor);
//printf("���� ������ �Է��ϰ� ENTER�� ��������");
//scanf("%d", &eng);
//double	total = kor + eng;
//avg = total / 2.0;
//printf("����� ������ ""%.1lf""�̰� ����� ""%.1lf""�Դϴ�.", total, avg);





	return 0;

}