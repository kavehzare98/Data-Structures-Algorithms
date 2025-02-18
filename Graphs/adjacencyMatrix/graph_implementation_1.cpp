/*
 * This is a C++ program to demonstrate Adjacency Matrix
 * representation of undirected and unweighted graph
*/
#include <vector>
#include <iostream>
using namespace std;

void addEdge(vector<vector<int>> &matrix,  int i, int j)
{
    matrix[i][j] = 1;
    matrix[j][i] = 1;
}

void displayMatrix(vector<vector<int>> &matrix)
{
    int V = matrix.size();
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Create a graph with 4 vertices and no edges 
    // Note that all values are initialized as 0

    int V = 4;
    vector<vector<int>> matrix(V, vector<int>(V, 0));   // initializing all to 0
    
    // Now adding all edges one by one
    addEdge(matrix, 0, 1);
    addEdge(matrix, 0, 2);
    addEdge(matrix, 1, 2);
    addEdge(matrix, 2, 3);

    cout << "Adjacency matrix representation" << endl;
    displayMatrix(matrix);
    
    return 0;
}
