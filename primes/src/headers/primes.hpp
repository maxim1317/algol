#ifndef __PRIMES_HPP__
#define __PRIMES_HPP__

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

using ll = long long;

class Sieve
{
public:
    ll amount_;
    std::string filename_;
    std::vector<ll> primes, colors;

    Sieve(ll, std::string);
    ~Sieve(){};
private:
    void buildSieve_();
    void findPrimes_();

    void visualize_();
};

#endif