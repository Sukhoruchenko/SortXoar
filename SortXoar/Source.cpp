#include <string.h>
#include <conio.h>
#include <iostream> 
#include <stdio.h> 
#include <stdlib.h>  
#include <cstdio> 

using namespace std;

void RandMas(int *a, int n)
{
	for (int i = 0; i < n; i++)
		a[i] = rand() % 100;
}

void Output(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void SortXoar(int *a, int l, int r)
{
	int i = l, j = r, k, x = a[(l + r) / 2];
	while (i <= j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			k = a[i];
			a[i] = a[j];
			a[j] = k;
			i++;
			j--;
		}
	}
      if (i < r) SortXoar(a, i, r);
      if (l < j) SortXoar(a, l, j);	
}

void main()
{
	int  *a, n;
	cout << "input kol-vo elements: ";
	cin >> n;
	a = new int[n];
	RandMas(a, n);
	Output(a, n);
	SortXoar(a, 0, n-1);
	Output(a, n);
	delete[] a;
	_getch();
}