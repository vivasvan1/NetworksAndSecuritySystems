#include <omp.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;
// using namespace std;
int a[5000];
int getrandomval()
{
	int x = rand() % 5000 + 1;
	return x;
}

int partition(int arr[], int low, int high){
	pivot = arr[high];
	i = (low - 1)
	for (j = low; j <= high- 1; j++)
    {
    	if (arr[j] < pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+ 1

}

int quicksort(int arr[], int low, int high){

	pi = partition(arr,high,low)
	quicksort(arr, low, pi-1)
	quicksort(arr, pi, high)
}

int main(){
	for (int i=0;i<m;i++){
  		a[i][j] = getrandomval();
  	}



	#pragma omp task

}