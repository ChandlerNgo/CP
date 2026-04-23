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
    map<string,int> guilds;
    map<int,string> indexToGuild;
    int index = 0;
    DisjointSet df(2*n);
    vector<string> guildName;
    for(int i = 0; i < n; i++){
        string a; string b;
        cin >> a >> b;
        guildName.push_back(a);
        if(guilds.find(a) == guilds.end()){
            guilds[a] = index;
            indexToGuild[index] = a;
            index += 1;
        }
        if(guilds.find(b) == guilds.end()){
            guilds[b] = index;
            indexToGuild[index] = b;
            index += 1;
        }

        df.merge(guilds[b],guilds[a]);

    }
    for(int i = 0; i < n; i++){
        cout << guildName[i] << " " << indexToGuild[df.find(guilds[guildName[i]])] << endl;
    }
}