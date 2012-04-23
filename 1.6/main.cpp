/*	
    CareerCup 150 Questions 4th
    Solutions to Chapter 1 | Arrays and Strings
    1.6 Given an image represented by an NxN matrix, 
        where each pixel in the image is 4 bytes, 
        write a method to rotate the image by 90 degrees. 
        Can you do this in place?
    [VS2010][2012.04.23][by gboystal]
*/

#include<iostream>
#include<string>
using namespace std;

const int MAXN = 100;


void rotate1(int matrix[MAXN][MAXN], int newMatrix[MAXN][MAXN], int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            newMatrix[j][n - i - 1] = matrix[i][j];
}

void rotate2(int matrix[MAXN][MAXN], int n)
{
    for(int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;
        int last = n - first - 1;
        for(int i = first; i < last; i++)
        {
            int offset = i - first;

            //tmp = top
            int tmp = matrix[first][i];

            //top = left;
            matrix[first][i] = matrix[last - offset][first];

            //left = bottom
            matrix[last - offset][first] = matrix[last][last - offset];

            //bottom = right
            matrix[last][last - offset] = matrix[first + offset][last];

            //right = tmp
            matrix[first + offset][last] = tmp;
        }
    }
}

void printMatrix(int matrix[MAXN][MAXN], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 10;
    int matrix[MAXN][MAXN];
    int newMatrix[MAXN][MAXN];
    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            matrix[i][j] = count++;
    rotate2(matrix, n);
    printMatrix(matrix, n);
    return 0;
}