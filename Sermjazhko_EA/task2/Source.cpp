#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "Rus");
	int rezh1, chis, chis1, n, random, r1, r2;

	srand(time(NULL));
	printf("�������� ����� 1 ��� 2\n");
	scanf_s("%i", &rezh1);
	n = 1;

	if (rezh1 == 1)
	{
		printf("��������� ������� ����� �� 1 �� 1000. ���������� �������� ���. ������� ����� �� 1 �� 1000\n");
		scanf_s("%i", &chis);
		while ((chis > 1000) || (chis < 1))
		{
			printf("������ ������� �������. ���������� ��� ��� (�� 1 �� 1000)\n");
			scanf_s("%i", &chis);
		}
		random = 1 + rand() % 1000;
		if (chis == random)
			printf("�� �������� �����. ���������� �������: 1");
		else
		{
			while (chis > random || chis < random)
			{
				if (chis > random)
				{
					printf("���������� ����� ������ ������\n"); 
				}
				else
				{
					printf("���������� ����� ������ ������\n");
				}
				scanf_s("%i", &chis);
				n++;
			}
			printf("�� ������� �����! ���������� �������: %i", n);
		}
	}
	else
	{
		printf("��������� ����� � ��������� �� 1 �� 1000, � ��������� ���������� ��� ��������\n");
		scanf_s("%i", &chis);

		while ((chis > 1000) || (chis < 1))
		{
			printf("������ ������� �������. ���������� ��� ��� (�� 1 �� 1000)\n");
			scanf_s("%i", &chis);
		}

		printf("���� ����� %i (�����������)\n", chis);
		random = 1 + rand() % 1000;
		chis1 = 0;
		printf("�� ��������: %i?\n ���� ��(=), ��������: 1\n ���� ���� ����� ������(>), ��������: 2\n ���� ������(<), ��������: 3 \n", random);
		scanf_s("%i", &chis1);
		r1 = 1;
		r2 = 1000;

		if (chis1 == 1)
			printf("��������� ������ ����� � 1 �������\n");
		else
		{
			while ((chis1 == 2) || (chis1 == 3))
			{
				if (chis1 == 2)
				{
					r1 = random;
					random = 1 + random + rand() % (r2-random);
					printf("�� ��������: %i?\n ���� ��(=), ��������: 1\n ���� ���� ����� ������(>), ��������: 2\n  ���� ������(<), ��������: 3 \n", random);
					scanf_s("%i", &chis1);
				}
				else 
				{
					r2 = random;
					random = 1 + random - rand() % (r1-random);
					printf("�� ��������: %i?\n ���� ��(=), ��������: 1\n ���� ���� ����� ������(>), ��������: 2\n  ���� ������(<), ��������: 3 \n", random);
					scanf_s("%i", &chis1);
				}
				n++;
			}
			printf("��������� ������ �����. ���������� �������: %i\n", n);
		}
			 
	}

}
