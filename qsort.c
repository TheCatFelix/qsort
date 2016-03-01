#include "stdio.h"

void swap(int* a, int* b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;

}

void qsort(int* data, int length) {

	if (length<1) return;

	int pivot = data[length];
	int f = 0;		// first unsorted number
	int l = length-1;	// last unsorted number

	for (; f<l; ) data[f] > pivot ? swap(data+f, data+l--): f++;

	data[f] > pivot ? swap(data+f, data+length): swap(data+(++f), data+length); 

	qsort(data, f-1);
	qsort(data+f+1, length-f-1);

}

void main() {
	
	int data[] = { 86, 76, 92, 30, 84, 83, 94, 4, 32, 73, 16, 37, 83, 29, 13, 41, 7, 25, 24, 46 };
	int length = 19;

	/*	
	int data = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	int length = 9;

	int data[] = { 2, 1, 5, 4, 3 };
	int length = 4;
	
	int data[] = { 1, 2 };
	int length = 1;

	int data[] = { 3, 2, 1 };
	int length = 2;

	int data[] = { 7 };
	int length = 0;
	*/

	for (int i=0; i<=length; i++) printf("%2d ", data[i]);
	printf("\n");

	qsort((int*) data, length);
	
	for (int i=0; i<=length; i++) printf("%2d ", data[i]);
	printf("\n");

}
