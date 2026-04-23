#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool canDivide(vector<int> trainCars, int locomotives, int size, int n){
    int index = 1;
    // cout << "locomotives: " << locomotives << " ";
    for(int i = 0; i < trainCars.size(); i++){
        if(trainCars[i] < index){
            continue;
        }
        if(trainCars[i] <= index+size-1){ // can the first train car fit into size
            index = index + size;
            locomotives -= 1;
        }else{ // first train does not fit into size, send one away and take the rest to belgium
            index = trainCars[i] + size;
            locomotives -= 2;
        }
    }
    // cout << "index: " << index << " locomotives after: " << locomotives << " size: " << size << endl;
    if(locomotives > 0 || (locomotives == 0 && index > n)){
        return true;
    }else{
        return false;
    }
}

// 1* 2 3 4* 5 6 7* 8

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; int w; int l;
        cin >> n >> w >> l;
        vector<int> trainCars;
        for(int i = 0; i < w; i++){
            int car;
            cin >> car;
            trainCars.push_back(car);
        }

        int low = 1;
        int high = n;
        int result = -1;

        while(low <= high){
            int mid = (low+high)/2;

            if(canDivide(trainCars,l,mid,n)){
                result = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        
        cout << result << endl;
    }
    
}