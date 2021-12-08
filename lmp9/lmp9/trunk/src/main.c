#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	printf("macierz rownan");
	printToScreen(A);
	printf("macierz wyrazow wolnych");
	printToScreen(b);

	if(eliminate(A,b))
	exit(EXIT_FAILURE);
	x = createMatrix(b->r, 1);
	if (x != NULL) {
		if(backsubst(x,A,b))
		exit(EXIT_FAILURE);
		printf("macierz po eliminacji");
		printToScreen(A);
		printf("macierz rozwiazan");
		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}
//	freeMatrix(A);
//	freeMatrix(b);

	

	return 0;
}
