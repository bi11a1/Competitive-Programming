#include<bits/stdc++.h>
#define MX 1000005
using namespace std;
typedef long long ll;

/*-----------------LIS (length only) Begin------------------*/
// Parameter => Set infinity larger than max array element
// Parameter => Set max equals to (max array size+5)

const int inf=1e9;
int tree[4*MX];

void update(int node, int b, int e, int pos, int val){
    if(b==e && b==pos){
        if(val==inf) tree[node]=val;
        else if(tree[node]>val) tree[node]=val;
        return;
    }
    if(b>pos || e<pos) return;
    int l=2*node, r=l+1, m=(b+e)/2;
    update(l, b, m, pos, val);
    update(r, m+1, e, pos, val);
    tree[node]=min(tree[l], tree[r]);
}

int query(int node, int b, int e, int val){
    if(b==e){
        if(tree[node]<val) return b;
        return 0;
    }
    int l=2*node, r=l+1, m=(b+e)/2;
    if(tree[r]<val) return query(r, m+1, e, val);
    if(tree[l]<val) return query(l, b, m, val);
    return 0;
}

int longestIncreasingSubsequenceLength(vector<int> arr){
    int i, j, k;
    int sz=arr.size(), ans=0;
    for(i=1; i<=sz; ++i) update(1, 1, sz, i, inf);
    for(i=0; i<sz; ++i){
        k=query(1, 1, sz, arr[i])+1;
        ans=max(ans, k);
        update(1, 1, sz, k, arr[i]);
    }
    return ans;
}

/*-----------------LIS (length only) End------------------*/

int main(){
    vector< int > vt;
    int i, j, k;
    int n;
    scanf("%d", &n);
    for(i=0; i<n; ++i){
        scanf("%d", &k);
        vt.push_back(k);
    }
    printf("%d\n", longestIncreasingSubsequenceLength(vt));
    return 0;
}