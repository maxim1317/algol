#ifndef __GRAPH_DIJKSTRA_HPP__
#define __GRAPH_DIJKSTRA_HPP__
#endif

// int Graph::MinEdge(bool sptSet[])
// {
//     int min = INT_MAX, min_index;

//     for (int v = 0; v < n; v++)
//     if (sptSet[v] == false && distance[v] <= min)
//     {
//         min = distance[v];
//         min_index = v;
//     }
//     return min_index;
// }

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
        if ((I[i] == from && J[i] == to) || (J[i] == from && I[i] == to))
            return weight[i];
    }

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

    std::vector<int> q, neighbours;

    distance.clear();
    distance.assign(n, INT_MAX);
    mark.clear();
    mark.assign(n, 0);
    
    distance[start] = 0;
    q.push_back(start);
    while (q.size() != 0)
    {
        printf("!\n");
        int v = q[0];
        q = pop(q);

        neighbours = this->GetNeighbours(v);
        printf("v = %d\n", v);


        std::vector<int> u;
        for (int i = 0; i < neighbours.size(); ++i)
        {
            u.push_back(MinEdge(v, neighbours));
            neighbours = del(neighbours, u[i]);
        }
        neighbours = u;
        printf("neighbours = ");
        for (int i = 0; i < neighbours.size(); ++i)
        {
            printf("%d, ", neighbours[i]);
        }
        printf("\n");

        for (int i = 0; i < neighbours.size(); i++)
        {
            printf("v=%d, i= %d:%d + %d < %d\n", i, v, distance[v], GetWeight(v, neighbours[i]), distance[neighbours[i]]);
            if ((distance[neighbours[i]] == INT_MAX) || (distance[v] + GetWeight(v, neighbours[i]) < distance[neighbours[i]]))
            {
                printf("!!!\n");
                distance[neighbours[i]] = distance[v] + GetWeight(v, neighbours[i]);
                mark[neighbours[i]] = 1;
                q.push_back(neighbours[i]);
                q = priority(q);
            }
        }

        printf("q = ");
        for (int i = 0; i < q.size(); ++i)
        {
            printf("%d, ", q[i]);
        }
        printf("\n");
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
        printf("GetWeight(%d, %d) = %d\n", v, nlist[i], u);
        if (u < min)
        {
            min = u;
            min_index = nlist[i];
        }
    }
    printf("min_index = %d\n", min_index);
    return min_index;

}


// std::vector<int> Graph::pushmin(std::vector<int> &q, int from, int to)
// {
//     std::vector<int> res;
//     int w = GetWeight(from, to);
//     for (int i = 0; i < q.size(); ++i)
//     {
//         if (w < GetWeight(from, q[i])
//         {
//             q.insert(q.begin() + i, to);
//             res = q;            
//             return res;
//         }
//     }

//     q.push_back(to);
//     res = q;
//     return res;
// }