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
    int n,k,water=1,position;
    cin >> n >>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int present = v[k-1],moment = 0,nxt=0;
    sort(v.begin(),v.end());
    int pos = lower_bound(v.begin(),v.end(),present)-v.begin();
    for(int i=pos;i<n-1;i++){
         nxt = nxt+(v[i+1]-present);
        position = v[i+1];
        water = nxt;
        if(present<nxt){
            cout << "NO" << endl;
            return;
        }
        present = v[i+1];
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