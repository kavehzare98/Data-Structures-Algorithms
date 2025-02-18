def addEdge(matrix, i, j):
    matrix[i][j] = 1
    matrix[j][i] = 1


def displayMatrix(matrix):
    V = len(matrix)
    for i in range(V):
        for j in range(V):
            print(matrix[i][j], end=" ")
        print()

if __name__ == "__main__":
    V = 4
    matrix = [[0] * V for i in range(V)]

    addEdge(matrix, 0, 1)
    addEdge(matrix, 0, 2)
    addEdge(matrix, 1, 2)
    addEdge(matrix, 2, 3)

    print("Adjacency Matrix representation: ")
    displayMatrix(matrix)

