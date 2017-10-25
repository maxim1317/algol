#ifndef __GRAPH_BELFORD_HPP__
#define __GRAPH_BELFORD_HPP__
#endif

void Graph::Belford(int start) 
{

    distance.clear();
    distance.assign(n, INT_MAX);
    distance[start] = 0;
    // for (int i = 0; i < n-1; ++i)
    //     for (int j = 0; j < m; ++j)
    //         if (distance[IJ[j]] < INT_MAX)
    //             distance[IJ[2*m-j-1]] = min (distance[IJ[2*m - j - 1]], distance[IJ[j]] + weight[j]);


    // Step 2: Relax all edges |V| - 1 times. A simple shortest 
    // path from src to any other vertex can have at-most |V| - 1 
    // edges
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
 
    // Step 3: check for negative-weight cycles.  The above step 
    // guarantees shortest distances if graph doesn't contain 
    // negative weight cycle.  If we get a shorter path, then there
    // is a cycle.
    for (int i = 0; i < m; i++)
    {
        int u = I[i];
        int v = J[i];
        int weights = weight[i];
        if (distance[u] != INT_MAX && distance[u] + weights < distance[v])
            printf("Graph contains negative weight cycle");
    }        
}