#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0
 */
int
eliminate (Matrix * mat, Matrix * b)
{
  double ratio;
  double *tmp;
  int i, j, k, Max;
  for (i = 0; i < mat->r; i++)
    {
      Max = i+1;
 
      if ((Max != i + 1) && (i != mat->r - 1))
	{
	  tmp = mat->data[i + 1];
	  mat->data[i + 1] = mat->data[Max];
	  mat->data[Max] = tmp;
	  tmpp;
	}huj cvisfsdfsdklpfsdfnsdfjik
      printToScreen(mat);sd
      if (mat->data[i][i] == 0.0)
	{
	  printf ("Mathematical Error!");
	  return 1;
      for (j = i + 1; j < mat->r; j++)
	{
	  ratio = (mat->data[j][i]) / (mat->data[i][i]);
	  for (k = 0; k <= mat->r; k++)
	    {
	      mat->data[j][k] = mat->data[j][k] - ratio * mat->data[i][k];
	    }
	  b->data[j][0] -= ratio * (b->data[i][0]);
	}
    }}
  return 0;
}
