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
    ll a,b,x,y,cnt=0;
    cin >>a>>b >> x >> y;
    if(a==b){
        cout << 0 << endl;
        return;
    }
    if(a>b){
        if((a&1)&& a-b==1){
            cout << y << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    if(x<=y){
        cout << (b-a)*x << endl;
        return;
    }
   while(a!=b){
    if(a%2==0){
        cnt+=y;
        a^=1;
    }
    else {
        a++;
        cnt+=x;
    }
   }
   cout << cnt << endl;
    
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