#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


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
    int t;
    cin >> t;
    
    int recipes = 0;

    DisjointSet uf = DisjointSet(500002);
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        vector<int> ingredients;
        map<int,int> sets;
        //convert sets vector to map<leader,ingredient count>

        //? because itll count map[leader] == setSize == true


        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            ingredients.push_back(num);
            int leader = uf.find(num);
            if(sets.find(leader) == sets.end()){
                sets[leader] = 1;
            }else{
                sets[leader] += 1;
            }
        }

        // some not used some in pot(no extra)
        bool pass = true;
        for(auto curIter: sets){
            // curIter is pair<leader,ingredient count>
            if(uf.getSetSize(curIter.first) != curIter.second){
                pass = false;
                break;
            }
        }

        if(pass){
            recipes += 1;
            for(int j = 0; j < ingredients.size(); j++){
                if(j != 0){
                    uf.merge(ingredients[j],ingredients[j-1]);
                }
            }
        }
    }
    cout << recipes << endl;
}