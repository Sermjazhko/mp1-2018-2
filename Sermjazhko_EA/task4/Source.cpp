#include <stdio.h> 
#include <locale.h> 
#include <time.h> 
#include <stdlib.h> 
#include <string.h>
#define N 20

void main()
{
	setlocale(LC_ALL, "Rus");
	int products[5][4];//массив для штрихкодов
	int i, j, kup=0, shtrih=0, z[4], k, skid[5];//счетчик, переменная для завершения покупки, штрихкод
	int a=0, b=0;
	float w=0, p=0, q=0, Sum=0;//для вычисления цены
	char food[5][N], cen[5], s[5];//массив для продуктов
	srand(time(NULL));

	strcpy_s(food[0], "Молоко");
	strcpy_s(food[1], "Батон");
	strcpy_s(food[2], "Яйца дес.");
	strcpy_s(food[3], "Сок яблочный");
	strcpy_s(food[4], "Вода");

	cen[0] = 40;
	cen[1] = 31;
	cen[2] = 41;
	cen[3] = 46;
	cen[4] = 16;

	for (j = 0; j < 5; j++)//обнуление массива
		s[j] = 0;
    for (j = 0; j < 5; j++)//скидка
		skid[j] = 1 + rand() % 50;;
	for (i = 0; i < 5; i++)//ввод штрихкода
	{
		for (j = 0; j < 4; j++)
		{
			products[i][j] = i+j+1;
		}
	}
	printf("Штрихкоды товаров:\n");
	for (i = 0; i < 5; i++)//вывод на экран штрихкодов товаров с названиями
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d", products[i][j]);
		}
		printf(" - %s\n", food[i]);
	}
	while (shtrih < 3)
	{
		printf("Если хотите совершить покупку наберите 1 и введите штрихкод.\nЕсли вы хотите завершить покупку и сформировать чек, наберите 2.\n\n");
		scanf_s("%d", &shtrih);
		switch (shtrih)
		{
		case 1:
			printf("Введите штрихкод товара:\n");
		    scanf_s("%d", &shtrih);
			for (k = 3; k >= 0; k--)
			{
				z[k] = shtrih % 10;
				shtrih = shtrih / 10;
			}
			for (i = 0; i < 5; i++)//поиск штрихкода
			{
				for (k = 0; k < 4; k++)
				{
				    	a = a + z[k];
						a = a * 10;
						b = b + products[i][k];
						b = b * 10;	
				}
				if (a == b)
				{
					break;
				}
				else
				{
					a = 0;
					b = 0;
				}
			}
			s[i]++;
			printf("Продукт: %s, цена: %d руб., скидка: %d%%\n\n", food[i], cen[i], skid[i]);
			break;
		case 2:
			printf("\nЧек\n\n");
			for (i = 0; i < 5; i++)
			{
				if (s[i] != 0)
				{
					w = cen[i];
					p = (1.00 - skid[i] / 100.0);
					q = s[i];
					printf("%s (%dшт.), скидка: %d%%, цена товара: %2.2f руб.\n\n", food[i], s[i], skid[i], p*q*w);
					Sum = Sum + p * w * q;
				}
			}
			printf("\nОбщая цена за покупку: %2.2f руб.\n", Sum);
			scanf_s("%d", &i);
			break;
		default:
			while (shtrih != 1)
			{
				printf("Ошибка. Нажмите 1.\n");
				scanf_s("%d", &shtrih);
			}
			break;
		}
	}
}
