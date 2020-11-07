#include "Node.h"
#include "BFS.h"
#include "BFS.cpp"
#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>


int main(){
    vector<int> puzzle;
    puzzle.push_back(1);
    puzzle.push_back(2);
    puzzle.push_back(5);
    puzzle.push_back(3);
    puzzle.push_back(4);
    puzzle.push_back(0);
    puzzle.push_back(6);
    puzzle.push_back(7);
    puzzle.push_back(8);

    Node root = new Node(puzzle);
    BFS Test;
    list<Node> solution = Test.BreadthFirstSearch(root);

    if(solution.size() > 0){

        solution.reverse();
        for (int i = 0; i < solution.size() ; i++) {
            solution[i].PrintPuzzle();
        }
    }
    else{

        cout<<"No Solution"<<endl;

    }
}