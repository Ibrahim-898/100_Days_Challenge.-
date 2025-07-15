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
    int n,sum=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        sum+=v[i];
    }
    if(n==1){
        cout << 0 << endl;
        return;
    }
    sort(v.begin(),v.end());
    int s = v[n-1]+v[n-2];
    int i=0,j=n-1,cnt=0,ans=0;
    while(s>0){
        cnt=0;
        i=0;
        j=n-1;
    while(i<j){
        if(v[i]+v[j]==s) {
            i++;
            j--;
            cnt++;
        }
        else if(v[i]+v[j]<s) i++;
        else if(v[i]+v[j]>s) j--;
    }
    ans = max(ans,cnt);
    s--;
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