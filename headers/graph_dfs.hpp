#ifndef __GRAPH_DFS_HPP__
#define __GRAPH_DFS_HPP__
#endif

using namespace std;


void Graph::ConnectedComponent(){
    algorithm = "DFS";
    colors.push_back(0);
    int color = 0;
    for (int i = 0; i < numComp.size(); i++)
    {
        numComp[i] = -1;
    }
    for(int i = 0; i < n; i++){
        DFS(i, color);
        if (colors[color] != 0) 
        {
            color++;
            colors.push_back(0);
        }
    }

    PrintColors();

    colors.clear();
}

void Graph::DFS(int v, int color){
    if(numComp[v] == -1){
        numComp[v] = color;
        colors[color]++;

        for(int i = 0; i < 2*m; i++){
            if(IJ[i] == v){
                DFS(IJ[IJ.size() - 1 - i], color);
            }
        }
    }

}