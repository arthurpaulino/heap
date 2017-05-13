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
	int num = 10;
	int base[num];
	base[0] = 3; base[1] = 10; base[2] = 9; base[3] = 2; base[4] = 7;
	base[5] = 1; base[6] = 4; base[7] = 8; base[8] = 0; base[9] = 6;
	
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
