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
int ans = -1;
signed solve(int i,int prev,vector<vector<int>>& arr,int n,vector<vector<int>>& dp){
    if(i >= n)return 0;
    if(prev == -1){
        return max({
            arr[i][0] + solve(i+1,0,arr,n,dp),
            arr[i][1] + solve(i+1,1,arr,n,dp),
            arr[i][2] + solve(i+1,2,arr,n,dp)
        });
    }
    if(prev != -1 && dp[i][prev] != -1)
        return dp[i][prev];
    if(prev == 0){
        return dp[i][0] = max(
            arr[i][1] + solve(i+1,1,arr,n,dp),
            arr[i][2] + solve(i+1,2,arr,n,dp)
        );
    }
    if(prev == 1){
        return dp[i][1] = max(
            arr[i][0] + solve(i+1,0,arr,n,dp),
            arr[i][2] + solve(i+1,2,arr,n,dp)
        );
    }
    if(prev == 2){
        return dp[i][2] = max(
            arr[i][1] + solve(i+1,1,arr,n,dp),
            arr[i][0] + solve(i+1,0,arr,n,dp)
        );
    }
    return 0;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int> >arr(n,vector<int>(3));
    rep(0,n){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    vector<vector<int>>dp(n,vector<int>(3,-1));
    cout << solve(0,-1,arr,n,dp);
    return 0;
}