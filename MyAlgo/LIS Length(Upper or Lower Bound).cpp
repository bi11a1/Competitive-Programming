//Source: https://codeforces.com/blog/entry/13225?#comment-495271

// For Strictly Increasing LIS
vector<int> v;
for (int i = 0; i < n; i++) {
    auto it = lower_bound(v.begin(), v.end(), a[i]);
    if (it != v.end()) *it = a[i];
    else v.push_back(a[i]);
}
return v.size();

// For non-decreasing LIS
vector<int> v;
for (int i = 0; i < n; i++) {
    auto it = upper_bound(v.begin(), v.end(), a[i]);
    if (it != v.end()) *it = a[i];
    else v.push_back(a[i]);
}
return v.size();
