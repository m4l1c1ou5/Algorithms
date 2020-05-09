#include<iostream>
using namespace std;
struct node{
    int key;
    node *next;
};
node* newnode(int k){
    node *head=new node;
    head->key=k;
    head->next=NULL;
    return head;
}
int hashing(int k){
    return k%10;
}
void insert(node *arr[],int key){
    node *temp=newnode(key);
    temp->next=arr[hashing(key)];
    arr[hashing(key)]=temp;
}
bool find(node *arr[],int key){
    node *temp=new node;
    temp=arr[hashing(key)];
    while(temp!=NULL){
        if(temp->key==key)
            return true;
        temp=temp->next;
    }
    return false;
}
node* del_node(node *head,int key){
    if(head==NULL){
        cout<<" #{not found} ";
        return NULL;
    }
    if(head->key==key){
        return head->next;
    }
    head->next=del_node(head->next,key);
    return head;
} 
void delete_node(node *arr[],int key){
    arr[hashing(key)]=del_node(arr[hashing(key)],key);
}
int main(){
    node *arr[10];
    for(int i=0;i<10;i++)
        arr[i]=NULL;
    insert(arr,5);
    insert(arr,15);
    insert(arr,25);
    delete_node(arr,15);
    delete_node(arr,10);
    cout<<arr[5]->key<<" ";
    cout<<arr[5]->next->key<<" ";
}