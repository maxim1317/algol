#ifndef __GRAPH_BELFORD_HPP__
#define __GRAPH_BELFORD_HPP__
#endif

// void Graph::Belford(int start) 
// {

//     distance.clear();
//     distance.assign(n, INT_MAX);
//     distance[start] = 0;
//     for (int i = 1; i <= n-1; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             int u = I[j];
//             int v = J[j];
//             int weights = weight[j];
//             if (distance[u] != INT_MAX && distance[u] + weights < distance[v])
//                 distance[v] = distance[u] + weights;
//         }
//     }
//     for (int i = 0; i < m; i++)
//     {
//         int u = I[i];
//         int v = J[i];
//         int weights = weight[i];
//         if (distance[u] != INT_MAX && distance[u] + weights < distance[v])
//             printf("Negative cycle\n");
//     }        
// }

std::vector<int> Graph::priority(std::vector<int> &q)
{
    std::vector<int> res;
    for (int i = 0; i < q.size(); ++i)
    {
        if (mark[i] == 0)
            res.push_back(q[i]);
        else
            res.insert(res.begin(), q[i]);
    }

    return res;
}

void Graph::Belford(int start)
{

    std::vector<int> q, neighbours;

    distance.clear();
    mark.clear();
    distance.assign(n, INT_MAX);
    mark.assign(n, 0);
    
    distance[start] = 0;
    q.push_back(start);
    while (q.size() != 0)
    {
        int v = q[0];
        q = pop(q);

        neighbours = this->GetNeighbours(v);
        for (int i = 0; i < neighbours.size(); ++i)
        {
            if (distance[v] == INT_MAX || distance[v] + GetWeight(v, neighbours[i]) < distance[neighbours[i]])
            {
                distance[neighbours[i]] = distance[v] + GetWeight(v, neighbours[i]);
                mark[neighbours[i]] = 1;
                q.push_back(neighbours[i]);
                q = priority(q);
            }

        }
    }

}