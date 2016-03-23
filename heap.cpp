#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string.h>

class heap {

	public:

	int get_length();
	void print();
	int remove_top();
	//int add_item();

	heap();
	heap(int*, int);
	~heap();

	private:

	int* data;
	int length;
	void build_heap();
	void update_heap();
	int P(int);
	int L(int);
	int R(int);
	void swap(int*, int*);
	
};

typedef class heap heap_t;

heap::heap() {

	length = 0;
	data = 0;

}

heap::heap(int* _data, int _length) {

	length = _length;
	data = (int*) malloc((length+1)*sizeof(int));
	memcpy(data, _data, (length+1)*sizeof(int));
	build_heap();

} 

heap::~heap() {

	if (data) free(data);

}

int heap::get_length() {

	return length;

}

void heap::swap(int *a, int *b) {

        int tmp = *a;
        *a = *b;
        *b = tmp;

}

int heap::P(int n) { return (n-1)/2; }

int heap::L(int n) { return (2*n+1); }

int heap::R(int n) { return (2*n+2); }

void heap::build_heap() {

        if (length<1) return;

        int i;
        int s; // swaps this round

        do {

                s = 0;
                i = length;

                do if (data[P(i)]<data[i]) swap(data+P(i), data+(s=i));
                while (--i); // 1 since top has no parent

        } while (s);
	
}

void heap::update_heap() {

        if (length<1) return;

        int i = 0;

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

}

int heap::remove_top() {

	if (length<1) return *data;

	int top = *data;
	*data = *(data+length--);
	update_heap();

	return top;

}

void heap::print() {

	for (int i=0; i<=length; i++) std::cout << std::setw(2) << data[i] << " ";
	std::cout << std::endl;
}

int main() {

	int data[] = { 86, 76, 92, 30, 84, 83, 94, 4, 32, 73, 16, 37, 83, 29, 13, 41, 7, 25, 24, 46 };
	int length = 19;

	for (int i=0; i<=length; i++) std::cout << std::setw(2) << data[i] << " ";
	std::cout << std::endl;

	heap_t my_heap(data, length);

	for (int i=length; i+1; i--) data[i] = my_heap.remove_top();

	for (int i=0; i<=length; i++) std::cout << std:: setw(2) << data[i] << " ";
	std::cout << std::endl;

	return 0;

}
