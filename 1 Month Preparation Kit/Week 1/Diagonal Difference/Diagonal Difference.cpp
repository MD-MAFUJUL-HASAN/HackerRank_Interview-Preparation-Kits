#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int i, j, k = 0, l = 0, m, n;
    cin >> n;
    vector<vector<int>> z(n, vector<int>(n));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> z[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = i; j <= i; j++)
        {
            k = k + z[i][j];
        }
        l = l + z[i][n - i - 1];
    }
    m = abs(k - l);
    cout << m;
    return 0;
}
