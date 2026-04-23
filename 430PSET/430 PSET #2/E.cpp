#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> heights;
    stack<int> indexes;
    ll length = 0;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        heights.push_back(num);
        if(indexes.empty()){
            indexes.push(i);
        }else{
            if(heights[indexes.top()] > num){
                indexes.push(i);
            }else if(!indexes.empty() && heights[indexes.top()] == num){
                length += (i-indexes.top()-1);
                indexes.pop();
                indexes.push(i);
            }else{
                while(!indexes.empty() && heights[indexes.top()] < num){
                    indexes.pop();
                }
                if(!indexes.empty() && heights[indexes.top()] == num){
                    length += (i-indexes.top()-1);
                    indexes.pop();
                    indexes.push(i);
                }else{
                    indexes.push(i);
                }
            }
        }
    }
    
    cout << length << endl;
}
