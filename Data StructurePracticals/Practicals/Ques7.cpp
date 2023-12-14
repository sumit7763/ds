#include<iostream>
using namespace std;

class Node{
    public:
    int elem;
    Node* next;
        Node(int x=0){
            elem=x;
            next=NULL;
        }
    friend class SinglyLinkedList;
    friend class StackList;
};
class SinglyLinkedList{
    protected:
    Node* head;
    Node* tail;
    int size;
    public:
        SinglyLinkedList(){
            size=0;
            head = tail = NULL;
        }
        ~SinglyLinkedList(){
            while (!empty()){ removeFront(); }
            delete head, tail;
        }
        const int & Front() const{
            return head->elem;
        }
        const int & Back() const{
            return tail->elem;
        }
        bool empty() const{
            return (head==NULL);
        }
        void addFront(int x);
        void addTail(int x);
        void removeFront();
        void removeBack();
        void display();
        int count(){
            return size;
        }
        friend class StackList;
};

void SinglyLinkedList::addFront(int x){
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

void SinglyLinkedList::addTail(int x){
    Node* newNode= new Node(x);
     if(head==NULL){
        head = tail= newNode;
    }
    else{
        tail->next= newNode;
        tail = newNode;
    }
    size++;
}

void SinglyLinkedList::removeFront(){
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

void SinglyLinkedList::removeBack(){
    if(empty()){ throw "List is already Empty!!";}
    Node* temp = head;
    if (head == tail){
        head = tail = NULL;
    }
    else{
        while (temp->next != tail){
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
        temp = temp->next;
    }
    delete temp;
    size--;
}

void SinglyLinkedList::display(){   
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



class StackList:private SinglyLinkedList{
    SinglyLinkedList s1;
    int size;
    int top;
    public:
        StackList();
        void push(int x);
        void pop();
        int topElem();
        bool empty();
        bool full();
        int count();
        void display();
};
StackList::StackList(){
    size=0;
    top=-1;
}
void StackList::push(int x){
    s1.addFront(x);
    size++;
}
void StackList::pop(){
    if(empty()) throw"Empty Stack can't pop element!";
    s1.removeFront();
    size--;
}
int StackList::topElem(){
    if(empty()) throw"Stack is empty";
    return s1.Front();
}
bool StackList::empty(){
    return s1.empty();
}

int StackList::count(){
    return s1.count();
}
void StackList::display(){
    s1.display();
}

int main(){
    try{
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
        
    }
    catch(const char* msg){
        cout << msg << endl;
    }
    return 0;
}