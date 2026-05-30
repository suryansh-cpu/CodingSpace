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
const long long INF = 1e18;
int n, W;

long long solve(int i, int value,vector<pair<int,int>>& items,vector<vector<int>>& dp) {
    if (value == 0) return 0;
    if (i == n) return INF;
    if (dp[i][value] != -1)return dp[i][value];
    long long notTake = solve(i + 1, value,items,dp);
    long long take = INF;
    if (value >= items[i].second) {
        take = items[i].first + solve(i + 1, value - items[i].second,items,dp);
    }
    return dp[i][value] = min(take, notTake);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> W;
    vector<pair<int,int>> items(n);
    int totalValue = 0;
    rep(0,n){
        cin >> items[i].first >> items[i].second;
        totalValue += items[i].second;
    }
    vector<vector<int>> dp(n+1,vector<int>(totalValue+1,-1));
    int ans = 0;
    for (int value = totalValue; value >= 0; value--) {
        if (solve(0,value,items,dp) <= W) {
            ans = value;
            break;
        }
    }
    cout << ans << '\n';
}