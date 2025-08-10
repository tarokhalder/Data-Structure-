#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
      int key;
      Node * left;
      Node * right;
      Node(int key){
         this->key = key;
	 left = right = NULL;
      }
};


Node * insert(Node * root , int key) {
       if (root == NULL) {
          return new Node (key);
       }
       if (root->key >= key) {
          root->left = insert(root->left , key);
       } else {
          root->right = insert(root->right , key);
       }
       return root;
}
Node * findmin(Node * root) {
   while (root->left != NULL) {
       root = root->left;
   }
   return root;
}
Node * remove(Node * root , int key) {
      if (root == NULL) {
         return NULL;
      }
      else if (key < root->key) {
           root->left = remove(root->left , key);
      } else if (key > root->key) {
          root->right = remove(root->right , key);
      } else {
          if (root->left == NULL && root->right == NULL) {
	      delete root;
	      root = NULL;
	      return root;
	  } else if (root->left == NULL) {
	     Node * temp = root;
	     root = root->right;
	     delete temp;
	  } else if (root->right == NULL) {
	     Node * temp = root;
	     root = root->left;
	     delete temp;
	  } else {
	      Node * temp = findmin(root->right);
	      root->key = temp->key;
	      root->right =  remove(root->right , temp->key);
	  }
      }
      return root;
}
void print(Node * root) {
     if (root == NULL) {
        return;
     }
     print(root->left);
     cout << root->key << " ";
     print(root->right);
}
int main() {
    vector <int> a = {5 , 1 , 10 , 15 , 3};
    Node * root = NULL;
    for (int x : a) {
        root = insert(root , x);
    }
    remove(root , 10);
    print(root);
}
