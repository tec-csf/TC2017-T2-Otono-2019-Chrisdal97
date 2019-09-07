//
//  main.cpp
//  Ejemplos
//
//  Created by Christian Alberto Dalma Schults on 9/5/19.
//  Copyright © 2019 Christian Alberto Dalma Schultz. All rights reserved.
//
// C++ program to implement Tree Sort

#include <iostream>
#include <chrono>
#include <array>

using namespace std;
using namespace std::chrono;


//To swap elements in the array
void swap(int *x, int *y)
{
    int temporal = *x;
    *x = *y;
    *y = temporal;
}


//cocktail sort
void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    
    while (swapped) {
        // reset the swapped flag on entering
        // the loop, because it might be true from
        // a previous iteration.
        swapped = false;
        
        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        
        // if nothing moved, then array is sorted.
        if (!swapped)
            break;
        
        // otherwise, reset the swapped flag so that it
        // can be used in the next stage
        swapped = false;
        
        // move the end point back by one, because
        // item at the end is in its rightful spot
        --end;
        
        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        
        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}


int main()
{
    unsigned t0,t1;
    t0 = clock();
    
    srand(time(0));
    //change the size of the array
    const unsigned int SizeOfArray =300000;
    
    
    int arr[SizeOfArray];
    for (int i=0; i<SizeOfArray; i++) {
        arr[i]= rand()% 1500;
    }
    
    int n = sizeof(arr)/sizeof(arr[0]);
    //CocktailSort(arr, n);
    selectionSort(arr, n);
    
    t1 = clock();
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    cout<< "time in S: "<<tiempo<<endl;
    return 0;
    
}
