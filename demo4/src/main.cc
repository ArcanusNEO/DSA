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
  while (true) {
    while (~(ch = cin.peek()) && (ch == ',' || ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t'))
      cin.get();
    getline(cin, s, ',');
    // cout << s << endl;
    auto index = s.find(']');
    if (index != string::npos) {
      s.erase(index);
      arr.push_back(s);
      break;
    }
    arr.push_back(s);
  }
  Tree<int> tree;
  tree.build(arr.begin(), arr.end());
  arr.clear();
  while (~(ch = cin.peek()) && !(ch >= '0' && ch <= '9' || ch == '-'))
    cin.get();
  int p, q;
  cin >> p;
  while (~(ch = cin.peek()) && !(ch >= '0' && ch <= '9' || ch == '-'))
    cin.get();
  cin >> q;
  auto lca = tree.getLca(p, q);
  if (lca == nullptr) exit(1);
  cout << lca->val << endl;
  tree.dumpToVecStr(arr, lca);
  for (const auto& str : arr)
    cout << str << endl;
  deque<int> v;
  tree.dumpMaxSubToDeq(v, lca);
  cout << lca->maxSub << " (";
  cout << v[0];
  for (size_t i = 1; i < v.size(); ++i) {
    if (v[i] < 0) cout << v[i];
    else cout << "+" << v[i];
  }
  cout << ")";
}
