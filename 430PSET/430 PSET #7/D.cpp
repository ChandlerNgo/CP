#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

pair<double,double> getDistanceFromTime(vector<pair<int,int>>& upward, vector<pair<int,int>>& downward, double time){
    double upwardDistance = 0;
    double upwardTime = 0;
    // for(auto x : upward){
    //     cout << x.first << " " << x.second << endl;
    // }
    // cout << endl;
    for(int i = 0; i < upward.size()-1; i++){
        if (upward[i+1].second >= time && time >= upward[i].second) {
            double timeInSegment = time - upward[i].second;
            double speed = (double)(upward[i+1].first - upward[i].first) / (upward[i+1].second - upward[i].second);
            upwardDistance = upward[i].first + (speed * timeInSegment);
            break;
        } else {
            upwardTime += upward[i+1].second;
        }
    }
    
    double maxDistance = downward[0].first;
    double downwardDistance = downward[0].first;
    double downwardTime = 0;
    // for(auto x : downward){
    //     cout << x.first << " " << x.second << endl;
    // }
    for(int i = 0; i < downward.size()-1; i++){
        if (downward[i+1].second >= time && time >= downward[i].second) {
            double timeInSegment = time - downward[i].second;
            double speed = (double)(downward[i+1].first - downward[i].first) / (downward[i+1].second - downward[i].second);
            // cout << speed << " " << timeInSegment << endl;
            downwardDistance = downward[i].first + (speed * timeInSegment);
            break;
        } else {
            // cout << downwardDistance << " " << downwardTime<< endl;
            // downwardDistance = downward[i+1].first; // subtracts by 4 instead of the actual distance traveled
            downwardTime += downward[i+1].second;
            // cout << downwardDistance << " " << downwardTime<< endl;
        }
    }

    // cout << "time: " << time << " " << "upwardDistance: " << upwardDistance << " " << "downwardDistance: " << downwardDistance << endl << endl;

    return {upwardDistance,downwardDistance};
}

// 0 10
// 10 1
// 0 11
// 10 1

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,int>> upward; // height, time
    vector<pair<int,int>> downward; // height, time
    int u;
    int d;
    cin >> u >> d;
    int currentHeight = 0;
    upward.push_back({0,0});
    int currentTime = 0;
    for(int i = 0; i < u; i++){
        int h;
        int t;
        cin >> h >> t;
        currentHeight += h;
        currentTime += t;
        upward.push_back({currentHeight,currentTime});
    }
    downward.push_back({currentHeight,0});
    double b = currentTime;
    currentTime = 0;
    for(int i = 0; i < d; i++){
        int h;
        int t;
        cin >> h >> t;
        currentHeight -= h;
        currentTime += t;
        downward.push_back({currentHeight,currentTime});
    }
    
    double a = 0;
    b = fmin(b,currentTime);
    while((b-a) > 1e-6){
        double m = (a+b)/2;
        pair<double,double> f = getDistanceFromTime(upward, downward, m);
        // cout << a << " " << b << " " << f1 << " " << f2 << endl;
        if(f.first >= f.second){
            b = m;
        }else{
            a = m;
        }
    }
    cout << fixed << setprecision(6) << (a+b)/2 << endl;
    // 3 3
    // 4 2
    // 0 3
    // 6 3

    // 6 2
    // 0 3
    // 4 4
}