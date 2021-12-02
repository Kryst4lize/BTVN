#include<vector>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
/*
int sumRow(int n, int k)
{
    int row = 0, col = 0;

    int boundary = n - 1;
    int sizeLeft = n - 1;
    int flag = 1;
    char move = 'r';
    int matrix[n][n] = { 0 };

    for (int i = 1; i < n * n + 1; i++)
    {
        matrix[row][col] = i;

        switch (move)
        {
        case 'r':
            col += 1;
            break;
        case 'l':
            col -= 1;
            break;
        case 'u':
            row -= 1;
            break;
        case 'd':
            row += 1;
            break;
        }
        if (i == boundary)
        {
            boundary += sizeLeft;
            if (flag != 2)
            {
                flag = 2;
            }
            else
            {
                flag = 1;
                sizeLeft -= 1;
            }
            switch (move)
            {
            case 'r':
                move = 'd';
                break;
            case 'd':
                move = 'l';
                break;
            case 'l':
                move = 'u';
                break;
            case 'u':
                move = 'r';
                break;
            }
        }
    }
    int sum=0;
    for (int i = 0; i < n; i++) {
        sum += matrix[k - 1][i];
    }
    return sum;
}

// Driver Code
int mainte1()
{

    // Get the size of size
    int size = 5;
    int k = 4;
    cin >> size >> k;
    // Print the Spiral Pattern
    sumRow(size,k);
    return 0;
}
*/