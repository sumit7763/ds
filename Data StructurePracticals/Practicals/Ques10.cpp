#include<iostream>
using namespace std;

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
    friend class DoubleEndedQueue;
};

class DoublyLinkedList{
    private:
        DNode* header;
        DNode* trailer;
        int size=0;
    public:
        DoublyLinkedList(){
            size=0;
            header= new DNode;
            trailer=new DNode;
            header->next= trailer;
            trailer->prev=header;
        }
        ~DoublyLinkedList(){
            while (empty()){ 
                removeFront();
            }
            delete header;
            delete trailer;
        }
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
        void addFront(const int& e){
            DNode* newNode=new DNode;
            newNode->elem= e;
            newNode->prev= header;
            newNode->next= header->next;
            header->next->prev= newNode;
            header->next= newNode;
            size++;
        }
        void addBack(const int& e){
            DNode* newNode=new DNode;
            newNode->elem= e;
            newNode->prev= trailer->prev;
            newNode->next= trailer;
            trailer->prev->next= newNode;
            trailer->prev=newNode;
            size++;
        }
        void removeFront(){
            if(empty())throw "List is empty";
            DNode* p=header->next;
            header->next= p->next;
            p->next->prev=header;
            delete p;
            size--;
        }
        void removeBack(){
            if(empty())throw "List is empty";
            DNode* p=trailer->prev;
            trailer->prev=p->prev;
            p->prev->next=trailer;
            delete p;
            size--;
        }
        void display(){
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
        int count(){  return size;}
    friend class DoubleEndedQueue;
};

class DoubleEndedQueue{
    private:
        DoublyLinkedList D;
        int n;
    public: 
        DoubleEndedQueue():D(),n(0){}
        int size() const{
            return n;
        }
        bool empty() const{
            return n==0;
        }
        const int& front() const;
        const int& back() const;
        void insertFront(const int& e){
            D.addFront(e);
            n++;
        }
        void insertBack(const int& e){
            D.addBack(e);
            n++;
        }
        void removeFront(){
            if(empty()) throw "Queue is Empty";
            D.removeFront();
            n--;
        }
        void removeBack(){
            if(empty()) throw "Queue is Empty";
            D.removeBack();
            n--;
        }
        void display(){
            D.display();
        }
};


int main(){
    try{
       DoubleEndedQueue l1;
       l1.insertFront(8);
       l1.display();
       l1.insertFront(7);
       l1.display();
       l1.insertFront(6);
       l1.display();
       l1.insertFront(5);
       l1.display();
       l1.insertFront(4);
       l1.display();
       l1.insertFront(3);
       l1.display();
       l1.insertBack(9);
       l1.display();

       cout<<"Remove Front: ";
       l1.removeFront();
       l1.display();
       cout<<"Remove back: ";
       l1.removeBack();
       l1.display();
       cout<<"Size: "<<l1.size()<<endl;
       cout<<"Empty: "<<l1.empty()<<endl;
    //    cout<<"Front: "<<l1.front()<<endl;
    //    cout<<"Back: "<<l1.back()<<endl;


       

    }
    catch(const char* msg){
        cout<<msg<<endl;
    }
    return 0;
}
