#include "BFS.h"
#include "Node.cpp"
#include "Node.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>

 class BFS {

     bool Contains(list<Node> list, Node c) {

         bool contains = false;

         for (int i = 0; i < list.size(); i++) {

             if (list[i].IsSamePuzzle(c.Puzzle))
                 contains = true;

         }

         return contains;

     }

     void Trace(list<Node> path, Node n) {

         cout << "Tracing Path ...." << endl;
         Node current = n;
         path.push_back(current);

         while (current.Parent != NULL) {

             current = current.Parent;
             path.push_back(current);

         }

     }


 public:
     list<Node> BreadthFirstSearch(Node root) {

         list<Node> Path;
         list<Node> Open;
         list<Node> Closed;

         Open.push_back(root);
         bool goalFound = false;

         while (Open.size() > 0 && !goalFound) {

             Node currentNode = Open[0];
             Closed.push_back(currentNode);
             Open.erase(Open.begin());

             currentNode.ExpandNode();

             for (int i = 0; i < currentNode.children.size(); i++) {

                 Node currentChild = currentNode.children[i];
                 if (currentChild.GoalTest()) {

                     cout << "Goal Found" << endl;
                     goalFound = true;
                     Trace(Path, currentChild);
                 }

                 if (!Contains(Open, currentChild) && !Contains(Closed, currentChild)) {
                     Open.push_back(currentChild);
                 }

             }

             return Path;
         }

     }
 };