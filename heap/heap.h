#ifndef __HEAP_H__
#define __HEAP_H__
#endif

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using vec = std::vector<int>;

class Heap
{
public:
    int n = 0;
    vec array;

    Heap(vec &);
    ~Heap(){};

    void MakeHeap();
    
    void Add(int);
    void Remove(int);
    
    int GetMin();

    void FixO(int);
    void FixI(int);
    
};

#include "heap_main.hpp"