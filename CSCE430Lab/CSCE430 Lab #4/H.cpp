#include <bits/stdc++.h>

#include <iostream>
#define ll long long
#define pii pair<int, int>

using namespace std;

constexpr int INF = 1e9;
constexpr int MOD = 1e9 + 7;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}

void rotate(vector<string> &grille, int n) {
    vector<vector<char>> new_grille(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_grille[j][n - i - 1] = grille[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grille[i][j] = new_grille[i][j];
        }
    }

    // for (auto row : grille) {
    //     cout << row << endl;
    // }
    // cout << endl;
}

int main() {
    setIO();

    int n;
    cin >> n;
    

    vector<string> grille(n);
    for (int i = 0; i < n; i++) {
        cin >> grille[i];
    }

    string message;
    cin >> message;

    vector<vector<char>> ans(n, vector<char>(n, '?'));

    int idx = 0;

    for (int r = 0; r < 4; r++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grille[i][j] == '.') {
                    ans[i][j] = message[idx];
                    idx++;
                    
                }
            }
        }
        rotate(grille, n);
        // for (auto row : ans) {
        //     for (auto val : row) {
        //         cout << val;
        //     }
        //     cout << endl;
        // }
        // cout << endl;
    }
    // for (auto row : ans) {
    //     for (auto val : row) {
    //         cout << val;
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    


    bool ok = true;
    string ans_s = "";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] == '?') {
                ok = false;
            } else {
                ans_s += ans[i][j];
            }
        }
    }

    if (ok) {
        cout << ans_s << endl;
    } else {
        cout << "invalid grille" << endl;
    }
}