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
#define rep(a,n) for(int i=a;i<n;++i)
#define sortn(a) sort(a.begin(),a.end())
#define sortr(a) sort(a.begin(),a.end(),greater<int>())
using namespace std;
int solve(vector<pair<int,int>>& items,int i,int n,int W,vector<vector<int>>& dp){
    if(i>=n || W <= 0)return 0;
    // if(w > W)return 0;
    // int a = solve(items,i+1,n,w+items[i].first,val += items[i].second);
    if(dp[i][W] != -1)return dp[i][W];
    if(items[i].first > W){
        dp[i][W] = solve(items,i+1,n,W,dp);
        return dp[i][W];
    }
    dp[i][W] = max((long long)items[i].second + solve(items,i+1,n,W-items[i].first,dp),(long long)solve(items,i+1,n,W,dp));
    return dp[i][W];
    // return max(solve(items,i+1,n,w+items[i].first),solve(items,i+1,n,w));
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,w;
    cin >> n >> w;
    vector<pair<int,int>>items(n);
    rep(0,n){
        cin >> items[i].first >> items[i].second;
        // cout << items[i].first << items[i].second;
    }
    vector<vector<int>>dp(n+1,vector<int>(w+1,-1));
    cout << solve(items,0,n,w,dp);
    return 0;
}