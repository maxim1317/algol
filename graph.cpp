#include <stdio.h>
#include <iostream>
#include <vector>
#include "graph.h"


using namespace std;

int main(int argc, char const *argv[])
{

  //Graph a;
  //a.ReadIJ();
  vector<int> vi = {0, 0, 3, 4};
  vector<int> vj = {1, 2, 2, 2};

  Graph a(5, vi, vj);
  a.PrintIJHL();
  //a.Add(0, 3);
  a.PrintIJHL();
  a.Export();
  a.ConnectedComponent();

  return 0;
}


