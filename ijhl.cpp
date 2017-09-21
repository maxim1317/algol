#include <stdio.h>
#include <iostream>
#include <vector>


using namespace std;

int main(int argc, char const *argv[])
{
    int k = 1;
    int buf;
    int max = 0;
    vector<int> I;
    vector<int> J;

    
    printf("| # | I | J |\n");
    printf("| 0 | ? | J |\n");
    cin>>buf;
    I.push_back(buf);
    if (buf > max) max = buf;
    printf("| 0 | %d | ? |\n", buf);
    cin>>buf;
    J.push_back(buf);
    if (buf > max) max = buf;



    while (buf >= 0)
    {
        printf("| %d | ? | J |\n", k);
        cin>>buf;
        if (buf >= 0)  
        {
            I.push_back(buf);
            if (buf > max) max = buf;
            printf("| %d | %d | ? |\n", k, buf);
            cin>>buf;
            J.push_back(buf);
            if (buf > max) max = buf;
            k++;
        }
    }

    unsigned int vec_s = I.size();
    printf("| # | I | J |\n");


    for (k = 0; k < vec_s; k++) {
        printf("| %d | %d | %d |\n", k, I[k], J[k]);
    }

    vector<int> H(max,-1);
    vector<int> L(vec_s);

    for (int k = 0; k < vec_s; k++)
    {
        int j = I[k];
        L[k] = H[j];
        H[j] = k;
    }

    unsigned int vec_sH = H.size();

    printf("\n\n\n| # |  H |  L |\n");

    k = 0;

    H[vec_sH] = -1;


    while (k <= vec_sH)
    {    
        printf("| %d | %2d | %2d |\n", k, H[k], L[k]);
        k++;
    }
    while (k < vec_s)
    {
        printf("| %d |    | %2d |\n", k, L[k]);
        k++;
    }


    return 0;
}


