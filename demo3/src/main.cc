#include <bits/stdc++.h>
#include "List.hh"
using namespace std;
void func(List<int64_t>& ls, int64_t& ans, const function<void(int64_t& x, int64_t y)>& proc, const string head = "(", char sep = '\0', const string rear = ")") {
  int64_t n; cin >> n;
  if (n < 1) return;
  List<int64_t> r;
  while (n--) {
    proc(ans, ls.back());
    r.pushFront(ls.back());
    ls.popBack();
  }
  cout << ans;
  if (sep) {
    cout << head << r.front();
    ls.pushBack(r.front());
    r.popFront();
  }
  while (!r.empty()) {
    if (sep) cout << sep << r.front();
    ls.pushBack(r.front());
    r.popFront();
  }
  if (sep) cout << "=" << ans << rear;
  cout << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  char ch;
  List<int64_t> ls;
  while (cin >> ch) {
    switch (ch) {
    case 'a': {
      int64_t x; cin >> x;
      ls.pushBack(x);
      auto it = ls.begin();
      cout << "[" << *it;
      for (++it; it != ls.end(); ++it)
        cout << "," << *it;
      cout << "]" << endl;
      break;
    }
    case 'b': {
      int64_t ans = 1;
      func(ls, ans, [](int64_t& x, int64_t y) { x *= y; }, " (", '*', ")");
      break;
    }
    case 'c': {
      int64_t ans = INT64_MIN;
      func(ls, ans, [](int64_t& x, int64_t y) { x = max(x, y); });
      break;
    }
    default: break;
    }
  }
}