// #include <cassert>
// #include <cctype>
// #include <cerrno>
// #include <cfloat>
// #include <ciso646>
// #include <climits>
// #include <clocale>
// #include <cmath>
// #include <csetjmp>
// #include <csignal>
// #include <cstdarg>
// #include <cstddef>
// #include <cstdio>
// #include <cstdlib>
// #include <cstring>
// #include <ctime>
// #if __cplusplus >= 201103L
// #include <ccomplex>
// #include <cfenv>
// #include <cinttypes>
// #include <cstdbool>
// #include <cstdint>
// #include <ctgmath>
// #include <cwchar>
// #include <cwctype>
// #endif
// #include <algorithm>
// #include <bitset>
// #include <complex>
// #include <deque>
// #include <exception>
// #include <fstream>
// #include <functional>
// #include <iomanip>
// #include <ios>
// #include <iosfwd>
// #include <iostream>
// #include <istream>
// #include <iterator>
// #include <limits>
// #include <list>
// #include <locale>
// #include <map>
// #include <memory>
// #include <new>
// #include <numeric>
// #include <ostream>
// #include <queue>
// #include <set>
// #include <sstream>
// #include <stack>
// #include <stdexcept>
// #include <streambuf>
// #include <string>
// #include <typeinfo>
// #include <utility>
// #include <valarray>
// #include <vector>
// #if __cplusplus >= 201103L
// #include <array>
// #include <atomic>
// #include <chrono>
// #include <condition_variable>
// #include <forward_list>
// #include <future>
// #include <initializer_list>
// #include <mutex>
// #include <random>
// #include <ratio>
// #include <regex>
// #include <scoped_allocator>
// #include <system_error>
// #include <thread>
// #include <tuple>
// #include <typeindex>
// #include <type_traits>
// #include <unordered_map>
// #include <unordered_set>
// #endif
// #define int long long int
// #define endl "\n"
// #define pb push_back
// #define rep(i,n) for(int i=0;i<n;++i)
// #define sortn(a) sort(a.begin(),a.end())
// #define sortr(a) sort(a.begin(),a.end(),greater<int>())
// using namespace std;
// vector<bool>visited;
// vector<vector<int>>adj;
// int countt = 0;
// void DFS(int node){
//     visited[node] = true;
//     countt++;
//     for(auto it : adj[node]){
//         if(visited[it]){
//             continue;
//         }
//         DFS(it);
//     }
// }
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n,m;
//     cin >> n >> m;
//     adj.resize(n+1);
//     visited.assign(n+1,false);
//     rep(i,m){
//         int a,b;
//         cin >> a >> b;
//         adj[a].pb(b);
//     }
//     int min_adjs = INT_MAX;
//     int minimum_adj = 0;
//     for(int it = 1;it<=n;it++){
//         int a = adj[it].size();
//         // min_adjs = min(min_adjs,(long long)(adj[it].size()));
//         min_adjs = min(a,min_adjs);
//         if(min_adjs == a)minimum_adj = it;
//     }
//     visited.clear();
//     visited.assign(n+1,false);
//     countt = 0;
//     DFS(minimum_adj);
//     if(countt == n){
//         cout << "YES";
//     }
//     else{
//         cout << "NO" << endl;
//         for(int i = 1;i<=n;i++){
//             if(!visited[i]){
//                 cout << minimum_adj << " " << i;
//                 break;
//             }
//         }
//     }
//     return 0;
// }
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
vector<bool>visited;
vector<vector<int>>reverse_adj;
vector<bool>visited_reverse;
void DFS(int node){
    visited[node] = true;
    for(auto it : adj[node]){
        if (!visited[it]){
            DFS(it);    
        }
        
    }
}
void DFSR(int node){
    visited_reverse[node] = true;
    for(auto it : reverse_adj[node]){
        if (!visited_reverse[it]){
            DFSR(it);    
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    adj.resize(n+1);
    reverse_adj.resize(n+1);
    rep(i,m){
        int a,b;
        cin >> a >> b;
            adj[a].pb(b);
            reverse_adj[b].pb(a);
    }
    bool done = false;
    visited.resize(n+1);
    DFS(1);
    visited_reverse.resize(n+1);
    DFSR(1);
    for(int i = 1;i<=n;i++){
        if(!visited[i]){
            cout << "NO" << endl;
            cout << "1 " << i;
            done = true;
            break;
        }
    }
    if(done == false){
        for(int i = 1;i<=n;i++){
            if(!visited_reverse[i]){
                cout << "NO" << endl;
                cout << i << " 1";
                done = true;
                break;
            }
        }
        if(!done){
            cout << "YES";
        }
    }
    return 0;
}