#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libbmp.h"

void ExchangePixel(Pixel* A, Pixel* B)
{
    Pixel temp = *A;
    *A = *B;
    *B = temp;
}

int CompareRed(Pixel* A, Pixel* B)
{
    if (A->R < B->R)
        return -1;
    else if ( A->R == B->R)
        return 0;
    else
        return 1;
}

int CompareLuminosity(Pixel* A, Pixel* B)
{
    if (A->Y > B->Y)
        return 1;
    else if (A->Y == B->Y)
        return 0;
    else
        return -1;
}

int CompareColor(Pixel* A, Pixel* B)
{
    if (A->H > B->H)
        return 1;
    else if (A->H == B->H)
        return 0;
    else
        return -1;
}

int CompareCb(Pixel *A, Pixel* B)
{
    if (A->Cr > B->Cr)
        return 1;
    else if (A->Cr == B->Cr)
        return 0;
    else
        return -1;
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
   // int RandPivot = rand()%(D-G+1) + G;
 //   ExchangePixel(&Pic->pix[RandPivot], &Pic->pix[G]);
    int pivot = PartitionPixel(Pic, G, D, Compare);
    if (pivot > G)
        sortImage(Pic, G, pivot - 1, Compare);
    if (pivot < D)
        sortImage(Pic, pivot + 1, D, Compare);
}

int main() {
    srand(time(NULL));
    Image *Pic = readImage("../Pics/Babybijau.bmp");
    printf(" Size : %d header : %s\n",Pic->size, Pic->header);
    sortImage(Pic, 0, Pic->size - 1, CompareColor);
    writeImage(Pic, "../Pics/testAfter.bmp");

    return 0;
}
