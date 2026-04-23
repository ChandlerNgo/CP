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
    
    double sumDistance = 0;
    vector<tuple<double,int,int>> tarDistances;
    vector<tuple<double,int,int>> featherDistances;
    vector<bool> tarVisited(m,false);
    vector<bool> featherVisited(p,false);
    vector<bool> tarJudges(n,false);
    vector<bool> featherJudges(n,false);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tarDistances.push_back({distance(judges[i].first,judges[i].second,tars[j].first,tars[j].second), i, j});
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            featherDistances.push_back({distance(judges[i].first,judges[i].second,feathers[j].first,feathers[j].second), i, j});
        }
    }

    sort(tarDistances.begin(),tarDistances.end());
    sort(featherDistances.begin(),featherDistances.end());

    for(int i = 0; i < tarDistances.size(); i++){
        if(tarJudges[get<1>(tarDistances[i])] || tarVisited[get<2>(tarDistances[i])]){
            continue;
        }

        tarJudges[get<1>(tarDistances[i])] = true;
        tarVisited[get<2>(tarDistances[i])] = true;

        sumDistance += get<0>(tarDistances[i]);
        // cout << i << ": " << get<0>(tarDistances[i]) << endl;
    }

    for(int i = 0; i < featherDistances.size(); i++){
        if(featherJudges[get<1>(featherDistances[i])] || featherVisited[get<2>(featherDistances[i])]){
            continue;
        }

        featherJudges[get<1>(featherDistances[i])] = true;
        featherVisited[get<2>(featherDistances[i])] = true;

        sumDistance += get<0>(featherDistances[i]);
    }

    cout << fixed << setprecision(8) << sumDistance << endl;
}