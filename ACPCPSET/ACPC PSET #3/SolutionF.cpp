#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int q;
    cin >> n >> q;

    vector<vector<int>> trees;
    
    vector<int> temp(n, 0);
    trees.push_back(temp);

    for(int i = 0; i < n; i++){
        string word;
        cin >> word;
        vector<int> currentRow;
        currentRow.push_back(0);
        for(int j = 0; j < n; j++){
            currentRow.push_back(currentRow[j] + trees[i][j+1] - trees[i][j] + (word[j] == '*'));
        }
        trees.push_back(currentRow);
    }

    for(int i = 0; i < q; i++){
        int y1;
        int x1;
        int y2;
        int x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << trees[y2][x2] - trees[y2][x1-1] - trees[y1-1][x2] + trees[y1-1][x1-1] << endl;

        // 0 0 0 0 0
        // 0 0 1 1 1
        // 0 1 2 3 4
        // 0 2 4 5 6
        // 0 3 6 8 10
    }
}