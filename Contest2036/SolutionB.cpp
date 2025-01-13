#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int l = 0; l < t; l++){
        map<int,int> shelf;
        int n; // shelves
        int k; // bottles
        cin >> n >> k;
        for(int i = 0; i < k; i++){
            int b; // brand
            int c; // cost
            cin >> b >> c;
            if(shelf.find(b) == shelf.end()){
                shelf[b] = c;
            }else{
                shelf[b] += c;
            }
        }

        priority_queue<int> shelves;
        for(auto i = shelf.begin(); i != shelf.end(); i++){
            shelves.push(i->second);
        }
        int total = 0;
        while(!shelves.empty() && n != 0){
            total += shelves.top();
            shelves.pop();
            n -= 1;
        }
        cout << total << endl;
    }
}