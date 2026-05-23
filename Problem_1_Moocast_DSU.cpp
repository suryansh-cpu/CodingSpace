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
#define sortn(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.begin(),a.end(),greater<int>())
using namespace std;
vector<pair<int,int>>location;
vector<vector<pair<int,int>>>edges;
vector<vector<bool>>visited;
int length = 0;
struct DSU{
    public:
        vector<int>parent,size;
        int n = 0;
        int clusters = 0;
        DSU(int sizee) : parent(sizee),size(sizee){
            n = sizee;
            clusters = sizee;
        }
        int find(int a){
            while(parent[a] != a){
                a = parent[a];
                parent[a] = parent[parent[a]];
            }
            return a;
        }
        void make_set(){
            rep(i,n){
                size[i] = 1;
                parent[i] = i;
            }
        }
        void merge(int a,int b){
            a = find(a); b = find(b);
            if(a != b){
                if(size[a] < size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
                clusters--;
            }
        }
        int solving(){
            rep(i,n){
                for(auto e : edges[i]){
                    if(!visited[i][e.second]){
                        visited[i][e.second] = true;
                        // visited[e.second][i] = true;
                        auto it = std::find(edges[e.second].begin(),edges[e.second].end(),edges[i][e.second]);
                        if(it != edges[e.second].end()){
                            int idx = it - edges[e.second].begin();
                            visited[e.second][idx] = true;
                            merge(e.second,edges[e.second][idx].second);
                        }
                        length = max(length,e.first);
                        break;
                    }
                }
            }
            return length;
        }
};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("closing.in", "r", stdin);
    int n;
    cin >> n;
    DSU dsu(n);
    dsu.make_set();
    location.resize(n);
    edges.resize(n);
    visited.resize(n);
    rep(i,n){
        int a,b;
        cin >> a >> b;
        location[i] = {a,b};
    }
    rep(i,n){
        rep(j,n){
            if(i == j)continue;
            // int a = location[i].first - location[j].first;
            // int b = location[i].second - location[j].second;
            // edges[i].push_back({abs(a)+abs(b),j});
            int dx = location[i].first - location[j].first;
            int dy = location[i].second - location[j].second;
            edges[i].push_back({dx*dx + dy*dy, j});

            visited[i].push_back(false);
        }
        sort(edges[i].begin(),edges[i].end());
    }
    int ans = dsu.solving();
    cout << ans;
    return 0;
    freopen("closing.out", "w", stdout);
}