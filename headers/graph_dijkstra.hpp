#ifndef __GRAPH_DIJKSTRA_HPP__
#define __GRAPH_DIJKSTRA_HPP__
#endif

// int Graph::GetWeight(int from, int to)
// {
//     int k = H[from];
//     if (IJ[2*m - k - 1] == to)
//         return weight[k];
//     while (k != -1)
//     {
//         if (L[k] == -1)
//             if (IJ[k] == to)
//                 return weight[k];
//         k = L[k];
//         if (IJ[2*m - k - 1] == to)
//         {
//             if (k > m)
//                 return weight[2*m - k - 1];
//             else
//                 return weight[k];
//         }

//     }

//     return 0;
// }

int Graph::GetWeight(int from, int to)
{
    for (int i = 0; i < m; ++i)
    {
        if ((I[i] == from && J[i] == to) || ((J[i] == from && I[i] == to) && mode != 2))
            return weight[i];
    }
    return 0;
}

// void Graph::Dijkstra(int start)
// {
//     distance.clear();
//     distance.assign(n, INT_MAX);
//     distance[start] = 0;
  
//     bool sptSet[n];

//     for (int i = 0; i < n; i++)
//         sptSet[i] = false;
  
//     for (int count = 0; count < n-1; count++)
//     {
//         int u = MinEdge(sptSet);
  
//         sptSet[u] = true;
  
//         for (int v = 0; v < n; v++)
//         {
//             if (!sptSet[v] && GetWeight(u, v) && distance[u] != INT_MAX && distance[u]+ GetWeight(u, v) < distance[v])
//                 distance[v] = distance[u] + GetWeight(u, v);
//         }
//     }
// }

void Graph::Dijkstra(int start)
{
    algorithm = "Dijkstra";

    process.clear();

    std::vector<int> q, neighbours;

    distance.clear();
    distance.assign(n, INT_MAX);
    mark.clear();
    mark.assign(n, 0);
    
    distance[start] = 0;
    q.push_back(start);
    while (q.size() != 0)
    {
        int v = q[0];
        process.push_back(v);
        q = pop(q);

        neighbours = this->GetNeighbours(v);

        std::vector<int> u;
        for (int i = 0; i < neighbours.size(); ++i)
        {
            u.push_back(MinEdge(v, neighbours));
            neighbours = del(neighbours, u[i]);
        }
        u.push_back(MinEdge(v, neighbours));
        neighbours = u;

        for (int i = 0; i < neighbours.size(); i++)
        {
            if ((distance[neighbours[i]] == INT_MAX) || (distance[v] + GetWeight(v, neighbours[i]) < distance[neighbours[i]]))
            {
                distance[neighbours[i]] = distance[v] + GetWeight(v, neighbours[i]);
                mark[neighbours[i]] = 1;
                q.push_back(neighbours[i]);
                q = priority(q);
            }
        }
    }

}

int Graph::MinEdge(int v, std::vector<int> &nlist)
{
    int min = INT_MAX;
    int min_index = v;
    int u;
    for (int i = 0; i < nlist.size(); ++i)
    {
        u = GetWeight(v, nlist[i]);
        if (u < min)
        {
            min = u;
            min_index = nlist[i];
        }
    }
    return min_index;

}

