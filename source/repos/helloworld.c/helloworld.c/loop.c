#include <stdio.h>	

int main(void)
{
	/*for (int i = 1; i <= 10; i++)
	{
		printf("Hello World\n",i);
	}*/
	/*int i = 1;
	while (i <= 10)
	{
		printf("Hello World\n", i);
		i++;
	}*/
	// do while

	/*int i = 1;
	do {
		printf("Hello World\n",i++);
	} while (i <= 10);
	{
	*/
	// 구구단

	/*for (int i = 2; i <= 9; i++)
	{
		printf("%d단 계산\n", i);
		for (int j = 1; j <= 9; j++)
		{
			printf("  %d x %d = %d\n", i, j, i * j);
		}
	}*/

	/*for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("*");
		}
		printf("\n");
	}*/

	/*int floor;
	printf("몇 층으로 쌓을거냐?");
	scanf_s("%d", &floor);
	for ( int i = 0; i < floor; i++)
	{
		for (int j = i; j < floor - 1; j++)
		{
			printf(" ");
		}
			for (int k = 0; k < i * 2 + 1; k++)
			{
				printf("*");

			}
		printf("\n");
	}*/

	int i, j;
	for ( i = 2; i < 10; i++)
	{
		printf("%d단 계산", i);
		for (j = 1; j < 10; j++)
		{
			printf("%d X %d = %d", i, j, i * j);

		}
	}



	






	return 0;

}
