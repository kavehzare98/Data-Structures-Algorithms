#include <iostream>
using namespace std;

// Node to store adjacency list
class AdjNode {
    public:
        int vertex;         // This is the data point that's stored
        AdjNode* next;      // next pointer

        AdjNode(int data)   // Constructor for the class
        {
            vertex = data;
            next = nullptr;
        }
};

// Adjacency List representation
class AdjList {
private:
    int v;                  // stores number of vertices
    AdjNode** graph;        // pointer to an array of pointers to AdjNode objects.
public:
    AdjList(int vertices) { // constructor for the AdjList class
        v = vertices;       
        graph = new AdjNode*[v]; // dynamically allocated space for the AdjList
        for (int i = 0; i < v; ++i) 
            graph[i] = nullptr;     // setting all nodes to nullptr
    }

    void addEdge(int source, int destination) {
        AdjNode* node = new AdjNode(destination);
        node->next = graph[source];
        graph[source] = node;
    }

    void addVertex(int vk, int source, int destination) {
        addEdge(source, vk);
        addEdge(vk, destination);
    }

    void printGraph() {
        for (int i = 0; i < v; ++i) {
            if (graph[i] == nullptr)
                continue;
            
                cout << i << " ";
                AdjNode* temp = graph[i];
                while (temp != nullptr) {
                    cout << "-> " << temp->vertex << " ";
                    temp = temp->next;
                }
                cout << endl;
        }
    }

    void delVertex(int k) {
        for (int i = 0; i < v; i++) {
            AdjNode *curr = graph[i], *prev = nullptr;
            if (i == k) {
                graph[i] = nullptr;
                while (curr != nullptr) {
                    AdjNode* next = curr->next;
                    delete (curr);
                    curr = next;
                }
            } else {
                while (curr != nullptr) {
                    if (curr->vertex == k) {
                        if (prev == nullptr) {
                            graph[i] = curr->next;
                        } else {
                            prev->next = curr->next;
                        }
                        delete curr;
                        break;
                    }
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
    }
};

int main() {
    int V = 6;
    AdjList graph(V);  
    graph.addEdge(0, 1);
    graph.addEdge(0, 3);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(3, 2);
    graph.addEdge(4, 3);

    cout << "Initial adjacency list" << endl;
    graph.printGraph();

    graph.addVertex(5, 3, 2);
    cout << "Adjacency list after adding vertex" << endl;
    graph.printGraph();

    graph.delVertex(4);
    cout << "Adjacency list after deleting vertex" << endl;
    graph.printGraph();

    return 0;
}