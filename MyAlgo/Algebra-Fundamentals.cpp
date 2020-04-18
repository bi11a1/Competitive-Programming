#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX=1e5+5;

/// Finding big mod in iterative way.
/// Calculates (base^power)%mod
/// Base and power both cannot be 0
ll bigMod(ll base, ll power, ll mod){
     ll res=1;
     while(power){
          if(power & 1) res=(res*base)%mod;
          base=(base*base)%mod;
          power >>= 1;
     }
     return res;
}

/// Calculates GCD of a and b recursively
int GCD(int a, int b){
     return a?GCD(b%a, a):b;
}

/// Calculates GCD of a and b iteratively
int GCD(int a, int b){
     while(a){
          b%=a;
          swap(a, b);
     }
     return b;
}

/// ax+by=g, Given a and b, finds x and y, also returns  GCD(a, b).
/// a and b both should not be 0
ll extended_gcd(ll a, ll b, ll &x, ll &y){
     if(a==0){
          x=0;
          y=1;
          return b;
     }
     ll x1, y1;
     ll g=extended_gcd(b%a, a, x1, y1);
     x=y1-(b/a)*x1;
     y=x1;
     return g;
}

/// Checks if there is any solution in ax+by=c, where x, y>=0
ll find_any_solution(ll a, ll b, ll c){
     ll x, y;
     ll g=extended_gcd(a, b, x, y);
     if(c%g) return 0;
     x*=c/g;
     y*=c/g;
     double lft=double(y*g)/a, rht=double(-x*g)/b;
     ll l=floor(lft), r=ceil(rht);
     return r<=l;
}

/// Counts all solution of the equation ax+by=c given a, b, c
/// The range of the solution is x1<=x<=x2 and y1<=y<=y2
/// We can get the value of x and y by iterating through the range
/// Handles a=0, b=0 cases too
ll all_solution(ll a, ll b, ll c, ll x1, ll x2, ll y1, ll y2){
     if(a==0 && b==0) return c?0:(x2-x1+1)*(y2-y1+1);

     ll i, j, k;
     ll x, y, g=extended_gcd(abs(a), abs(b), x, y);
     if(c%g) return 0;

     if(a==0) return (y1<=c/b && c/b<=y2)?x2-x1+1:0;
     if(b==0) return (x1<=c/a && c/a<=x2)?y2-y1+1:0;

     x*=c/g;
     y*=c/g;
     if(a<0) x*=-1;
     if(b<0) y*=-1;

     double lft, rht;
     lft=double(x1-x)*g/double(b), rht=double(x2-x)*g/double(b);
     if(b<0) swap(lft, rht);
     ll lft1=ceil(lft), rht1=floor(rht);

     lft=double(y-y2)*g/double(a), rht=double(y-y1)*g/double(a);
     if(a<0) swap(lft, rht);
     ll lft2=ceil(lft), rht2=floor(rht);

     return max(0LL, min(rht1, rht2)-max(lft1, lft2)+1);
}

int main(){


}
