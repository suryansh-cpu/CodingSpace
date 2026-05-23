// //                                                                     //  code 1


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
class farmDSU{
    public:
        vector<int>parent;
        vector<int>size;
        vector<vector<int> > nodes;
        vector<int>order_of_barn_closing;
        vector<string>answer;
        map<int,bool>is_barn_open;
        int count_of_diff_barns = 0;
        int n = 1;
        farmDSU(int sizee) : parent(sizee+1),size(sizee+1),order_of_barn_closing(sizee+1),nodes(sizee+1){
            n = sizee;
        }
        void make_set(){
            for(int i = 1;i<n+1;i++){
                size[i] = 1;
                parent[i] = i;
                is_barn_open[i] = false;
            }
        }
        int find_set(int a){
            while(parent[a] != a){
                a = parent[a];
                parent[a] = parent[parent[a]];
            }
            return a;
        }
        void merge(int a, int b){
            a = find_set(a); b = find_set(b);
            if(a != b){
                if(size[a] < size[b]) swap(a,b);
                parent[b] = a;
                size[a] += size[b];
                count_of_diff_barns--;
            }
        }
        vector<string> solvingg(){
            rep(i,n){
                is_barn_open[order_of_barn_closing[i]] = true;
                count_of_diff_barns++;
                for(int j = 0; j < nodes[order_of_barn_closing[i]].size(); j++){
                    if(is_barn_open[nodes[order_of_barn_closing[i]][j]]){
                        merge(order_of_barn_closing[i],nodes[order_of_barn_closing[i]][j]);
                    }
                }
                if(count_of_diff_barns == 1)answer.pb("YES");
                else answer.pb("NO");
            }
            return answer;
        }
};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("closing.in", "r", stdin);
    int n,m;
    cin >> n >> m;
    farmDSU dsu(n);
    dsu.make_set();
    rep(i,m){
        int a,b;
        cin >> a >> b;
        dsu.nodes[a].pb(b);
        dsu.nodes[b].pb(a);
    }
    rep(i,n){
        int a;
        cin >> a;
        dsu.order_of_barn_closing[i] = a;
    }
    reverse(dsu.order_of_barn_closing.begin(),dsu.order_of_barn_closing.begin() + n);
    vector<string> ans = dsu.solvingg();
    // freopen("closing.out", "w", stdout);
    reverse(ans.begin(),ans.end());
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}

// #include <bits/stdc++.h> 
// using namespace std;

// // BeginCodeSnip{DSU}
// struct DSU {
// 	vector<int> e;
// 	DSU(int N) : e(N, -1) {}

// 	// get representative component (uses path compression)
// 	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

// 	bool same_set(int a, int b) { return get(a) == get(b); }

// 	int size(int x) { return -e[get(x)]; }

// 	// union by size
// 	bool unite(int x, int y) {
// 		x = get(x), y = get(y);
// 		if (x == y) return false;
// 		if (e[x] > e[y]) swap(x, y);
// 		e[x] += e[y];
// 		e[y] = x;
// 		return true;
// 	}
// };
// // EndCodeSnip

// int main() {
// 	freopen("closing.in", "r", stdin);
// 	int n, m;
// 	cin >> n >> m;

// 	vector<vector<int>> adj(n);
// 	for (int i = 0; i < m; i++) {
// 		int u, v;
// 		cin >> u >> v;
// 		u--;
// 		v--;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}

// 	// conn[i] = whether the ith farm is closed
// 	vector<bool> conn(n);
// 	vector<int> rev(n);
// 	for (int i = 0; i < n; i++) {
// 		cin >> rev[i];
// 		rev[i]--;
// 	}

// 	DSU dsu(n);
// 	reverse(rev.begin(), rev.end());

// 	conn[rev[0]] = 1;
// 	// one node is always connected
// 	vector<string> ans = {"YES"};

// 	// connected components
// 	int cc = 1;
// 	for (int i = 1; i < n; i++) {
// 		cc++;
// 		conn[rev[i]] = 1;
// 		for (int j : adj[rev[i]]) {
// 			if (conn[j]) {
// 				if (dsu.unite(j, rev[i])) { cc--; }
// 			}
// 		}
// 		ans.push_back(cc == 1 ? "YES" : "NO");
// 	}
// 	reverse(ans.begin(), ans.end());

// 	freopen("closing.out", "w", stdout);
// 	for (const string &i : ans) { cout << i << '\n'; }
// }


