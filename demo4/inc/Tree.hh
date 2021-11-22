#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Tree {
public:
  class Node {
  public:
    Node* fa, * son[2];
    T val;
    size_t siz;
    Node(const T& _val = T(), const size_t& _siz = 1, Node* father = nullptr, Node* ls = nullptr, Node* rs = nullptr)
      : val(_val), siz(_siz) {
      fa = father;
      son[0] = ls, son[1] = rs;
    }
  };
  Node* root = nullptr;
  Tree() : root(nullptr) {}
  Tree(const Tree& op) = delete;
  Tree(Tree&& op) {
    root = op.root;
    op.root = nullptr;
  }
  ~Tree() { clear(); }
  void clear() { __clear(root), root = nullptr; }
  void __clear(Node* proot = nullptr) {
    if (proot == nullptr) return;
    for (int i = 0; i < 2; ++i)
      __clear(proot->son[i]), proot->son[i] = nullptr;
    delete proot;
  }
  size_t __size(Node* proot) { return (proot == nullptr ? 0 : proot->siz); }
  size_t size() { return __size(root); }
  template<typename _Ty>
  void toLower(_Ty&& str) {
    for (auto it = str.begin(); it != str.end(); ++it)
      if (*it >= 'A' && *it <= 'Z') *it += 32;
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
  template<typename Iterator>
  void build(Iterator first, Iterator last) {
    if (last - first == 0 || toLower(*first) == "null") return;
    root = new Node(atoi(*first));
    queue<Node*> q;
    q.push(root);
    auto delNode = [](Node* nod) {
      auto father = nod->fa;
      bool whichSon = (father->son[1] == nod);
      delete father->son[whichSon];
      father->son[whichSon] = nullptr;
    };
    for (auto it = first; it != last; ++it) {
      auto nod = q.front(); q.pop();
      if (toLower(*it) == "null") {
        delNode(nod);
        continue;
      }
      nod->val = atoi(*it);
      for (int i = 0; i < 2; ++i) {
        nod->son[i] = new Node();
        nod->son[i]->fa = nod;
        q.push(nod->son[i]);
      }
    }
    while (!q.empty()) {
      auto nod = q.front(); q.pop();
      delNode(nod);
    }
    setSize(root);
  }
  void setSize(Node* proot) {
    if (proot == nullptr) return;
    setSize(proot->son[0]);
    setSize(proot->son[1]);
    proot->siz = 1 + __size(proot->son[0]) + __size(proot->son[1]);
  }
  void dumpToStr(string& str, Node* proot) {
    if (proot == nullptr) return;

  }

};
