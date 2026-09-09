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
    node* find_node(int);
    node* find_in_succ(node*);

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

node* BST::find_node(int x){
    if(root==NULL) return NULL;
    node *temp = root, *temp_child;
    temp_child = find_child(x,temp);
    while(temp_child!=NULL){
        if(temp->val == x) return temp;
        temp = temp_child;
        temp_child = find_child(x,temp);
    }
    return temp;
}

bool BST::find(int x){
    node* temp = find_node(x);
    return (temp!=NULL && temp->val == x);
}

node* BST::find_in_succ(node* temp){
    if(temp->right->left==NULL) return temp->right;
    node *ret = temp->right;
    while(ret->left!=NULL)
        ret = ret->left;
    return ret;
}

void BST::del(int x){
    node* temp = find_node(x), *temp_child;

    if(temp==NULL){
        cout << x << "does not exists!\n";
        return;
    }

    /// case 1
    if(temp->left==NULL && temp->right==NULL){
        if(temp == root) root = NULL;
        else if(temp->parent->left == temp)
            temp->parent->left = NULL;
        else if(temp->parent->right == temp)
            temp->parent->right = NULL;
        delete temp;
        return;
    }

    /// case 2
    if(temp->left==NULL || temp->right==NULL){
        temp_child = temp->left==NULL?temp->right:temp->left;
        if(temp==root) root = temp_child;
        else if(temp->parent->left == temp){
            temp->parent->left = temp_child;
            temp_child->parent = temp->parent;
        }
        else{
            temp->parent->right = temp_child;
            temp_child->parent = temp->parent;
        }
        delete temp;
        return;
    }

    /// case 3
    node * in_succ = find_in_succ(temp);
    node *cur = new node(in_succ->val);

    cur->left = temp->left;
    temp->left->parent = cur;

    bool direct_child = temp->right == in_succ;
    if(direct_child) cur->right = in_succ->right;
    else cur->right = temp->right;

    del(in_succ->val);

    if(temp->right != NULL) temp->right->parent = cur;
    if(temp==root) root = cur;
    else{
        cur->parent = temp->parent;
        if(temp->parent->left == temp) temp->parent->left = cur;
        else temp->parent->right = cur;
    }
    delete temp;
    return;
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

    bst->insert(20);
    bst->insert(15);
    bst->insert(10);
    bst->insert(18);
    bst->insert(19);
    bst->insert(17);
    bst->insert(16);
    bst->insert(25);
    bst->insert(28);
    bst->insert(21);
    bst->insert(22);
    bst->pre_traverse();
    bst->del(16);
    bst->pre_traverse();
    bst->del(21);
    bst->pre_traverse();
    bst->del(20);
    bst->pre_traverse();
    bst->del(15);
    bst->pre_traverse();

//    bst->insert(16);
//    cout << bst->find(18) << "\n";
//    cout << bst->find(17) << "\n";
//    cout << bst->find(14) << "\n";
//    cout << bst->find(13) << "\n";
//    cout << bst->find(16) << "\n";
//    bst->insert(17);
//    bst->pre_traverse();
//    bst->insert(13);
//    bst->insert(15);
//    bst->pre_traverse();
//    bst->in_traverse();
//    bst->post_traverse();
//    cout << bst->find(18) << "\n";
//    cout << bst->find(17) << "\n";
//    cout << bst->find(14) << "\n";
//    cout << bst->find(13) << "\n";
//    cout << bst->find(1) << "\n";
    return 0;
}
