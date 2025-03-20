#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

void dfs(map<string,vector<string>>& graph, string file, set<string>& visited, vector<string>& result){
    if(visited.find(file) != visited.end()){
        return;
    }

    visited.insert(file);
    
    for(auto s : graph[file]){
        dfs(graph,s,visited,result);
    }

    result.push_back(file);
}

vector<string> top_sort(map<string,vector<string>>& graph, string file){
    set<string> visited;
    vector<string> result;

    dfs(graph,file,visited,result);

    reverse(result.begin(), result.end());
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<string,vector<string>> graph;
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string s;
        getline(cin,s);
        stringstream ss(s);
        string file;
        string dep;

        ss >> file;
        file.pop_back();
        
        while(ss >> dep){
            graph[dep].push_back(file);
        }
    }

    // for (auto entry : graph) {
    //     cout << entry.first << ": ";
    //     for (auto dep : entry.second) {
    //         cout << dep << " ";
    //     }
    //     cout << endl;
    // }
    string filename;
    cin >> filename;

    vector<string> answer = top_sort(graph,filename);

    for(auto s : answer){
        cout << s << endl;
    }
}