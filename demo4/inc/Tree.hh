#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Tree {
public:
  class Node {
  public:
    Node* fa, * son[2];
    T val;
    Node(const T& _val = T(), Node* father = nullptr, Node* ls = nullptr, Node* rs = nullptr)
      : val(_val) {
      fa = father;
      son[0] = ls, son[1] = rs;
    }
  };
  Node* root = nullptr;
  size_t siz = 0;
  Tree() : root(nullptr), siz(0) {}
  Tree(const Tree& op) = delete;
  Tree(Tree&& op) {
    root = op.root;
    siz = op.siz;
    op.root = nullptr;
    op.siz = 0;
  }
  ~Tree() { clear(); }
  void clear() { __clear(root), root = nullptr; }
  void __clear(Node* proot = nullptr) {
    if (proot == nullptr) return;
    for (int i = 0; i < 2; ++i)
      __clear(proot->son[i]), proot->son[i] = nullptr;
    delete proot;
  }
};
