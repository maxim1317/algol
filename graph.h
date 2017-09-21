#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:

  int n, m;
  
  vector<int> I, J, H, L;

  void GenHl();
  void ReadIJ();
  void PrintIJHL();
  Graph(int, vector<int>&, vector<int>&);
  Graph();
  ~Graph(){};  
  
};

Graph::Graph()
{
	ReadIJ();
	GenHl();
}

Graph::Graph(int _n, vector<int>&_I, vector<int>&_J): n(_n), I(_I), J(_J), m(_I.size())
{
	GenHl();
}

void Graph::GenHl()
{
	H.assign(n, -1);
	L.resize(m);
	for (int i=0; i < m; i++) 
	{
        int k = I[i];
        L[i] = H[k];
        H[k] = i;
    }
}

void Graph::PrintIJHL()
{
	printf("| # | I | J |  H |  L |\n");
	int k = 0;
	while (k < n)
	{
		printf("| %d | %d | %d | %2d | %2d |\n", k, I[k], J[k], H[k], L[k]);
		k++;
	}
	H[k] = -1;
		while (k < m)
	{
		printf("| %d | %d | %d |    | %2d |\n", k, I[k], J[k], L[k]);
		k++;
	}
}

void Graph::ReadIJ()
{
    int k = 1;
    int buf;
    int max = 0;

    printf("Сколько нод будет?\n");
    cin>>n;
    printf("Сколько дуг?\n");
    cin>>m;    
    
    printf("| # | I | J |\n");
    printf("| 0 | ? | J |\n");
    cin>>buf;
    I.push_back(buf);
    if (buf > max) max = buf;
    printf("| 0 | %d | ? |\n", buf);
    cin>>buf;
    J.push_back(buf);
    if (buf > max) max = buf;



    while (buf >= 0 && k < m)
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



}

