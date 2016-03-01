#include "stdio.h"
#define L(n) (2*n+1) // left child
#define R(n) (2*n+2) // right child
#define P(n) (n-1)/2 // parent

void swap(int *a, int *b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;

}

void build_heap(int* data, int length) {

	if (length<1) return;

	int i;
        int s; // swaps this round

        do {

		s = 0;
		i = length;

               	do if (data[P(i)]<data[i]) swap(data+P(i), data+(s=i)); 
		while (i-->=1); // 1 since top has no parent 

       	} while (s!=0);

}

void hsort(int* data, int length) {

	if (length<1) return;

	int i = 0;

	swap(data, data+length--);

	do {

		if (R(i) <= length &&\
		    data[R(i)] >= data[L(i)] &&\
		    data[R(i)] > data[i]) {

			swap(data+i, data+R(i));
			i = R(i);
			continue;	

		}

		if (L(i) <= length &&\
		    data[L(i)] > data[i]) {

			swap(data+i, data+L(i));
			i = L(i);
			continue;

		}	
		
		break;

	} while (1);

	hsort(data, length);	

}

void main() {

	int data[] = { 86, 76, 92, 30, 84, 83, 94, 4, 32, 73, 16, 37, 83, 29, 13, 41, 7, 25, 24, 46 };
        int length = 19;
	
	/*
	int data[] = {5, 3, 7, 9, 2, 6, 8, 1, 4 };
	int length = 8;
	*/

	for (int i=0; i<=length; i++) printf("%2d ", data[i]); 
	printf("\n");

	build_heap((int*) data, length);
	hsort((int*) data, length);

	for (int i=0; i<=length; i++) printf("%2d ", data[i]); 
	printf("\n");

}
