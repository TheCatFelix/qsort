#include "stdio.h"

#define __left_child(n) 2*n+1 
#define __right_child(n) 2*n+2
#define __parent(n) (n-1)/2 // Integer division in C is "floor"
#define __swap(a,b) tmp=a;a=b;b=tmp;

int data[] = {5, 3, 7, 9, 2, 6, 8, 1, 4 };
int length = 8; // Last populated index, zero based array

void print_heap(int i, int* data) {

	int j;

	printf("#############################\n");

	for (j=0; j<=i; j++) { 

		printf("%d ", data[j]); 

	};

	printf("\n");

	do {
		
        	printf("Node %d, Parent %d\n", data[i], data[__parent(i)]);
        	i--;

	} while ( i>=1 ); // "1" since top of the heap has no parent

	printf("#############################\n");

}

void main() {

	int i;
	int n_swaps;
	int tmp;
	int current_length;

	//print_heap(length, (int*) &data);

	// Build a max heap by sift up from the back of the array

	do { 

		n_swaps =0;
		i = length;

		do {

			if ( data[__parent(i)] < data[i] ) { // sift up
	
				tmp = data[__parent(i)];
				data[__parent(i)] = data[i];
				data[i] = tmp;
				n_swaps++;
			}

		i--;

		} while ( i>=1 ); // "1" since top of the heap has no parent

	} while ( n_swaps>0 ); // Do I really need nested loops?

	//print_heap(length, (int*) &data);

	current_length = length;
	int next_i = 0;
	int has_left = 0;
	int has_right = 0;
        print_heap(current_length, (int*) data);

	do {
		// Remove top element
		// Reduce length by one
		
		tmp = data[0];
                data[0] = data[current_length];
                data[current_length] = tmp;
		current_length--;		

		// restore heap by sift down		

		next_i = 0;

		do {
	
			//print_heap(current_length, (int*) data);

			has_left = 0;
			has_right = 0;

                        if (__left_child(next_i)<=current_length) {

                                has_left = 1;
                                printf("P %d L %d ", data[next_i], data[__left_child(next_i)]);
                        }

                        if (__right_child(next_i)<=current_length) { 

				has_right = 1; 
				printf("R %d ", data[__right_child(next_i)]);

			} 

			if ( has_right && (data[__right_child(next_i)] >= data[__left_child(next_i)])) { // means that it has both child nodes

				if (data[__right_child(next_i)] > data[next_i]) {

					__swap(data[next_i],data[__right_child(next_i)])
					next_i = __right_child(next_i);
					printf("swap right child with parent\n");
					continue;
				}
	
			}
			
			if ( has_left && (data[__left_child(next_i)] > data[next_i])) { // has only left child node
	
				if (data[__left_child(next_i)] > data[next_i]) {
		
					__swap(data[next_i],data[__left_child(next_i)])	
					next_i = __left_child(next_i);
					printf("swap left child with parent\n");
					continue;
				}
	
			}
		
			break;	
		
		} while (1); 

	} while ( current_length > 0 );

	print_heap(length, (int*) &data);

}
