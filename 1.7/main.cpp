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


void SetZero(int matrix[MAXN][MAXN], int n)
{
    bool row[MAXN];
    bool colum[MAXN];
    memset(row, false, sizeof(row));
    memset(colum, false, sizeof(colum));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(matrix[i][j] == 0)
            {
                row[i] = true;
                colum[j] = true;
            }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(row[i] || colum[j]) matrix[i][j] = 0;
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
    int count = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            matrix[i][j] = count++;
    matrix[7][8] = 0;
    matrix[4][1] = 0;
    SetZero(matrix, n);
    printMatrix(matrix, n);
    return 0;
}