#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
struct BNode{//二叉树节点
    BNode(const char d='#'):data(d), left(NULL), right(NULL) {};
    char data;
    BNode* left;
    BNode* right;
};
//根据先序遍历构建一棵二叉树，返回root指针
BNode* constructBinaryTree(const string& preOrder, unsigned& index){
    if (preOrder.size() == 0 || index == preOrder.size() || preOrder[index] == '#')//若空串或者index超出范围，则返回空指针
        return NULL;
    BNode* T = new BNode(preOrder[index++]);
    T->left = constructBinaryTree(preOrder, index);
    T->right = constructBinaryTree(preOrder, ++index);
    return T;
}
//右边看 
void RightSee(BNode* T){
    if (T != NULL){
       cout<<T->data;
	   if(T->right)   
	   {
	   	RightSee(T->right);
	   }
	   else if(T->left)
	   {
	   	RightSee(T->left);
	   }
    }
}
int main(){
		int T;
	int i;
	scanf("%d",&T);
    string str;
    while (cin >> str){
        unsigned index = 0;
        BNode* root = constructBinaryTree(str, index);
        RightSee(root);
        cout << endl;
    }
    return 0;
}
