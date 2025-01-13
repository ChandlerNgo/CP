#include <iostream>

using namespace std;

int main(){
    int tests;
    cin >> tests;
    for(int i = 0; i < tests; i++){
        int lectures;
        int practicals;
        int lectureppen;
        int practicalppencil;
        int tools;
        cin >> lectures >> practicals >> lectureppen >> practicalppencil >> tools;
        int x = lectures/lectureppen;
        if(lectures % lectureppen != 0){
            x += 1;
        }
        int y = practicals/practicalppencil;
        if(practicals % practicalppencil != 0){
            y += 1;
        }
        if(x + y <= tools){
            cout << x << " " << y << "\n";
        }else{
            cout << "-1\n";
        }
    }
}