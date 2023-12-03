#include <iostream>
#include <vector>
using namespace std;


int maxCoins(vector<vector<int>>& castle, int N, vector<vector<int>>& path) {
    vector<vector<int>> dp(N, vector<int>(N, 0));
    dp[0][0] = castle[0][0];

    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + castle[i][0];
        dp[0][i] = dp[0][i - 1] + castle[0][i];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + castle[i][j];
        }
    }

    
    int i = N - 1, j = N - 1;
    while (i > 0 && j > 0) {
        path[i][j] = 1;
        if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    while (i > 0) {
        path[i][j] = 1;
        i--;
    }

    while (j > 0) {
        path[i][j] = 1;
        j--;
    }

    path[0][0] = 1;

    return dp[N - 1][N - 1];
}

int main() {

    setlocale(LC_ALL, "ukrainian");

    int N;
    cout << "Введіть кількість кімнат N: ";
    cin >> N;

    vector<vector<int>> castle(N, vector<int>(N));
    cout << "Введіть кількість монет в кожній кімнаті (всього " << N * N << " кімнат):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> castle[i][j];
        }
    }

    vector<vector<int>> path(N, vector<int>(N, 0));
    int result = maxCoins(castle, N, path);
    cout << "Максимальна кількість монет, які Буратіно може зібрати: " << result << endl;

    cout << "Маршрут, яким Буратіно пройде:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << path[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
