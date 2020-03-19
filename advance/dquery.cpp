#include<bits/stdc++.h>
 
using namespace std;
#define int long long
#define MOD 1000000007
#define maxn 300010
#define endl '\n'
const int E = -1e14;
int n;
vector<pair<pair<int, int>, int>> queries;
int ans[maxn];
 
struct data {
    int a;
};
 
int a[maxn];
data t[6 * maxn];
 
data doit(data a, data b) {
    data d;
    d.a = a.a + b.a;
    return d;
}
 
//lazy one
void update(int start, int end, int idx, int val, int index) {
    if (idx < start or idx > end)
        return;
 
    if (start == end and start == idx) {
        t[index].a = val;
        return;
    }
 
    int mid = start + end >> 1;
 
    if (idx <= mid)
        update(start, mid, idx, val, index << 1);
    else
        update(mid + 1, end, idx, val, index << 1 | 1);
    t[index] = doit(t[index << 1], t[index << 1 | 1]);
}
 
data query(int start, int end, int l, int r, int index) {
    if (r < start or l > end)
        return {0};
 
    if (l <= start and end <= r)
        return t[index];
 
    int mid = start + end >> 1;
    return doit(query(start, mid, l, r, index << 1),
                query(mid + 1, end, l, r, index << 1 | 1));
}
 
void update(int idx, int val) {
    update(0, n - 1, idx, val, 1);
}
 
data query(int l ,int r) {
    return query(0, n - 1, l, r, 1);
}
bool comp(pair<pair<int, int>, int> a , pair<pair<int, int>, int> b){
    return a.first.second < b.first.second;
}
 
void solve() {
    sort(queries.begin(), queries.end() , comp);
    map<int, int> last;
 
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (last.count(a[i])) {
            update(last[a[i]], 0);
        }
        last[a[i]] = i;
        update(i, 1);
        while (counter < queries.size() and queries[counter].first.second == i + 1) {
            ans[queries[counter].second] = query(queries[counter].first.first - 1 , i).a;
            counter++;
        }
    }
}
 
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    int q;
    cin >> q;
 
    for (int j = 0; j < q; ++j) {
        int u, v;
        cin >> u >> v;
 
        queries.push_back({{u, v}, j});
    }
    solve();
 
    for (int i = 0; i < queries.size(); i++)
        cout << ans[i] << endl;
}  
