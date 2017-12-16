#include <stdio.h>
#include <math.h>

#pragma warning (disable:4996)
struct pct
{
	int x;
	int y;
};
pct* cit(int l);
void afi(pct* a, int l);
double dis(pct* a, int x, int y);
double per(pct* a, int l);
double srf(pct* a, int l);
int main()
{
	int l;
	double d = 0;
	double s = 0;
	pct* a = 0;
	scanf("%d", &l);
	a = cit(l);
	afi(a, l);
	printf("\n");
	s = srf(a, l);
	printf("%lf", s);
	return 0;
}

pct* cit(int l)
{
	int i;
	pct* a = 0;
	a = new pct[l];
	for (i = 0; i < l; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	return a;
}

void afi(pct* a, int l)
{
	int i;
	for (i = 0; i < l; i++)
	{
		printf("{x:[%d],y:[%d]} \n", a[i].x, a[i].y);
	}
}

double dis(pct* a, int x, int y)
{
	return sqrt(pow((a[x].x - a[y].x), 2) + pow((a[x].y - a[y].y), 2));
}

double per(pct* a, int l)
{
	double per = 0;
	int i = 0;
	int j = 2;
	for (i = 0; i<sizeof(a) - 2; i++)
	{
		per = per + dis(a, i, i + 1);
	}
	if (l == 3)
		per = per + dis(a, l - 1, 0);
	else
	{
		per = per + dis(a, l - 1, 0);
		for (j = 2; j < l - 1; j++)
		{
			per = per + dis(a, l - j, l - (j - 1));
		}
	}

	return per;
}

double srf(pct* a, int l)
{
	double s = 0;
	double p = 0;
	double x = 0;
	p = per(a, l) / 2;
	x = p*(p - dis(a, 0, 1))*(p - dis(a, 1, 2))*(p - dis(a, 0, 2));
	s = sqrt(x);
	return s;
}