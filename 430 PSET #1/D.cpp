#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

string convertSecondsToTime(int seconds){
    int hours = seconds/(60*60);
    seconds = seconds % (60*60);
    int minutes = seconds/(60);
    seconds = seconds % (60);
    int second = seconds;
    string time = "";
    if(hours < 10){
        time += ("0" + to_string(hours) + ':');
    }else{
        time += (to_string(hours) + ":");
    }
    if(minutes < 10){
        time += ("0" + to_string(minutes) + ':');
    }else{
        time += (to_string(minutes) + ":");
    }
    if(second < 10){
        time += ("0" + to_string(second));
    }else{
        time += (to_string(second));
    }
    return time;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string start;
    string end;
    cin >> start >> end;
    
    stringstream ss(start);
    stringstream ss2(end);
    string s;

    char delimiter = ':';
    vector<int> startTimes;
    vector<int> endTimes;
    while(getline(ss,s,delimiter)){
        startTimes.push_back(stoi(s));
    }
    while(getline(ss2,s,delimiter)){
        endTimes.push_back(stoi(s));
    }

    int startTimeSeconds = startTimes[0]*60*60 + startTimes[1]*60 + startTimes[2];
    int endTimeSeconds = endTimes[0]*60*60 + endTimes[1]*60 + endTimes[2];

    int daySeconds = 24*60*60;
    if(startTimeSeconds > endTimeSeconds){
        cout << convertSecondsToTime(daySeconds-startTimeSeconds+endTimeSeconds) << endl;
    }else if(startTimeSeconds < endTimeSeconds){
        cout << convertSecondsToTime(endTimeSeconds-startTimeSeconds) << endl;
    }else{
        cout << "24:00:00" << endl;
    }
}