// SEGMENT TREE //
/* By Shark08*/
#include<bits/stdc++.h>
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/trie_policy.hpp>*/
// using namespace __gnu_pbds;
using namespace std;

#define ll 					long long int
#define ld 					long double 
#define mod 				1000000007
#define inf 				1e9
#define endl 				"\n"
#define pb 					push_back
#define vi					vector<ll>
#define vs 					vector<ss>
#define pii					pair<ll,ll>
#define ump					unordered_map
#define mp 					make_pair 
#define pq_max				priority_queue<ll,ll>
#define pq_min				priority_queue<ll,vector<ll>,greater<ll> >
#define all(v)				v.begin(),v.end()
#define ff 					first
#define ss      			second
#define mid(l,r) 			(l+(r-l)/2)
#define bitc(x)				__buildtin_popcount(x)
#define loop(i,a,b)			for(int i=a ; i<=b ; i++)
#define looprev(i,a,b) 		for(int i=a;i>=b;i--)
#define iter(c,it)			for(__typeof(c.begin()) it =c.begin() ; it!=c.end();it++)
#define log(args...)		{string _s = #args; replace(_s.begin(), _s.end(), ',',' ' ); stringstream __ss(_s); istream_iterator<string> _it(__ss) ; err(_it, args); }		
#define logarr(arr,a,b)     for(int z=a;z<=b;z++) cout<<(arr[z])<<" "; cout<<endl;
template<typename T> T gcd(T a, T b){ if(a%b) return gcd(b, a%b) ; return b;}
template<typename T> T lcm(T a ,T b) { return (a*(b/gcd(a,b)));}

void err(istream_iterator<string> it){}
template <typename T,typename... Args>
void err (istream_iterator<string> it, T a, Args... args){
	cout<< *it <<" = "<< a << endl;
	err(++it,args...);
}
//
//

void file_i_o()
{    
	ios_base::sync_with_stdio(false);
	//untie
	cin.tie(0);
	cout.tie(0);
    #ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
}




struct segmenttree{
	int n;
	vector<int> st;

	void init(int _n)
	{
		this->n = _n;
		st.resize(4*n,0);
	}

	void build(int start,int ending, int node, vector<int> &v)
	{
		if(start == ending)
		{
			st[node]= v[start];
			return;
		}

		int mid = (start+ending)/2;

		//left subtree is (start,mid)

		build(start,mid,2*node+1,v);

		//right subtree is (mid+1, ending)

		build(mid+1,ending,2*node+2,v);
		
		st[node] = st[2*node+1] + st[2*node+2];
	}

	int query(int start, int ending , int l, int r , int node)
	{
		if(start > r || ending <l) // non-overlaping case;
		{
			return 0;
		}

		//complete overlap 

		if(start>=l && ending <=r)
		{
			return st[node];
		}


		//partial overlap;
		int mid = (start+ending)/2;

		int q1 = query(start,mid,l,r,2*node+1);
		int q2 = query(mid+1,ending,l,r,2*node+2);

		return q1+q2;
	}


	void update(int start, int ending , int node ,int index , int value)
	{
		//base case
		if(start == ending)
		{
			st[node] = value;
			return;
		}
		int mid = (start+ending)/2;

		if(index <= mid)
		{
			update(start,mid,2*node+1,index,value);
		}
		else
		{
			update(mid+1,ending,2*node+2,index,value);
		}

		st[node ] = st[2*node+1] + st[2*node+2];
	}


	void build(vector<int> &v)
	{
		build(0,n-1,0,v);
	}

	int query(int l, int r)
	{
		return query(0,n-1,l,r,0);
	}

	void update(int x, int y)
	{
		update(0,n-1,0,x,y);
	}

};




int main(int argc, char const *argv[])
{
	/* code */
	clock_t begin = clock();
	file_i_o();

	vector<int> v ={1,2,3,4,5,6,7,8};

	segmenttree tree;
	tree.init(v.size());

	tree.build(v);

	cout<<tree.query(0,4)<<endl;

	tree.update(4,10);
	cout<<tree.query(2,6)<<endl;

	tree.update(2,20);

	cout<<tree.query(0,4)<<endl;



	#ifndef ONLINE_JUDGE
		clock_t end= clock();
		cout<<"\n\n\nExecuted In:"<< double(end-begin)/CLOCKS_PER_SEC*1000<<" ms";
	#endif
	return 0;
}