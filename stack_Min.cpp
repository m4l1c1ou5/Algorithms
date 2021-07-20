//stack implementation with a unique feature of providing minimum element present in the stack in O(1) time.
#include<bits/stdc++.h>
using namespace std;

////////////////////////DATA-STRUCTURE//////////////////////////////

class stack_min{
    stack<pair<int,int> > s;
    int min=1000000000;
    public:
    void push(int k){
        s.push(make_pair(k,min));
        if(min>k){
            min=k;
        }
    }
    int pop(){
        pair<int,int> p=s.top();
        min=p.second;
        s.pop();
    }
    int get_min(){
        return min;
    }
};

////////////////////////DATA-STRUCTURE//////////////////////////////

int main(){
    stack_min s;
    s.push(5);
    s.push(4);
    s.push(6);
    s.push(1);
    cout<<s.get_min();
    s.pop();
    cout<<s.get_min();
    s.push(2);
    cout<<s.get_min();
    s.push(10);
    cout<<s.get_min();
}
