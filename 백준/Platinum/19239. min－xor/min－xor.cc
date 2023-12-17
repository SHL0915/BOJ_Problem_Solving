// test code, from https://atcoder.jp/contests/abc308/submissions/43169076

#line 2 "/home/ftiasch/Documents/shoka/io.h"

#line 2 "/home/ftiasch/Documents/shoka/io_base.h"

#line 2 "/home/ftiasch/Documents/shoka/is_specialization_of.h"

#include <type_traits>

template <template <typename...> class Template, typename T>
struct is_specialization_of : std::false_type {};

template <template <typename...> class Template, typename... Args>
struct is_specialization_of<Template, Template<Args...>> : std::true_type {};

template <template <typename...> class Template, typename T>
inline constexpr bool is_specialization_of_v =
    is_specialization_of<Template, T>::value;
#line 4 "/home/ftiasch/Documents/shoka/io_base.h"

#include <tuple>
#include <vector>

#ifndef YES
#define YES "Yes"
#endif
#ifndef NO
#define NO "No"
#endif

template <typename IO> struct IOBaseT {
  template <typename T = int> T read(T &&v = T{}) {
    using DT = std::decay_t<T>;
    if constexpr (is_specialization_of_v<std::tuple, DT>) {
      read_t_(v, std::make_index_sequence<std::tuple_size_v<DT>>());
    } else if constexpr (is_specialization_of_v<std::vector, DT>) {
      for (auto &e : v) {
        read(e);
      }
    } else {
      static_cast<IO *>(this)->template read1(std::forward<T>(v));
    }
    return v;
  }

  template <typename T> IOBaseT &operator<<(const T &o) {
    if constexpr (std::is_same_v<bool, T>) {
      return static_cast<IO *>(this)->write1(o ? YES : NO), *this;
    } else if constexpr (is_specialization_of_v<std::vector, T>) {
      bool first = true;
      for (auto &&e : o) {
        if (first) {
          first = false;
        } else {
          static_cast<IO *>(this)->template write1(' ');
        }
        static_cast<IO *>(this)->template write1(e);
      }
      return *this;
    } else {
      return static_cast<IO *>(this)->template write1(o), *this;
    }
  }

  // helper

  template <typename T = int> std::vector<T> read_v(int n) {
    return read(std::vector<T>(n));
  }

  template <typename... Ts> std::tuple<Ts...> read_t() {
    return read(std::tuple<Ts...>{});
  }

private:
  template <typename Tuple, std::size_t... Index>
  void read_t_(Tuple &t, std::index_sequence<Index...>) {
    (..., (std::get<Index>(t) = read(std::tuple_element_t<Index, Tuple>{})));
  }
};
#line 4 "/home/ftiasch/Documents/shoka/io.h"

#include <iostream>

struct IO : public IOBaseT<IO> {
  friend class IOBaseT<IO>;

  explicit IO(bool sync = false) {
    if (!sync) {
      std::ios::sync_with_stdio(false);
      std::cin.tie(nullptr);
      std::cout.tie(nullptr);
    }
  }

private:
  template <typename T> void read1(T &&v) { std::cin >> v; }
  template <typename T> void write1(T &&v) { std::cout << v; }
};
#line 1 "/home/ftiasch/Documents/shoka/segment_tree.h"
#include <memory>
#line 3 "/home/ftiasch/Documents/shoka/segment_tree.h"

