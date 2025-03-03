def addEdge(adjList, i, j):
    adjList[i].append(j)
    adjList[j].append(i)

def displayAdjList(adjList):
    for i in range(len(adjList)):
        print(f"{i}: ", end="")
        for j in adjList[i]:
            print(j, end=" ")
        print()

V = 4
adj = [ [] for _ in range(V) ]

addEdge(adj, 0, 1)
addEdge(adj, 0, 2)
addEdge(adj, 1, 2)
addEdge(adj, 2, 3)

print("Adjacency List rep:")
displayAdjList(adj)
