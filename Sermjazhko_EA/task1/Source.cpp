#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	float h, w, d, l, L, Vp, Vb, Vd, Vz, Vk, m;//������, ������, �������, ��� �����;
	float dsp = 0.86, dvp = 0.82, tz = 0.05, tbk = 0.15, td = 1.0, p = 0.74;//������� ������ �., ������� ������� � ������, ������� �����, ��������� ����;
	printf("������� ������ ����� (�� 180 �� 220 ��)\n");
	scanf_s("%f", &h);
	printf("������� ������ ����� (�� 80 �� 120 ��)\n");
	scanf_s("%f", &w);
	printf("������� ������� ����� (�� 50 �� 90 ��)\n");
	scanf_s("%f", &d);
	printf("������� ������� ����� � ��\n");
	scanf_s("%f", &l);
	while ((h > 200) || (h < 180) || (w > 120) || (w < 80) || (d > 90) || (d < 90))
	{
		printf("������ ������� �������. ��� ��� ������� ������, ������ � �������.\n");
		scanf_s("%f", &h);
		scanf_s("%f", &w);
		scanf_s("%f", &d);
	}
	L = floor((h - 0.3) / (40.0 + l.0));
	printf("���������� �����=%f\n", &L);

	Vp = l * (w - 0.3)*d;
	Vb = 0.3*(d + 1.05)*(h - 0.3);
	Vd = (h - 0.3)*w;
	Vz = 0.05*(h - 0.3)*w;
	Vk = 0.3*(d + 1.05);
	m = Vz * dvp + Vb * dsp + Vd * p + Vk * dsp + Vp * dsp;
	printf("����� ����� � �� = %f", m / 1000);
}