#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int n, ran, i, q, r; //���������� ���� � �����, ������

	srand(time(NULL));
	printf("������� ����� ������������� ����� (�� 2 �� 4)\n");
	scanf_s("%d", &n);
	//������� �����
	if (n == 2)
	{ 
		ran = rand()%100;
		i = ran;
		q = i / 10;
		r = i % 10;
		while (q==r)//���� ��� ������� �� 10 ������� � ������� �����, �� ������
		{
			ran = rand() % 100;
			i = ran;
		}
		printf("����� ��������. ���������, ��� ����� ����������, ���� �������������?\n");
		scanf_s("%d%d", &i1, &j1);
	}
	else
	{
		if (n == 3)
		{
			ran1 = 1 + rand() % 9;
			i = ran1;
			ran2 = rand() % 10;
			j = ran2;
			ran3 = rand() % 10;
			d = ran3;
			while ((j == i) || (i == d) || (j == d))//���� ��� ������� �� 100 �������, ������� ��� ������� �� 10 � ������� ������� �����, �� ������
			{
				ran2 = rand() % 10;
				j = ran2;
				ran3 = rand() % 10;
				d = ran3;
			}
			printf("����� ��������. ���������, ��� ����� �����������, ���� �������������?\n");
			scanf_s("%d%d%d", &i1, &j1, &d1);
		}
		else
		{
			ran1 = 1 + rand() % 9;
			i = ran1;
			ran2 = rand() % 10;
			j = ran2;
			ran3 = rand() % 10;
			d = ran3;
			ran4 = rand() % 10;
			l = ran4;
			while ((j == i) || (i == d) || (j == d)||( i == l )||( j == l )||( d == l ))//���� ��� ������� �� 1000 �������, ������� ��� ������� �� 100, ������� �� ������� �� 10 � ��������� ���. �����, �� ������
			{
				ran2 = rand() % 10;
				j = ran2;
				ran3 = rand() % 10;
				d = ran3;
				ran4 = rand() % 10;
				l = ran4;
			}
			printf("����� ��������. ���������, ��� ����� ��������������, ���� �������������?\n");
			scanf_s("%d%d%d%d", &i1, &j1, &d1, &l1);
		}

	}

}