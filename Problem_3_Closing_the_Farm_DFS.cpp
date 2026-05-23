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
vector<vector<int>>adj;
vector<int>order_of_closing;
// map<int,bool>is_open;
vector<bool> is_open;
// vector<bool>visited;
int cnt = 0;
void DFS(int node,vector<bool>visited){
    visited[node] = true;
    cnt++;
    for(int it : adj[node]){
        if(!is_open[it] || visited[it]) continue;
        DFS(it,visited);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    // visited.assign(n+1,false);
    is_open.assign(n+1,false);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    rep(i,n){
        int a;
        cin >> a;
        order_of_closing.pb(a);
    }
    vector<bool>answer;
    int sizee = order_of_closing.size();
    for(int i = order_of_closing.size()-1;i>=0;i--){
        is_open[order_of_closing[i]] = true;
        // ++cnt;
        vector<bool>visited(n+1,false);

        // fill(visited.begin(), visited.end(), false);
        cnt = 0;
        DFS(order_of_closing[i],visited);
        if(cnt == (sizee - i)){
            answer.pb(true);
        }
        else{
            answer.pb(false);
        }
        
    }
    for(int i = n-1;i>=0;i--){
        cout << (answer[i] ? "YES" : "NO") << "\n";
    }
    return 0;
}
