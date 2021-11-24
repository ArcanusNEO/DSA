#include <bits/stdc++.h>
#include "Tree.hh"
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  string s;
  char ch;
  vector<string> arr;
  while (~(ch = cin.get()))
    if (ch == '[') break;
  while (~(ch = cin.peek()) && ch != ']') {
    while (~ch && (ch == ',' || ch == ' ' || ch == '\n' || ch == '\r'))
      cin.get(), ch = cin.peek();
    getline(cin, s, ',');
    arr.push_back(s);
  }
  Tree<int> tree;
  tree.build(arr.begin(), arr.end());
  arr.clear();
  while (~ch && !(ch >= '0' && ch <= '9' || ch == '-'))
    cin.get(), ch = cin.peek();
  int p, q;
  cin >> p;
  while (~ch && !(ch >= '0' && ch <= '9' || ch == '-'))
    cin.get(), ch = cin.peek();
  cin >> q;
  auto lca = tree.getLca(p, q);
  cout << lca->val << endl;
  tree.dumpToVecStr(arr, lca);
  for (const auto& str : arr)
    cout << str << endl;

}
