#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<math.h>
using namespace std;

typedef int infotype;
typedef struct TElmt *address;
typedef struct TElmt{
	infotype data;
	address right;
	address left;
} Elmt;

address allocation(infotype x){
	address newElmt = new Elmt();
	newElmt->data = x;
	newElmt->left=newElmt->right=NULL;
	
	return newElmt;
}

int findHeight(address root){
	int left, right;
	if(root==NULL) return -1;
	left=findHeight(root->left);
	right=findHeight(root->right);
	return max(left, right)+1;
}

int sumLeaf(address root){
	int left, right;
	if(root==NULL) return 0;
	left=sumLeaf(root->left);
	right=sumLeaf(root->right);
	return left+right+1;
}

void inOrder(address root){
	if (root == NULL) return;
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

void PreOrder(address root){
	if (root == NULL) return;
	cout<<root->data<<" ";
	PreOrder(root->left);
	PreOrder(root->right);
}

void PostOrder(address root){
	if (root == NULL) return;
	PostOrder(root->left);
	PostOrder(root->right);
	cout<<root->data<<" ";
}

bool searchh(address root, infotype data){
	if (root==NULL) return false;
	else if(root->data==data) return true;
	else if(data>=root->data) return searchh(root->right, data);
	else return searchh(root->left, data);
}

address insert(address root, infotype data){
	if(root==NULL){
		root=allocation(data);
	} else if(data <= root->data ){
		root->left = insert(root->left, data);
	} else{
		root->right = insert(root->right, data);
	}
	return root;
}

int findMin(address root){
	if(root==NULL) {
		cout<<"Tree is Empty!";
		return -1;
	}
	else if(root->left==NULL) return root->data;
	else return findMin(root->left);
}

int findMax(address root){
	if(root==NULL) {
		cout<<"Tree is Empty!";
		return -1;
	}
	else if(root->right==NULL) return root->data;
	else return findMin(root->right);
}

int main(){
	address root = NULL;
	int search;
	root=insert(root, 14);
	root=insert(root, 30);
	root=insert(root, 1);
	root=insert(root, 10);
	
	cout<<"Cin number search : "; cin>>search;
	if(searchh(root, search)) cout<<search<<" is Found! \n";
	else cout<<search<<" is Not found! \n";
	
	int min = findMin(root);
	int  max = findMax(root);
	cout<<"Minimum = "<<min;
	cout<<"\nMaximum = "<<max;
	
	int height=findHeight(root);
	cout<<"\n"<<height;
}


