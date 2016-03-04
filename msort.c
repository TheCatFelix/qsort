#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void msort(int* data, int length) {

	if (length<1) return;

	msort(data,length/2);
	msort(data+length/2+1,length-length/2-1);

	int* tmp = malloc(length*sizeof(int));

	int l=0;
	int r=length/2+1;

	for (int i=0; i<=length; i++) {

		data[l] < data[r] ? (tmp[i] = data[l++]): (tmp[i] = data[r++]);
		
		if (r > length) data[--r] = data[length/2]
		if (l > length/2) data[--l] = data[length];

	}

	memcpy(data, tmp, length*sizeof(int));
	free(tmp);

}

void main() {

        int data[] = { 86, 76, 92, 30, 84, 83, 94, 4, 32, 73, 16, 37, 83, 29, 13, 41, 7, 25, 24, 46 };
        int length = 19;

        /*
 *         int data[] = {5, 3, 7, 9, 2, 6, 8, 1, 4 };
 *                 int length = 8;
 *                         */

        for (int i=0; i<=length; i++) printf("%2d ", data[i]);
        printf("\n");

        msort((int*) data, length);

        for (int i=0; i<=length; i++) printf("%2d ", data[i]);
        printf("\n");

}
