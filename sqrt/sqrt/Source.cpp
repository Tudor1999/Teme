#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#pragma warning(disable:4996)

int prod(int a, int b);
void imp(unsigned int a,unsigned int b, int &c, int &r);
int put(int a, int b);
int nrc(int a);
int* grup(unsigned int a, int &z);

void main()
{
	unsigned int a;
	int z,i=0,c=0,x=0, y=0;
	int* b = 0;
	int p = 0;
	scanf("%d", &a);
	b = grup(a, z);
	c = b[0];
	for (i=0;i<z;i++)
	{
		while (prod(x, prod(20, p) + x) <= c)
			x++;
		p = prod(p, 10) + x;
		y = prod(x, prod(20, p) + x);
		c = prod(c, 100) + c;
		c = c - y;
	}
	printf("%d", p);
	VirtualFree(b, 0, MEM_RELEASE);
}
int prod(int a, int b)
{
	int p = 0;
	while (b > 0)
	{
		p = p + a;
		b = b - 1;
	}
	return p;
}
void imp(unsigned int a, unsigned int b, int &c, int &r)
{
	int i = 0;
	while (a>b)
	{
		a = a - b;
		i++;
	}
	c = i;
	r = a;
}
int put(int a, int b)
{
	int c = 1;
	while (b > 0)
	{
		a = prod(a, c);
		b = b - 1;
	}
	return a;
}
int nrc(int a)
{
	int b = 0, c, r;
	while (a != 0)
	{
		imp(a, 10, c, r);
		b = b + 1;
		a = c;
	}
	return b;
}
int* grup(unsigned int a, int &z)
{
	int i = 0, c, r, d;
	d = a;
	int* b = 0;
	while (a != 0)
	{
		imp(a, 100, c, r);
		a = c;
		i++;
	}
	z = i;
	i--;
	b = (int*)VirtualAlloc(0, i * sizeof(int), MEM_COMMIT, PAGE_READWRITE);
	while (d != 0)
	{
		imp(d, 100, c, r);
		d = c;
		b[i--] = r;
	}
	return b;
}
