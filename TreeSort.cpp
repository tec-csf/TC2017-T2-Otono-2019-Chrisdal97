//
//  main.cpp
//  Ejemplos
//
//  Created by Christian Alberto Dalma Schults on 9/5/19.
//  Copyright © 2019 Christian Alberto Dalma Schultz. All rights reserved.
//
// C++ program to implement Tree Sort

#include <chrono>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace std::chrono;

struct Node
{
    int key;
    struct Node *left, *right;
};

// A utility function to create a new BST Node
struct Node *newNode(int item)
{
    struct Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Stores inoder traversal of the BST
// in arr[]
void storeSorted(Node *root, int arr[], int &i)
{
    if (root != NULL)
    {
        storeSorted(root->left, arr, i);
        arr[i++] = root->key;
        storeSorted(root->right, arr, i);
    }
}

/* A utility function to insert a new
 Node with given key in BST */
Node* insert(Node* node, int key)
{
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);
    
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    
    /* return the (unchanged) Node pointer */
    return node;
}

// This function sorts arr[0..n-1] using Tree Sort
void treeSort(int arreglo[], int tamanio)
{
    struct Node *root = NULL;
    
    // Construct the BST
    root = insert(root, arreglo[0]);
    for (int i=1; i<tamanio; i++)
        insert(root, arreglo[i]);
    
    // Store inoder traversal of the BST
    // in arr[]
    int i = 0;
    storeSorted(root, arreglo, i);
}

// Function Main
int main()
{
    
    unsigned t0,t1;
    t0 = clock();
    
    srand(time(0));
    //change the size of the array
    const unsigned int SizeOfArray =1000000;
    
    
    int arr[SizeOfArray];
    for (int i=0; i<SizeOfArray; i++) {
        arr[i]= rand()% 1500;
    }
    
    int n = sizeof(arr)/sizeof(arr[0]);
    
    treeSort(arr, n);
    
    t1 = clock();
    double tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
    cout<< "time in S: "<<tiempo<<endl;
    return 0;
}
