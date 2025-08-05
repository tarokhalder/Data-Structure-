#include <bits/stdc++.h>

using namespace std;

class Node{
     public:
	char data;
	Node * children[26];
	bool isLeaf;
	Node() {
	   
	}
	Node(char d) {
	   data = d;
	   isLeaf = false;
	   for (int i = 0; i < 26; i++) {
	       children[i] = nullptr;
	   }
	}
};

class Trie{
    public:
      Node * root;	    
      Trie() {
         root = new Node('\0');
      }
      void insert(string a) {
          Node * temp = root;
	  for (char ch : a) {
	      if (temp->children[ch - 'a'] == nullptr) {
	          Node * n = new Node(ch);
		  temp->children[ch - 'a'] = n;
	      }
	      temp = temp->children[ch -'a'];
	  }
	  temp->isLeaf = true;
      }
      bool search(string a) {
           Node * temp = root;
	   for (char c : a) {
	       if (temp->children[c - 'a'] == nullptr) {
	           return false;
	       }
	       temp = temp->children[c - 'a'];
	   }
	   return temp->isLeaf;
      }
};

int main() {

   return 0;
}
