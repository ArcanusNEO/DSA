#pragma once
#include <iostream>
using std::string;
template<typename _Ty>
_Ty toLower(_Ty&& str) {
  for (auto it = str.begin(); it != str.end(); ++it)
    if (*it >= 'A' && *it <= 'Z') *it += 32;
  return str;
}
int64_t atoi(const string& str) {
  int64_t ans = 0;
  bool sign = false;
  auto it = str.begin();
  if (*it == '-') sign = true, ++it;
  for (; it != str.end(); ++it) {
    if (!(*it >= '0' && *it <= '9')) break;
    ans = ans * 10 + (*it - 48);
  }
  return (sign ? -ans : ans);
}
template<typename _Ty>
string itoa(_Ty x) {
  if (x == 0) return "0";
  string ret;
  bool sign = (x < 0);
  while (x) {
    ret = (char) (x % 10 + '0') + ret;
    x /= 10;
  }
  if (sign) ret = "-" + ret;
  return ret;
}