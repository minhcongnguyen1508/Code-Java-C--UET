// Tu tuong chinh la use BackTrack
#include <iostream>
#include "Common_Function.h"
// Cac vi tri can dien dc dien la 0.
#define UNASSIGNED 0

// Define so phan tu cua matrix la 9 x 9
#define N 9
using namespace std;
int main()
{   // Co the dua vao mot mang dung bat ki xong giau vi tri. Co the check lai.
    int grid[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {0, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
//
//    for(int i = 0; i < N; i++)
//    {
//        for(int j = 0; j < N; j++)
//        {
//            grid[i][j] = 0;
//        }
//    }


    printGrid(grid);
    cout<<endl<<endl;

    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
         cout<< "No solution exists"<<endl;

    return 0;
}
