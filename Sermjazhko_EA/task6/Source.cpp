#define _USE_MATH_DEFINES 
#include <stdio.h> 
#include <locale.h> 
#include <math.h> 

int Control(int limitl, int limitr, int& x)
{
  int a;
  while ((x > limitr) || (x < limitl))
  {
    printf("Значение введено неверно, повторите попытку (от %i до %i):\n", limitl, limitr);
    scanf_s("%i", &a);
    x = a;
  }
  return x;
}

double MySin(double x, int& n, double& eps)
{
  x = fmod(x, 2 * M_PI);
  int i, number = 0, j = 3;
  double mysin = x, buffer = x;

  for (i = 2; i <= n; i++)
  {
    mysin = (-1)*((x * x) / (j*(j - 1)))*mysin;
    buffer = buffer + mysin;
    j = j + 2;
    if (fabs(sin(x) - buffer) < eps)
      break;
    number++;
  }
  n = number + 1;
  eps = fabs(sin(x) - buffer);
  return buffer;
}

double MyCos(double x, int& n, double& eps)
{
  int i, number = 0, j = 2;
  double mycos = 1, buffer = 1;

  x = fmod(x, 2 * M_PI);
  for (i = 2; i <= n; i++)
  {
    mycos = (-1)*((x / j) * (x / (j - 1)))*mycos;
    buffer = buffer + mycos;
    j = j + 2;
    if (fabs(cos(x) - buffer) < eps)
      break;
    number++;
  }
  n = number + 1;
  eps = fabs(cos(x) - buffer);
  return buffer;
}

double MyAtanh(double x, int& n, double& eps)
{
  int i, number = 0, j = 3;
  double myatanh = x, buffer = x;

  if ((x >= 1) || (x <= -1))
  {
    if (x == 1)
      return INFINITY;
    if (x == -1)
      return -INFINITY;
    return -NAN;
  }
  for (i = 2; i <= n; i++)
  {
    myatanh = (myatanh * x * x) * (j-2) / j;
    buffer = buffer + myatanh;
    j = j + 2;
    if (fabs(atanh(x) - buffer) < eps)
      break;
    number++;
  }
  n = number + 1;
  eps = fabs(atanh(x) - buffer);
  return buffer;
}


double MyExp(double x, int& n, double& eps)
{
  int i, number = 0;
  double myexp = 1, buffer = 1;

  for (i = 2; i <= n; i++)
  {
    myexp = (myexp * x) / (i - 1);
    buffer = buffer + myexp;
    if (fabs(exp(x) - buffer) < eps)
      break;
    number++;
  }
  n = number + 1;
  eps = fabs(exp(x) - buffer);
  return buffer;
}

int main(void)
{
  double x = 0, eps;
  double myfun = 0, fun = 0;
  int n = 0, numberfun, regime, i, l = 1;

  double(*pf[4])(double, int&, double&);
  double(*p[4])(double);

  setlocale(LC_ALL, "Rus");
  pf[0] = MyExp;
  pf[1] = MySin;
  pf[2] = MyCos;
  pf[3] = MyAtanh;
  p[0] = exp;
  p[1] = sin;
  p[2] = cos;
  p[3] = atanh;

  printf("Выберите режим:\n 1 - Однократный расчет функции в заданной точке\n 2 - Серийный эксперимент\n");
  scanf_s("%i", &regime);
  Control(1, 2, regime);
  switch (regime)
  {
  case 1:
    printf("Выберите номер функции\n0 - exp(x)\n1 - sin(x)\n2 - cos(x)\n3 - atanh(x)\n");
    scanf_s("%i", &numberfun);
    Control(0, 3, numberfun);
    printf("Введите значение х:\n");
    scanf_s("%lf", &x);
    printf("Введите точность, например: 0,000001\n");
    scanf_s("%lf", &eps);
    printf("Введите количество слагаемых, которые хотите вычислить (от 1 до 1000):\n");
    scanf_s("%i", &n);
    Control(1, 1000, n);
    fun = (*p[numberfun])(x);
    printf("Эталонное значение: %f\n", fun);
    myfun = (*pf[numberfun])(x, n, eps);
    printf("Вычисленная оценка: %f\nРазница между оценкой и эталонным значением: %f\nКоличество слагаемых, которое было вычислено: %i\n", myfun, eps, n);

    getchar();
    getchar();
    break;
  case 2:
    printf("Выберите номер функции\n0 - exp(x)\n1 - sin(x)\n2 - cos(x)\n3 - atanh(x)\n");
    scanf_s("%i", &numberfun);
    Control(0, 3, numberfun);
    printf("Введите значение х:\n");
    scanf_s("%lf", &x);
    printf("Задайте число экспериментов (от 1 до 25):\n");
    scanf_s("%i", &n);
    Control(1, 25, n);

    printf("№ Эталонное значение Вычисленная оценка Разница\n");

    for (i = 1, l; i <= n; i++, l++)
    {
      eps = 0;
      fun = (*p[numberfun])(x);
      myfun = (*pf[numberfun])(x, l, eps);
      if (i < 10)
        printf("%i    %.5f   %.5f   %.5f\n", i, fun, myfun, eps);
      else
        printf("%i   %.5f   %.5f   %.5f\n", i, fun, myfun, eps);
      l = i;
    }
    scanf_s("%i", &n);
    break;
  }
}
