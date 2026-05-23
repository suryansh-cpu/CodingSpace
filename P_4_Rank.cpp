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
vector<vector<int>>adj;
vector<bool>in_stack;
vector<bool>visited;
vector<vector<int>>reverse_adj;
vector<bool>in_stack_reverse;
vector<bool>visited_reverse;
bool is_cycle = false;
void DFS(int node){
    visited[node] = true;
    in_stack[node] = true;
    for(auto it : adj[node]){
        if (!visited[it]){
            DFS(it);    
        }
        
        else if (in_stack[it]) is_cycle = true;
    }
    in_stack[node] = false;
}
void DFSR(int node){
    visited_reverse[node] = true;
    in_stack_reverse[node] = true;
    for(auto it : reverse_adj[node]){
        if (!visited_reverse[it]){
            DFSR(it);    
        }
        
        else if (in_stack_reverse[it]) is_cycle = true;
    }
    in_stack_reverse[node] = false;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    vector<bool>DFS1(n+1);
    vector<bool>DFS2(n+1);
    adj.resize(n+1);
    in_stack.resize(n+1);
    reverse_adj.resize(n+1);
    in_stack_reverse.resize(n+1);
    int number_of_cycles = 0;
    rep(i,m){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(c>d)
        {
            adj[a].pb(b);
            reverse_adj[b].pb(a);
        }
        else{ 
            adj[b].pb(a);
            reverse_adj[a].pb(b);
        }
    }
    for(int i = 1;i<=n;i++){
        in_stack.clear();
        visited.clear();
        in_stack.resize(n+1);
        is_cycle = false;
        visited.resize(n+1);
        DFS(i);
        if(is_cycle){
            DFS1[i] = true;
        }
        // if(is_cycle)number_of_cycles++;
    }
    for(int i = 1;i<=n;i++){
        in_stack_reverse.clear();
        visited_reverse.clear();
        in_stack_reverse.resize(n+1);
        is_cycle = false;
        visited_reverse.resize(n+1);
        DFSR(i);
        if(is_cycle){
            DFS2[i] = true;
            if(DFS1[i] == true){
                number_of_cycles++;
            }
        }
    }
    cout << number_of_cycles;
    return 0;
}