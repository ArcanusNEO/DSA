#include <bits/stdc++.h>
#include "Tree.hh"
using namespace std;

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
  string s;
  char ch;
  while (~(ch = cin.get()))
    if (ch == '[') break;
  while (~(ch = cin.peek()) && ch != ']') {
    while (~ch && (ch == ',' || ch == ' '))
      cin.get(), ch = cin.peek();
    int x;
    if (ch >= '0' && ch <= '9' || ch == '-') cin >> x;
  }
}
