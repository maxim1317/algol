#ifndef __GRAPH_PRINTS_HPP__
#define __GRAPH_PRINTS_HPP__
#endif

using namespace std;

void Graph::PrintIJHL()
{
	cout<<endl;
	printf("|  # | I | J |  H |  L | IJ |\n");
	int k = 0;

	int _n = n;
	int _m = m;

	if (m < n)
	{
		_n = m;
		_m = _n;
	}
	while (k < _n)
	{
		printf("| %2d | %d | %d | %2d | %2d | %2d |\n", k, I[k], J[k], H[k], L[k], IJ[k]);
		k++;
	}
	
	while (k < _m)
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

void Graph::Export(int fileNumber)
{
	FILE *out;
	string fileName = "tmp/graph";
	string dot = ".dot";
	fileName += to_string(fileNumber) + dot;
	out = fopen(fileName.c_str(), "w");
	fprintf(out, "graph graphname {\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(out, "  %d [style=filled, colorscheme=set19, fillcolor = %d];\n", i, numComp[i]+1);
	}
	for (int i = 0; i < m; i++)
	{
		// fprintf(out, "  %d -- %d;\n", I[i], J[i]);
		fprintf(out, "  %d -- %d ;\n", IJ[i], IJ[2 * m - i - 1]);
	}
	fprintf(out, "}\n" );
	fclose(out);


}
