//
//  main.cpp
//  ejemplo
//
//  Created by Christian Alberto Dalma Schults on 9/5/19.
//  Copyright © 2019 Christian Alberto Dalma Schultz. All rights reserved.
//

#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    /* create temp arrays */
    int L[n1], R[n2];
    
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    /* Copy the remaining elements of L[], if there
     are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    /* Copy the remaining elements of R[], if there
     are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
 sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        
        merge(arr, l, m, r);
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
    
    mergeSort(arr, 0, n);
    
    t1 = clock();
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    cout<< "time in MS: "<<tiempo<<endl;
    return 0;
}
