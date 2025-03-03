/*
 * Adjacency List Rep:
 * Collection of linked lists
 * There is an array of pointers which points to the edges connected to that vertex
*/

#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>> &adjList, int i, int j)
{
    adjList[i].push_back(j);
    adjList[j].push_back(i);
}

void displayAdjList(const vector<vector<int>> &adjList)
{
    for (int i = 0; i < adjList.size(); i++)
    {
        cout << i << ": "; // Print the vertex
        for (int j : adjList[i])
        {
            cout << j << " ";   // prints its adjacent
        }
        cout << endl;
    }
}

int main()
{
    int V = 4;
    vector<vector<int>> adjList(V);

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adjList);

    return 0;
}
