#include <stdio.h> 
#include <locale.h> 
#include <time.h> 
#include <stdlib.h> 

void main()
{
	setlocale(LC_ALL, "Rus");
	int n, i, mass[5], r1; //�����, �������, ������ �������, ��������� 
	int kor, byk, mas[5], m, a, k, N=0; //������, ����, ������ �����, �������, ���� �����, ������� 

	srand(time(NULL));
	printf("����: ������ � ����!\n ������� ����� ������������� ����� (�� 2 �� 5)\n");
	scanf_s("%d", &n);

	while ((n < 2) || (n > 5))
	{
		printf("������� ������� ����� ������������� �����. ���������� ��� ���\n");
		scanf_s("%d", &n);
	}

	r1 = 1;
	while (r1 == 1)//1 jib,rf 
	{
		r1 = 0;
		i = 0;
		while (i < n)
		{
			if (i == 0)
				mass[i] = 1 + rand() % 9;
			else

				mass[i] = rand() % 10;
			i++;
		}
		for (i = 0; i < n; i++)
			for (k = i + 1; k < n; k++) //2 jib 
			{
				//printf("!"); 
				if (mass[i] == mass[k])
				{
					r1 = 1;
					break;
					//printf("%d", mass[i]); 
				}
				//printf("!"); 
			}

	}
	byk = 0;
	while (byk != n)
	{
		printf("���� �������������?\n");
		scanf_s("%d", &a);
		byk = 0;
		kor = 0;
		N++;
		for (i = n - 1; i >= 0; i--)
		{
			m = a % 10;
			mas[i] = m;
			a = (a - m) / 10;
		}
		for (i = 0; i < n; i++)
		{
			if (mas[i] == mass[i])
				byk++;
			else
			{
				for (k = 0; k < n; k++)
				{
					if (mas[i] == mass[k])
						kor++;
				}
			}
		}
		printf("�����: %d, �����: %d \n", byk, kor);
	}

	printf("����������, �� ��������! ���������� �������: %d\n", N);
	scanf_s("%d", a);
}