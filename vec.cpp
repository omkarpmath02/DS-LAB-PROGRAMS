#include<iostream>
#include<vector>
#include<stack>

using namespace std;
int main(){
    stack<int> s;
    s.push(4);
    s.push(3);
    s.push(2);
    
while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    pair<int, pair<int,int>> act(3, make_pair(0,0));
}
