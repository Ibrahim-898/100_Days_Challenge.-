#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>  using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update >;
#define endl '\n'
#define ll long long
#define ld  long double
#define ios() ios_base:: sync_with_stdio(0);cin.tie(0);
bool cmp(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first!=b.first)
    return (a.first<b.first);
    else
     return (a.second>b.second);
}
class compare {
public:
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};
int fact(int n)
{
    return (n==1) ? 1: n * fact(n - 1); 
    // ? :
}
const int N=100;
void solve() {
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<bitset<31>> bit;
    for(int i=0;i<n;i++){
        bitset<31> b;
        b=v[i];
        bit.push_back(b);
    }
    ll cnt=0,f=0,ans=0;
    for(int i=0;i<31;i++){ 
      for(int j=0;j<n;j++){
      if(bit[j][i]==0) {
        cnt+=(1LL<<i);
        if(cnt<=k){
            ans++;
        }
      }
      else if(bit[j][i]==1){
        ans++;
      }
     }
   }

   for(int i=31;i<=60;i++){
    for(int j=0;j<n;j++){
    cnt+=(1LL<<i);
     if(cnt<=k) {
        ans++;
     }
     else {
        f=1;
        break;
     }
    }
    if(f) break;
   }
   cout << ans << endl;
    
}
int main()
{
    ios();
    int  t = 1;
    cin >> t;
    while(t--){
        solve();

    }
}