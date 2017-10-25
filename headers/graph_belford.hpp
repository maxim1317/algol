#ifndef __GRAPH_BELFORD_HPP__
#define __GRAPH_BELFORD_HPP__
#endif

void Graph::Belford(int start) 
{

    distance.clear();
    distance.assign(n, INT_MAX);
    distance[start] = 0;
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = I[j];
            int v = J[j];
            int weights = weight[j];
            if (distance[u] != INT_MAX && distance[u] + weights < distance[v])
                distance[v] = distance[u] + weights;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u = I[i];
        int v = J[i];
        int weights = weight[i];
        if (distance[u] != INT_MAX && distance[u] + weights < distance[v])
            printf("Negative cycle\n");
    }        
}