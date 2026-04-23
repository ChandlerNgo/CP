#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

double distance(int x1, int y1, int x2, int y2){
    int xdistance = (x2-x1) * (x2-x1);
    int ydistance = (y2-y1) * (y2-y1);
    return sqrt(xdistance + ydistance);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int m;
    int p;
    cin >> n >> m >> p;
    vector<pair<int,int>> judges;
    vector<pair<int,int>> tars;
    vector<pair<int,int>> feathers;
    vector<bool> tarVisited(m,false);
    vector<bool> featherVisited(p,false);
    vector<bool> tarJudges(n,false);
    vector<bool> featherJudges(n,false);

    for(int i = 0; i < n; i++){
        int x; int y;
        cin >> x >> y;
        judges.push_back({x,y});
    }
    for(int i = 0; i < m; i++){
        int x; int y;
        cin >> x >> y;
        tars.push_back({x,y});
    }
    for(int i = 0; i < p; i++){
        int x; int y;
        cin >> x >> y;
        feathers.push_back({x,y});
    }
    
    priority_queue<tuple<double,int,int>, vector<tuple<double,int,int>>, greater<tuple<double,int,int>>> tarDistances;
    priority_queue<tuple<double,int,int>, vector<tuple<double,int,int>>, greater<tuple<double,int,int>>> featherDistances;

    double sumDistance = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tarDistances.push({distance(judges[i].first,judges[i].second,tars[j].first,tars[j].second), i, j});
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            featherDistances.push({distance(judges[i].first,judges[i].second,feathers[j].first,feathers[j].second), i, j});
        }
    }

    while(!tarDistances.empty()){
        tuple<double,int,int> tar = tarDistances.top();
        tarDistances.pop();
        if(tarVisited[get<2>(tar)] || tarJudges[get<1>(tar)]){
            continue;
        }

        tarVisited[get<2>(tar)] = true;
        tarJudges[get<1>(tar)] = true;

        sumDistance += (get<0>(tar));
    }

    while(!featherDistances.empty()){
        tuple<double,int,int> feather = featherDistances.top();
        featherDistances.pop();
        if(featherVisited[get<2>(feather)] || featherJudges[get<1>(feather)]){
            continue;
        }
        
        featherVisited[get<2>(feather)] = true;
        featherJudges[get<1>(feather)] = true;

        sumDistance += (get<0>(feather));
    }

    cout << fixed << setprecision(8) << sumDistance << endl;
}