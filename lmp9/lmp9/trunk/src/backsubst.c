#include "backsubst.h"
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int
backsubst (Matrix * x, Matrix * mat, Matrix * b)
{
				/**
				 * Tutaj należy umieścić właściwą implemntację.
				 */

  /* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */
  int i,j; 
  x->data[mat->r-1][0] = b->data[b->r-1][0] / mat->data[mat->r-1][mat->r-1];

  for (i = mat->r - 2; i >= 0; i--)
    {
      x->data[i][0] = b->data[i][0];
      for (j = i + 1; j <= mat->r - 1; j++)
	{
	  x->data[i][0] = x->data[i][0] - mat->data[i][j] * x->data[j][0];
	}
      x->data[i][0] = x->data[i][0] / mat->data[i][i];
    }
  return 0;
}
