#include <bits/stdc++.h>

using namespace std;


struct segmenttree{
     vector <int> st;
     int n;
     void init(int n){
        this-> n = n;
	st.resize(4*n , 0);
     }
     void build(int start , int end , int node , vector <int> & a) {
	   if (start == end) {
	      st[node] = a[start];
	      return;
	   }  
           int mid = (start+end) / 2;
	   //left subtree
	   build(start , mid , 2*node+1 , a);
	   //right subtree
	   build (mid+1 , end , 2*node +2 , a);

	   st[node] = st[node*2 +1] + st[node * 2 + 2];
     }

     void build(vector <int> & a) {
        build(0 , int(a.size())-1 , 0 , a);
     }
     
     int query(int start , int end , int l , int r , int node) {
          if (start > r ||  end < l) {
	      return 0;   // no overlapping
	  }
	  // complete overlap
	  if ( l <= start && end <= r) {
	       return st[node];
	  }

	  int mid = (start + end) / 2;
	  int q1 = query(start , mid , l , r , 2 * node+1);
	  int q2= query(mid+1 , end , l , r , 2 * node + 2);

	  return q1 + q2;
     } 

     int query(int l , int r) {
         return query(0 , n - 1 , l , r , 0);
     }
     
     void update(int start , int end , int node ,int index , int value) {
	 if ( start == end ){
	     st[node ] = value;
	     return;
	 }    
         int mid = (start + end) / 2;
	 if ( index <= mid) {
	     update(start , mid , 2 * node + 1 , index , value);
	 }
	 else{
	    update(mid+1 , end , 2 * node +2 , index , value);
	 }

	 st[node] = st[node * 2 + 1] + st[node * 2 + 2];
     }

     void update(int x , int y) {
         update(0 , n - 1 , 0 , x , y);
     }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);    
    
    return 0;
}
