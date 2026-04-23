#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

double findDistance(double x, vector<pair<double,double>>& houses){
    double maxKid = -1;
    double distanceSum = 0;
    for(auto house : houses){
        double distance = sqrt(pow(house.first - x, 2) + pow(house.second, 2));
        distanceSum += distance;
        maxKid = max(maxKid, distance);
    }
    return maxKid;
}

pair<double,double> binary_search(double a, double b, vector<pair<double,double>>& houses){
    while((b-a) > 1e-6){
        double m1 = a + (b - a) / 3;
        double m2 = b - (b - a) / 3;
        double f1 = findDistance(m1, houses);
        double f2 = findDistance(m2, houses);
        if(f1 < f2){
            b = m2;
        }else{
            a = m1;
        }
    }
    return {(a+b)/2, findDistance((a+b)/2,houses)};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n != 0){
        vector<pair<double,double>> houses;
        double minX = 1000000;
        double maxX = -1000000;
        for(int i = 0; i < n; i++){
            pair<double,double> coord;
            cin >> coord.first >> coord.second;
            houses.push_back(coord);
            minX = min(minX, coord.first);
            maxX = max(maxX, coord.first);
        }
        pair<double,double> answer = binary_search(minX,maxX,houses);
        // ! loop through houses and find max distance from (x,0)
        cout << answer.first << " " << answer.second << endl;
        cin >> n;
    }
}