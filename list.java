public class IntList{
    public int data;
    public IntList rest;
    public IntList(int d,IntList r){
        data=d;
        rest=r;
    }
    public int getsize(){
        if(rest==null)
            return 1;
        return 1+rest.getsize();
    }
    public static void main(String[] args){
        IntList L=new IntList(10,null);
        L=new IntList(5,L);
        L=new IntList(0,L);
        System.out.println(L.getsize());
    }
}
//#include <iostream>
//using namespace std;
//
//struct node{
//    int first;
//    node* rest;
//    node(int f,node* r)
//    {
//        first=f;
//        rest=r;
//    }
//    int getsize()
//    {
//        if(rest==nullptr)
//            return 1;
//        return 1+rest->getsize();
//    }
//};
//int main()
//{
//    node* p=new node(12,nullptr);
//    p=new node(10,p);
//    p=new node(8,p);
//    cout<<p->getsize();
//    return 0;
//}
