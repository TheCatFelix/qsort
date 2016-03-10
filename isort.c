#include "stdio.h"

void swap(int* a, int* b) {

	int tmp = *a;
	*a = *b;
	*b = tmp;

}

void isort(int* data, int length) {

	if (length<1) return;

	for (int i=1; i<=length; i++) {

		int j=i;
		while (j>0 && data[j]<data[--j]) swap(data+j+1, data+j); 

	}

}

void main() {

	int data[] = { 86, 76, 92, 30, 84, 83, 94, 4, 32, 73, 16, 37, 83, 29, 13, 41, 7, 25, 24, 46 };
	int length = 19;

	for (int i=0; i<=length; i++) printf("%2d ", data[i]);
	printf("\n");

	isort((int*) data, length);

	for (int i=0; i<=length; i++) printf("%2d ", data[i]);
        printf("\n");


}
