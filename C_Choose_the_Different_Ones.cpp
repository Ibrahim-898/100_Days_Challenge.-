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
    int n,m,k;
    cin >> n >> m >> k;
    map<int,int> a,b;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x<=k) a[x]++;

    }
     for(int i=0;i<m;i++){
        int x;
        cin >> x;
         if(x<=k) b[x]++;
    }
   
    int common=0,cnt1=0,cnt2=0;
    for(int i=1;i<=k;i++){
        if(a[i]>0 && b[i]==0){
           if(cnt1<k/2)cnt1++;

        }
        else if(b[i]>0 && a[i]==0){
             if(cnt2<k/2) cnt2++;
        }
    }
     int i=1,j=1;
   
        while(i<=k && cnt1<k/2 ){
            if(a[i]>0 && b[i]>0){
            cnt1++;
            a[i]=0;
            }
            i++;
            
        }
        while(j<=k && cnt2<k/2 ){
            if(a[j]>0 && b[j]>0){
            cnt2++;
            b[i]=0;
            }
            j++;
            
        }
         if(cnt1==k/2 && cnt2==k/2) {
       cout << "YES" << endl;
       return;
     }
     cout << "NO" << endl;
     
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