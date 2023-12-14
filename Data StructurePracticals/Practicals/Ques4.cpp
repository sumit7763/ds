#include<iostream>
using namespace std;
// template <typename T>
class DNode{
    private:
        int elem; 
        DNode* prev; 
        DNode* next; 
    public:
        DNode(int x=0){
            elem=x;
            prev=NULL;
            next=NULL;
        }
    friend class DoublyLinkedList;
};

// template <typename T>
class DoublyLinkedList{
    private:
        DNode* header;
        DNode* trailer;
        int size=0;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        bool empty() const{
            return header->next==trailer;
        }
        const int& Front(){
            if(empty())throw "List is empty";
            return header->next->elem;
        }
        const int& Back(){
            if(empty())throw "List is empty";
            return trailer->prev->elem;
        }
        void addFront(const int& e);
        void addBack(const int& e);
        void removeFront();
        void removeBack();
        void insert(int pos, int val);
        void concatenate(DoublyLinkedList &obj);
        DNode *get(int value) const;
        void remove(int pos);
        void display();
        int count(){  return size;}
    protected:
        void removep(int x);
};

DoublyLinkedList::DoublyLinkedList(){
    size=0;
    header= new DNode;
    trailer=new DNode;
    header->next= trailer;
    trailer->prev=header;
}

DoublyLinkedList::~DoublyLinkedList(){
    while (empty()){ 
        removeFront();
    }
    delete header;
    delete trailer;
}

void DoublyLinkedList::addFront(const int& e) { 
    DNode* newNode=new DNode;
    newNode->elem= e;
    newNode->prev= header;
    newNode->next= header->next;
    header->next->prev= newNode;
    header->next= newNode;
    size++;
}

void DoublyLinkedList::addBack(const int& e){
    DNode* newNode=new DNode;
    newNode->elem= e;
    newNode->prev= trailer->prev;
    newNode->next= trailer;
    trailer->prev->next= newNode;
    trailer->prev=newNode;
    size++;
}

void DoublyLinkedList::removeFront(){
    if(empty())throw "List is empty";
    DNode* p=header->next;
    header->next= p->next;
    p->next->prev=header;
    delete p;
    size--;
}

void DoublyLinkedList::removeBack(){
    if(empty())throw "List is empty";
    DNode* p=trailer->prev;
    trailer->prev=p->prev;
    p->prev->next=trailer;
    delete p;
    size--;
}

void DoublyLinkedList::display(){
    // if(empty()){
    //     cout<<"Empty List";
    // }
    // else{
        DNode * pt= header->next;
        while(pt!=trailer){
            cout<<pt->elem<<" ";
            pt= pt->next;
        }
    // }
    cout<<endl;
}

void DoublyLinkedList::concatenate(DoublyLinkedList &obj){
    if(obj.empty() && empty()) return;
    else if (obj.empty()) return;
    else if(empty()){
        header= obj.header;
        trailer= obj.trailer;
    }
    else{
        trailer->next = obj.header;
        trailer = obj.trailer;
    }
    this->size = this->size + obj.size;
    obj.header=obj.trailer=NULL;
    obj.size = 0;
}

DNode* DoublyLinkedList::get(int x) const{
    DNode* ptr=header->next;
    while(ptr!=trailer){
        if(ptr->elem==x){
            cout<<ptr;
        }
        ptr=ptr->next;
    }
    return NULL;
}

void DoublyLinkedList::insert(int pos,int x){
        if (pos < 1|| pos-1 > size){ throw "Invalid Position";}
        DNode* ptr=header;
        int counter=0;
        while((ptr!=trailer)&&(counter<pos-1)){
            ptr=ptr->next;
            counter++;
        }
        DNode* newnode=new DNode;
        newnode->elem=x;
        newnode->next=ptr->next;
        newnode->prev=ptr;
        ptr->next->prev=newnode;
        ptr->next=newnode;
}

void DoublyLinkedList::remove(int pos){
            if (empty()) {throw "Can't delete in Empty List!";}
            if (pos<1||pos > size){ throw "Invalid postion";}
            else if (pos == 1) removeFront();
            else if (pos == size) removeBack();
            else{
                DNode* ptr=header->next;
            int counter=0;
            while((ptr!=trailer)&&(pos<counter)){
                ptr=ptr->next;
                counter++;
            }
            ptr=ptr->next;
            DNode* old=ptr->next;
            ptr->next=old->next;
            old->next->prev=ptr;
            delete old;
                // DNode* temp= header;
                // DNode* t= NULL;
                // int cur_pointer = 1;
                // while(cur_pointer < pos){
                //     t = temp;
                //     temp = temp->next;
                //     cur_pointer++;
                // }
                // t->next = temp->next;
                // delete temp;
                // size--;
            }
        }


int main(){
    try{
        cout<<"L1 is: ";
        DoublyLinkedList l1;
        l1.addFront(7);
        l1.addFront(6);
        l1.addFront(5);
        l1.addFront(4);
        l1.display();
    
        cout<<"(i) Insert an element 3 at Head: ";
        l1.addFront(3);
        l1.display();

        cout<<"(ii) Insert an element x at 4th position: ";
        l1.insert(4,10);
        l1.display();

        cout<<"(iii)Insert an element 8 at Tail: ";
        l1.addBack(8);
        l1.display();

        cout<<"(iv) Remove an element from Head: ";
        l1.removeFront();
        l1.display();

        cout<<"(vi) Remove an element from Tail: ";
        l1.removeBack();
        l1.display(); 

        cout<<"Front: "<<l1.Front()<<endl;
        cout<<"Back : "<<l1.Back()<<endl;

        cout<<"(v) Remove an element from position3: "; 
        l1.remove(3);
        l1.display();
        
        
        cout<<"(vii) Search 5 and return its pointer: "<<l1.get(5)<<endl;
        cout<<"      Search 6 and return its pointer: "<<l1.get(6)<<endl;

        cout<<"L2 is: ";
        DoublyLinkedList l2;
        l2.addFront(13);
        l2.addFront(12);
        l2.addFront(11);
        l2.addFront(10);
        l2.addFront(9);
        l2.display();
        cout<<"(viii)After Concatenate l1 is: ";
        l1.concatenate(l2);
        l1.display();
        cout<<"After Concatenate l2 is: ";
        l2.display();
        cout<<"size of l1: "<<l1.count()<<endl;
        cout<<"size of l2: "<<l2.count()<<endl;

    }
    catch(const char* msg){
        cout<<msg<<endl;
    }
    return 0;
}