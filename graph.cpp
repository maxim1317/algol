#include <stdio.h>
#include <iostream>
#include <vector>
#include "headers/graph.h"

using namespace std;

int main(int argc, char const *argv[])
{

  //Graph a;
  //a.ReadIJ();
  vector<int> vi = {0, 3, 4, 5};
  vector<int> vj = {1, 2, 2, 6};

  Graph a(7, vi, vj);
  printf("\n");


  // a.PrintIJHL();

  a.ConnectedComponent();
  a.Export(1);
  
  a.Add(6, 4);
  // a.PrintIJHL();
  
  a.ConnectedComponent();
  a.Export(2);

  a.Add(1,6);
  a.PrintIJHL();

  a.ConnectedComponent();
  a.BFS(2);
  a.Export(3, 1);

  return 0;
}


