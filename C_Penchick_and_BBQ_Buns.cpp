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
    cin>> n;
    if(n&1 && n<27){
        cout << -1 << endl;
        return;
    }
    if(n%2==0){
        for(int i=1;i<=n/2;i++){
            cout << i << " " << i << " ";
        }
        cout << endl;
        return;
    }
    int x=3;
    cout << 1 << " ";
    for(int i=1;i<=n/2;i++){
        if(i==5 || i==13) cout << 1 << " " << 2 << " ";
        else {
            cout << x << " " << x << " ";
            x++;
        }
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