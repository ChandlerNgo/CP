    #include <bits/stdc++.h>
    typedef long long ll;
    typedef long double ld;
    using namespace std;

    struct Point{
        int x;
        int y;
    };

    double weightFormula(Point one, Point two){
        return (one.x-two.x)*(one.x-two.x) + (one.y-two.y)*(one.y-two.y);
    }

    struct Compare {
        bool operator()(const pair<int, double>& a, const pair<int, double>& b) {
            return a.second > b.second;
        }
    };

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        Point start;
        Point end;
        vector<Point> shadySpots(n+2);
        for(int i = 0; i < n; i++){
            Point point;
            cin >> point.x >> point.y;
            shadySpots[i] = point;
        }
        cin >> start.x >> start.y >> end.x >> end.y;
        shadySpots[n] = start;
        shadySpots[n+1] = end;

        // for(int i = 0; i < n+2; i++){
        //     cout << i << ": " << shadySpots[i].x << " " << shadySpots[i].y << endl;
        // }
        // turn point back into index(int) bc we need to return path
        vector<vector<pair<int,double>>> adj(n+2); // start : <end, weight>
        for(int i = 0; i < n+2; i++){
            for(int j = i+1; j < n+2; j++){
                adj[i].push_back({j,weightFormula(shadySpots[i],shadySpots[j])});
                adj[j].push_back({i,weightFormula(shadySpots[i],shadySpots[j])});
            }
        }

        //pq, distance, previous 

        vector<double> distance(n+2,DBL_MAX);
        vector<int> previous(n+2,-1);

        priority_queue<pair<int, double>, vector<pair<int, double>>, Compare> pq;
        distance[n] = 0;

        pq.push({n,0});

        while(!pq.empty()){
            pair<int,double> cur = pq.top();
            int start_index = cur.first;
            double start_weight = cur.second;
            pq.pop();

            if(start_weight > distance[start_index]){
                continue;
            }

            // cout << start_index << " start " << shadySpots[start_index].x << " " << shadySpots[start_index].y << endl;

            for(auto edge : adj[start_index]){ // edge = pair<int,double>
                int end_index = edge.first;
                double end_weight = edge.second;
                if(distance[start_index] + end_weight < distance[end_index]){
                    distance[end_index] = distance[start_index] + end_weight;
                    previous[end_index] = start_index;
                    pq.push({end_index, distance[end_index]});
                }
            }
        }

        vector<int> path;
        int curNode = n+1;

        while(curNode != -1){
            if(curNode != n && curNode != n+1){
                path.push_back(curNode);
            }
            curNode = previous[curNode];
        }

        reverse(path.begin(), path.end());

        if(path.size() == 0){
            cout << "-" << endl;
        }else{
            for(auto node : path){
                cout << node << endl;
            }
        }
    }