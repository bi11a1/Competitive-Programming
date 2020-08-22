///PBDS SET
///Helpful if element index is required in set
//Copy code starting from here and ends before main function

#include<bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp> //Required for PBDS
#include <ext/pb_ds/tree_policy.hpp> //Required for PBDS
using namespace __gnu_pbds; //Required for PBDS

using namespace std;
typedef long long ll;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//Declaring PBDS Set variable
//type is declared in the tree update 'int' with required type
//All operations are of: O(log n)
ordered_set st;

int main(){
     int i, j, k;

     ///Insert element: st.insert(key)
     //Its a set, so no duplicate value will be inserted
     //Index starts from 0
     st.insert(3);
     st.insert(15);
     st.insert(5);
     st.insert(7);
     st.insert(5);

     //Accessing element using iterator
     for(auto it=st.begin(); it!=st.end(); ++it) cout << *it << " ";  // Output: 3 5 7 15
     cout << endl;

     ///Accessing element at i'th index: st.find_by_order(index)
     //Returns an iterator, so in order to access value we need pointer
     for(i=0; i<st.size(); ++i) cout << *st.find_by_order(i) << " ";  // Output: 3 5 7 15
     cout << endl;

     ///Finding index of some value 'key': st.order_of_key(key)
     ///Returns number of items that are strictly smaller than our value 'key'
     //Similar to lower_bound
     cout << st.order_of_key(5) << endl;     // Output: 1
     cout << st.order_of_key(9) << endl;     // Output: 3

     /// Can also apply lower_bound/lower_bound just like normal set
     //Returns an iterator
     cout << *st.lower_bound(5) << endl; // Output: 5
     cout << *st.upper_bound(5) << endl; // Output: 7

     /// Can use PBDS SET as multiset by using time variable with each value
     /// Element in set is key pair of: {key, time}

}
