public class sllist{

    private static class IntNode{
        public int data;
        public IntNode next;
        public IntNode(int d,IntNode n){
            data=d;
            next=n;
        }
    }

    private IntNode first;
    private int _size;
    public sllist(int x){
        first=new IntNode(x,null);
        ++_size;
    }
    public void AddNode(int ad){
        first=new IntNode(ad,first);
        ++_size;
    }
    public int getsize(){
        return _size;
    }

    public static class List{
        public class Node{
            public int data;
            public Node front;
            public Node back;
            public Node(int d,Node f,Node b){
                data=d;
                front=f;
                back=b;
            }
        }
        private Node head,tail;
        private int size;
        public List(int d){
            head=new Node(d,null,null);
            tail=new Node(d,null,null);
            size=1;
        }
        public void AddF(int d){
            head.front=new Node(d,null,head);
            head=head.front;
            size++;
        }
        public void AddB(int d){
            tail.back=new Node(d,tail,null);
            tail=tail.back;
            size++;
        }
        public int getsize(){
            return size;
        }
        public void Forder(){
            int tep=size;
            Node t=new Node(head.data,head.front,head.back);
            while(tep>0){
                tep--;
                System.out.println(t.data);
                t=t.back;
            }
        }
    }
    public static void main(String[] args){
        sllist sl=new sllist(5);
        sl.AddNode(10);
        System.out.println(sl.getsize());
        List L=new List(3);
        L.AddF(2);
        L.AddF(1);
        L.Forder();
    }
}

//#include <iostream>
//using namespace std;
//struct node{
//    int data;
//    node* next;
//    node(int d,node* n)
//    {
//        data=d;
//        next=n;
//    }
//};
//struct List{
//    List(int d)
//    {
//        first=new node(d,nullptr);
//        _size=1;
//    }
//    void AddNode(int ad)
//    {
//        first=new node(ad,first);
//        ++_size;
//    }
//    int getsize()
//    {
//        return _size;
//    }
//
//    ~List()
//    {
//        for(int i=0;i<_size;i++)
//        {
//            node* tep=first->next;
//            delete first;
//            first=tep;
//        }
//    }
//    private:
//    node* first;
//    int _size;
//};
//struct Node{
//    Node *front,*back;
//    int data;
//    Node(int d,Node* f,Node* b)
//    {
//        data=d;
//        front=f;
//        back=b;
//    }
//};
//struct List2{
//    List2(int d)
//    {
//        head=new Node(d,nullptr,nullptr);
//        tail=head;
//        _size=1;
//    }
//    void AddFront(int d)
//    {
//        head->front=new Node(d,nullptr,head);
//        head=head->front;
//        ++_size;
//    }
//    void AddBack(int d)
//    {
//        tail->back=new Node(d,tail,nullptr);
//        tail=tail->back;
//        ++_size;
//    }
//    int getsize()
//    {
//        return _size;
//    }
//    void Forder()
//    {
//        int tep=_size;
//        Node* t=this->head;
//        while(tep--)
//        {
//            cout<<t->data<<endl;
//            t=t->back;
//        }
//    }
//    void Rorder()
//    {
//        int tep=_size;
//        Node* t=this->tail;
//        while(tep--)
//        {
//            cout<<t->data<<endl;
//            t=t->front;
//        }
//    }
//    ~List2()
//    {
//        while(_size--)
//        {
//            Node* tep=head->back;
//            delete head;
//            head=tep;
//        }
//    }
//    private:
//    Node* head,*tail;
//    int _size;
//};
//int main()
//{
//    List L(5);
//    L.AddNode(10);
//    L.AddNode(15);
//    List2 L2(3);
//    L2.AddFront(2);
//    L2.AddFront(1);
//    L2.Rorder();
//}
