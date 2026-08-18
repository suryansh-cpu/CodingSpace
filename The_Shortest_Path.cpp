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
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<vector<int>> adj(n+1);
        // vector<string> city_name(n+1);
        map<string,int> city_name;
        for(int i = 1;i<=n;i++){
            string name;
            cin >> name;
            city_name[name] = i;
            int neibhours = 0;
            cin >> neibhours;
            while(neibhours--){
                int a,b;
                cin >> a >> b;
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
        }
        int number_of_paths = 0;
        cin >> number_of_paths;
        while(number_of_paths--){
            string cityA,cityB;
            cin >> cityA >> cityB;
            multiset<pair<int,string>> s;
            s.insert({0,cityA});
            vector<int>path_sum(n+1,INT_MAX);
            while(!s.empty()){
                pair<int,string> a = *s.begin();
                s.erase(s.begin());
                if(a.second == cityB){
                    cout << a.first << endl;
                    break;
                }
                for(int j = 0;j<adj[city_name[cityA]].size();j++){
                    if(a.first + adj[city_name[cityA]][j] < path_sum[adj[city_name[cityA]][j]])
                    // change adj to pair<int,int> then solve with same djikstra
                }
            }
        }
    }
    return 0;
}