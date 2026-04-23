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

struct Coord{
    double x;
    double y;
    int index;
    bool operator<(const Coord& other) const {
        return std::tie(x, y) < std::tie(other.x, other.y);
    }
};

struct Distance{
    Coord a;
    Coord b;
    double distance;
};

class Compare {
    public:
        bool operator()(Distance a, Distance b)
        {
            return a.distance > b.distance;
        }
};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int e;
    int p;
    cin >> n >> e >> p;

    vector<Coord> locations;
    DisjointSet uf(n+1);
    double x;
    double y;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        locations.push_back({x,y,i});
    }

    for(int i = 1; i < e; i++){
        uf.merge(i, i-1);
    }

    for(int i = 0; i < p; i++){
        int one;
        int two;
        cin >> one >> two;
        uf.merge(one-1, two-1);
    }

    priority_queue<Distance,vector<Distance>, Compare> pq;

    for(auto location : locations){
        for(auto loc : locations){
            if(loc.x != location.x  || loc.y != location.y){
                pq.push({loc,location,sqrt(pow(loc.x-location.x,2) + pow(loc.y-location.y,2))});
            }
        }
    }
    double cost = 0;

    while(!pq.empty()){
        Distance dis = pq.top();
        pq.pop();
        if(uf.find(dis.a.index) != uf.find(dis.b.index)){
            cost += dis.distance;
            uf.merge(dis.a.index,dis.b.index);
        }
    }

    cout << cost << endl;
}