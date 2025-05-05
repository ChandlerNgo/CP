#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

double epsilon = 0.0001;

struct Point{
    double x;
    double y;
};

struct Line{
    Point first;
    Point second;
};

Point intersection(Line line1, Line line2){
    double dy1 = line1.second.y - line1.first.y;
    double dx1 = line1.first.x - line1.second.x;
    double res1 = dy1*(line1.first.x) + dx1*(line1.first.y);

    double dy2 = line2.second.y - line2.first.y;
    double dx2 = line2.first.x - line2.second.x;
    double res2 = dy2*(line2.first.x) + dx2*(line2.first.y);

    double det = (dy1*dx2) - (dy2*dx1);

    return {(dx2*res1 - dx1*res2)/det,(dy1*res2 - dy2*res1)/det};
}

bool is_between(double v, double a, double b){
    if(a > b){
        swap(a,b);
    }
    return v >= a && v <= b;
}

bool can_intersect(Line line1, Line line2){
    double dy1 = line1.second.y - line1.first.y;
    double dx1 = line1.first.x - line1.second.x;
    double res1 = dy1*(line1.first.x) + dx1*(line1.first.y);

    double dy2 = line2.second.y - line2.first.y;
    double dx2 = line2.first.x - line2.second.x;
    double res2 = dy2*(line2.first.x) + dx2*(line2.first.y);

    double det = (dy1*dx2) - (dy2*dx1);

    double x = (dx2*res1 - dx1*res2)/det;
    double y = (dy1*res2 - dy2*res1)/det;

    if(!is_between(x, line1.first.x, line1.second.x) || !is_between(x, line2.first.x, line2.second.x) || !is_between(y, line1.first.y, line1.second.y) || !is_between(y, line2.first.y, line2.second.y)){
        return false;
    }

    return abs(det) > epsilon;
}

bool different(Point one, Point two){
    return (abs(one.x - two.x) > epsilon) || (abs(one.y - two.y) > epsilon);
}

bool forms_triangle(Line line1, Line line2, Line line3){
    
    if(!can_intersect(line1,line2) || !can_intersect(line1,line3) || !can_intersect(line2,line3)){
        return false;
    }
    Point p1 = intersection(line1,line2);
    Point p2 = intersection(line2,line3);
    Point p3 = intersection(line1,line3);

    return different(p1,p2) && different(p2,p3) && different(p1,p3);
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin >> n && n != 0){
        vector<Line> lines;
        for(int i = 0; i < n; i++){
            double x1;
            double y1;
            double x2;
            double y2;
            cin >> x1 >> y1 >> x2 >> y2;
            lines.push_back({{x1,y1},{x2,y2}});
        }

        int count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    if(forms_triangle(lines[i],lines[j],lines[k])){
                        count += 1;
                    }
                }
            }
        }
        cout << count << "\n";
    }
    cout << flush;
}