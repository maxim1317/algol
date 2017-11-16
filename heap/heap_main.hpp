#ifndef __HEAP_MAIN_HPP__
#define __HEAP_MAIN_HPP__
#endif

Heap::Heap(vec &input)
{
    this->n=input.size();
    for (int i = 0; i < input.size(); ++i)
    {
        this->array.push_back(input[i]);
    }
    this->MakeHeap();
}

void Heap::MakeHeap()
{
    for(int k = (this->n-1)/2; k >= 0; k--)
        FixO(k); 
}

void Heap::Add(int a)
{
    this->array[this->n] = a;
    this->n++;
    FixI(n-1);
}
void Heap::Remove(int k0)
{
    int a = this->array[k0]; 
    this->array[k0] = this->array[n-1]; 
    n--; 
    if (this->array[k0] > a) 
        FixO(k0); 
    else 
        FixI(k0); 
}

int Heap::GetMin() 
{
    int min = this->array[0];
    this->array[0] = this->array[n-1];
    n--;
    FixO(0); 

    return min;
}

void Heap::FixO(int k0)
{
    int k1 = 0;
    int k2 = 0;

    for(int k = k0; k < (n-1)/2; k = k1)
    {
        k1 = 2*k + 1; 
        k2 = k1 + 1; 
        if (k2 < n && this->array[k2] < this->array[k1])
            k1 = k2; 
        
        if(this->array[k] < this->array[k1]) break;
    } 
}

void Heap::FixI(int k0)
{
    int k1=0;
    for(int k = k0; k > 0; k = k1)
    {
        k1 = (k-1)/2; 
        if (this->array[k1] < this->array[k]) break;
    }
}