#include <stdio.h>
#include <stdbool.h> //bool ���ǵ�
int main()
{
	/*float i ;
	printf("������ ���ͷ��� �Է��Ͻʽÿ�.");
	scanf_s("%f", &i);
	printf("������ \"���ͷ�\"�� %.2f�Դϴ�.", i);*/
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
	//b2 = 2; //0�� �ƴϸ� ��� 1�� �����
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