#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#define int long long int
#define endl "\n"
#define pb push_back
#define rep(i,n) for(int i=0;i<n;++i)
#define sortn(a) sort(first.begin(),first.end())
#define sortr(a) sort(first.begin(),first.end(),greater<int>())
using namespace std;
struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }

    int size(int x) {
        return sz[find(x)];
    }
};

struct Edge {
    int u, v;
    int r;
};

struct Query {
    int k, v, idx;
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);
    int N, Q;
    cin >> N >> Q;

    vector<Edge> edges(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].r;
    }

    vector<Query> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].k >> queries[i].v;
        queries[i].idx = i;
    }
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.r > b.r;
    });
    sort(queries.begin(), queries.end(), [](const Query &a, const Query &b) {
        return a.k > b.k;
    });
    DSU dsu(N);
    vector<int> answer(Q);
    int e = 0;
    for (auto &q : queries) {
        while (e < N - 1 && edges[e].r >= q.k) {
            dsu.unite(edges[e].u, edges[e].v);
            e++;
        }
        answer[q.idx] = dsu.size(q.v) - 1;
    }
    for (int i = 0; i < Q; i++) {
        cout << answer[i] << "\n";
    }
    return 0;
}