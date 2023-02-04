#include <iostream>
#include <vector>
using namespace std;
class DisjointSet{
    private:
        vector<int> v;
    public :
        DisjointSet(int num){
            while(num--)
                v.push_back(-1);
        }
        int _find(int x){//根节点
            if(v[x]>=0){
                return v[x]=_find(v[x]);
            }
            else{
                return x;
            }
        }
        //大小
        int _value(int x){
            x=_find(x);
            return -v[x];
        }
        void _connect(int a,int b){
            int a1=_find(a);
            int b1=_find(b);
            if(a1==b1) return ;
            if(v[a1]<v[b1]){
                v[a1]+=v[b1];
                v[b1]=v[a1];
            }
            else{
                v[b1]+=v[a1];
                v[a1]=v[b1];
            }
        }
};
int main(){
    DisjointSet D(3);
    D._connect(1,2);
    D._connect(1,0);
    cout<<D._find(1)<<endl;
    cout<<D._value(1);
}
