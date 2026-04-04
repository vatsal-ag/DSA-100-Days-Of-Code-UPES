// You are given an image represented by an m x n grid of integers image, where image[i][j] represents the pixel value of the image. You are also given three integers sr, sc, and color. Your task is to perform a flood fill on the image starting from the pixel image[sr][sc].
// To perform a flood fill:
// Begin with the starting pixel and change its color to color.
// Perform the same process for each pixel that is directly adjacent (pixels that share a side with the original pixel, either horizontally or vertically) and shares the same color as the starting pixel.
// Keep repeating this process by checking neighboring pixels of the updated pixels and modifying their color if it matches the original color of the starting pixel.
// The process stops when there are no more adjacent pixels of the original color to update.
// Return the modified image after performing the flood fill.
// Name: Vatsal Agarwal
// SAP ID: 590023223

#include <stdio.h>
#include <stdlib.h>

void dfs(int **image, int row, int col, int rows, int cols, int originalColor, int newColor)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols || image[row][col] != originalColor)
    {
        return;
    }

    image[row][col] = newColor;

    dfs(image, row + 1, col, rows, cols, originalColor, newColor);
    dfs(image, row - 1, col, rows, cols, originalColor, newColor);
    dfs(image, row, col + 1, rows, cols, originalColor, newColor);
    dfs(image, row, col - 1, rows, cols, originalColor, newColor);
}

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int color, int *returnSize, int **returnColumnSizes)
{
    int rows = imageSize;
    int cols = imageColSize[0];
    int originalColor = image[sr][sc];

    if (originalColor != color)
    {
        dfs(image, sr, sc, rows, cols, originalColor, color);
    }

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}

int main()
{
    int rows = 3, cols = 3;
    int **image = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        image[i] = (int *)malloc(cols * sizeof(int));
    }

    int data[3][3] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            image[i][j] = data[i][j];
        }
    }

    int returnSize;
    int *returnColSizes;
    int sr = 1, sc = 1, newColor = 2;

    int **result = floodFill(image, rows, &cols, sr, sc, newColor, &returnSize, &returnColSizes);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void dfs(int **image, int row, int col, int rows, int cols, int originalColor, int newColor)
{
    if (row < 0 || row >= rows || col < 0 || col >= cols || image[row][col] != originalColor)
    {
        return;
    }

    image[row][col] = newColor;

    dfs(image, row + 1, col, rows, cols, originalColor, newColor);
    dfs(image, row - 1, col, rows, cols, originalColor, newColor);
    dfs(image, row, col + 1, rows, cols, originalColor, newColor);
    dfs(image, row, col - 1, rows, cols, originalColor, newColor);
}

int **floodFill(int **image, int imageSize, int *imageColSize, int sr, int sc, int color, int *returnSize, int **returnColumnSizes)
{
    int rows = imageSize;
    int cols = imageColSize[0];
    int originalColor = image[sr][sc];

    if (originalColor != color)
    {
        dfs(image, sr, sc, rows, cols, originalColor, color);
    }

    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;
    return image;
}

int main()
{
    int rows = 3, cols = 3;
    int **image = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        image[i] = (int *)malloc(cols * sizeof(int));
    }

    int data[3][3] = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            image[i][j] = data[i][j];
        }
    }

    int returnSize;
    int *returnColSizes;
    int sr = 1, sc = 1, newColor = 2;

    int **result = floodFill(image, rows, &cols, sr, sc, newColor, &returnSize, &returnColSizes);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}