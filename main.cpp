#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x, Node* n){
        data=x;
        next=n;
    }
};

class Queue{
public:
    Node* top;
    Node* bottom;
    int size;

    Queue(){
       top=NULL;
       bottom=NULL;
       size=0;
    }

    void push(int x) {
        Node *temp = new Node(x, NULL);
        if(bottom==NULL){
            top = bottom = temp;
            size+=1;
            return;
        }

        bottom->next=temp;
        bottom=temp;
        size+=1;
    }

    int pop(){
        if(top==NULL){
            return 0;
        }

        Node* temp = top;
        top = top->next;
        size-=1;
        if(top == NULL)
            bottom=NULL;

        return temp->data;
    }

    void peek(){
        if(top==NULL){
            return;
        }
        cout<< top->data<<endl;
        while (top->next != NULL){
            top = top->next;
            cout<<top->data<<endl;
        }
    }

    bool isEmpty(){
        return (top == NULL);
    }

    int sizeofQ(){
        return size;
    }

};

int main() {
    Queue q;
    q.push(5);
    q.push(6);
    q.push(1);
    q.push(3);
    q.push(6);
    q.push(2);
    q.push(4);

    q.peek();

    if (q.isEmpty()){
        cout<<"is empty"<<endl;
    }
    else
        cout<<"full of bullshit"<<endl;

    cout << q.sizeofQ()<<endl;

    return 0;
}


