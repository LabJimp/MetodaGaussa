#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int eliminate(Matrix *mat, Matrix *b){
	double ratio;
	int i, j, k;
	for(i=0;i<mat->r;i++)
	 {
		if(mat->data[i][i] == 0.0)
	      	{
			 printf("Mathematical Error!");
		 	 return 1;
		 }
		 for(j=i+1;j<mat->c;j++)
		 {
		 	ratio = (mat->data[j][i])/(mat->data[i][i]);
	  
			for(k=0;k<=mat->c;k++)
			 {	
				 (mat->data[j][k]) = (mat->data[j][k]) - ratio*(mat->data[i][k]);
			 }
		}
	}
		return 0;
}

