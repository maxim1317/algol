#include "graph.h"

Graph::Graph(int _n, vector<int>&_I, vector<int>&_J): n(_n), I(_I), J(_J), m(_I.size())
{
	H.assign(n, -1);
	L.resize(m);
	GenHl();
}

void Graph::GenHl()
{
	for (int i(0); i < m; ++i) 
	{
        int k = I[i];
        L[i] = H[k];
        H[k] = i;
    }
}

void Graph::PrintIJHL()
{
	printf("| # | I | J |  H |  L |\n");
}

void Graph::ReadIJ();
{
    int k = 1;
    int buf;
    int max = 0;

    printf("Сколько  нод будет?\n");
    cin>>n;
    
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

  	m = I.size();

    GenHl();
}

