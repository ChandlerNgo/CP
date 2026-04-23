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
    cin >> n;
    DisjointSet unionSet(n+1);
    vector<pair<int, int>> redundantRoads;
    set<int> leaders;

    for(int i = 1; i < n; i++){
        int a;
        int b;
        cin >> a >> b;
        if(unionSet.find(a) == unionSet.find(b)){
            redundantRoads.emplace_back(a,b);
        }
        unionSet.merge(a,b);
    }

    for (int i = 1; i <= n; i++) {
        leaders.insert(unionSet.find(i));
    }
    
    cout << (leaders.size() - 1) << endl;

    if(leaders.size() != 1){
        int index = 0;
        for(auto i = leaders.begin(); i != leaders.end(); i++){
            auto j = i++;
            if(j == leaders.end()){
                break;
            }
            cout << redundantRoads[index].first << " " << redundantRoads[index].second << " " << *i << " " << *j << endl;
            index += 1;
        }
    }
}