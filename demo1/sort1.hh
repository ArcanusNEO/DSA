#include <iostream>
#include <queue>
template<typename Iterator>
inline void sort1(Iterator first, Iterator last, unsigned radix = 10) {
  using namespace std;
  using Ele_t = decltype((*first)++);
  vector<deque<Ele_t>> buf(radix + 1);
  vector<Ele_t> powRadix;
  auto maxEle = *first;
  for (auto it = first; it != last; ++it)
    maxEle = max(maxEle, *it);
    __uint128_t t = 1;
  do {
    powRadix.push_back(t);
  } while ((t *= radix) / radix <= maxEle);
  for (auto i = powRadix.size() - 1; i; --i) {
    for (auto it = first; it != last; ++it)
      buf[((*it) % powRadix[i]) / powRadix[i - 1]].push_back(*it); //hash
    auto it = first;
    for (auto k = 0; k < radix && it != last; ++k) { //write back
      while (!buf[k].empty()) {
        (*it++) = buf[k].front();
        buf[k].pop_front();
      }
    }
  }
}
