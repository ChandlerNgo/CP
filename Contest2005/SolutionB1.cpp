#include <iostream>

using namespace std;

int main(){
    long long t;
    cin >> t;
    for(int i = 0; i < t; i++){
        long long n;
        long long m;
        long long q;
        cin >> n >> m >> q;
        long long teacherA;
        long long teacherB;
        cin >> teacherA >> teacherB;
        long long david;
        cin >> david;
        if(teacherA < david && teacherB < david){
            cout << n - teacherB << endl;
        }else if(teacherA < david && teacherB > david){
            cout << (teacherA + teacherB - 2)/2 << endl;
        }else{
            cout << teacherA - 1 << endl;
        }
    }




    return 0;
}