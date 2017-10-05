#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:

  int n, m;
  
  vector<int> I, J, H, L, IJ, numComp;

  void GenHl();
  void ReadIJ();
  void GenIJ();
  void Export();
  void PrintIJHL();
  void Add(int, int);
  void DeleteArc(int, int);
  void DFS(int, int);
  void ConnectedComponent();
  Graph(int, vector<int>&, vector<int>&);
  Graph();
  ~Graph(){};  
  
};

Graph::Graph()
{
	//ReadIJ();
	GenIJ();
}

Graph::Graph(int _n, vector<int>&_I, vector<int>&_J): n(_n), m(_I.size())
{
	for (int i = 0; i < n; i++)
	{
		numComp.push_back(-1);
	}
  IJ.resize(2*m);
  for (int k(0); k < m; ++k) {
    IJ[k] = _I[k];
    int ind = 2*m - k - 1;
    IJ[ind] = _J[k];
  }
  I = _I;
  J = _J;
	GenHl();
}

void Graph::GenHl()
{
//	H.clear();
//	L.clear();
	//printf("!!!\n");
	H.assign(n, -1);
	L.resize(2*m);
	for (int k = 0; k < m*2; ++k )
	{
		int i = IJ[k];
		L[k] = H[i];
		H[i] = k;
	}
}

void Graph::PrintIJHL()
{
	cout<<endl;
	cout<<endl;
	cout<<endl;
	printf("n = %d\n", n);
	printf("|  # | I | J |  H |  L | IJ |\n");
	int k = 0;


	
	while (k < n)
	{
		printf("| %2d | %d | %d | %2d | %2d | %2d |\n", k, I[k], J[k], H[k], L[k], IJ[k]);
		k++;
	}
	
	while (k < m)
	{
		printf("| %2d | %d | %d |    | %2d | %2d |\n", k, I[k], J[k], L[k], IJ[k]);
		k++;
	}
	while (k < 2*m)
	{
		printf("| %2d |   |   |    | %2d | %2d |\n", k, L[k], IJ[k]);
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
void Graph::Add(int i, int j)
{
	I.push_back(i);
	J.push_back(j);
	m++;
	// IJ.clear();
 //  GenIJ();
	IJ.insert(IJ.begin() + m - 1, i);
	IJ.insert(IJ.begin() + m, j);
	H.clear();
	L.clear();
	GenHl();
}

void Graph::GenIJ()
{
	for (int k = m-1; k >=0; k--)
	{
		IJ.insert(IJ.begin(),I[k]);
		IJ.push_back(J[k]);
	}
	GenHl();
}

void Graph::Export()
{
	FILE *out;
	out = fopen("graph.dot", "w");
	fprintf(out, "graph graphname {\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(out, "  %d;\n", i);
	}
	for (int i = 0; i < m; i++)
	{
		// fprintf(out, "  %d -- %d;\n", I[i], J[i]);
		fprintf(out, "  %d -- %d;\n", IJ[i], IJ[2 * m - i - 1]);
	}
	fprintf(out, "}\n" );
	fclose(out);


}

void Graph::DeleteArc(int v, int a)
{
    if(H[v] == a)
    {
        int temp = H[v];
        H[v] = L[H[v]];
        L[temp] = -1;
    }
    else
    {
        for (int k = H[v]; k !=-1; k = L[k])
        {
            if (L[k] == a)
            {
                int temp = L[k];
                L[k] = L[L[k]];
                L[temp] = -1;
            }
        }
    }
}

void Graph::DFS(int v, int color){
	if(numComp[v] == -1){
		numComp[v] = color;

		for(int i = 0; i < m; i++){
			if(IJ[i] == v){
				printf("%d %d %d %d\n", v, color, i);
				DFS(IJ[IJ.size() - 1 - i], color);
			}
		}
	}
}

void Graph::ConnectedComponent(){

	for(int i = 0; i < n; i++){
		DFS(i, i);
	}

	printf("| Col |\n");
	for (int i = 0; i < n; i++)
	{
		printf("| %3d |\n", numComp[i]);
	}
}