#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libbmp.h"
#include "Compare.h"
#include "Sort.h"

void Menu(int* Method)
{
    char AvailableSorts[9][2] = {"R","G","B","H","S","V","Y","Cb","Cr"};

    printf(" _____                                            _   _             \n"
           "|_   _|                                          | | (_)            \n"
           "  | | _ __ ___   __ _  __ _  ___   ___  ___  _ __| |_ _ _ __   __ _ \n"
           "  | || '_ ` _ \\ / _` |/ _` |/ _ \\ / __|/ _ \\| '__| __| | '_ \\ / _` |\n"
           " _| || | | | | | (_| | (_| |  __/ \\__ \\ (_) | |  | |_| | | | | (_| |\n"
           " \\___/_| |_| |_|\\__,_|\\__, |\\___| |___/\\___/|_|   \\__|_|_| |_|\\__, |\n"
           "                       __/ |                                   __/ |\n"
           "                      |___/                                   |___/\n\n\n");

    for (int i = 0; i<9; ++i)
    {
        printf("- (%d) Sort depending of %.2s\n", i+1, AvailableSorts[i]);
    }
    printf("\n\n Your choice (1-9) : ");
    scanf("%d",Method);
}

void LaunchSort(int* Method, float* execTime, Image* Pic)
{
    // En
    clock_t start, end;
    switch(*Method)
    {
        case 1:   start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareR);
            end = clock();
            break;
        case 2 : start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareG);
            end = clock();
            break;
        case 3:   start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareB);
            end = clock();
            break;
        case 4 : start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareH);
            end = clock();
            break;
        case 5:   start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareS);
            end = clock();
            break;
        case 6 : start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareV);
            end = clock();
            break;
        case 7:   start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareY);
            end = clock();
            break;
        case 8 : start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareCb);
            end = clock();
            break;
        case 9:   start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareCr);
            end = clock();
            break;
        default : start = clock();
            sortImage(Pic, 0, Pic->size - 1, CompareH);
            end = clock();
            break;
    }
    *execTime = ((float)(end - start)) / CLOCKS_PER_SEC;
}


int main() {
    system("clear");
    srand(time(NULL));
    int Method = 0;
    float execTime;
    Menu(&Method);

    Image *Pic = readImage("./Pics/Rainbow.bmp");

    LaunchSort(&Method, &execTime, Pic);
    printf("Execution time : %lf sec\n", execTime);

    writeImage(Pic, "./Pics/testAfter.bmp");

    return 0;
}
