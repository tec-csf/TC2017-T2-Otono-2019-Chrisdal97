//
//  main.cpp
//  Ejemplo2
//
//  Created by Christian Alberto Dalma Schults on 9/5/19.
//  Copyright © 2019 Christian Alberto Dalma Schultz. All rights reserved.
//
// C++ program to implement Tree Sort

#include <iostream>
#include <algorithm>
#include <vector>
#include<string.h>
using namespace std;
using namespace std::chrono;
using namespace std;
#define RANGE 255



void countSort(int arreglo[], int n) {
    int i, j, k;
    int idx = 0;
    int min, max;
    
    min = max = arreglo[0];
    for(i = 1; i < n; i++) {
        min = (arreglo[i] < min) ? arreglo[i] : min;
        max = (arreglo[i] > max) ? arreglo[i] : max;
    }
    
    k = max - min + 1;
    
    int *B = new int [k];
    for(i = 0; i < k; i++) B[i] = 0;
    
    for(i = 0; i < n; i++) B[arreglo[i] - min]++;
    for(i = min; i <= max; i++)
        for(j = 0; j < B[i - min]; j++) arreglo[idx++] = i;
    
    
    delete [] B;
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
    
    countSort(arr, n);
    
    t1 = clock();
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    cout<< "time in S: "<<tiempo<<endl;
    return 0;
    
}
