#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
//#include "/opt/NR/numerical_recipes.c/nrutil.h"
//#include "/opt/NR/numerical_recipes.c/nrutil.c" // na taurusie 
//#include "/opt/NR/numerical_recipes.c/gaussj.c"
# include "nrutil.h"
# include "nrutil.cpp" // na wlasnym komputerze
# include "gaussj.cpp"
#define N 400 // rozmiar macierzy A: NxN

int main(void)
{
	float **A, **b;
	//	Alokacja macierzy
	A = matrix(1, N, 1, N);
	b = matrix(1, N, 1, 1);

	// 	Wypelnienie macierzy A i wektora b
	for (int i = 1; i <= N; ++i)
	{
		b[i][1] = 0.0;
		for (int j = 1; j <= N; ++j)
			A[i][j] = 0.0;
	}
	// b[1][1] = -4.0;
	// b[2][1] = 9.0;
	// b[3][1] = -16.0;

	// A[1][1] = 2.0; A[1][2] = 3.0; A[1][3] = 0.0;
	// A[2][1] = -1.0; A[2][2] = 1.0; A[2][3] = 4.0;
	// A[3][1] = 3.0; A[3][2] = 11.0; A[3][3] = 1.0;

	A[1][1] = 1;
	A[2][1] = -1;
	A[2][2] = 1;
	int j = 2;
	float h = 0.1;
	for (int i = 3; i <= N; i++)
	{
		A[i][j] = h * h - 2;
		A[i][j - 1] = A[i][j + 1] = 1;
		j++;
	}
	b[1][1] = 1;
	b[2][1] = 0;

	// for (int i=1;i<=N;i++)
	// {
	// 	for (int j=1;j<=N;j++)
	// 	std::cout<<A[i][j]<<" ";
	// 	std::cout<<std::endl;
	// }

	//	Rozwiazanie ukladu rownan Ax=b - wywolanie procedury:
	gaussj(A, N, b, 1);

	//	Wypisanie rozwiazania, ktore procedura gaussj(A,N,b,1); zapisala w wektorze b.
	// for(int i=1; i<=N; ++i)
	// 	printf("%g\n",  b[i][1]);

	FILE *file_ptr;
	file_ptr = fopen("out.dat", "w");
	if (!file_ptr)
		std::cout << "ERR opening file!" << std::endl; // zmiana w pliku glownym polegala na dodaniu jednej kolumny przy wypisywaniu do pliku (posluzyla ona do 							      // ograniczenia osi x z 400 do 40 
	for (int i = 1; i <= N; i++)
		fprintf(file_ptr,"%d %f\n",i, b[i][1]); // Wypisanie danych do pliku

	//	Zwolnienie pamieci
	free_matrix(A, 1, N, 1, N);
	free_matrix(b, 1, N, 1, 1);

	return 0;
}
