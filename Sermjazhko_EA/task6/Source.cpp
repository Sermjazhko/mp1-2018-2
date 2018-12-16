#define _USE_MATH_DEFINES 
#include <stdio.h> 
#include <locale.h> 
#include <math.h> 

double Control(double limitl, double limitr, int& x)
{
  double a;
  while ((x > limitr) || (x < limitl))
  {
    printf("Çíà÷åíèå ââåäåíî íåâåðíî, ïîâòîðèòå ïîïûòêó (îò %.0f äî %.0f):\n ", limitl, limitr);
    scanf_s("%lf", &a);
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
    myatanh += (myatanh * x * x) / j;
    j = j + 2;
    if (fabs(atanh(x) - myatanh) < eps)
      break;
    number++;
  }
  n = number + 1;
  eps = fabs(atanh(x) - myatanh);
  return myatanh;
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

  printf("Âûáåðèòå ðåæèì:\n 1 - Îäíîêðàòíûé ðàñ÷åò ôóíêöèè â çàäàííîé òî÷êå\n 2 - Ñåðèéíûé ýêñïåðèìåíò\n");
  scanf_s("%i", &regime);
  Control(1, 2, regime);
  switch (regime)
  {
  case 1:
    printf("Âûáåðèòå íîìåð ôóíêöèè\n0 - exp(x)\n1 - sin(x)\n2 - cos(x)\n3 - atanh(x)\n");
    scanf_s("%i", &numberfun);
    Control(0, 3, numberfun);
    printf("Ââåäèòå çíà÷åíèå õ:\n");
    scanf_s("%lf", &x);
    printf("Ââåäèòå òî÷íîñòü >=0,000001:\n");
    scanf_s("%lf", &eps);
    printf("Ââåäèòå êîëè÷åñòâî ñëàãàåìûõ, êîòîðûå õîòèòå âû÷èñëèòü (îò 1 äî 1000):\n");
    scanf_s("%i", &n);
    Control(1, 1000, n);
    fun = (*p[numberfun])(x);
    printf("Ýòàëîííîå çíà÷åíèå: %f\n", fun);
    myfun = (*pf[numberfun])(x, n, eps);
    printf("Âû÷èñëåííàÿ îöåíêà: %f\nÐàçíèöà ìåæäó îöåíêîé è ýòàëîííûì çíà÷åíèåì: %f\nÊîëè÷åñòâî ñëàãàåìûõ, êîòîðîå áûëî âû÷èñëåíî: %i\n", myfun, eps, n);

    getchar();
    getchar();
    break;
  case 2:
    printf("Âûáåðèòå íîìåð ôóíêöèè\n0 - exp(x)\n1 - sin(x)\n2 - cos(x)\n3 - atanh(x)\n");
    scanf_s("%i", &numberfun);
    Control(0, 3, numberfun);
    printf("Ââåäèòå çíà÷åíèå õ:\n");
    scanf_s("%lf", &x);
    printf("Çàäàéòå ÷èñëî ýêñïåðèìåíòîâ (îò 1 äî 25):\n");
    scanf_s("%i", &n);
    Control(1, 25, n);

    printf("¹ Ýòàëîííîå çíà÷åíèå Âû÷èñëåííàÿ îöåíêà Ðàçíèöà\n");

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
