#include<iostream>
using namespace std;
class Node{
    int elem;
    Node* next;
    public:
        Node(int x=0){
            this->elem=x;
            next=NULL;
        }
    friend class StackList;
};

class StackList{
    int top;
    Node* head;
    Node* tail;
    int size;
    public:
        StackList(){
            top=-1;
            size=0;
            head=tail= NULL;
        }
        ~StackList(){
            while(!empty()){
                pop();
            }
            delete head, tail;
        }
        const int & topElem() const{
            return head->elem;
        }
        const int & Back() const{
            return tail->elem;
        }
        bool empty() const{
            return (head==NULL);
        }
        void push(int x);
        // void addTail(int x);
        void pop();
        // void removeBack();
        void display();
        int count(){
            return size;
        }
};


void StackList::push(int x){
    Node* newNode=new Node(x);
    if(empty()){
        head= tail= newNode;
    }
    else{
        newNode->next=head;
        head= newNode;
    }
    size++; 
}
void StackList::pop(){
    if(empty()){ throw"List is Empty";}
    Node* temp = head;
    if(head==tail){
        head=tail=NULL;
    }
    else{
        head = head->next;
    }
    delete temp;
    size--;
}

void StackList::display(){   
    // if(head==NULL){
    //     cout<<"Empty List";
    // }
    // else{
        Node* ptr=head;
        while(ptr!=NULL){
            cout<<ptr->elem<<" ";
            ptr=ptr->next;
        }cout<<"NULL";
    //}
    cout<<endl; 
}

int main(){
    StackList s;
        s.push(9);
        s.push(8);
        s.push(7);
        s.push(6);
        s.push(5);
        s.push(4);
        s.push(3);
        s.display();
        s.pop();
        s.pop();
        s.display();
        s.pop();
        s.display();
        cout<<"Size is: "<<s.count()<<endl;
        cout<<"Top Element: "<<s.topElem()<<endl;
        cout<<"is empty: "<<s.empty()<<endl;
        //cout<<"is full: "<<s.full()<<endl;
        
    return 0;
}