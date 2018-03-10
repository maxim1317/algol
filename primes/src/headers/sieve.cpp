#ifndef __SIEVE_CPP__
#define __SIEVE_CPP__

#include "primes.hpp"

Sieve::Sieve(ll num, std::string filename)
{
    amount_=num+1;
    filename_ = filename;

    colors.assign(amount_, 0);

    findPrimes_();
    // buildSieve_();
}

void Sieve::buildSieve_()
{
    FILE *out;
    std::string dir = "tmp/";
    std::string ext = ".sv";
    filename_ = dir + filename_ + "_" + std::to_string(amount_) + ext;
    out = fopen(filename_.c_str(), "w");

    for (ll i = 0; i < amount_; ++i)
    {
        fprintf(out, "%lld\n", i);
    }
    fclose(out);
}

void Sieve::findPrimes_()
{
    ll curcolor = 1;

    bool flag = false;

    colors[0] = -1;
    colors[1] = -1;

    for (ll i = 2; i < amount_; ++i)
    {
        flag = false;
        if (!colors[i])
        {
            colors[i] = -2;
            primes.push_back(i);
            for (ll j = 2*i; j < amount_; j += i)
            {
                if (!colors[j]) 
                {
                    colors[j] = curcolor;
                    flag = true;
                }
            }
            if (flag)
                curcolor++;
        }
    }

    printf("primes = ");
    for (ll i = 0; i < primes.size(); ++i)
    {
        printf("%lld ", primes[i]);    
    }
    printf("\n");
    printf("curcolor = %lld\n", curcolor);
}

void Sieve::visualize_()
{
    for (ll i = 1; i < amount_; ++i)
    {
        
    }
}


#endif