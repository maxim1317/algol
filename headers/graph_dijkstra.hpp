#ifndef __GRAPH_DIJKSTRA_HPP__
#define __GRAPH_DIJKSTRA_HPP__
#endif

int Graph::MinEdge(bool sptSet[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
    if (sptSet[v] == false && distance[v] <= min)
    {
        min = distance[v];
        min_index = v;
    }
    return min_index;
}

int Graph::GetWeight(int from, int to)
{
    int k = H[from];
    if (IJ[2*m - k - 1] == to)
        return weight[k];
    while (k != -1)
    {
        k = L[k];
        if (IJ[2*m - k - 1] == to)
        {
            if (k > m)
                return weight[2*m - k - 1];
            else
                return weight[k];
        }
        
    }

    return 0;
}

void Graph::Dijkstra(int start)
{
    distance.clear();
    distance.assign(n, INT_MAX);
    distance[start] = 0;
  
    bool sptSet[n];

    for (int i = 0; i < n; i++)
        sptSet[i] = false;
  
    for (int count = 0; count < n-1; count++)
    {
        int u = MinEdge(sptSet);
  
        sptSet[u] = true;
  
        for (int v = 0; v < n; v++)
        {
            if (!sptSet[v] && GetWeight(u, v) && distance[u] != INT_MAX && distance[u]+ GetWeight(u, v) < distance[v])
                distance[v] = distance[u] + GetWeight(u, v);
        }
    }
  
}