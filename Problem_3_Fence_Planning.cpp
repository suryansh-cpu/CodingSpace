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
vector<vector<int>>loc;
vector<vector<int>>adj;
vector<bool>visited;
int smallest_perimeter=INT_MAX;
int minx=INT_MAX,miny=INT_MAX,maxx=0,maxy=0;
void DFS(int node){
    visited[node] = true;
    if(loc[node][0] > maxx){
        maxx = loc[node][0];
    }
    if(loc[node][0] < minx){
        minx = loc[node][0];
    }
    if(loc[node][1] > maxy){
        maxy = loc[node][1];
    }
    if(loc[node][1] < miny){
        miny = loc[node][1];
    }
    for(int it : adj[node]){
        if(visited[it]) continue;
        DFS(it);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    loc.resize(n+1);
    adj.resize(n+1);
    visited.assign(n+1,false);
    rep(i,n){
        int x,y;
        cin >> x >> y;
        loc[i+1].pb(x);
        loc[i+1].pb(y);
    }
    rep(i,m){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i = 1;i<=n;i++){
        if(visited[i] == true)continue;
        DFS(i);
        int a = 2*((maxx - minx) + (maxy - miny));
        smallest_perimeter = min(smallest_perimeter,a);
        minx=INT_MAX,miny=INT_MAX,maxx=0,maxy=0;
    }
    cout << smallest_perimeter;
    return 0;
}