#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#include <io.h> 
#include <time.h>
#include <string.h>
#include <locale.h>
void Bub(unsigned long *a, char b[10000][32], char *direct, long number)
{
  int i, j, puz;
  char buffer[260];
  for (i = 0; i < number; i++) //сортировка пузырьком 
    for (j = (number - 1); j > i; j--)
      if (a[j] < a[j - 1])
      {
        puz = a[j];
        a[j] = a[j - 1];
        a[j - 1] = puz;
        strncpy(buffer, b[j], 32);
        strncpy(b[j], b[j - 1], 32);
        strncpy(b[j - 1], buffer, 32);
      }
}
void Cho(unsigned long *a, char b[10000][32], char *direct, long number)
{
  int i, j, puz, vb;
  char buffer[260];

  for (i = 0; i < number; i++)//выбором
  {
    puz = i;
    vb = a[i];
    for (j = i + 1; j < number; j++)
      if (a[j] > vb)
      {
        puz = j;
        vb = a[j];

      }
    a[puz] = a[i];
    a[i] = vb;
    strncpy(buffer, b[puz], 32);
    strncpy(b[puz], b[i], 32);
    strncpy(b[i], buffer, 32);
  }
}
void Sort(unsigned long *a, char b[10000][32], char *direct, long number) //Хоара
{
  long i = 0, j = number - 1;
  unsigned long temp, mid;
  char buffer[260];
  mid = a[number >> 1];
  do
  {
    while (a[i] < mid)
      i++;
    while (a[j] > mid)
      j--;
    if (i <= j)
    {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      strncpy(buffer, b[i], 32);
      strncpy(b[i], b[j], 32);
      strncpy(b[j], buffer, 32);
      i++;
      j--;
    }
  } while (i <= j);
  if (j > 0)
    Sort(a, b, direct, j + 1);
  if (number > i)
    Sort(a + i, b + i, direct, number - i);
}
void Ins(unsigned long *a, char b[10000][32], char *direct, long number) //Вставками
{
  int x;
  long i, j;
  char buffer[260];
  for (i = 0; i < number; i++)
  {
    x = a[i];
    for (j = i - 1; j >= 0 && a[j] > x; j--)
    {
      a[j + 1] = a[j];
      strncpy(buffer, b[j + 1], 32);
      strncpy(b[j + 1], b[j], 32);
      strncpy(b[j], buffer, 32);
    }
    a[j + 1] = x;
  }
}
char file_names[10000][32];
unsigned long file_sizes[10000];
int main(void)
{
  setlocale(LC_ALL, "Rus");
  int i;
  struct _finddata_t c_file;
  intptr_t hFile;
  char direct[260];
  int number = 0, sorting = 1;
  clock_t t1, t2;
  double tt = 0;
  printf("Ведите путь до директории\n");
  do
  {
    gets_s(direct, 260);
    strcat(direct, "*");
    if ((hFile = _findfirst(direct, &c_file)) == -1L)
      printf("Пути %s не существует! Попробуйте ещё раз:\n", direct);
    else
    {
      printf("Список файлов в %s\n\n", direct);
      printf("Файлы             Размер\n", ' ');
      printf("----                ----\n", ' ');
      do
      {
        strncpy(file_names[number], c_file.name, 32);
        file_sizes[number] = c_file.size;
        printf("%-12.12s %10u\n", file_names[number], file_sizes[number]);
        number++;
      } while (_findnext(hFile, &c_file) == 0);
      _findclose(hFile);
      printf("\nКоличество файлов: %d\n", number);
      printf("\n");
    }
  } while ((hFile = _findfirst(direct, &c_file)) == -1L);
  while (sorting != 0)
  {
    printf("Выберите сортировку:\n 1.Пузырьком\n 2.Выбором \n 3.Хоара \n 4.Вставками\n Если хотите выйти, введите 0\n");
    scanf("%i", &sorting);
    while ((sorting > 4) || (sorting < 0))
    {
      printf("Неверно выбрана сортировка!\n Выберите сортировку:\n 1.Пузырьком\n 2.Выбором \n 3.Хоара \n 4.Вставками\n Если хотите выйти, введите 0\n");
      scanf("%i", &sorting);
    }
    switch (sorting)
    {
    case 1:
      t1 = clock();
      Bub(file_sizes, file_names, direct, number);
      t2 = clock();
      break;
    case 2:
      t1 = clock();
      Cho(file_sizes, file_names, direct, number);
      t2 = clock();
      break;
    case 3:
    {
      t1 = clock();
      Sort(file_sizes, file_names, direct, number);
      t2 = clock();
      break;
    }
    case 4:
    {
      t1 = clock();
      Ins(file_sizes, file_names, direct, number);
      t2 = clock();
      break;
    }
    case 0:
      sorting = 0;
      break;
    }
    tt = double(t2 - t1) / CLOCKS_PER_SEC;
    //вывод результата
    printf("Файлы             Размер\n", ' ');
    printf("----                ----\n", ' ');
    if ((sorting == 1) || (sorting == 2))
    {
      for (i = 0; i < number; i++)
        printf("%-12.12s %10u\n", file_names[i], file_sizes[i]);
    }
    else
      for (i = number - 1; i >= 0; i--)
        printf("%-12.12s %10u\n", file_names[i], file_sizes[i]);
    printf("\nВремя работы сортировки :%f\n\n", tt);
  }
}