#ifndef __GRAPH_PRINTS_HPP__
#define __GRAPH_PRINTS_HPP__
#endif

using namespace std;

void Graph::PrintIJHL()
{
	printf("\n");

	printf("%s", conColor(50));
  	printf("__________VERSION_%d__________\n", version);
  	printf("%s", conColor(0));
	printf("%s", conColor(160));
	printf("|  # | I | J |  H |  L | IJ |\n");
	printf("%s", conColor(0));
	int k = 0;

	if (m < n)
    {
        while (k < m)
        {
            printf("%s", conColor(50+10*(k%2)));
            printf("| %2d | %d | %d | %2d | %2d | %2d |\n", k, I[k], J[k], H[k], L[k], IJ[k]);
            printf("%s", conColor(0));
            k++;
        }
        
        while (k < n)
        {
            printf("%s", conColor(50+10*(k%2)));
            printf("| %2d |   |   | %2d | %2d | %2d |\n", k, H[k], L[k], IJ[k]);
            printf("%s", conColor(0));
            k++;
        }
    }
    else{
    	while (k < n)
    	{
    		printf("%s", conColor(50+10*(k%2)));
    		printf("| %2d | %d | %d | %2d | %2d | %2d |\n", k, I[k], J[k], H[k], L[k], IJ[k]);
    		printf("%s", conColor(0));
    		k++;
    	}
    	
    	while (k < m)
    	{
    		printf("%s", conColor(50+10*(k%2)));
    		printf("| %2d | %d | %d |    | %2d | %2d |\n", k, I[k], J[k], L[k], IJ[k]);
    		printf("%s", conColor(0));
    		k++;
    	}
    }
	while (k < 2*m)
	{
		printf("%s", conColor(50+10*(k%2)));
		printf("| %2d |   |   |    | %2d | %2d |\n", k, L[k], IJ[k]);
		printf("%s", conColor(0));
		k++;
	}
}

void Graph::PrintColors()
{
	printf("%s",conColor(160));
    printf("\n|Col %d|", version);
    printf("%s\n",conColor(0));
    for (int i = 0; i < n; i++)
    {
    	printf("%s", conColor(160));
    	cout<<"|__";
    	printf("%s", conColor(110+numComp[i]*10));
        printf("%1d", numComp[i]);
        printf("%s", conColor(160));
    	cout<<"__|\n";
    	printf("%s", conColor(0));
    }
}

void Graph::Export(int option = 0)
{
	FILE *out;
	string fileName = "tmp/dots/graph";
	string dot = ".dot";
	fileName += to_string(version) + dot;
	out = fopen(fileName.c_str(), "w");
	fprintf(out, "graph graphname {\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(out, "  %d [style=filled, colorscheme=set19, fillcolor = %d];\n", i, numComp[i]+1);
        if (option)
        {
            fprintf(out, " %d--%d  [style=dotted, arrowhead=odot, arrowsize=1] ;\n", i, i+n+1);
            fprintf(out, " %d [shape=plaintext,label=\"%d\"]", i+n+1, distance[i]);
            fprintf(out, " {rank=same; %d;%d}\n", i, i+n+1);

//             b->iuc [style=dotted, arrowhead=odot, arrowsize=1] ;
// iuc [shape=plaintext,label="This is a test of a long\n comment and how dot is showing\n it"];
// {rank=same; b;iuc}
        }
	}
	for (int i = 0; i < m; i++)
	{
		// fprintf(out, "  %d -- %d;\n", I[i], J[i]);
		fprintf(out, "  %d -- %d ;\n", IJ[i], IJ[2 * m - i - 1]);
	}
	fprintf(out, "}\n" );
	fclose(out);


}
