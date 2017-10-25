#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include "headers/graph.h"

using namespace std;



int main(int argc, char const *argv[])
{

  //Graph a;
  //a.ReadIJ();
  vector<int> vi = {0, 0, 3, 4};
  vector<int> vj = {1, 2, 2, 6};
  std::vector<int> vh;

  Graph a(7, vi, vj);
  printf("\n");

  if (argc > 1)
    if (argv[1][1] == 'v')
    {
      val = 1;
    }

  // a.PrintIJHL();

  // a.prefix = "A";

  // a.ConnectedComponent();
  // a.Export();
  
  // a.Add(6, 4);
  // // a.PrintIJHL();
  
  // a.ConnectedComponent();
  // a.Export();

  // a.Add(1,6);
  // a.PrintIJHL();

  // a.ConnectedComponent();
  // a.BFS(2);
  // a.Export(1);

  vi.clear();
  vj.clear();
  vi = {0, 0, 1, 1, 1, 3, 3, 4};
  vj = {1, 2, 2, 3, 4, 2, 1, 3};
  vh = {1, 4, 3, 2, 2, 5, 1, 3};

  Graph b{5, vi, vj, vh};
  b.prefix = "B";

  b.PrintIJHL();
  b.ConnectedComponent();
  b.Belford(0);
  b.Export(1);
  // b.version++;
  // b.PrintIJHL();
  // b.ConnectedComponent();
  // b.Dijkstra(0);
  // b.Export(1);


  return 0;
}


