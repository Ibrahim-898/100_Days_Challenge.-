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
    int n,k;
    cin >> n >> k; 
     vector<vector<int>> v;
     for(int i=0;i<n;i++){
        int a,b,c;
        cin >> a>> b >> c;
        v.push_back({a,b,c});
       
     }
      sort(v.begin(),v.end());
      int sum=k,i=0,pos=-1;
      for(int i=0;i<n;i++){
        if(sum>=v[i][0] && sum<=v[i][1]){
            if(v[i][2]>=sum) pos = i;
            sum = max(v[i][2],sum);
        }
      }
      cout << sum << endl;

    
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