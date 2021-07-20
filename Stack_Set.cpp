// set of multiple stack with predefined capacity

#include<bits/stdc++.h>
using namespace std;

////////////////////DATA-STRUCTURE/////////////////////

class stack_set{
    stack<stack<int> > s;
    int capacity;
    public:
    stack_set(int x){
        capacity=x;
    }
    void push(int x){
        if(s.empty()){
            stack<int> temp;
            temp.push(x);
            s.push(temp);
            return;
        }
        if(s.top().size()==capacity){
            stack<int> temp;
            temp.push(x);
            s.push(temp);
        }
        else{
            s.top().push(x);
        }
    }
    int pop(){
        if(s.empty()){
            return -1;
        }
        int temp=s.top().top();
        s.top().pop();
        if(s.top().size()==0){
            s.pop();
        }
        return temp;
    }
};

////////////////////DATA-STRUCTURE/////////////////////

int main(){
    stack_set s(3);
    s.push(5);
    s.push(4);
    s.push(6);
    s.push(1);
    cout<<s.pop();
    s.push(2);
    s.push(10);
    cout<<s.pop();
}
