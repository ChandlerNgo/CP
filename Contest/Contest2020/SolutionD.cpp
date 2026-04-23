#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;


    for(int i = 0; i < t; i++){
        int n; int m;
        cin >> n >> m;
        vector<vector<int>> points;
        for(int j = 0; j < m; j++){
            int a; int d; int k;
            cin >> a >> d >> k;
            vector<int> currentPoints;
            while(k != -1){
                currentPoints.push_back(a + k*d);
                k -= 1;
            }
            for(int l = 0; l < points.size(); l++){
                vector<int> unionSet(points[l].size() + currentPoints.size());

                sort(points[l].begin(),points[l].end());
                sort(currentPoints.begin(),currentPoints.end());

                auto it = set_union(points[l].begin(), points[l].end(), currentPoints.begin(), currentPoints.end(), unionSet.begin());
                unionSet.resize(it - unionSet.begin());
                if(it - unionSet.begin() != points[l].size() + currentPoints.size()){
                    points.erase(points.begin() + l);
                    currentPoints = unionSet;
                    l--;
                }
            }
            points.push_back(currentPoints);
        }

        int amountOfPoints = 0;
        for(int j = 0; j < points.size(); j++){
            amountOfPoints += points[j].size();
        }
        cout << n-amountOfPoints+points.size() << endl;
    }
}