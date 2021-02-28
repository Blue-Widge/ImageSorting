//
// Created by bluew on 28/02/2021.
//
#include "libbmp.h"

#ifndef TRIIMAGE_SORT_H
#define TRIIMAGE_SORT_H

void ExchangePixel(Pixel* A, Pixel* B);
int PartitionPixel(Image *Pic, int G, int D, int (*Compare)(Pixel *A, Pixel *B));
void sortImage(Image *Pic, int G, int D, int (*Compare)(Pixel* A, Pixel* B));

#endif //TRIIMAGE_SORT_H
