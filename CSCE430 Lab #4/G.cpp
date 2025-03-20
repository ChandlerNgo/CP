#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int start;
    int end;
    int n;
    cin >> start >> end >> n;
    vector<int> walkTime;
    vector<int> busRideTime;
    vector<int> busArriveTime;
    for(int i = 0; i <= n; i++){
        int num;
        cin >> num;
        walkTime.push_back(num);
    }
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        busRideTime.push_back(num);
    }
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        busArriveTime.push_back(num);
    }

    int time = 0;
    int index = 0;
    for(int i = 0; i < n; i++){
        time += walkTime[index];
        // bus needs to arrive
        int timeslot = (time % busRideTime[index]);
        if(timeslot != 0){
            time += (busRideTime[index]-(time % busRideTime[index]));
        }
        // bus rides
        time += busArriveTime[index];
        if(time > end){
            break;
        }
    }
    time += walkTime[n];
    if(time < end){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}