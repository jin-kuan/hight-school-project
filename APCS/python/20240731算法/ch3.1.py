def printMatrix(matrix):
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print(matrix[i][j], end=' ')
        print()

def matrixAdd(A, B):
    n = len(A)
    m = len(A[0])
    C = [[None]*m for row in range(n)]
    for i in range(n):
        for j in range(m):
            C[i][j] = A[i][j]+B[i][j]
    return C

def matrixSubtract(A, B):
    n = len(A)
    m = len(A[0])
    C = [[None]*m for row in range(n)]
    for i in range(n):
        for j in range(m):
            C[i][j] = A[i][j]-B[i][j]
    return C

matrixA = [[1,3,5], [7,9,11], [13,15,17]]
matrixB = [[9,8,7], [6,5,4], [3,2,1]]
matrixC = matrixAdd(matrixA,matrixB)
matrixD = matrixSubtract(matrixA,matrixB)

print("MatrixA:")
printMatrix(matrixA)
print("MatrixB:")
printMatrix(matrixB)
print("MatrixA + MatrixB:")
printMatrix(matrixC)
print("MatrixA - MatrixB:")
printMatrix(matrixD)
