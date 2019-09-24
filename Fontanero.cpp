#include <iostream>
using namespace std;

void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)

    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}


int  main() {

  int lug = 0;
  int time[lug];
  int totalT=0;
  int total = 0;

  cout<<"Cuantos lugares va a visitar el plomero:"<<endl;
  cin>>lug;

  for (int i = 0; i < lug; i++) {
    cout<<"Tiempo ["<<i+1<<"] : "<<endl;
    cin>>time[i];
  }

  //sort(time.begin(),time.end());
  bubbleSort(time,lug);

  cout<<"El orden de los tiempos es: "<<endl;

  for (int j = 0; j < lug; j++) {

    totalT = time [j]+totalT;
    cout<<"Tiempo que tarda: "<<j+1 << " "<<totalT<< " minutos"<<endl;
    if (j==lug) {

      totalT += time [j];
      cout<<"Tiempo que tarda: "<<lug << " "<<totalT<< " minutos"<<endl;
    }
  }


}
