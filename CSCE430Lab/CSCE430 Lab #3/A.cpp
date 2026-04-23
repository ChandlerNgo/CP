#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // bfs with groceries
    map<string,set<int>> groceries;

    int stores;
    int items;
    cin >> stores >> items;

    for(int i = 0; i < items; i++){
        int store;
        string item;
        cin >> store >> item;
        if(groceries.find(item) == groceries.end()){
            groceries[item] = set<int>();
        }
        groceries[item].insert(store);
    }
    int boughtItems;
    cin >> boughtItems;
    vector<string> groceryList;
    for(int i = 0; i < boughtItems; i++){
        string item;
        cin >> item;
        groceryList.push_back(item);
    }

    queue<int> currentStores;
    queue<set<int>> visited;
    for(int i = 0; i < groceryList.size(); i++){
        for(auto j = groceries[groceryList[i]].begin(); j != groceries[groceryList[i]].end(), j++){
            cout << "hello0";
        }
        while(!visited.empty()){

        }
    }
}