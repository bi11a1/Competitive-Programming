#include<bits/stdc++.h>
#define MX 1000005
using namespace std;
typedef long long ll;

/*-----------------LIS (length only) Begin------------------*/
// Parameter => Set infinity larger than max array element

int LIS_Length(vector<int> arr, int inf=1e9){
    int i, j, k;
    int sz=arr.size(), ans=0;
    vector<int> length(sz+1, inf);
    for(i=0; i<sz; ++i){
        int low=1, high=sz, mid, pos=0;
        while(high>=low){
            mid=(low+high)/2;
            if(length[mid]<arr[i]){
                pos=mid;
                low=mid+1;
            }
            else high=mid-1;
        }
        pos++;
        ans=max(ans, pos);
        length[pos]=min(length[pos], arr[i]);
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
    printf("%d\n", LIS_Length(vt));
    return 0;
}
