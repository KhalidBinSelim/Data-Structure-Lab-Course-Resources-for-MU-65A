#include<iostream>
using namespace std;

struct node{
    int val;
    node* left, *right, *parent;
    node(int x){
        val = x;
        left = right = parent = NULL;
    }
};

struct BST{
    node *root;
    /// constructor
    BST();

    /// utility function
    node* find_child(int,node*);
    void pre_t_node(node*);
    void in_t_node(node*);
    void post_t_node(node*);
    void print_node(node*);

    /// global function
    void insert(int);
    void del(int);
    bool find(int);
    void pre_traverse();
    void in_traverse();
    void post_traverse();

};

BST::BST(){
    root = NULL;
}

void BST::print_node(node *x){
    cout << "Val = " << x->val << "; Adrs = " << x << "\n";
    if(x->left!=NULL) cout << "Left  = " << x->left->val << "; Adrs = " << x->left << "\n";
    else cout << "Left child does not exist!\n";
    if(x->right!=NULL) cout << "Right = " << x->right->val << "; Adrs = " << x->right << "\n";
    else cout << "Right child does not exist!\n";
    if(x->parent!=NULL) cout << "Parent = " << x->parent->val << "; Adrs = " << x->parent << "\n";
    else cout << "Parent does not exist!\n";
    cout <<"------------\n";
}

void BST::pre_t_node(node* cur){
    print_node(cur);
    if(cur->left!=NULL) pre_t_node(cur->left);
    if(cur->right!=NULL) pre_t_node(cur->right);
}

void BST::in_t_node(node* cur){
    if(cur->left!=NULL) in_t_node(cur->left);
    print_node(cur);
    if(cur->right!=NULL) in_t_node(cur->right);
}

void BST::post_t_node(node* cur){
    if(cur->left!=NULL) post_t_node(cur->left);
    if(cur->right!=NULL) post_t_node(cur->right);
    print_node(cur);
}

void BST::pre_traverse(){
    cout <<"Pre-order Traversal - Start  ------\n";
    pre_t_node(root);
    cout <<"Pre-order Traversal - End    ------\n";
}

void BST::in_traverse(){
    cout <<"In-order Traversal - Start   ------\n";
    in_t_node(root);
    cout <<"In-order Traversal - End     ------\n";
}

void BST::post_traverse(){
    cout <<"Post-order Traversal - Start ------\n";
    post_t_node(root);
    cout <<"Post-order Traversal - End   ------\n";
}


node* BST::find_child(int val,node* temp){
    if(temp->val <= val) return temp->right;
    return temp->left;
}

void BST::insert(int x){
    node *cur = new node(x), *temp, *temp_child;
    if(root == NULL){
        root = cur;
        return;
    }
    temp = root;
    temp_child = find_child(x,temp);
    while(temp_child!=NULL){
        temp = temp_child;
        temp_child = find_child(x,temp);
    }
    if(temp->val <= x) temp->right = cur;
    else temp->left = cur;
    cur->parent = temp;
}

int main()
{
    BST *bst = new BST();
    bst->insert(16);
    bst->insert(17);
    bst->pre_traverse();
    bst->insert(15);
    bst->pre_traverse();
    bst->in_traverse();
    bst->post_traverse();

    return 0;
}
