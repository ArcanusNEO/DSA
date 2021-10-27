#include <iostream>
#include <functional>
template<typename Iterator>
inline void sort2(Iterator first, Iterator last, unsigned radix = 10) {
  using namespace std;
  using Ele_t = decltype((*first)++);
  function<bool (Ele_t, Ele_t)> comp = [radix](Ele_t x, Ele_t y) -> bool {
    while (x && y) {
      auto xx = x % radix, yy = y % radix;
      if (xx != yy) return xx < yy;
      x /= radix, y /= radix;
    }
    return false;
  };
  int len = last - first, step;
  while (step < len / 3)
    step = 3 * step + 1;
  while (step >= 1) {
    for (auto i = step; i < len; i++)
      for (auto j = i; j >= step && comp(*(first + j), *(first + (j - step))); j -= step)
        swap(*(first + j), *(first + (j - step)));
    step = step / 3;
  }
}
