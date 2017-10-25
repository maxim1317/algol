#ifndef __GRAPH_H__
#define __GRAPH_H__
#endif

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <climits>

int val = 0;

class Graph
{
private:
// In /headers/graph_main.hpp:
    void GenIJ();
    void GenHl();
    void PrintColors();   

// In /headers/graph_dfs.hpp:
    void DFS(int, int);

// In /headers/graph_bfs.hpp:
    std::vector<int> GetNeighbours(int);


public:

    int n, m, version;
    int tmp = 0;
    char* prefix = ""; 

    std::vector<int> I, J, H, L, IJ;
    std::vector<int> weight, numComp, colors;
    std::vector<int> queue, distance, mark;

// In /headers/graph_main.hpp:
    void ReadIJ();
    void Add(int, int);
    void DeleteArc(int, int);

    Graph(int, std::vector<int>&, std::vector<int>&);
    Graph(int, std::vector<int>&, std::vector<int>&, std::vector<int>&);
    Graph();
    ~Graph(){}; 

// In /headers/graph_dfs.hpp:
    void ConnectedComponent();

// In /headers/graph_bfs.hpp:
    void BFS(int);

// In /headers/graph_bfs.hpp:
    void Belford(int);

// In /headers/graph_prints.hpp:
    void Export(int);
    void PrintIJHL();
    
};

#include "colors.hpp"

// In /headers/colors.hpp:
const char* conColor (int);

std::vector<int> pop(std::vector<int> &vec)
{
    if (!vec.size()) return vec;
    std::vector<int> res;
    for (int i = 1; i < vec.size(); i++)
        res.push_back(vec[i]);
    
    return res;
}

#include "graph_main.hpp"
#include "graph_dfs.hpp"
#include "graph_bfs.hpp"
#include "graph_belford.hpp"
#include "graph_prints.hpp"


