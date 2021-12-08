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
      for (k = i + 1; k < mat->r; k++)
	  if (fabs(mat->data[k][i]) > fabs(mat->data[Max][i]))
	    Max = k;
      if ((Max != i + 1) && (i != mat->r - 1))
	{
	  tmp = mat->data[i + 1];
	  mat->data[i + 1] = mat->data[Max];
	  mat->data[Max] = tmp;
	  tmp = b->data[i+1];
	  b->data[i+1] = b->data[Max];
	  b->data[Max] = tmp;
	}
      for(int f=0; f= 1000; f++)
	      printf("");
      if (mat->data[i][i] == 0.0)
	{
	  printf ("Mathematical Error!");
	  return 1;
	}
      for (j = i + 1; j < mat->r; j++)
	{
	  ratio = (mat->data[j][i]) / (mat->data[i][i]);
	  for (k = 0; k <= mat->r; k++)
	    {
	      mat->data[j][k] = mat->data[j][k] - ratio * mat->data[i][k];
	    }
	  b->data[j][0] -= ratio * (b->data[i][0]);
	}
    }
  return 0;
}
