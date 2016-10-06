#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include <time.h>

void gnome(unsigned int size, int * a){
	unsigned int pos = 0;
	while( pos < size ) {
		if( pos == 0 ) {
			pos++;
		} else {
			if( a[pos] >= a[pos-1] ) {
				pos++;
			} else {
				int temp = a[pos];
				a[pos] = a[pos-1];
				a[pos-1] = temp;
				pos--;
			}
		}
	}
}

int main(int argc, char * argv[]){
	unsigned int size;
	if(argc != 2) {
		std::cout << "Syntax: gnome-sort 1000" << std::endl;
	} else {
		size = atoi(argv[1]);
	}
	int * a = new int[size];
	std::cout << "Initial array size: " << size << std::endl;
	srand(time(0));	
	for(int i = 0; i < size; i++) {
		a[i] = rand() % 100;
	}
	std::cout << std::endl;
	
	std::cout << "Starting gnome sort..." << std::endl;
	std::clock_t start = std::clock();
	gnome(size, a);
	std::clock_t finish = std::clock();
	
	std::cout << std::fixed << std::setprecision(2) << "Time: " << 1000.0 * (finish - start) / CLOCKS_PER_SEC << " ms" << std::endl;

	return 0;
}
