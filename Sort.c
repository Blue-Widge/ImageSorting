//
// Created by bluew on 28/02/2021.
//
#include "Sort.h"

void ExchangePixel(Pixel* A, Pixel* B)
{
    Pixel temp = *A;
    *A = *B;
    *B = temp;
}

int PartitionPixel(Image *Pic, int G, int D, int (*Compare)(Pixel *A, Pixel *B)) {
    int pivot = G;
    while (G < D)
    {
        if (pivot == G)
        {
            if (Compare(&Pic->pix[pivot], &Pic->pix[D]) == 1)
            {
                ExchangePixel(&Pic->pix[pivot], &Pic->pix[D]);
                G = pivot;
                pivot = D;
            }
            else
            {
                D--;
            }
        }
        else if (pivot == D)
        {
            if (Compare(&Pic->pix[pivot], &Pic->pix[G]) == -1)
            {
                ExchangePixel(&Pic->pix[pivot], &Pic->pix[G]);
                D = pivot;
                pivot = G;
            }
            else
            {
                G++;
            }
        }
    }
    return pivot;
}
void sortImage(Image *Pic, int G, int D, int (*Compare)(Pixel* A, Pixel* B))
{
    int pivot = PartitionPixel(Pic, G, D, Compare);
    if (pivot > G)
        sortImage(Pic, G, pivot - 1, Compare);
    if (pivot < D)
        sortImage(Pic, pivot + 1, D, Compare);
}

