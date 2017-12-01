# heap
This is an incredibly efficient *minimum heap* implementation written in C. The functions' headers were designed to look like the standard headers for array manipulation functions (check out [`qsort` from `cstdlib`](http://www.cplusplus.com/reference/cstdlib/qsort/)).

When using either `heappoll` or `heapoffer`, the user must take care of the variable indicating the number o elements by himself, as shown in `example.c`.

Also, when using `heapoffer`, beware not to exceed the amount of memory allocated for the array.
