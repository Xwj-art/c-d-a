#include <iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int d,node* n)
    {
        data=d;
        next=n;
    }
};
struct List{
    List(int d)
    {
        first=new node(d,nullptr);
        _size=1;
    }
    void AddNode(int ad)
    {
        first=new node(ad,first);
        ++_size;
    }
    int getsize()
    {
        return _size;
    }

    ~List()
    {
        for(int i=0;i<_size;i++)
        {
            node* tep=first->next;
            delete first;
            first=tep;
        }
    }
    private:
    node* first;
    int _size;
};
struct Node{
    Node *front,*back;
    int data;
    Node(int d,Node* f,Node* b)
    {
        data=d;
        front=f;
        back=b;
    }
};
struct List2{
    List2(int d)
    {
        head=new Node(d,nullptr,nullptr);
        tail=head;
        _size=1;
    }
    void AddFront(int d)
    {
        head->front=new Node(d,nullptr,head);
        head=head->front;
        ++_size;
    }
    void AddBack(int d)
    {
        tail->back=new Node(d,tail,nullptr);
        tail=tail->back;
        ++_size;
    }
    int getsize()
    {
        return _size;
    }
    void Forder()
    {
        int tep=_size;
        Node* t=this->head;
        while(tep--)
        {
            cout<<t->data<<endl;
            t=t->back;
        }
    }
    void Rorder()
    {
        int tep=_size;
        Node* t=this->tail;
        while(tep--)
        {
            cout<<t->data<<endl;
            t=t->front;
        }
    }
    ~List2()
    {
        while(_size--)
        {
            Node* tep=head->back;
            delete head;
            head=tep;
        }
    }
    private:
    Node* head,*tail;
    int _size;
};
int main()
{
    List L(5);
    L.AddNode(10);
    L.AddNode(15);
    List2 L2(3);
    L2.AddFront(2);
    L2.AddFront(1);
    L2.Rorder();
}
