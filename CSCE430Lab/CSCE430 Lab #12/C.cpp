#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Point{
    float x;
    float y;
};

struct Edge{
    int from;
    int to;
    float weight;
};

float calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

struct pairCompare {
    bool operator()(const pair<int,float>& a, const pair<int,float>& b) {
        return a.second > b.second;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<Point> points;
    Point start;
    Point end;
    cin >> start.x >> start.y;
    cin >> end.x >> end.y;
    points.push_back(start);
    points.push_back(end);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        float x;
        float y;
        cin >> x >> y;
        points.push_back({x,y});
    }
    map<int, vector<Edge>> adj;
    for(int i = 0; i < points.size(); i++){
        for(int j = 0; j < points.size(); j++){
            if(i == j){
                continue;
            }
            float distance = calculateDistance(points[i],points[j]);
            if(i == 0 || i == 1){
                adj[i].push_back({i,j,distance/5});
            }else{
                if(distance > 50){
                    adj[i].push_back({i,j,2 + ((distance-50)/5)});
                }else{
                    adj[i].push_back({i,j,2 + (50-distance)/5});
                }
            }
        }
    }

    priority_queue<pair<int,float>, vector<pair<int,float>>, pairCompare> pq;
    pq.push({0,0});
    set<int> visited;

    while(!pq.empty()){
        pair<int,float> cur = pq.top();
        pq.pop();
        if(cur.first == 1){
            cout << cur.second << endl;
            break;
        }
        visited.insert(cur.first);
        for(auto x : adj[cur.first]){
            if(visited.find(x.to) == visited.end()){
                pq.push({x.to,cur.second+x.weight});
            }
        }
    }
    
}