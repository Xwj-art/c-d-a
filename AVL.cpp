#include <iostream>
using namespace std;
//AVL树的节点信息
template<typename T>
class node{
public:
    explicit node(T x):data(x){}
    T data;
    int h=0;
    node* l=nullptr;
    node* r=nullptr;
};

template<typename T>
class AVL{
private:
    int height(node<T>* n) const;
    node<T>*  SingRotateLeft(node<T>* &k2);
    node<T>*  SingRotateRight(node<T>* &k2);
    node<T>* DoubleRotateLR(node<T>* &k3);
    node<T>* DoubleRotateRL(node<T>* &k3);
    int Max(int cmpa,int cmpb);
    void insubtree(node<T>* node);
    void rolate(node<T>* &n);
    void Insert(node<T>* &n,T x);
    void Delete(node<T>* &n,T x);
public:
    node<T>* root;
    AVL():root(nullptr){}
    void insert(T x);
    void del(T x);
    void Traversal();
};

template<typename T>
int AVL<T>::height(node<T>* n) const{
    if(n!=nullptr)  return n->h;
    return -1;
}

template<typename T>
int AVL<T>::Max(int cmpa,int cmpb){
    return cmpa>cmpb?cmpa:cmpb;
}

template<typename T>
node<T>* AVL<T>::SingRotateLeft(node<T>* &k){
    node<T>* l=k->l;
    k->l=l->r;
    l->r=k;
    k->h=Max(height(k->l),height(k->r))+1;
    l->h=Max(height(l->l),k->h)+1;
    return l;
}

template<typename T>
node<T>* AVL<T>::SingRotateRight(node<T>* &k){
    node<T>* r=k->r;
    k->r=r->l;
    r->l=k;
    k->h=Max(height(k->r),height(k->l))+1;
    r->h=Max(height(r->r),k->h)+1;
    return r;
}

template<typename T>
node<T>* AVL<T>::DoubleRotateLR(node<T>* &k){
    k->l=SingRotateRight(k->l);
    return SingRotateLeft(k);
}

template<typename T>
node<T>* AVL<T>::DoubleRotateRL(node<T>* &k){
    k->r=SingRotateLeft(k->r);
    return SingRotateRight(k);
}

template<typename T>
void AVL<T>::rolate(node<T>* &n){
    if(height(n->l)-height(n->r)==2){
        if(height(n->l->r)>height(n->l->l))
            n=DoubleRotateLR(n);
        else{
            n=SingRotateLeft(n);
        }
    }
    else if(height(n->r)-height(n->l)==2){
        if(height(n->r->l)>height(n->r->r))
            n=DoubleRotateRL(n);
        else{
            n=SingRotateRight(n);
        }
    }
}

template<typename T>
void AVL<T>::Insert(node<T>* &n,T x){
    if(n==nullptr){
        n=new node<T>(x);
        return ;
    }
    if(x<n->data){
        Insert(n->l,x);
        rolate(n);
        n->h=Max(height(n->l),height(n->r))+1;
        return ;
    }
    else if(x>n->data){
        Insert(n->r,x);
        rolate(n);
        n->h=Max(height(n->l),height(n->r))+1;
        return ;
    }
}

template<typename T>
void AVL<T>::insert(T x){
    Insert(root,x);
}

template<typename T>
void AVL<T>::Delete(node<T>* &n,T x){
    if(n==nullptr){
        return ;
    }
    if(x<n->data){
        Delete(n->l,x);
        rolate(n);
    }
    else if(x>n->data){
        Delete(n->r,x);
        rolate(n);
    }
    else if(x==n->data){
        if(n->r && n->l){
            node<T>* tep=n->r;
            if(tep->l){
                while(tep->l && tep->l->l){
                    tep=tep->l;
                }
                T key=tep->l->data;
                tep=n;
                Delete(n,key);
                tep->data=key;
            }
            else{
                int key=tep->data;
                tep=n;
                Delete(n,key);
                tep->data=key;
            }
        }
        else if(n->r || n->l) {
            node<T>* tep=n->r?n->r:n->l;
            delete n;
            n=tep;
        }
        else{
            delete n;
            n=nullptr;
        }
    }
    if(n)
        n->h=Max(height(n->l),height(n->r))+1;
}

template<typename T>
void AVL<T>::del(T x){
    Delete(root,x);
}

template<typename T>
void AVL<T>::insubtree(node<T>* n){
    if(!n)      return ;
    insubtree(n->l);
    cout<<n->data<<endl;
    insubtree(n->r);
}

template<typename T>
void AVL<T>::Traversal(){
    insubtree(root);
}

int main(){
    AVL<int> tree;
    tree.insert(3);
    tree.insert(9);
    tree.insert(6);
    tree.insert(1);
    tree.insert(7);
    tree.insert(8);
    tree.Traversal();
    cout<<endl;
    tree.del(3);
    tree.del(6);
    tree.Traversal();
}

