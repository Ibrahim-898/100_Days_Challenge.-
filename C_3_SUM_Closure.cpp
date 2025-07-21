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
    ll n,pos=0,neg=0,zero=0;
    cin >> n;
    vector<ll> v(n);
    map<ll,ll> mp;
    for(int i=0;i<n;i++){
        cin >> v[i];
        mp[v[i]]++;
        if(v[i]>0) pos++;
        else if(v[i]<0) neg++;
        else zero++;
    }
    if(pos>2 || neg>2){
        cout << "NO" << endl;
        return;
    }
    if((pos==2 || neg==2) && zero>0 ){
        cout << "NO" << endl;
        return;
    }
    if(mp[0]>2){
        v.clear();
        v.push_back(0);
        v.push_back(0);
        for(auto u:mp){
            if(u.first!=0){
                for(int i=0;i<u.second;i++) v.push_back(u.first);
            }
        }
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            for(int k=j+1;k<v.size();k++){
                ll sum = v[i]+v[j]+v[k];
                if(mp[sum]==0){
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    }
    cout << "YES" << endl;
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