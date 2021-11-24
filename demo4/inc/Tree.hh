#pragma once
#include <bits/stdc++.h>
#include "utils.hh"
using namespace std;
template<typename T>
class Tree {
public:
  class Node {
  public:
    Node* fa, * son[2];
    T val, maxSub, maxLine;
    size_t siz;
    bool vis : 1, maxLineSon : 1;
    Node* maxSubPtr;
    Node(const T& _val = T(), const size_t& _siz = 1, Node* father = nullptr, Node* ls = nullptr, Node* rs = nullptr)
      : val(_val), siz(_siz), maxSub(_val), vis(false), fa(father), maxSubPtr(nullptr) {
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
  size_t __size(Node* proot) const { return (proot == nullptr ? 0 : proot->siz); }
  size_t size() const { return __size(root); }
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
    resetProperty(root);
  }
  void resetProperty(Node* proot) {
    if (proot == nullptr) return;
    resetProperty(proot->son[0]);
    resetProperty(proot->son[1]);
    proot->siz = 1 + __size(proot->son[0]) + __size(proot->son[1]);
    proot->vis = false;
    if (proot->son[0] == nullptr && proot->son[1] == nullptr) {
      proot->maxSub = proot->maxLine = proot->val;
      proot->maxSub = proot;
    } else if (proot->son[0] == nullptr) {
      proot->maxLineSon = 1;
      proot->maxLine = proot->val + proot->son[1]->maxLine;
      T thisTree = proot->maxLine;
      if (proot->son[1]->maxSub < thisTree) {
        proot->maxSubPtr = proot;
        proot->maxSub = thisTree;
      } else {
        proot->maxSubPtr = proot->son[1];
        proot->maxSub = proot->son[1]->maxSub;
      }
    } else if (proot->son[1] == nullptr) {
      proot->maxLineSon = 0;
      proot->maxLine = proot->val + proot->son[0]->maxLine;
      T thisTree = proot->maxLine;
      if (proot->son[0]->maxSub < thisTree) {
        proot->maxSubPtr = proot;
        proot->maxSub = thisTree;
      } else {
        proot->maxSubPtr = proot->son[0];
        proot->maxSub = proot->son[0]->maxSub;
      }
    } else {
      proot->maxLineSon = (proot->son[0]->maxLine < proot->son[1]->maxLine);
      proot->maxLine = proot->val + proot->son[proot->maxLineSon]->maxLine;
      T thisTree = proot->val + proot->son[0]->maxLine + proot->son[1]->maxLine;
      if (proot->son[0]->maxSub < proot->son[1]->maxSub) {
        proot->maxSubPtr = proot->son[1]->maxSubPtr;
        proot->maxSub = proot->son[1]->maxSub;
      } else {
        proot->maxSubPtr = proot->son[0]->maxSubPtr;
        proot->maxSub = proot->son[0]->maxSub;
      }
      if (proot->maxSub < thisTree) {
        proot->maxSubPtr = proot;
        proot->maxSub = thisTree;
      }
    }
  }
  void dumpToVecStr(vector<string>& vs, Node* proot = nullptr) const {
    if (root == nullptr) return;
    if (proot == nullptr) proot = root;
    string buf;
    function<void(string&, Node*)> dfs = [&](Node* proot) {
      if (proot == nullptr) {
        if (!buf.empty()) vs.push_back(buf);
        return;
      }
      size_t orig = buf.size();
      buf += itoa(proot->val);
      dfs(proot->son[0]);
      dfs(proot->son[1]);
      buf.resize(orig);
    };
    dfs(proot);
  }
  Node* __search(const T& x, Node* proot) const {
    if (proot == nullptr) return nullptr;
    Node* ret = __search(x, proot->son[0]);
    if (ret != nullptr) return ret;
    return __search(x, proot->son[1]);
  }
  Node* search(const T& x, Node* proot = nullptr) const {
    if (proot == nullptr) proot = root;
    return __search(x, proot);
  }
  Node* getLca(const T& x, const T& y) const {
    if (root == nullptr) return nullptr;
    resetProperty(root);
    auto px = search(x), py = search(y);
    if (px->val != x || py->val != y) return nullptr;
    Node* lca = nullptr;
    while (true) {
      if (px == nullptr && py == nullptr) break;
      if (px != nullptr) {
        if (px->vis) {
          lca = px;
          break;
        }
        px->vis = true;
        px = px->fa;
      }
      if (py != nullptr) {
        if (py->vis) {
          lca = py;
          break;
        }
        py->vis = true;
        py = py->fa;
      }
    }
    return lca;
  }
};
