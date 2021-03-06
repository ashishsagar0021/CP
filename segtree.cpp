#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
#define int                 		long long
#define double              		long double
#define endl                		"\n"
#define pb                  		push_back
#define PI                  		3.1415926535897932384626433832795l
#define F                   		first
#define S                   		second
#define mp                  		make_pair
#define f(i,n)              		for(int i=0;i<n;++i)
#define loop(i,a,b)         		for (int i=a ; i<b ;++i)
#define fastio              		ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define all(v)              		(v).begin(),(v).end()
#define rall(v)             		(v).rbegin(),(v).rend()
#define gcd(a,b)            		__gcd((a),(b))
#define fill(a,value)       		memset(a,value,sizeof(a));
#define minn(v)             		*min_element(v.begin(), v.end());
#define maxx(v)             		*max_element(v.begin(), v.end());
#define print(x)            		cout<<(x)<<endl;
typedef pair<int, int>      		pii;
typedef vector<int>         		vi;
const int mod = 1e9 + 7;
const int MOD = 998244353;

struct segtree
{
	int size;
	vector<int> sums;
	void init(int n)
	{
		size = 1;
		while (size < n)size *= 2;
		sums.assign(2 * size, 0);
	}
	void build(vector<int>&a, int x, int lx, int rx)
	{
		if (rx - lx == 1)
		{
			if (lx < (int)a.size())
			{
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];

	}
	void build(vector<int> &a)
	{
		build(a, 0, 0, size);
	}
	void set(int i, int v, int x, int lx, int rx)
	{
		if (rx - lx == 1)
		{
			sums[x] = v;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m)
		{
			set(i, v, 2 * x + 1, lx, m);
		}
		else
		{
			set(i, v, 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}
	void set(int i, int v)
	{
		set(i, v, 0, 0, size);
	}
	int sum(int l, int r, int x, int lx, int rx)
	{
		if (lx >= r or l >= rx) return 0;
		if (lx >= l and rx <= r) return sums[x];
		int m = (lx + rx) / 2;
		int s1 = sum(l, r, 2 * x + 1, lx, m);
		int s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}
	int sum(int l, int r)
	{
		return sum(l, r, 0, 0, size);
	}
};

void solve()
{
	int n, m;
	cin >> n >> m;

	segtree st;
	st.init(n);
	vector<int>a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	st.build(a);
	while (m--)
	{
		int op;
		cin >> op;
		if (op == 1)
		{
			int i, v;
			cin >> i >> v;
			st.set(i, v);
		}
		else
		{
			int l, r;
			cin >> l >> r;
			cout << st.sum(l, r) << "\n";
		}
	}



}

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio;
	cout << fixed << setprecision(12);
	int T = 1;
	//cin >> T;
	while (T--)
	{

		solve();

	}
	return 0;
}