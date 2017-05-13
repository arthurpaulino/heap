#include <stdio.h>
#include "heap.h"

int compar(const void *a, const void *b) {
	int *A = (int*)a;
	int *B = (int*)b;
	return *A-*B;
}

void printArray(int *base, int num) {
	int i;
	for (i=0; i<num; i++) printf("%d ", base[i]);
	printf("\n");
}

int main() {
	
	int base[1024], i;
	int num = 10;
	
	for (i = 0; i < num; i++) {
		base[i] = 5*num - 3*i;
	}

	printf("Original array:\n\t"); printArray(base, num);
	
	heapify(base, num, sizeof(int), compar);
	
	printf("After heapify:\n\t"); printArray(base, num);
	
	heappoll(base, num--, sizeof(int), compar);
	
	printf("After heappoll:\n\t"); printArray(base, num);
	
	int x = 5;
	heapoffer(&x, base, num++, sizeof(int), compar);
	
	printf("After heapoffer:\n\t"); printArray(base, num);
	
	heapsort(base, num, sizeof(int), compar);
	
	printf("After heapsort:\n\t"); printArray(base, num);

	return 0;
}
