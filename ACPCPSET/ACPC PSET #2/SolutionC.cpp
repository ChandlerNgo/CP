#include <iostream>
#include <set>

using namespace std;

int main(){
    int points = 10;
    set<double> xPoints;
    set<double> yPoints;
    for(int i = 0; i < points;i++){
        double x;
        double y;
        cin >> x >> y;
        xPoints.insert(x);
        yPoints.insert(y);
    }

    if(xPoints.size() < 7 || yPoints.size() < 7){
        cout << "CASSETTE\n";
    }else{
        cout << "VINYL\n";
    }

    return 0;
}