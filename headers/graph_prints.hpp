#ifndef __GRAPH_PRINTS_HPP__
#define __GRAPH_PRINTS_HPP__
#endif

using namespace std;

void Graph::PrintIJHL()
{
	printf("\n");
    const char* s1 = conColor(50);
	printf("%s", s1);
  	printf("____________VERSION_%s-%d____________", prefix.c_str(), version);
  	printf("%s\n", conColor(0));
	printf("%s", conColor(160));
	printf("|  # | I | J |  H |  L | IJ |  W  |");
	printf("%s\n", conColor(0));
	int k = 0;
    int n = this->n;

	if (m < n)
    {
        while (k < m)
        {
            printf("%s", conColor(50+10*(k%2)));
            printf("| %2d | %d | %d | %2d | %2d | %2d | %3s |", k, I[k], J[k], H[k], L[k], IJ[k], getw(k));
            printf("%s\n", conColor(0));
            k++;
        }
        
        while (k < n)
        {
            printf("%s", conColor(50+10*(k%2)));
            if (mode != 2)
                printf("| %2d |   |   | %2d | %2d | %2d |     |", k, H[k], L[k], IJ[k]);
            else
                printf("| %2d |   |   | %2d |    | %2d |     |", k, H[k], IJ[k]);
            printf("%s\n", conColor(0));
            k++;
        }
    }
    else{
    	while (k < n)
    	{
    		printf("%s", conColor(50+10*(k%2)));
    		printf("| %2d | %d | %d | %2d | %2d | %2d | %3s |", k, I[k], J[k], H[k], L[k], IJ[k], getw(k));
    		printf("%s\n", conColor(0));
    		k++;
    	}
    	
    	while (k < m)
    	{
    		printf("%s", conColor(50+10*(k%2)));
    		printf("| %2d | %d | %d |    | %2d | %2d | %3s |", k, I[k], J[k], L[k], IJ[k], getw(k));
    		printf("%s\n", conColor(0));
    		k++;
    	}
    }
	while (k < 2*m/mode)
	{
		printf("%s", conColor(50+10*(k%2)));
		printf("| %2d |   |   |    | %2d | %2d |     |", k, L[k], IJ[k]);
		printf("%s\n", conColor(0));
		k++;
	}
}

void Graph::PrintColors()
{
	printf("\n%s",conColor(160));
    printf("|Col %d|", version);
    printf("%s\n",conColor(0));

    printf("%s",conColor(160));
    printf("|  %1s  |", prefix.c_str());
    printf("%s\n",conColor(0));
    for (int i = 0; i < n; i++)
    {
    	printf("%s", conColor(160));
    	cout<<"|__";
    	printf("%s", conColor(110+numComp[i]*10));
        printf("%1d", numComp[i]);
        printf("%s", conColor(160));
    	cout<<"__|";
    	printf("%s\n", conColor(0));
    }
}

void Graph::Export(int option = 0)
{
	FILE *out;
	string fileName = "tmp/dots/graph";
	string dot = ".dot";
	fileName += "_" + prefix + "-" + to_string(version) + "_" + algorithm + dot;
	out = fopen(fileName.c_str(), "w");
    fileName = prefix + "_" + to_string(version) + "_" + algorithm;
    if (mode != 2)
	   fprintf(out, "graph %s {\n", fileName.c_str());
    else
        fprintf(out, "digraph %s {\n", fileName.c_str());
	for (int i = 0; i < n; i++)
	{
		fprintf(out, "  %d [style=filled, colorscheme=set19, fillcolor = %d];\n", i, numComp[i]+1);
        if (option == 1)
        {
            if (mode != 2)
                fprintf(out, "    %d--%d  [style=dotted, arrowhead=tee, arrowsize=1] ;\n", i, i+n+1);
            else
                fprintf(out, "    %d->%d  [style=dotted, arrowhead=tee, arrowsize=1] ;\n", i, i+n+1);
            if (distance[i] != INT_MAX)
                fprintf(out, "    %d [shape=plaintext,label=\"%d\"]", i+n+1, distance[i]);
            else
                fprintf(out, "    %d [shape=plaintext,label=\"INF\"]", i+n+1);
            fprintf(out, "    {rank=same; %d;%d}\n\n", i, i+n+1);
        }
	}
	for (int i = 0; i < m; i++)
	{
        if (weight[i] != INT_MAX)
        {
            if (mode != 2)
                fprintf(out, "  %d -- %d [label = %s];\n", IJ[i], IJ[2 * m - i - 1], getw(i));
            else
                fprintf(out, "  %d -> %d [label = %s];\n", IJ[i], IJ[2 * m - i - 1], getw(i));
        }
        else
        {
            if (mode != 2)
                fprintf(out, "  %d -- %d ;\n", IJ[i], IJ[2 * m - i - 1]);
            else
                fprintf(out, "  %d -> %d ;\n", IJ[i], IJ[2 * m - i - 1]);
        }

	}
    if (process.size() != 0)
    {
        for (int i = 0; i < process.size(); ++i)
        {
            fprintf(out, "  %d [style=filled, colorscheme=set19, fillcolor = 3, label=\"%d\"];\n", process[i] + 3*n, process[i]);
        }
        for (int i = 0; i < process.size() - 1; ++i)
        {
            fprintf(out, "  %d -> %d;\n", process[i] + 3*n, process[i+1] + 3*n);
        }
    }

	fprintf(out, "}\n" );
	fclose(out);
}

const char* Graph::getw(int w)
{
    string r = "INF";
    if (weight[w] != INT_MAX)
    {
        if (weight[w] < 0)
            r = to_string(weight[w])+" ";
        else
            r = " " + to_string(weight[w]) + " ";
        return r.c_str();
    }
    return r.c_str();
}