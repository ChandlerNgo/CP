#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> setSize;

    public:
        DisjointSet(int N) : parent(N), setSize(N) {
            for (int i = 0; i < N; ++i) {
                parent[i] = i;
                setSize[i] = 1;
            }
        }

        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }

        void merge(int a, int b) {
            a = find(a);
            b = find(b);

            if (a != b) {
                parent[b] = a;
                setSize[a] += setSize[b];
            }
        }

        int getSetSize(int a) {
            return setSize[find(a)];
        }
};

set<int> primeFactors(int n, int p) {
    set<int> primes;
    while (n % 2 == 0) {
        if(2 >= p){
            primes.insert(2);
        }
        n = n/2; 
    } 
    for (int i = 3; i*i <= n; i = i + 2) {
        while (n % i == 0) {
            if(i >= p){
                primes.insert(i);
            }
            n = n/i; 
        } 
    } 
    if (n > 2){
        if(n >= p){
            primes.insert(n);
        }
    }
    return primes;
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int l = 1; l <= t; l++){
        int a;
        int b;
        int p;
        cin >> a >> b >> p;
        DisjointSet ds(b+1);
        for(int i = a; i <= b; i++){
            for(int j = i+1; j <= b; j++){
                set<int> set1 = primeFactors(i,p);
                set<int> set2 = primeFactors(j,p);
                set<int> values;
                for(auto x : set1){
                    values.insert(x);
                }
                for(auto x : set2){
                    values.insert(x);
                }
                if(values.size() < (set1.size()+set2.size())){
                    ds.merge(i,j);
                }
            }
        }

        set<int> leaders;
        for(int i = a; i <= b; i++){
            leaders.insert(ds.find(i));
        }
        cout << "Case #" << l << ": " << leaders.size() << endl;
    }
}