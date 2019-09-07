//
//  main.cpp
//  Ejemplos
//
//  Created by Christian Alberto Dalma Schults on 9/5/19.
//  Copyright © 2019 Christian Alberto Dalma Schultz. All rights reserved.
//

/* C implementation QuickSort */
#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function takes last element as pivot, places
 the pivot element at its correct position in sorted
 array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right
 of pivot */
int partition (int arreglo[], int low, int high)
{
    int pivot = arreglo[high]; // pivot
    int i = (low - 1); // Index of smaller element
    
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arreglo[j] <= pivot)
        {
            i++; // increment index of smaller element
            swap(&arreglo[i], &arreglo[j]);
        }
    }
    swap(&arreglo[i + 1], &arreglo[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
 low --> Starting index,
 high --> Ending index */
void quickSort(int arreglo[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
         at right place */
        int pi = partition(arreglo, low, high);
        
        // Separately sort elements before
        // partition and after partition
        quickSort(arreglo, low, pi - 1);
        quickSort(arreglo, pi + 1, high);
    }
}

// main of program
int main()
{
    unsigned t0,t1;
    t0 = clock();
    srand((unsigned) time(0));
    
    //time adjuster
    int size = 1000000;
    int arreglo[size];
    
    for (int cont = 0; cont < size; cont++) {
        arreglo[cont] = (rand()%1500);
    }
    int T = sizeof(arreglo)/sizeof(arreglo[0]);
    
    quickSort(arreglo, 0, T-1);
     t1 = clock();
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    cout<< "time in S: "<<tiempo<<endl;
    return 0;
}
