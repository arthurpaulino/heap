#ifndef HEAP_H_GUARD
#define HEAP_H_GUARD

void heapify(void *base, const size_t num, const size_t size, int (*compar)(const void*,const void*));

void heappoll(void *base, const size_t num, size_t size, int (*compar)(const void*,const void*));

//Beware not to exceed the amount of allocated memory for 'base'
void heapoffer(void *x, void *base, const size_t num, const size_t size, int (*compar)(const void*,const void*));

void heapsort(void *base, const size_t num, const size_t size, int (*compar)(const void*,const void*));

#endif
