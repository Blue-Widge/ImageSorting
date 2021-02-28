//
// Created by bluew on 19/02/2021.
//

#ifndef TRIIMAGE_FUNCTIONS_H
#define TRIIMAGE_FUNCTIONS_H
void ExchangePixel(Pixel* A, Pixel* B);

int PartitionPixel(Image *Pic, int G, int D, int (*Compare)(Pixel *A, Pixel *B));

void sortImage(Image *Pic, int G, int D, int (*Compare)(Pixel* A, Pixel* B));
#endif //TRIIMAGE_FUNCTIONS_H
