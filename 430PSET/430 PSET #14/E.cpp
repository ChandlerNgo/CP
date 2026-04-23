#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

double distance(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3){
    double x0 = p1.first;
    double y0 = p1.second;
    double x1 = p2.first;
    double y1 = p2.second;
    double x2 = p3.first;
    double y2 = p3.second;

    double dy = y2 - y1;
    double dx = x2 - x1;
    double a = -dy;
    double b = dx;
    double c = dy * x1 - dx * y1;

    double k = a*a + b*b;
    double d = abs(a * x0 + b * y0 + c) / sqrt(k);

    double max_y = max(y1, y2), min_y = min(y1, y2);
    double max_x = max(x1, x2), min_x = min(x1, x2);

    double px = (b * (b * x0 - a * y0) - a * c) / k;
    double py = (a * (-b * x0 + a * y0) - b * c) / k;

    if (max_y >= py && py >= min_y && max_x >= px && px >= min_x) {
        return d;
    }

    double d1 = sqrt((y1 - y0) * (y1 - y0) + (x1 - x0) * (x1 - x0));
    double d2 = sqrt((y2 - y0) * (y2 - y0) + (x2 - x0) * (x2 - x0));
    return min(d1, d2);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        int m;
        cin >> n;
        vector<pair<int,int>> poly1;
        for(int i = 0; i < n; i++){
            int x;
            int y;
            cin >> x >> y;
            poly1.push_back({x,y});
        }
        cin >> m;
        vector<pair<int,int>> poly2;
        for(int i = 0; i < m; i++){
            int x;
            int y;
            cin >> x >> y;
            poly2.push_back({x,y});
        }

        double minD = DBL_MAX;
        for(int i = 0; i < m; i++){
            for(auto p : poly1){
                pair<int,int> p2 = poly2[i];
                pair<int,int> p3 = poly2[(i - 1 + m) % m];
                double d = distance(p,p2,p3);
                if(d < minD){
                    minD = d;
                }
            }
        }
        cout << fixed << setprecision(10) << minD / 2.0 << endl;
    }
}