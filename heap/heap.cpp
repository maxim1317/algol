#include "heap.h"

int main(int argc, char const *argv[])
{
    vec inp{1, 2, 3, 4, 5, 6};
    Heap A(inp);
    A.MakeHeap();
    return 0;
}