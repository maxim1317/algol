#include <stdio.h>
#include <iostream>
#include <vector>
#include "graph.h"


using namespace std;

int main(int argc, char const *argv[])
{

  //Graph a;
  //a.ReadIJ();
  vector<int> vi = {0, 1, 0, 3, 3, 4, 2};
  vector<int> vj = {1, 3, 2, 2, 4, 2, 4};

  Graph a(5, vi, vj);
  a.PrintIJHL();
  a.Add(0, 3);
  a.PrintIJHL();
  a.Export();
  return 0;
}


