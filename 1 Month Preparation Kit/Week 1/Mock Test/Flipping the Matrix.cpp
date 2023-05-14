#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int q;
    cin >> q;
    
    while (q--) {
        int n;
        cin >> n;
        
        int mat[2*n][2*n];
        for (int i = 0; i < 2*n; i++) {
            for (int j = 0; j < 2*n; j++) {
                cin >> mat[i][j];
            }
        }

        int sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += max(mat[i][j], max(mat[2*n - 1 - i][j], max(mat[i][2*n - 1 - j], mat[2*n - 1 - i][2*n - 1 - j])));
            }
        }

        cout << sum << "\n";
    }
}
