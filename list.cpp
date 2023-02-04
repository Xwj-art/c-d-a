#include <iostream>
using namespace std;

struct node{
    int first;
    node* rest;
    node(int f,node* r)
    {
        first=f;
        rest=r;
    }
    int getsize()
    {
        if(rest==nullptr)
            return 1;
        return 1+rest->getsize();
    }
};
int main()
{
    node* p=new node(12,nullptr);
    p=new node(10,p);
    p=new node(8,p);
    cout<<p->getsize();
    return 0;
}
