#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int ALPHABET = 26;

struct TrieNode {
    TrieNode* children[ALPHABET] = {};
    bool isEndOfWord = false;

    void insert(const string& word) {
        TrieNode* node = this;
        for (char c : word) {
            int idx = c - 'A';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }
};

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

void dfs(int x, int y, vector<string>& board, vector<vector<bool>>& visited, TrieNode* node, string currentWord, set<string>& foundWords) {
    char c = board[x][y];
    int idx = c - 'A';
    if (!node->children[idx]) return;

    node = node->children[idx];
    currentWord += c;
    if (node->isEndOfWord) {
        foundWords.insert(currentWord);
    }

    visited[x][y] = true;
    for (int d = 0; d < 8; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4 && !visited[nx][ny]) {
            dfs(nx, ny, board, visited, node, currentWord, foundWords);
        }
    }
    visited[x][y] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    TrieNode* root = new TrieNode();

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        root->insert(s);
    }

    vector<int> points = {0, 0, 0, 1, 1, 2, 3, 5, 11};

    int m;
    cin >> m;
    while (m--) {
        vector<string> board(4);
        for (int i = 0; i < 4; i++) {
            cin >> board[i];
        }

        set<string> foundWords;
        vector<vector<bool>> visited(4, vector<bool>(4, false));

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                dfs(i, j, board, visited, root, "", foundWords);
            }
        }

        string maxWord = "";
        int total = 0;

        for (const string& word : foundWords) {
            int len = word.length();
            total += points[len];
            if (len > maxWord.length() || (len == maxWord.length() && word < maxWord)) {
                maxWord = word;
            }
        }

        cout << total << " " << maxWord << " " << foundWords.size() << "\n";
    }

    return 0;
}
