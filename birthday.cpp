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
vector<vector<int>>pairs;
// vector<bool>visited;
int cnt = 0;
void DFS(int node,pair<int,int>pairr,vector<bool> &visited){
    visited[node] = true;
    cnt++;
    for(auto it : adj[node]){
        if(visited[it] || ( (pairr.first == node && pairr.second == it) || (pairr.first == it && pairr.second == node) )){
            continue;
        }
        DFS(it,pairr,visited);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(1>0){
        int p,c;
        cin >> p >> c;
        if(p == 0 && c == 0){
            break;
        }
        else{
            adj.clear();
            adj.resize(p);
            bool iss = true;
            // pairs.resize(c+1);
            vector<bool>visited(p,false);
            cnt = 0;
            pairs.clear();
            rep(i,c){
                int a,b;
                cin >> a >> b;
                adj[a].pb(b);
                adj[b].pb(a);
                // pairs[i].pb(a);
                // pairs[i].pb(b);
                pairs.pb({a,b});
            }
            for(auto it1 : pairs){
                pair<int,int> a = {it1[0],it1[1]};
                DFS(0,a,visited);
                if(cnt == p){
                    // cout << "No" << endl;
                }
                else{
                    // cout << "Yes" << endl;
                    iss = false;
                    break;
                }
                // vector<bool>visited(p+1,false);
                fill(visited.begin(), visited.end(), false);
                cnt = 0;
            }
            if(iss == true){
                cout << "No" << endl;
            }
            else{
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}