//                                                                      code 2


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
// #define sortn(a) sort(first.begin(),first.end())
// #define sortr(a) sort(first.begin(),first.end(),greater<int>())
// using namespace std;
// class farmDSU{
//     public:
//         vector<int>parent;
//         vector<int>size;
//         vector<vector<int> > nodes;
//         vector<int>order_of_barn_closing;
//         vector<string>answer;
//         map<int,bool>is_barn_open;
//         int count_of_diff_barns = 0;
//         int n = 1;
//         farmDSU(int sizee) : parent(sizee+1),size(sizee+1),order_of_barn_closing(sizee+1),nodes(sizee+1){
//             n = sizee;
//         }
//         void make_set(){
//             for(int i = 1;i<n+1;i++){
//                 size[i] = 1;
//                 parent[i] = i;
//                 is_barn_open[i] = false;
//             }
//         }
//         int find_set(int a){
//             while(parent[a] != a){
//                 a = parent[a];
//                 parent[a] = parent[parent[a]];
//             }
//             return a;
//         }
//         void merge(int a, int b){
//             a = find_set(a); b = find_set(b);
//             if(a != b){
//                 if(size[a] < size[b]) swap(a,b);
//                 parent[b] = a;
//                 size[a] += size[b];
//                 count_of_diff_barns--;
//             }
//         }
//         vector<string> solvingg(){
//             rep(i,n){
//                 is_barn_open[order_of_barn_closing[i]] = true;
//                 count_of_diff_barns++;
//                 int cur = order_of_barn_closing[i];
//                 for (int j = 0; j < nodes[cur].size(); j++) {
//                     int nei = nodes[cur][j];
//                     if (is_barn_open[nei]) {
//                         merge(cur, nei);
//                     }
//                 }
//                 if(count_of_diff_barns == 1)answer.pb("YES");
//                 else answer.pb("NO");
//             }
//             return answer;
//         }
// };
// signed main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     // freopen("closing.in", "r", stdin);
//     int n,m;
//     cin >> n >> m;
//     farmDSU dsu(n);
//     dsu.make_set();
//     rep(i,m){
//         int a,b;
//         cin >> a >> b;
//         dsu.nodes[a].pb(b);
//         dsu.nodes[b].pb(a);
//     }
//     rep(i,n){
//         int a;
//         cin >> a;
//         dsu.order_of_barn_closing[i] = a;
//     }
//     reverse(dsu.order_of_barn_closing.begin(),dsu.order_of_barn_closing.begin() + n);
//     vector<string> ans = dsu.solvingg();
//     // freopen("closing.out", "w", stdout);
//     reverse(ans.begin(),ans.end());
//     rep(i,n){
//         cout << ans[i] << endl;
//     }
//     return 0;
// }
// // #include <bits/stdc++.h> 
// // using namespace std;

// // // BeginCodeSnip{DSU}
// // struct DSU {
// // 	vector<int> e;
// // 	DSU(int N) : e(N, -1) {}

// // 	// get representative component (uses path compression)
// // 	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

// // 	bool same_set(int a, int b) { return get(a) == get(b); }

// // 	int size(int x) { return -e[get(x)]; }

// // 	// union by size
// // 	bool unite(int x, int y) {
// // 		x = get(x), y = get(y);
// // 		if (x == y) return false;
// // 		if (e[x] > e[y]) swap(x, y);
// // 		e[x] += e[y];
// // 		e[y] = x;
// // 		return true;
// // 	}
// // };
// // // EndCodeSnip

// // int main() {
// // 	freopen("closing.in", "r", stdin);
// // 	int n, m;
// // 	cin >> n >> m;

// // 	vector<vector<int>> adj(n);
// // 	for (int i = 0; i < m; i++) {
// // 		int u, v;
// // 		cin >> u >> v;
// // 		u--;
// // 		v--;
// // 		adj[u].push_back(v);
// // 		adj[v].push_back(u);
// // 	}

// // 	// conn[i] = whether the ith farm is closed
// // 	vector<bool> conn(n);
// // 	vector<int> rev(n);
// // 	for (int i = 0; i < n; i++) {
// // 		cin >> rev[i];
// // 		rev[i]--;
// // 	}

// // 	DSU dsu(n);
// // 	reverse(rev.begin(), rev.end());

// // 	conn[rev[0]] = 1;
// // 	// one node is always connected
// // 	vector<string> ans = {"YES"};

// // 	// connected components
// // 	int cc = 1;
// // 	for (int i = 1; i < n; i++) {
// // 		cc++;
// // 		conn[rev[i]] = 1;
// // 		for (int j : adj[rev[i]]) {
// // 			if (conn[j]) {
// // 				if (dsu.unite(j, rev[i])) { cc--; }
// // 			}
// // 		}
// // 		ans.push_back(cc == 1 ? "YES" : "NO");
// // 	}
// // 	reverse(ans.begin(), ans.end());

// // 	freopen("closing.out", "w", stdout);
// // 	for (const string &i : ans) { cout << i << '\n'; }
// // }