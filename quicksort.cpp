#include <omp.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
// using namespace std;
int a[10];
int getrandomval()
{
	return rand() % 5000;
}
int partition(int arr[], int low, int high){
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high- 1; j++)
    {
    	if (arr[j] < pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i + 1;
}
int quicksort(int arr[], int low, int high){

	int pi = partition(arr,high,low);
	quicksort(arr, low, pi-1);
	quicksort(arr, pi, high);
}
int main(){
	cout<<"asdfasdf";
	for (int i=0;i<sizeof(a)/sizeof(a[0]);i++){
  		a[i] = getrandomval();
  	}


  	quicksort(a,0,sizeof(a)/sizeof(a[0]));

  	for (int i=0;i<sizeof(a)/sizeof(a[0]);i++){
  		cout<<a[i];
  	}
  	return 0;

}