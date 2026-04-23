#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int Ystreak = 0;
    int Nstreak = 0;
    string curStreak = "";
    int curStreakAmount = 0;
    int Ylead = 0;
    int Nlead = 0;
    int Y = 0;
    int N = 0;
    while(n--){
        string s;
        cin >> s;
        if(s == "Yraglac"){
            Y += 1;
        }else{
            N += 1;
        }

        //check lead
        Ylead = max(Ylead,Y-N);
        Nlead = max(Nlead,N-Y);
        // check streak
        if(curStreak == ""){
            curStreak = s;
            curStreakAmount = 1;
        }else if(curStreak == s){
            curStreakAmount += 1;
        }else{
            if(curStreak == "Yraglac"){
                Ystreak = max(Ystreak, curStreakAmount);
            }else{
                Nstreak = max(Nstreak, curStreakAmount);
            }
            curStreak = s;
            curStreakAmount = 1;
        }
    }
    if(curStreak == "Yraglac"){
        Ystreak = max(Ystreak, curStreakAmount);
    }else{
        Nstreak = max(Nstreak, curStreakAmount);
    }
    string Nwin = "";
    if(Ystreak > Nstreak){
        Nwin = "Yraglac";
    }else if(Nstreak > Ystreak){
        Nwin = "Notnomde";
    }else{
        Nwin = "tie";
    }
    string Ywin = "";
    if(Ylead > Nlead){
        Ywin = "Yraglac";
    }else if(Nlead > Ylead){
        Ywin = "Notnomde";
    }else{
        Ywin = "tie";
    }
    if(Nwin == Ywin){
        cout << "Agree" << endl;
    }else{
        cout << "Disagree" << endl;
    }
}