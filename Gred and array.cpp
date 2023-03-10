#include <bits/stdc++.h>
using namespace std;

#define FAST ios::sync_with_stdio(0), cin.tie(0),cout.tie(0)
#define yes cout<<"Yes"<<endl;
#define no cout<<"No"<<endl;
#define endl '\n'
#define ll long long
#define pb push_back
#define SORT(v) sort(v.begin(),v.end());

string lower(string s){
    string str="";
    for(long long i=0;i<s.size();i++){
        str+=tolower(s[i]);
    }
    return str;
}

int isSubstr(string s1, string s2){
    if (s1.find(s2) != string::npos){
        return s1.find(s2);
    }
    return -1;
}
ll v[1000005];
ll occ[1000005];
ll cum[1000005];

void solve(){
        ll n,m,k;
        cin>>n>>m>>k;

        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        vector<pair<ll,ll>>vect(1000005);
        vector<ll>val(1000005);

        for(long long i=1;i<=m;i++){
            long long l,r,d;
            cin>>l>>r>>d;
            vect[i]=make_pair(l,r);
            val[i]=d;
        }

        for(ll i=1;i<=k;i++){
            long long x,y;
            cin>>x>>y;
            occ[x]++;
            occ[y+1]--;
        }
        
        for (ll i=1;i<=k;i++){
            occ[i]+=occ[i-1];
        }
        
        for(ll i=1;i<=m;i++){
            val[i]= occ[i]*val[i];
        }
        
        for (ll i=1;i<=m;i++){
            ll a = vect[i].first;
            ll b = vect[i].second;

            cum[a]+=(val[i]);
            cum[b+1]-=(val[i]);
        }
        
        for(ll i=1;i<=n;i++){
            cum[i]+=cum[i-1];
        }

        for(ll i=1;i<=n;i++){
            cout<<cum[i]+v[i]<<" ";
        }
       
}

int main(){
    FAST;
    solve();
   return 0;
}
