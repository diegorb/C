#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node{
    int val;
    struct node * left;
    struct node * right;
}Node;

Node* NewNode(int val){
    Node * newnode = (Node*) malloc(sizeof(Node));
    newnode->val = val;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

/* Insert the new value and return the root pointer */
Node* Insert(Node *root, int val){
    if(root == NULL){
        return NewNode(val);
    }else{
        if(val <= root->val){
            root->left = Insert(root->left,val);
        }else{
            root->right = Insert(root->right,val);
        }
        return root;
    }
}

Node* Search(Node *root, int val){
    if(root == NULL || root->val == val){
        return root;
    }else{
        if(val <= root->val){
            return Search(root->left,val);
        }else{
            return Search(root->right,val);
        }
    }
}

bool ExistValue(Node * root, int val){
    Node * aux = Search(root,val);
    bool flag = false;
    if(aux->val == val){
        flag = true;
    }
    return flag;
}

int main() {
    Node * root = NewNode(5);
    Insert(root,2);
    Insert(root,3);
    printf("%d\n",ExistValue(root,3));
    printf("%d",root->left->val);
    return 0;
}