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
	for(int s = 0; s < 10000; s+=1000) {
	unsigned int size = s;
	int * a = new int[size];
	double currentTime = 0;
	for(int j=0;j<5;j++) {
		srand(time(0));	
		for(int i = 0; i < size; i++) {
			a[i] = rand() % 100;
		}
		std::clock_t start = std::clock();
		gnome(size, a);
		std::clock_t finish = std::clock();
		if( j == 0 ) 
			currentTime = 1000.0 * (finish - start);
		else
			currentTime = (currentTime + 1000.0 * (finish - start) ) / 2.0;
	}
	std::cout << std::fixed << std::setprecision(2) << size << "\t"<< currentTime / CLOCKS_PER_SEC << std::endl;
	}
	return 0;
}
