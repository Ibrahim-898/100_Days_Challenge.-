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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    if(n==2){
        if(abs(v[1]-v[0])<=1){
            cout << 0 << endl;
        }
        else cout << -1 << endl;
        return;
    }
    for(int i=0;i<n-1;i++){
        if(abs(v[i+1]-v[i])<=1) {
            cout << 0 << endl;
        return;
        }
    }
    for(int i=0;i<n-2;i++){
        int mn = min(v[i+1],v[i+1]),mx = max(v[i+1],v[i+2]);
        int vmn = v[i]-1 ,vmx=v[i]+1;
        if(vmn<mn){
            if(vmx>=mn && vmx-1<=mx){
                cout << 1 << endl;
            }
            else cout << 1 << endl;
           
        }
        else{
            c
        }
    }
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