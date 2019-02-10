#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_
// Cac vi tri can dien dc dien la 0.
#define UNASSIGNED 0

// Define so phan tu cua matrix la 9 x 9
#define N 9
// Function tim vi tri can dien
bool FindUnassignedLocation(int grid[N][N], int &row, int &col);

// Function tim kiem vi tri de dien
bool isSafe(int grid[N][N], int row, int col, int num);

// Function chinh, use backTracking de dien vi tri
bool SolveSudoku(int grid[N][N]);

// Test hang
bool UsedInRow(int grid[N][N], int row, int num);
// Test cot
bool UsedInCol(int grid[N][N], int col, int num);
// Test 9 ô xung quanh
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num);
//  Test vi tri
bool isSafe(int grid[N][N], int row, int col, int num);
// Print Matrix
void printGrid(int grid[N][N]);
#endif // COMMON_FUNCTION_H_
