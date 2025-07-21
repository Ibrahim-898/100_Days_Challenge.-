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
    int n,k,cnt=1;
    cin >> n >> k;
    vector<int> v(n);
    vector<pair<int,int>> pr;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        cin >> v[i];
        pr.push_back({v[i],i});  
    }
    sort(pr.begin(),pr.end());
    for(auto [x,y]: pr){
        mp[x]++;
      if(mp[x]<=k) {
        v[y]=cnt;
        cnt++;
        if(cnt>k) cnt=1;
      }
      else v[y]=0;
       
    }
    while(cnt>1){
       auto indx = pr.back();
       if(v[indx.second]!=0) {
        v[indx.second] = 0;
        cnt--;
       }
       pr.pop_back();
    }
    for(auto u:v){
        cout << u << " ";
    }
    cout << endl;
      
    
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