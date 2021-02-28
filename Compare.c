//
// Created by bluew on 28/02/2021.
//
#include "libbmp.h"
#include "Compare.h"

int CompareR(Pixel* A, Pixel* B)
{
    if (A->R < B->R)
        return -1;
    else if ( A->R == B->R)
        return 0;
    else
        return 1;
}

int CompareG(Pixel* A, Pixel* B)
{
    if (A->G < B->G)
        return -1;
    else if ( A->G == B->G  )
        return 0;
    else
        return 1;
}

int CompareB(Pixel* A, Pixel* B)
{
    if (A->B < B->B)
        return -1;
    else if ( A->B == B->B)
        return 0;
    else
        return 1;
}

int CompareH(Pixel* A, Pixel* B)
{
    if (A->H > B->H)
        return 1;
    else if (A->H == B->H)
        return 0;
    else
        return -1;
}

int CompareS(Pixel* A, Pixel* B)
{
    if (A->S > B->S)
        return 1;
    else if (A->S == B->S)
        return 0;
    else
        return -1;
}

int CompareV(Pixel* A, Pixel* B)
{
    if (A->V > B->V)
        return 1;
    else if (A->V == B->V)
        return 0;
    else
        return -1;
}

int CompareY(Pixel* A, Pixel* B)
{
    if (A->Y > B->Y)
        return 1;
    else if (A->Y == B->Y)
        return 0;
    else
        return -1;
}

int CompareCb(Pixel *A, Pixel* B)
{
    if (A->Cb > B->Cb)
        return 1;
    else if (A->Cb == B->Cb)
        return 0;
    else
        return -1;
}

int CompareCr(Pixel *A, Pixel* B)
{
    if (A->Cr > B->Cr)
        return 1;
    else if (A->Cr == B->Cr)
        return 0;
    else
        return -1;
}

