using namespace std;
#include <iostream>

int main(){
    int t;
    cin >> t;
    while(t--){
        int a;
        int b;
        cin >> a >> b;
        if(b > a){
            swap(a,b);
        }
        
        if((a+b)% 3 == 0 && (2*b) >= a){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}