#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];       
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];       
        }

        int higher = 0; // step 1 ai > bi
        int lower = 0; // step 2 ai < bi
        for(int i = 0; i < n; i++){
            if(a[i] > b[i]){
                higher += a[i]-b[i];
            }else if(a[i] < b[i]){
                lower += b[i]-a[i];
            }
        }

        cout << higher + 1 << "\n";
    }
}