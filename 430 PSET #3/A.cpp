#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

class AlmostUnionFind{
    private:
        vector<int> parent;
        vector<int> setSize;
        vector<int> setSum;

    public:
        AlmostUnionFind(int N) : parent(N), setSize(N), setSum(N) {
            for(int i = 0; i < N; ++i){
                parent[i] = i;
                setSize[i] = 1;
                setSum[i] = i;
            }
        }

        int find(int i){
            if(parent[i] == i){
                return i;
            }
            return parent[i] = find(parent[i]); // path compression
        }

        void unionSet(int a, int b){
            a = find(a);
            b = find(b);

            if(a != b){
                parent[b] = a;
                setSize[a] += b;
            }
        }

        void moveSet(int a, int b){
            int aLeader = find(a);
            int bLeader = find(b);

            if(aLeader != bLeader){
                parent[a] = b;
                setSize[a] += setSize[b];
                setSum[b] += setSum[a];
            }

            cout << a << " " << b << endl;
        }

        int getSetSum(int a){
            return setSum[find(a)];
        }

        int getSetSize(int a){
            return setSize[find(a)];

        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    cin >> n >> m;
    AlmostUnionFind uf = AlmostUnionFind(n);
    for(int i = 0; i < m; i++){
        int action;
        cin >> action;
        if(action == 1){
            int a;
            int b;
            cin >> a >> b;
            uf.unionSet(a,b);
        }else if(action == 2){
            int a;
            int b;
            cin >> a >> b;
            uf.moveSet(a,b);
        }else{
            int a;
            cin >> a;
            cout << uf.getSetSize(a) << " " << uf.getSetSum(a) << endl;
        }
    }
}