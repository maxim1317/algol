#ifndef __GRAPH_BFS_HPP__
#define __GRAPH_BFS_HPP__
#endif

void Graph::BFS(int start)
{
    std::vector<int> q;
    std::vector<int> neighbours;
    for (int i = 0; i < n; i++)
    {
        distance.push_back(0);
        mark.push_back(0);
    }

    q.push_back(start);
    mark[start] = 1;

    while (q.size() != 0)
    {
        int v = q[0];
        q=pop(q);
        neighbours = this->GetNeighbours(v);
        for (int i = 0; i < neighbours.size(); ++i)
        {
            if (mark[neighbours[i]] == 0)
            {
                // То вычисляем расстояние
                distance[neighbours[i]] = distance[v] + 1;
                // И он становится серым
                mark[neighbours[i]] = 1;
                q.push_back(neighbours[i]);
            }

        }
    }
}

std::vector<int> Graph::GetNeighbours(int vertex)
{
    int v;
    std::vector<int> res;
    v = H[vertex];

    while (v != -1)
    {
        res.push_back(IJ[m*2-v-1]);
        v = L[v];
    }

    return res;
}