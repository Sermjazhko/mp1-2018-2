#include <stdio.h> 
#include <locale.h> 
#include <time.h> 
#include <stdlib.h> 
#include <string.h>
#define N 20

void main()
{
  setlocale(LC_ALL, "Rus");

  int products[5][4];//������ ��� ����������
  int i, j, kup = 0, shtrih = 0, z[4], k, skid[5];//�������, ���������� ��� ���������� �������, ��������
  int a = 0, b = 0;
  float w = 0, p = 0, q = 0, Sum = 0;//��� ���������� ����
  char food[5][N], cen[5], s[5];//������ ��� ���������

  srand(time(NULL));

  strcpy_s(food[0], "������");
  strcpy_s(food[1], "�����");
  strcpy_s(food[2], "���� ���.");
  strcpy_s(food[3], "��� ��������");
  strcpy_s(food[4], "����");

  cen[0] = 40;
  cen[1] = 31;
  cen[2] = 41;
  cen[3] = 46;
  cen[4] = 16;

  for (j = 0; j < 5; j++)//��������� �������
    s[j] = 0;
  for (j = 0; j < 5; j++)//������
    skid[j] = 1 + rand() % 50;;
  for (i = 0; i < 5; i++)//���� ���������
    for (j = 0; j < 4; j++)
      products[i][j] = i + j + 1;
  printf("��������� �������:\n");
  for (i = 0; i < 5; i++)//����� �� ����� ���������� ������� � ����������
  {
    for (j = 0; j < 4; j++)
      printf("%d", products[i][j]);
    printf(" - %s\n", food[i]);
  }
  while (shtrih < 3)
  {
    printf("���� ������ ��������� ������� �������� 1 � ������� ��������.\n���� �� ������ ��������� ������� � ������������ ���, �������� 2.\n\n");
    scanf_s("%d", &shtrih);
    switch (shtrih)
    {
    case 1:
      printf("������� �������� ������:\n");
      scanf_s("%d", &shtrih);
      for (k = 3; k >= 0; k--)
      {
        z[k] = shtrih % 10;
        shtrih = shtrih / 10;
      }
      for (i = 0; i < 5; i++)//����� ���������
      {
        for (k = 0; k < 4; k++)
        {
          a = a + z[k];
          a = a * 10;
          b = b + products[i][k];
          b = b * 10;
        }
        if (a == b)
          break;
        else
        {
          a = 0;
          b = 0;
        }
      }
      s[i]++;
      printf("�������: %s, ����: %d ���., ������: %d%%\n\n", food[i], cen[i], skid[i]);
      break;
    case 2:
      printf("\n���\n\n");
      for (i = 0; i < 5; i++)
        if (s[i] != 0)
        {
          w = cen[i];
          p = (1.00 - skid[i] / 100.0);
          q = s[i];
          printf("%s (%d��.), ������: %d%%, ���� ������: %2.2f ���.\n\n", food[i], s[i], skid[i], p*q*w);
          Sum = Sum + p * w * q;
        }
      printf("\n����� ���� �� �������: %2.2f ���.\n", Sum);
      scanf_s("%d", &i);
      break;
    default:
      while (shtrih != 1)
      {
        printf("������. ������� 1.\n");
        scanf_s("%d", &shtrih);
      }
      break;
    }
  }
}