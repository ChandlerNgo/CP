#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    int cars;
    cin >> cars;
    vector<int> enter;
    vector<int> exit;
    set<int> finedCars;
    for(int i = 0; i < cars;i++){
        int car;
        cin >> car;
        enter.push_back(car);
    }
    for(int i = 0; i < cars;i++){
        int car;
        cin >> car;
        exit.push_back(car);
    }

    int enterPoint = 0;
    int exitPoint = 0;
    int fined = 0;

    for(exitPoint = 0; exitPoint < cars; exitPoint++){
        if(exit[exitPoint] != enter[enterPoint] && finedCars.find(enter[enterPoint]) == finedCars.end()){
            fined += 1;
            finedCars.insert(exit[exitPoint]);
        }else{  
            enterPoint += 1;
        }
    }

    cout << fined << "\n";

    return 0;
}