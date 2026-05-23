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
using namespace std;
class roadsDSU{
    public:
        vector<int>parent;
        vector<int>size;
        int n,max_size = 1;
        roadsDSU(int sizee) : parent(sizee+1),size(sizee+1){
            n = sizee;
            // parent.resize(sizee+1);
            // size.resize(sizee+1);
        }
        void make_set(){
            rep(i,n+1){
                if(i>0){
                    parent[i] = i;
                }
                size[i] = 1;
            }
        }
        int find_set(int a){
            while(parent[a] != a){
                a = parent[a];
                parent[a] = parent[parent[a]];
            }
            return a;
        }
        pair<bool,int> merge(int a, int b){
            int find_a = find_set(a);
            int find_b = find_set(b);
            if(find_a != find_b){
                if(size[find_b]>size[find_a]){
                    // swap(find_a,find_b);
                    
                    size[find_b]+=size[find_a];
                    max_size = max(size[find_b],max_size);
                    parent[find_a] = b;
                }
                else{
                    size[find_a]+=size[find_b];
                    max_size = max(size[find_a],max_size);
                    parent[find_b] = a;
                }
                return {false,max_size};
            }
            return {true,max_size};
        }
};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    roadsDSU dsu(n);
    dsu.make_set();
    int component = n;
    rep(i,m){
        int u,v;
        cin >> u >> v;
        pair<bool,int> temp = dsu.merge(u,v);
        if(!temp.first){
            component--;
        }
        cout << component << " " << temp.second << endl;
    }
    
    return 0;
}