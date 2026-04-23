#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

struct Car{
    string name;
    int price;
    int pickupCost;
    int mileCost;
};

struct Person{
    int total;
    bool isConsistent;
    bool isPickedUp;
    string currentCar;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; int m;
        cin >> n >> m;
        map<string,Car> cars;

        for(int i = 0; i < n; i++){
            string name;
            int price;
            int pickupCost;
            int mileCost;
            cin >> name >> price >> pickupCost >> mileCost;
            cars[name] = {name,price,pickupCost,mileCost};
        }

        map<string,Person> people; //{name, amountPaid}

        
        for(int i = 0; i < m; i++){
            int time;
            string name;
            char action;
            cin >> time >> name >> action;
            if(people.find(name) == people.end()){
                //init
                people[name] = {0,true,false,""};
            }
            if(action == 'p'){
                string car;
                cin >> car;
                if(!people[name].isPickedUp){
                    people[name].total += cars[car].pickupCost;
                    people[name].isPickedUp = true;
                    people[name].currentCar = car;
                }else{
                    people[name].isConsistent = true;
                }
            }else if(action == 'r'){
                int distanceTraveled;
                cin >> distanceTraveled;
                if(people[name].isPickedUp && people[name].currentCar != ""){
                    people[name].isPickedUp = false;
                    people[name].total += distanceTraveled*(cars[people[name].currentCar].mileCost);
                    people[name].currentCar = "";
                }else{
                    people[name].isConsistent = false;
                }
            }else{
                int percent;
                cin >> percent;
                if(people[name].currentCar != ""){
                    people[name].total += ceil((1/percent) * cars[people[name].currentCar].price);
                }else{
                    people[name].isConsistent = false;
                }
            }
        }
    }
}
// 1
// 2 8
// bmw 5000 150 10
// jaguar 7000 200 25
// 10 mallory p bmw
// 15 jb p jaguar
// 20 jb r 500
// 35 badluckbrian a 100
// 50 mallory a 10
// 55 silva p jaguar
// 60 mallory r 100
// 110 silva a 30
