#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator *
(const std::basic_string<Char, Traits, Allocator> s, size_t n)
{
   std::basic_string<Char, Traits, Allocator> tmp = s;
   for (size_t i = 0; i < n; ++i)
   {
      tmp += s;
   }
   return tmp;
}

template<typename Char, typename Traits, typename Allocator>
std::basic_string<Char, Traits, Allocator> operator *
(size_t n, const std::basic_string<Char, Traits, Allocator>& s)
{
   return s * n;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int a;
        int b;
        cin >> a >> b;
        string first = "";
        
        for(int i = 0; i < min(a,b); i++){
            first += "01";
        }
        string second = "";
        if(a > b){
            second = string(max(a,b)-min(a,b),'0');
        }else{
            second = string(max(a,b)-min(a,b),'1');
        }
        cout << first << second << endl;
    }


}