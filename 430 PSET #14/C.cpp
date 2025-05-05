#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Point{
    int x;
    int y;
    bool operator<(const Point& p) const{
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator==(const Point& p) const{
        return x == p.x && y == p.y;
    }
};

Point toVector(Point a, Point b){
    Point cur = {b.x - a.x, b.y - a.y};
    return cur;
}

double dot(Point a, Point b){
    return a.x * b.x + (double)a.y * (double)b.y;
}

double normal_square(Point v){
    return v.x*v.x + v.y*v.y;
}

double angle(Point a, Point o, Point b){
    Point oa = toVector(o, a);
    Point ob = toVector(o, b);
    return acos(dot(oa,ob) / sqrt(normal_square(oa) * normal_square(ob)));
}

void cutting(vector<Point>& points){
    while(points.size() > 3){
        vector<double> angles;

        double minAngle = 100;
        int minIndex = -1;

        for(int i = 0; i < points.size(); i++){
            int a = (i - 1 + points.size()) % points.size();
            int b = (i + 1) % points.size();
            angles.push_back(angle(points[a], points[i], points[b]));
            if(angles[i] < minAngle){
                minAngle = angles[i];
                minIndex = i;
            }
        }
        int a = (minIndex - 2 + points.size()) % points.size();
        int b = (minIndex - 1 + points.size()) % points.size();
        int c = (minIndex + 1) % points.size();
        int d = (minIndex + 2) % points.size();


        if(angle(points[a],points[b],points[c]) > minAngle && angle(points[b],points[c],points[d]) > minAngle){
            points.erase(points.begin() + minIndex);
        }else{
            break;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n && n != 0){
        vector<Point> points;
        while(n--){
            int x;
            int y;
            cin >> x >> y;
            points.push_back({x,y});
        }
        cutting(points);
        cout << points.size();
        for(auto x : points){
            cout << " " << x.x << " " << x.y;
        }
        cout << endl;
    }
}