#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        int m;
        int x;
        cin >> n >> m >> x;
        // clockwise is +
        // ccw is -
        set<int> visited;
        queue<int> possiblePlaces;
        possiblePlaces.push(x);
        priority_queue<int,vector<int>, greater<int>> sortedVisited;

        queue<int> newPlaces;
        bool first = true;
        for(int i = 0; i < m; i++){
            int distance;
            char direction;
            cin >> distance >> direction;
            while(!possiblePlaces.empty()){
                int spot = possiblePlaces.front();
                possiblePlaces.pop();
                if(!first && visited.find(spot) == visited.end()){
                    visited.insert(spot);
                    sortedVisited.push(spot);
                }
                first = false;
                int pos = (spot+n+distance) % n;
                int neg = (spot+n-distance) % n;
                if(pos == 0){
                    pos = n;
                }
                if(neg == 0){
                    neg = n;
                }
                cout << "test: " << spot << " " << distance << " " << pos << " " << neg << endl;
                if(direction == '0'){
                    newPlaces.push(pos);
                }else if(direction == '1'){
                    newPlaces.push(neg);
                }else{
                    newPlaces.push(pos);
                    newPlaces.push(neg);
                }
            }
            while(!newPlaces.empty()){
                possiblePlaces.push(newPlaces.front());
                newPlaces.pop();
            }
        }

        while(!possiblePlaces.empty()){
            if(visited.find(possiblePlaces.front()) == visited.end()){
                visited.insert(possiblePlaces.front());
                sortedVisited.push(possiblePlaces.front());
            }
            possiblePlaces.pop();
        }
        
        cout << sortedVisited.size() << endl;
        while(!sortedVisited.empty()){
            cout << sortedVisited.top() << " ";
            sortedVisited.pop();
        }
        cout << endl;
    }
}