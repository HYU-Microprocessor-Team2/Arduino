# include <stdio.h>

int main_printscanf() {
	// ������ ����
	/*printf("Hello world \n");
	*/
	
	//printf("1\n");
	//printf("2\n");
	//printf("3\n");
	

	//�Ǽ��� ����
	/*float f = 46.5f;
	printf("%.2f\n", f);// float�� f �Է�
	double d = 4.428;
	printf("%.2lf\n", d);// double�� lf�Է�
	*/

	// ����� ����

	//const int YEAR = 2000;
	//printf("�¾ ���� : %d\n", YEAR);
	//YEAR = 2001;
	
	//pritnf
	// ����
	//int add = 3 + 7;//10
	//printf("3+7=%d",add);
	//printf("%d+%d=%d\n",3, 7, 3 + 7);

	//scanf
	//Ű���� �Է��� �޾� ����

	/*int input;
	printf("���� �Է��ϼ��� : ");
	scanf_s("%d", &input);
	printf("�Է°� : %d\n", input);*/

	/*int one, two, three;
	printf("3���� ������ �Է��ϼ��� : ");
	scanf_s("%d %d %d", &one, &two, &three);
	printf("ù��° �� : %d\n", one);
	printf("�ι�° �� : %d\n", two);
	printf("����° �� : %d\n", three);*/
	
	// ����(�� ����) ���ڿ�(�� ���� �̻��� ���� ����)

	//char c = 'A';
	//printf("%c\n", c);

	//���ڿ�

	//char str[256];
	//scanf_s("%s", str,sizeof(str));
	//printf("%s\n", str);

	//������Ʈ

	char name[256];
	printf("�̸��� ������?");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("����̿���?");
	scanf_s("%d", &age);

	float weight;
	printf("�����Դ� �� kg�̿���?");
	scanf_s("%f", &weight);

	double height;
	printf("Ű�� ���̿���?");
	scanf_s("%lf", &height);
	
	char what[256];
	printf("���˸��� ������?");
	scanf_s("%s", what, sizeof(what));
	

	//�������� ���

	/*printf("\n\n-----������ ����------\n\n");
	printf("�̸�      : %s\n", name);
	printf("����      : %d\n", age);
	printf("������      : %.2f\n", weight);
	printf("Ű      : %.2lf\n", height);
	printf("���˸�      : %s\n", what);
	*/





	
	
	
	
	return 0;
}