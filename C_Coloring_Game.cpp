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
    ll n,ans=0,mx=0;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        mx = max(mx,v[i]);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n-1;j++){
            ll sum  = v[i]+v[j];
            if(sum>mx){
                ans+=1;
            }
            else{
               ll need = mx-sum+1;
                int indx = lower_bound(v.begin()+j+1,v.end(),need)-v.begin();
                cout <<  indx << endl;
                ans+=(n-indx-1);
            }
           
        }
        cout << endl;
       
    }
    
     cout << " * " <<  ans <<  endl;
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