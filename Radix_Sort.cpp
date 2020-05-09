#include<iostream>
#include<math.h>
using namespace std;
struct node{
    int key;
    node *next;
};
node* newnode(int k){
    node *n=new node;
    n->key=k;
    n->next=NULL;
    return n;
}
node* insert(node *head,int k){
    while(head->next!=NULL){
        head=head->next;
    }
    head->next=newnode(k);
    return head->next;
}
node* insert_first(int k){
    return newnode(k);
}
node* counting_sort(node *head,int exp){
    int k=10;
    node *arr[k];
    node *temp=new node;
    node *temp1=new node;
    int n;
    for(int i=0;i<k;i++)
        arr[i]=NULL;
    while(head!=NULL){
        temp=head;
        temp1=head->next;
        n=head->key/pow(10,exp);
        n=n%10;
        temp->next=arr[n];
        //cout<<head->next;
        arr[n]=temp;
        
        head=temp1;
        
    }
    int flag=1;
    for(int i=0;i<k;i++){
        if(arr[i]!=NULL){
            if(flag==0){
                temp=insert(temp,arr[i]->key);
                while(arr[i]->next!=NULL){
                    temp=insert(temp,arr[i]->next->key);
                    arr[i]=arr[i]->next;
                }
            }
            if(flag==1){
                head=insert_first(arr[i]->key);
                temp=head;
                while(arr[i]->next!=NULL){
                    temp=insert(temp,arr[i]->next->key);
                    arr[i]=arr[i]->next;
                }
                flag=0;
            }
        }
    }
    return head;
}
node* radix_sort(node *head,int exp){
    for(int i=0;i<=exp;i++){
        head=counting_sort(head,i);
        head=counting_sort(head,i);
    }
    return head;
}
int main(){
    int k=10,n=10;
    int a[]={123,843,513,465,934,990,898,991,990,92};
    node *temp=new node;
    node *head=NULL;
    int max=-20000,count=0;
    head=insert_first(a[0]);
    for(int i=1;i<10;i++){
        insert(head,a[i]);
        if(max<a[i])
            max=a[i];   
    }
    while(max/10>0){
        max=max/10;
        count++;
    }
    head=radix_sort(head,count);
    /*head=counting_sort(head,0);
    head=counting_sort(head,1);

    head=counting_sort(head,1);*/
    temp=head;
    while(temp!=NULL){
        cout<<temp->key<<" ";
        temp=temp->next;
    }
}