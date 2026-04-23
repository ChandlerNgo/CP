#include <bits/stdc++.h>
typedef long long ll;
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
    int m;

    cin >> n >> m;

    int numComponents = n;
    int largestComponent = 1;
    
    DisjointSet disjointSet(n+1);

    for(int i = 0; i < m; i++){
        int a;
        int b;
        cin >> a >> b;
        if(disjointSet.find(a) != disjointSet.find(b)){
            disjointSet.merge(a,b);
            numComponents -= 1;
            largestComponent = max(disjointSet.getSetSize(a),largestComponent);
        }
        cout << numComponents << " " << largestComponent << endl;
    }
}