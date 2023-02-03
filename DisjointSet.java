public class DisjointSet{
    static private int[] t;
    public DisjointSet(int num){
        t=new int[num];
        for(int i=0;i<num;i++){
            t[i]=-1;
        }
    }
    //返回a所在树的大小
    public int value(int a){
        if(t[a]>0){
            return value(t[a]);
        }
        else{
            return -t[a];
        }
    }
    //返回头节点数值
    public int find(int a){
        if(t[a]>0){
            return t[a]=find(t[a]);//将所有节点指向头节点，路径压缩
        }
        return a;
    }
    //合并树
    public void connect(int a,int b){
        int a1=find(a);
        int b1=find(b);
        if(a1==b1)  return ;
        if(t[a1]<t[b1]){
            t[a1]+=t[b1];
            t[b1]=t[a1];
        }
        else{
            t[b1]+=t[a1];
            t[a1]=t[b1];
        }
    }
    public static void main(String[] args){
        DisjointSet D=new DisjointSet(6);
        D.connect(1,3);
        System.out.println(D.find(1));
        System.out.println(D.value(1));
        D.connect(1,5);
        System.out.println(D.find(1));
        System.out.println(D.value(1));
    }
}
//#include <iostream>
//#include <vector>
//using namespace std;
//class DisjointSet{
//    private:
//        vector<int> v;
//    public :
//        DisjointSet(int num){
//            while(num--)
//                v.push_back(-1);
//        }
//        int _find(int x){//根节点
//            if(v[x]>=0){
//                return v[x]=_find(v[x]);
//            }
//            else{
//                return x;
//            }
//        }
//        //大小
//        int _value(int x){
//            x=_find(x);
//            return -v[x];
//        }
//        void _connect(int a,int b){
//            int a1=_find(a);
//            int b1=_find(b);
//            if(a1==b1) return ;
//            if(v[a1]<v[b1]){
//                v[a1]+=v[b1];
//                v[b1]=v[a1];
//            }
//            else{
//                v[b1]+=v[a1];
//                v[a1]=v[b1];
//            }
//        }
//};
//int main(){
//    DisjointSet D(3);
//    D._connect(1,2);
//    D._connect(1,0);
//    cout<<D._find(1)<<endl;
//    cout<<D._value(1);
//}
