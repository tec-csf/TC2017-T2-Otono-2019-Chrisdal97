//
//  main.cpp
//  Problema de la mochila
//
//  Created by Christian Alberto Dalma Schults y Jorge Palacios Hristova on 9/24/19.
//  Copyright © 2019 Christian Alberto Dalma Schultz y Jorge Palacios Hristova. All rights reserved.
//


#include <iostream>
using namespace std;

int main()
{
// ----------Variables---------
 int n,m;
 int compa=-1,best=0;
 cout<<"Escribe N y M (n=cantidad de objetos que puede cargar la mochila) (m=peso maximo): "<<endl;
 cin>>n;
 cin>>m;
 n=n+1;
 m=m+1;
 int Mochila[n][m];
 int peso[n+1];
 int ben[n+1];
 peso[0]=0;
 ben[0]=0;
//-----------variables---------
 
//----------peso y beneficio--------------
    for(int i=1;i<n;++i){
     cout<<"Peso ["<<i<<"] : "<<endl;
     cin>>peso[i];
 }
    
  for(int j=1;j<n;++j){
     cout<<"Beneficio ["<<j<<"] : "<<endl;
     cin>>ben[j];
 }
    
//----------peso y beneficio---------
    
//--------llenar matriz mochila-----------
 for(int i=0;i<m;i++){
     Mochila[0][i]=0;
     if(i<n){
         Mochila[i][0]=0;
     }
 }
//----------llenar matriz mochila 0-----------
    
// --------comparacion  y llenado de mochila--------
 for(int i=1;i<=n-1;++i){
    for(int j=1;j<=m-1;++j){
        if(j-peso[i]<0){
                Mochila[i][j]=Mochila[i-1][j];
        }
        else{
        Mochila[i][j]= max(Mochila[i-1][j], Mochila[i-1][j-peso[i]] + ben[i]);
        }
    }
 }
// -------comparacion y llenado de mochila-----------

// --------comparaciion y BEST------------
 for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
        //cout<<Mochila[i][j]<<" ";
        if(Mochila[i][j]>compa){
            compa=Mochila[i][j];
            best=Mochila[i][j];
        }
  //      cout<< compa<<"\n";
        
    }
     //cout<<"\n";
}
cout<<"\n";
cout<<"mayor beneficio: "<<best<<endl;
}
//-------------comparacion y BEST------------