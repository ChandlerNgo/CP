#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> setSize;
        vector<int> setSum;

    public:
        DisjointSet(int N) : parent(N), setSize(N), setSum(N) {
            for (int i = 0; i < N; ++i) {
                parent[i] = i;
                setSize[i] = 1;
                setSum[i] = 0;
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
                setSum[a] += setSum[b];
            }
        }

        int getSetSize(int a) {
            return setSize[find(a)];
        }

        int getSetSum(int a){
            return setSum[find(a)];
        }

        void update(int index, int val){
            setSum[index] = val;
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    cin >> n >> m;
    DisjointSet uf(n);


    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        uf.update(i,num);
    }

    for(int i = 0; i < m; i++){
        int a; int b; cin >> a >> b;
        uf.merge(a,b);
    }

    bool notEven = false;
    for(int i = 0; i < n; i++){
        if(uf.getSetSum(i) != 0){
            notEven = true;
            break;
        }
    }
    if(notEven){
        cout << "IMPOSSIBLE" << endl;
    }else{
        cout << "POSSIBLE" << endl;
    }
}
