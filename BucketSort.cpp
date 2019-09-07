//
//  main.cpp
//  Ejemplos
//
//  Created by Christian Alberto Dalma Schults on 9/5/19.
//  Copyright © 2019 Christian Alberto Dalma Schultz. All rights reserved.
//
// C++ program to implement Tree Sort

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using namespace std::chrono;


void BucketSort(int arreglo[], int n) {
    const int max = n;
    
    int bucket[10][max+1];
    
    for(int x=0;x<10;x++) bucket[x][max] = 0;
    
    for(int digit = 1; digit <= 1000000000; digit *= 10) {
        
        for(int i = 0; i < max; i++) {
            
            int dig = (arreglo[i] / digit) % 10;
            
            bucket[dig][bucket[dig][max]++] = arreglo[i];
        }
        
        int idx = 0;
        for(int x = 0; x < 10; x++) {
            for(int y = 0; y < bucket[x][max]; y++) {
                arreglo[idx++] = bucket[x][y];
            }
            
            bucket[x][max] = 0;
        }
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
    
    BucketSort(arr, n);
    
    t1 = clock();
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    cout<< "time in S: "<<tiempo<<endl;
    return 0;
    
}