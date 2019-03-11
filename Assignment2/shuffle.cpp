#include<iostream>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h> 

using namespace std;

int main(){
		int verbose = 1;
		// Intialize array
		int arr[49];
		for (int i = 0; i < 49; i++)
		{
			arr[i] = i + 1;
		}
		// Shuffle
		int arrLen = sizeof(arr) / sizeof(arr[0]);
		int range = arrLen; //49
		srand(time(NULL));

		for (int j = arrLen - 1; j > 0; j--)
		{
			int r = random() % range;
			swap(arr[r], arr[j]);
			range--;
		}
		// sort array in ascending order
		sort(arr, arr+6);
		// generate 6 random numbers to the ticket
		// Print first 6 elements in the array if required
		if (verbose == 1)
		{
			cout << "A new ticket was successfully generated. The numbers are: ";
			for (int k = 0; k < 6; k++)
			{
				if(k == 5){
				cout << arr[k];
				} else{
					cout << arr[k] << ", " ;
				}
			}
			
			cout << endl;
		}
	}