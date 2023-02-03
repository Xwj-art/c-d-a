#include <vector>
#include <iostream>
using namespace std;

// void bubble(vector<int>& v)
// {
//     for(int i=0;i=v.size()-1;i++)
// }
int main()
{
    vector<int> V;
    for(auto a:{1,2,3,4,5,6})
    {
        V.push_back(a);
    }
    cout<<V.size()<<V.capacity()<<endl;
    // bubble(V);
    return 0;
}
