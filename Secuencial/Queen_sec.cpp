/*
Compilation Instructions

g++ -std=c++11 -fopenmp Queen.cpp

Execution Instructions

Example ./a.out

Example 2 OMP_NUM_THREADS=4 ./a.out
*/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <assert.h>
#include <omp.h>
#define stream istringstream
using namespace std;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
int n;

int call(int col, int rowmask, int move1, int move2)
{
    if (col == n)
    {
        return 1;
    }
    int row, ans = 0;

    for (row = 0; row < n; row++)
    {
        if (!(rowmask & (1 << row)) & !(move1 & (1 << (row + col))) & !(move2 & (1 << ((row + n - 1) - col))))
        {
            ans += call(col + 1, rowmask | 1 << row, move1 | (1 << (row + col)), move2 | (1 << ((row + n - 1) - col)));
        }
    }
    return ans;
}

double serial()
{

    double st = omp_get_wtime();
    int ans = 0;
    int i;
    int rowmask = 0, move1 = 0, move2 = 0;
    for (i = 0; i < n; i++)
    {
        rowmask = 0;
        move1 = 0, move2 = 0;
        int col = 0, row = i;
        ans += call(1, rowmask | 1 << row, move1 | (1 << (row + col)), move2 | (1 << ((row + n - 1) - col)));
    }
    printf("Found %d configuration for n=%d\n", ans, n);
    double en = omp_get_wtime();
    return en - st;
}
int main()
{
    READ("in");
    int count = 0;
    for (int i = 2; i <= 15; i++)
    {
        count++;
        n = i;
        double stime = serial();
        printf("Secuential takes %lf seconds for n=%d\n", stime, n);
        puts("===============");
    }
    return 0;
}
