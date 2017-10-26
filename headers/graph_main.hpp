#ifndef __GRAPH_MAIN_HPP__
#define __GRAPH_MAIN_HPP__
#endif

using namespace std;


Graph::Graph()
{
	ReadIJ();
	GenIJ();
}

Graph::Graph(int _n, vector<int>&_I, vector<int>&_J): n(_n), m(_I.size())
{
    version = 1;
	for (int i = 0; i < n; i++)
	{
		numComp.push_back(-1);
        weight.push_back(INT_MAX);
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

Graph::Graph(int _n, vector<int>&_I, vector<int>&_J, vector<int>&_Weights): n(_n), m(_I.size())
{
    version = 1;
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
    weight = _Weights;
    GenHl();
}

void Graph::GenHl()
{
//	H.clear();
//	L.clear();
	//printf("!!!\n");
	H.assign(n, -1);
	L.resize(2*m/mode);
	for (int k = 0; k < m*2/mode; ++k )
	{
		int i = IJ[k];
		L[k] = H[i];
		H[i] = k;
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
    version++;
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
