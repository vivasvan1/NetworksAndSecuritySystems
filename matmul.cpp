#include <omp.h>
#include <iostream>
#include <stdlib.h>
#include <time.h> 
// #define m 1000
// #define n 1000
// #define p 1000
 
#define m 2000
#define n 2000
#define p 2000
// int var = 25;
using namespace std;
int a[m][n];
int b[n][p];
int c[m][p];
int d[m][p];
int getrandomval()
{
	int x = rand() % 5000 + 1;
	return x;

}
int main(){
	// cout<<"ASDf";

	double time_begin;
  	double time_elapsed;
  	double time_stop;
	// cout<<"Hello";
	// Init matrix here
  	srand(time(0));
  	for (int i=0;i<m;i++){
  		for (int j=0;j<n;j++){
  			a[i][j] = getrandomval();
  		}
  	}
  	srand(time(0));

  	for (int i=0;i<n;i++){
  		for (int j=0;j<p;j++){
  			b[i][j] = getrandomval();
  		}
  	}
	// END: Init matrix here
  	time_begin = omp_get_wtime();
	// for (int i =0;i<m;i++){
	// 	for (int j=0;j<p;j++){
	// 		d[i][j] = 0 ;
	// 		for (int k=0;k<n;k++){
	// 			d[i][j] = d[i][j] + (a[i][k]*b[k][j]);
	// 		}
	// 	}
	// }
	time_stop = omp_get_wtime();
	time_elapsed = time_stop - time_begin;
	cout << "  Elapsed time dT = " << time_elapsed  << "\n";

  	time_begin = omp_get_wtime();

  	// omp_set_dynamic(0);
  	// omp_set_num_threads(200);
  	// OMP_
  	#pragma omp parallel for collapse(2)
	for (int i =0;i<m;i++){
		for (int j=0;j<p;j++){
			c[i][j] = 0 ;
			for (int k=0;k<n;k++){
				c[i][j] = c[i][j] + (a[i][k]*b[k][j]);
  				// cout<<omp_get_num_threads()<<endl;

			}
		}
	}
  	// cout<<omp_get_num_threads()<<endl;

	time_stop = omp_get_wtime();

	time_elapsed = time_stop - time_begin;
	cout << "  Elapsed time dT = " << time_elapsed  << "\n";

	// for (int i =0;i<m;i++){
	// 	for(int j=0;j<p;j++){
	// 		if (c[i][j] != d[i][j]){
	// 			cout<<"asdf";
	// 		}
	// 	}
	// 	// cout<<"\n";
	// }


	return 0;

}