#include<iostream>
using namespace std;
class Stack{
    int size;
    int top,x;
    int* array;
    public:
        Stack(int size=10){
            this->size=size;
            array=new int[size];
            top=-1;
        }
        void push(int x);
        void pop();
        int topElem();
        bool empty();
        bool Full();
        int count();
        void display();
};
void Stack:: push(int x){
    if(top==size-1) throw "Overflow";
    else{
        top++;
        array[top]=x;
    }
}
void Stack:: pop(){
    if(top==-1)throw "UnderFlow";
    x=array[top];
    top--;
    // return x;
}
int Stack:: topElem(){
    if(top==-1)throw "UnderFlow";
    else
        return array[top];
}
bool Stack:: empty(){
    return top==-1;
}
bool Stack:: Full(){
    return top==size-1;
}
int Stack:: count(){
    return top+1;
}
void Stack:: display(){
    if(empty()){
        cout<<"Stack is empty";
    }
    else{
        for(int i=0; i<=top;i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    try{
        cout<<"Stack s1: ";
        Stack s1;
        s1.push(7);
        s1.push(6);
        s1.push(5);
        s1.push(4);
        s1.push(3);
        s1.pop();
        s1.pop();
        s1.pop();
        s1.display();
        cout<<"Top element: "<<s1.topElem()<<endl;
        cout<<"Size: "<<s1.count()<<endl;
        cout<<"Is Empty: "<<s1.empty()<<endl;
        cout<<"Is FULL: "<<s1.Full()<<endl;

    }
    catch(const char* msg){
        cout<<msg<<endl;
    }
    return 0;
}