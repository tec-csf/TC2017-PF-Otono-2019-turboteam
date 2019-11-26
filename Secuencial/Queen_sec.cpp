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
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repv(i, n) for (int i = n - 1; i >= 0; i--)
#define repl(i, n) for (int i = 1; i <= (int)n; i++)
#define replv(i, n) for (int i = n; i >= 1; i--)

#define sz(x) (int)x.size()
#define INF (1061109567)
#define pb(x) push_back(x)
#define ppb pop_back
#define all(x) x.begin(), x.end()
#define mem(x, y) memset(x, y, sizeof(x));
#define eps 1e-9
#define pii pair<int, int>
#define pll pair<i64, i64>
#define pmp make_pair
using namespace std;
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1};

#define mx 1002

int n;

int call(int col, int rowmask, int dia1, int dia2)
{
    if (col == n)
    {
        return 1;
    }
    int row, ans = 0;

    for (row = 0; row < n; row++)
    {
        if (!(rowmask & (1 << row)) & !(dia1 & (1 << (row + col))) & !(dia2 & (1 << ((row + n - 1) - col))))
        {
            ans += call(col + 1, rowmask | 1 << row, dia1 | (1 << (row + col)), dia2 | (1 << ((row + n - 1) - col)));
        }
    }
    return ans;
}

double serial()
{

    double st = omp_get_wtime();
    int ans = 0;
    int i;
    int rowmask = 0, dia1 = 0, dia2 = 0;
    for (i = 0; i < n; i++)
    {
        rowmask = 0;
        dia1 = 0, dia2 = 0;
        int col = 0, row = i;
        ans += call(1, rowmask | 1 << row, dia1 | (1 << (row + col)), dia2 | (1 << ((row + n - 1) - col)));
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
