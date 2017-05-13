#include <string.h>
#include "heap.h"

#define PAI(i) ((i-1)>>1)
#define FILHOESQ(i) ((i<<1)+1)
#define FILHODIR(i) ((i<<1)+2)

static void heapup(void *base, int i, const size_t size, int (*compar)(const void*,const void*)) {
	char valor[size];
	memcpy(valor,(char*)base+i*size,size);
	int pai=PAI(i), d = (i-pai)*size;
	void *pi = (char*)base+i*size;
	while (compar((char*)base+pai*size,valor) > 0 && i!=0) {
		memcpy(pi,(char*)pi-d,size);
		pi = (char*)pi-d;
		d>>=1;
		i = pai;
		pai = PAI(i);
	}
	memcpy((char*)base+i*size,valor,size);
}

static void heapdown(void *base, const size_t num, int i, const size_t size, int (*compar)(const void*,const void*)) {
	char valor[size];
	memcpy(valor,(char*)base+i*size,size);
	int filhoesq = FILHOESQ(i), filhodir = FILHODIR(i), menorfilho = ((filhodir >= num) || compar((char*)base+size*filhoesq,(char*)base+size*filhodir)<0) ? filhoesq : filhodir;
	while (menorfilho < num && compar((char*)base+menorfilho*size,valor) < 0) {
		memcpy((char*)base+i*size,(char*)base+size*menorfilho,size);
		i = menorfilho;
		filhoesq = FILHOESQ(i);
		filhodir = FILHODIR(i);
		menorfilho = ((filhodir >= num) || compar((char*)base+size*filhoesq,(char*)base+size*filhodir)<0) ? filhoesq : filhodir;
	}
	memcpy((char*)base+i*size,valor,size);
}

void heapify(void *base, const size_t num, const size_t size, int (*compar)(const void*,const void*)) {
	int l;
	for (l=num>>1;l>=1;l--) {
		heapdown(base,num,l-1,size,compar);
	}
}

void heappoll(void *base, const size_t num, const size_t size, int (*compar)(const void*,const void*)) {
	memcpy(base,(char*)base+size*(num-1),size);
	heapdown(base,num,0,size,compar);
}

void heapoffer(void *x, void *base, const size_t num, const size_t size, int (*compar)(const void*,const void*)) {
	memcpy((char*)base+size*(num+1),x,size);
	heapup(base,num,size,compar);
}

static int (*compara)(const void*,const void*);

static int complemento(const void *a, const void *b) {
	return -compara(a,b);
}

void heapsort(void *base, const size_t num, const size_t size, int (*compar)(const void*,const void*)) {
	int i,mult;
	compara = compar;
	heapify(base,num,size,complemento);
	char temp[size];	
	for (i=num-1;i>0;--i) {
		memcpy(temp,base,size);
		mult = i*size;
		memcpy(base,(char*)base+mult,size);
		memcpy((char*)base+mult,temp,size);
		heapdown(base,i,0,size,complemento);
	}
}
