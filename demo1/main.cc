#include "sort1.hh"
#include "sort2.hh"
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void solve() {
    int n;
    cin >> n;
    vector<int64_t> arr1(n);
    for (auto & x : arr1)
      cin >> x;
    auto arr2 = arr1;
    sort1(arr1.begin(), arr1.end());
    sort2(arr2.begin(), arr2.end());
    for (auto x : arr1)
      cout << x << " ";
    cout << endl;
    for (auto x : arr2)
      cout << x << " ";
    cout << endl;
  }
};
Solution s;
signed main () {
  ios_base::sync_with_stdio(false);
  s.solve();  
}