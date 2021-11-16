#include <bits/stdc++.h>
#include "List.hh"
#include "RadixSort.hh"
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  uint32_t x;
  List<uint32_t> ls;
  while (cin >> x)
    ls.pushBack(x);
  List<uint32_t> r[2];
  while (!ls.empty()) {
    x = ls.front(); ls.popFront();
    if (r[0].search(x) == r[0].cend()) r[0].pushBack(x);
  }
  radixSort(r[0].cbegin(), r[0].cend());
  ls = move(r[0]);
  for (const auto& x : ls)
    cout << x << " ";
  cout << endl;
  while (!ls.empty()) {
    x = ls.front(); ls.popFront();
    r[!(x & 1)].pushBack(x);
  }
  for (auto i = 0; i < 2; ++i) {
    for (const auto& x : r[i])
      cout << x << " ";
    cout << endl;
  }
}