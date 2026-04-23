#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string, set<string>> graph;
    map<string, int> colors;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        graph[s] = set<string>();
        colors[s] = -1;
    }

    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string one;
        string two;
        cin >> one >> two;
        graph[one].insert(two);
        graph[two].insert(one);
    }

    set<string> visited;

    bool possible = true;
    queue<string> q;

    for(auto x : graph){
        if(colors[x.first] == -1){

            q.push(x.first);
            colors[x.first] = 0;
            while(!q.empty()){
                string word = q.front();
                q.pop();
                visited.insert(word);
                for(auto x : graph[word]){
                    if(visited.find(x) == visited.end()){
                        if(colors[x] == colors[word]){
                            possible = false;
                        }
                        colors[x] = !colors[word];
                        q.push(x);
                    }
                }
            }
        }
    }

    if(possible){
        for(auto x : graph){
            if(colors[x.first]){
                cout << x.first << " ";
            }
        }
        cout << endl;
        bool modified = false;
        for(auto x : graph){
            if(!colors[x.first]){
                modified = true;
                cout << x.first << " ";
            }
        }
        if(modified){
            cout << endl;
        }
        
    }else{
        cout << "impossible";
    }
}