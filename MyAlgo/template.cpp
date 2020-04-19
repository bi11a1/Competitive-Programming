#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define mem(a,b) memset(a, b, sizeof(a))
#define F first
#define S second
#define sqr(a) ((a)*(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define all(v) v.begin(), v.end()

#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d %d", &a, &b)
#define siii(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sl(a) scanf("%lld", &a)
#define sll(a, b) scanf("%lld %lld", &a, &b)
#define slll(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)
#define sd(a) scanf("%lf", &a)
#define sc(a) scanf("%c", &a)

int dx[]={1, -1, 0, 0}, dy[]={0, 0, 1, -1};
int dxx[]={0, 0, 1, -1, -1, 1, -1, 1}, dyy[]={-1, 1, 0, 0, 1, 1, -1, -1};

typedef long long ll;
typedef unsigned long long ull;
typedef pair< int,int > pii;
typedef pair< ll,ll > pll;
typedef vector< int > vi;
typedef vector< ll > vl;

const double PI=acos(-1);
const double eps=1e-9;

bool chkBit(ll n, ll i){ return (n&(1LL<<i)); }
ll setBit(ll n, ll i){ return (n|(1LL<<i)); }
ll resetBit(ll n, ll i){ return (n&(~(1LL<<i))); }

#ifdef bi11a1

template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
	return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
	os << "{";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << *it;
	}
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin()) os << ", ";
		os << *it;
	}
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
	os << "[";
	for(auto it = v.begin(); it != v.end(); ++it) {
		if( it != v.begin() ) os << ", ";
		os << it -> first << " = " << it -> second ;
	}
    return os << "]";
}

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)

clock_t tStart = clock();
#define timeStamp dbg("Execution Time: ", (double)(clock() - tStart)/CLOCKS_PER_SEC)

void faltu () { cerr << endl; }

template <typename T>
void faltu( T a[], int n) {
     cerr << "{";
	for(int i = 0; i < n; ++i) {
          cerr << a[i];
          if(i!=n-1) cerr << ' ';
	}
	cerr << "}" << endl;
}

template <typename T, typename ... hello>
void faltu( T arg, const hello &... rest) { cerr << arg << ' '; faltu(rest...); }

#else
#define dbg(args...)
#endif


int main(){
     int i, j, k;


}