template <typename Node, typename Impl> struct SegmentTreeBase {
  explicit SegmentTreeBase(int n_) : n(n_), nodes(n << 1) {}

  Node &root() { return get_node(0, n - 1); }

  const Node &root() const { return get_node(0, n - 1); }

  template <typename H> H traverse_all(H &&h) {
    traverse_all(std::forward<H>(h), 0, n - 1);
    return h;
  }

  template <typename H> H traverse(H &&h, int a, int b) {
    traverse<H, 0>(std::forward<H>(h), 0, n - 1, a, b);
    return h;
  }

  template <typename H> H reverse_traverse(H &&h, int a, int b) {
    traverse<H, 1>(std::forward<H>(h), 0, n - 1, a, b);
    return h;
  }

  Node &get_node(int l, int r) { return nodes[l + r | (l != r)]; }

protected:
  template <typename Op> void traverse_all(Op &&op, int l, int r) {
    Node &n = get_node(l, r);
    op(l, r, n);
    if (l < r) {
      int m = (l + r) >> 1;
      Node &ln = get_node(l, m);
      Node &rn = get_node(m + 1, r);
      static_cast<Impl *>(this)->propagate(l, m, r, n, ln, rn);
      traverse_all(std::forward<Op>(op), l, m);
      traverse_all(std::forward<Op>(op), m + 1, r);
      static_cast<Impl *>(this)->collect(l, m, r, n, ln, rn);
    }
  }

  template <typename Op, int direction>
  void traverse(Op &&op, int l, int r, int a, int b) {
    if (b < l || r < a) {
      return;
    }
    Node &n = get_node(l, r);
    if (a <= l && r <= b) {
      op(l, r, n);
    } else {
      int m = (l + r) >> 1;
      Node &ln = get_node(l, m);
      Node &rn = get_node(m + 1, r);
      static_cast<Impl *>(this)->propagate(l, m, r, n, ln, rn);
      if (direction) {
        traverse<Op, 1>(std::forward<Op>(op), m + 1, r, a, b);
        traverse<Op, 1>(std::forward<Op>(op), l, m, a, b);
      } else {
        traverse<Op, 0>(std::forward<Op>(op), l, m, a, b);
        traverse<Op, 0>(std::forward<Op>(op), m + 1, r, a, b);
      }
      static_cast<Impl *>(this)->collect(l, m, r, n, ln, rn);
    }
  }

  int n;
  std::vector<Node> nodes;
};
#line 1 "/home/ftiasch/Documents/shoka/snippets/discretization.h"
#include <algorithm>
#line 3 "/home/ftiasch/Documents/shoka/snippets/discretization.h"

template <typename T, typename Compare = std::less<T>>
struct Discretization : public std::vector<T> {
  using std::vector<T>::begin;
  using std::vector<T>::end;

  explicit Discretization() = default;

  explicit Discretization(const std::vector<T> &a_) : std::vector<T>(a_) {
    normalize();
  }

  void normalize() {
    std::sort(begin(), end(), Compare{});
    std::vector<T>::erase(std::unique(begin(), end()), end());
  }

  int index(T x) const {
    return std::lower_bound(begin(), end(), x, Compare{}) - begin();
  }
};
#line 2 "/home/ftiasch/Documents/shoka/snippets/u64.h"

#include <cstdint>

using Long = long long;
using u64 = std::uint64_t;
#line 5 "/tmp/tmp-547185LiSlFfys62cr.cpp"

#include <bits/stdc++.h>

struct Node {
  int count = 0, left = -1, right = -1, minimum = INT_MAX;
};

struct SegmentTree : public SegmentTreeBase<Node, SegmentTree> {
  using SegmentTreeBase<Node, SegmentTree>::SegmentTreeBase;

  static void collect(int l, int m, int r, Node &n, const Node &ln,
                      const Node &rn) {
    n.left = ~ln.left ? ln.left : rn.left;
    n.right = ~rn.right ? rn.right : ln.right;
    n.minimum = std::min(ln.minimum, rn.minimum);
    if (~ln.right && ~rn.left) {
      n.minimum = std::min(n.minimum, ln.right ^ rn.left);
    }
  }

  static void propagate(int l, int m, int r, Node &n, Node &ln, Node &rn) {}
};

template <int d> struct Add {
  void operator()(int l, int r, Node &n) {
    n.count += d;
    n.left = n.right = n.count ? values[l] : -1;
    n.minimum = n.count > 1 ? 0 : INT_MAX;
  }

  Discretization<int> &values;
};

int main() {
  IO io;
  auto Q = io.read();
  std::vector<std::pair<int, int>> ops(Q);
  Discretization<int> values;
  for (int i = 0; i < Q; i++) {
    auto op = io.read();
    int x = -1;
    if (op < 3) {
      x = io.read();
      values.push_back(x);
    }
    ops[i] = {op, x};
  }
  values.normalize();
  int m = values.size();
  SegmentTree sgt{m};
  for (auto &&[op, x] : ops) {
    if (op == 3) {
      io << sgt.root().minimum << "\n";
    } else {
      x = values.index(x);
      if (op == 1) {
        sgt.traverse(Add<1>{values}, x, x);
      } else {
        sgt.traverse(Add<-1>{values}, x, x);
      }
    }
  }
}
