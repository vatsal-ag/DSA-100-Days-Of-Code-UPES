// Given a 2D integer array matrix, return the transpose of matrix.
// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
// Name: Vatsal Agarwal
// SAP ID: 590023223

int **transpose(int **matrix, int matrixSize, int *matrixColSize, int *returnSize, int **returnColumnSizes)
{
    int rows = matrixSize;
    int cols = matrixColSize[0];
    *returnSize = cols;
    *returnColumnSizes = (int *)malloc(cols * sizeof(int));
    int **result = (int **)malloc(cols * sizeof(int *));
    for (int i = 0; i < cols; i++)
    {
        (*returnColumnSizes)[i] = rows;
        result[i] = (int *)malloc(rows * sizeof(int));
        for (int j = 0; j < rows; j++)
        {
            result[i][j] = matrix[j][i];
        }
    }

    return result;
}
