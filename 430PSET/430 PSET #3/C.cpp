#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> setSize;

    public:
        DisjointSet(int N) : parent(N), setSize(N) {
            for (int i = 0; i < N; ++i) {
                parent[i] = i;
                setSize[i] = 1;
            }
        }

        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        void merge(int a, int b) {
            a = find(a);
            b = find(b);

            if (a != b) {
                parent[b] = a;
                setSize[a] += setSize[b];
            }
        }

        int getSetSize(int a) {
            return setSize[find(a)];
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    map<string,int> bridges;
    DisjointSet uf = DisjointSet(2*n + 1);
    int uniqueID = 0;

    for(int i = 0; i < n; i++){
        string build1;
        string build2;
        cin >> build1 >> build2;
        if(bridges.find(build1) == bridges.end()){
            bridges[build1] = uniqueID;
            uniqueID += 1;
        }
        if(bridges.find(build2) == bridges.end()){
            bridges[build2] = uniqueID;
            uniqueID += 1;
        }

        uf.merge(bridges[build1],bridges[build2]);
        cout << uf.getSetSize(bridges[build1]) << endl;
    }
}