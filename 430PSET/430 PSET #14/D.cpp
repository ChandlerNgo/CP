#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Point{
    int x;
    int y;
};

struct Node{
    int index;
    int area;
    bool operator<(const Node& node) const{
        if(area == node.area){
            return index < node.index;
        }
        return area < node.area;
    }
};

int getArea(int index, vector<Point> points, vector<int> leftNeighbor, vector<int> rightNeighbor){
    int leftIndex = leftNeighbor[index];
    int rightIndex = rightNeighbor[index];
    Point leftPoint = points[leftIndex];
    Point curPoint = points[index];
    Point rightPoint = points[rightIndex];

    return abs((leftPoint.x - curPoint.x)*(rightPoint.y - curPoint.y) - (leftPoint.y - curPoint.y)*(rightPoint.x - curPoint.x));
}

void simplifyPolyline(int numPoints, int numSegments, vector<Point> points){
    vector<int> leftNeighbor;
    vector<int> rightNeighbor;
    leftNeighbor.push_back(0);
    rightNeighbor.push_back(0);
    for(int i = 1; i <= numPoints; i++){
        leftNeighbor.push_back(i-1);
        rightNeighbor.push_back(i+1);
    }

    set<Node> nodes;
    vector<int> area;
    area.push_back(0);
    for(int i = 1; i <= numPoints; i++){
        area.push_back(getArea(i, points, leftNeighbor, rightNeighbor));
        nodes.insert({i, area[i]});
    }

    int removePoints = numPoints - numSegments;
    while(removePoints--){
        auto smallestAreaNode = nodes.begin();
        int pointToRemove = smallestAreaNode->index;
        nodes.erase(smallestAreaNode);

        rightNeighbor[leftNeighbor[pointToRemove]] = rightNeighbor[pointToRemove];
        leftNeighbor[rightNeighbor[pointToRemove]] = leftNeighbor[pointToRemove];

        if(leftNeighbor[pointToRemove] != 0){
            int leftPoint = leftNeighbor[pointToRemove];
            nodes.erase(nodes.find({leftPoint, area[leftPoint]}));
            area[leftPoint] = getArea(leftPoint, points, leftNeighbor, rightNeighbor);
            nodes.insert({leftPoint, area[leftPoint]});
        }

        if(rightNeighbor[pointToRemove] != numPoints){
            int rightPoint = rightNeighbor[pointToRemove];
            nodes.erase(nodes.find({rightPoint, area[rightPoint]}));
            area[rightPoint] = getArea(rightPoint, points, leftNeighbor, rightNeighbor);
            nodes.insert({rightPoint, area[rightPoint]});
        }

        cout << pointToRemove << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int p;
    int s;
    cin >> p >> s;
    vector<Point> points;
    for(int i = 0; i <= p; i++){
        int x;
        int y;
        cin >> x >> y;
        points.push_back({x,y});
    }

    simplifyPolyline(p,s,points);
}