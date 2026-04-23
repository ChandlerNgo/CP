#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

template<typename T>
struct Tree {
    static constexpr T base = 0;
    vector<T> v;
    int n, size;
    string combType;
    T comb(T a, T b) { //change this when doing maximum vs minimum etc.
        if(this->combType == "max"){
            return max(a,b);
        }else{
            return a + b;
        }
    }
    Tree(int n = 0, T def = base, string combType = "sum") {
        this->n = n; //max number of elements
        size = 1;
        this->combType = combType;
        while(size < n) size *= 2;
        v.assign(size * 2, def);
    }
    void update(int pos, T val) { //update 0 indexed, assignment
        assert(pos < n && pos >= 0);
        int curr = pos + size;
        v[curr] = val;
        while(curr != 1) {
            if(curr & 1) { //handles non-communative operations
                v[curr / 2] = comb(v[curr ^ 1], v[curr]);
            } else {
                v[curr / 2] = comb(v[curr], v[curr ^ 1]);
            }
            curr /= 2;
        }
    }
    T at(int idx) {
        assert(idx >= 0 && idx < n);
        return v[idx + size];
    }
    T query(int l, int r) {//queries in range [l,r)
        return _query(1,0,size,l,r);
    }
    T _query(int idx, int currl, int currr, int &targetl, int &targetr) {
        if(currr <= targetl || currl >= targetr) return base;
        if(currl >= targetl && currr <= targetr) return v[idx];
        int mid = (currl + currr) / 2;
        return comb(
            _query(idx * 2, currl, mid, targetl, targetr),
            _query(idx * 2 + 1, mid, currr, targetl, targetr)
        );
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int q;
    scanf("%d", &n);
    while(n != 0){
        vector<pair<int,int>> trackedRain; // {year, amtrain}
        for(int i = 0; i < n; i++){
            int year;
            int amtRain;
            scanf("%d%d",&year,&amtRain);   
            trackedRain.push_back({year,amtRain});
        }
        int totalYears = (trackedRain[n-1].first - trackedRain[0].first)+1;
        Tree<int> rain = Tree<int>(totalYears,0,"max");
        Tree<int> rainPresent = Tree<int>(totalYears,0,"sum");
        int baseYear = trackedRain[0].first;
        int highestYear = trackedRain[n-1].first - baseYear;
        for(int i = 0; i < n; i++){
            rain.update(trackedRain[i].first-baseYear, trackedRain[i].second);
            rainPresent.update(trackedRain[i].first-baseYear, 1);
        }

        scanf("%d", &q);
        for(int i = 0; i < q; i++){
            int year1;
            int year2;
            scanf("%d%d",&year1,&year2);
            year1 -= baseYear;
            year2 -= baseYear;
            // every year is known
            bool isEveryYearKnown = false;
            if(year1 <= highestYear && year2 <= highestYear){
                if(rainPresent.query(year1,year2+1) == year2-year1+1){
                    isEveryYearKnown = true;
                }
            }
            // every year where year1 < year < year2, rain in year < rain in year2
            bool lowerRain = false;
            if(year1+1 <= highestYear && year2 <= highestYear){
                if(rain.query(year1+1,year2) < rain.at(year2)){
                    lowerRain = true;
                }
            }else if(year2 > highestYear){
                if(rain.query(year1+1,highestYear+1) < rain.at(highestYear)){
                    lowerRain = true;
                }
            }

            // rain in year1 >= rain in year2
            bool rainGreater = false;
            if(year2 <= highestYear && rain.at(year1) >= rain.at(year2)){
                rainGreater = rain.at(year1) >= rain.at(year2);
            }else if(year1 <= highestYear){
                if(rain.at(year1) >= rain.at(highestYear)){
                    rainGreater = rain.at(year1) >= rain.at(highestYear);
                }
            }


            if(isEveryYearKnown && lowerRain && rainGreater){
                printf("true\n");
            }else if(!lowerRain || !rainGreater){
                printf("false\n");
            }else{
                printf("maybe\n");
            }
        }

        scanf("%d", &n);
    }
    scanf("%d",&q);
}