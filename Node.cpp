#include "Node.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>
#include <list>
#include <array>

using namespace std;

class Node {

    public: list<Node> children;
    public: Node Parent;
    vector<int> Puzzle;
    int x = 0;
    int col = 3;

    Node(vector<int> p) {
        SetPuzzle(p);
    }

    void SetPuzzle(vector<int> p) {

        for (int i = 0; i < Puzzle.size(); i++)
            this->Puzzle[i] = p[i];
    }

    void Right(vector<int> p, int i) {

        if (i % col < col - 1) {

            vector<int> pc;
            CopyPuzzle(pc, p);

            int temp = pc[i + 1];
            pc[i + 1] = pc[i];
            pc[i] = temp;

            Node child = *new Node(pc);
            children.push_back(child);
            child.Parent = this;

        }

    }

    void Left(vector<int> p, int i) {

        if (i % col > 0) {

            vector<int> pc;
            CopyPuzzle(pc, p);

            int temp = pc[i - 1];
            pc[i - 1] = pc[i];
            pc[i] = temp;

            Node child = *new Node(pc);
            children.push_back(child);
            child.Parent = this;

        }
    }

    void Up(vector<int> p, int i) {

        if (i - col >= 0) {

            vector<int> pc;
            CopyPuzzle(pc, p);

            int temp = pc[i - 3];
            pc[i - 3] = pc[i];
            pc[i] = temp;

            Node child = *new Node(pc);
            children.push_back(child);
            child.Parent = this;

        }

    }

    void Down(vector<int> p, int i) {

        if (i + col < Puzzle.size()) {

            vector<int> pc;
            CopyPuzzle(pc, p);

            int temp = pc[i + 3];
            pc[i + 3] = pc[i];
            pc[i] = temp;

            Node child = *new Node(pc);
            children.push_back(child);
            child.Parent = this;
        }
    }

    void CopyPuzzle(vector<int> a, vector<int> b) {

        for (int i = 0; i < b.size(); i++) {
            a[i] = b[i];
        }
    }

    void PrintPuzzle() {

        cout << "\n" << endl;
        int m = 0;
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < col; j++) {
                cout << Puzzle[m] + " " << endl;
                m++;
            }
            cout << "\n" << endl;
        }
    }

    bool IsSamePuzzle(vector<int> p) {

        bool samePuzzle = true;
        for (int i = 0; i < p.size(); i++) {
            if (Puzzle[i] != p[i]) {
                samePuzzle = false;
            }
        }
        return samePuzzle;
    }

    void ExpandNode() {

        for (int i = 0; i < Puzzle.size(); i++) {
            if (Puzzle[i] == 0) {
                x = i;
            }
            Right(Puzzle, x);
            Left(Puzzle, x);
            Up(Puzzle, x);
            Down(Puzzle, x);
        }
    }


    bool GoalTest() {

        bool isGoal = true;
        int m = Puzzle[0];

        for (int i = 0; i < Puzzle.size(); i++) {
            if (m > Puzzle[i])
                isGoal = false;
            m = Puzzle[i];
        }

        return isGoal;
    }
};