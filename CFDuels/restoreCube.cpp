#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    vector<set<vector<long long>>> cube;
    for(int i = 0; i < 8; i++){
        set<vector<long long>> possibleCoords;
        long long x;
        long long y;
        long long z;
        cin >> x >> y >> z;
        vector<long long> coord = {x,y,z};
        possibleCoords.insert(coord);
        coord = {x,z,y};
        possibleCoords.insert(coord);
        coord = {y,x,z};
        possibleCoords.insert(coord);
        coord = {y,z,x};
        possibleCoords.insert(coord);
        coord = {z,x,y};
        possibleCoords.insert(coord);
        coord = {z,y,x};
        possibleCoords.insert(coord);
    }

    


    return 0;
}