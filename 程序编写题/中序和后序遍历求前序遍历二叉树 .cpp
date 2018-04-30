#include <iostream>
#include <fstream>
#include <string>

struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char  elem;
};

//����ͺ��������ǰ����������� 
TreeNode* BinaryTreeFromOrderings(char* inorder, char* aftorder, int length)
{
	//��ֵ��Ч 
    if(length == 0)
    {
        return NULL;
    }
    
    
    TreeNode* node = new TreeNode;//Noice that [new] should be written out.
    
    node->elem = *(aftorder+length-1);   //������������һ����һ���ǽڵ㣬����ֱ��ȡ�� 
    
   std::cout<<node->elem<<std::endl;//��ӡ��Ԫ�� 
    
    int rootIndex = 0;
    for(;rootIndex < length; rootIndex++)//a variation of the loop
    {
        if(inorder[rootIndex] ==  *(aftorder+length-1))
            break;
    }
    node->left = BinaryTreeFromOrderings(inorder, aftorder , rootIndex);
    
    node->right = BinaryTreeFromOrderings(inorder + rootIndex + 1, aftorder + rootIndex , length - (rootIndex + 1));
     
    return node;
}



int main(int argc, char** argv)
{
    char* af="AEFDHZMG";    
    char* in="ADEFGHMZ"; 
    char* be ="GDAFEMHZ";
    BinaryTreeFromOrderings(in, af, 8); 
    printf("\n");
    return 0;
}
