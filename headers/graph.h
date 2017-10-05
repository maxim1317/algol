#ifndef __GRAPH_H__
#define __GRAPH_H__
#endif

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>


class Graph
{
private:
  void DFS(int, int);
  void GenIJ();
  void GenHl();
public:

  int n, m;
  int tmp = 0;   
  std::vector<int> I, J, H, L, IJ, numComp, colors;

  void ReadIJ();
  void Export(int i);
  void PrintIJHL();
  void Add(int, int);
  void DeleteArc(int, int);
  void ConnectedComponent();
  Graph(int, std::vector<int>&, std::vector<int>&);
  Graph();
  ~Graph(){};  
  
};

#include "colors.hpp"

const char* conColor (int);

#include "graph_main.hpp"
#include "graph_dfs.hpp"
#include "graph_prints.hpp"