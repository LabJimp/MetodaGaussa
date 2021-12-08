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
  int i, j, k, max;
  for (i = 0; i < mat->r; i++)
    {
      max = i+1;
      for (k = i + 1; k < mat->r; k++)
	  if (fabs(mat->data[k][i]) > fabs(mat->data[max][i]))
	    max = k;
      if ((max != i + 1) && (i != mat->r - 1))
	{
	  tmp = mat->data[i + 1];
	  mat->data[i + 1] = mat->data[max];
	  mat->data[max] = tmp;
	  tmp = b->data[i+1];
	  b->data[i+1] = b->data[max];
	  b->data[max] = tmp;
	}
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
