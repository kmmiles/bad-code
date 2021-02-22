#include <iostream>
#include <vector>

using namespace std;

int main() {
    int M = 0, N = 0;
    cin >> M >> N;
    vector<vector<char>> art( M , vector<char> (N, 0)); 

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            art[i][j] = 'B';
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << art[i][j] << " ";
        }
        cout << "\n";
    }
}
