#include<iostream>
using namespace std;

class Node{
    int elem;
    Node* next;
    public:
        Node(int x=0){
            elem=x;
            next=NULL;
        }
    friend class SinglyLinkedList;
};
class SinglyLinkedList{
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
        void addFront(int x){
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
        void addTail(int x){
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
        void removeFront(){
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

        void removeBack(){
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
        void insert(int x, int pos){
            if (pos < 1|| pos-1 > size){ throw "Invalid Position";}

            if (pos == 1) addFront(x);
            else if (pos - 1 == size) addTail(x);
            else {
                Node* temp = head;
                Node* ins = new Node(x);
                int cur_pointer = 1;
                while (cur_pointer < pos-1){
                    temp = temp->next;
                    cur_pointer++;
                }
                ins->next = temp->next;
                temp->next = ins;
                size++;
            }
        }

        void concate(SinglyLinkedList &obj){
            if(obj.empty() && empty()) return;
            else if (obj.empty()) return;
            else if(empty()){
                head= obj.head;
                tail= obj.tail;
            }
            else{
                tail->next = obj.head;
                tail = obj.tail;
                this->size = this->size + obj.size;
            }
            obj.head=obj.tail=NULL;
            obj.size = 0;
        }

        void remove(int pos){
            if (empty()) {throw "Can't delete in Empty List!";}
            if (pos<1||pos > size){ throw "Invalid postion";}
            else if (pos == 1) removeFront();
            else if (pos == size) removeBack();
            else {
                Node* temp= head;
                Node* t= NULL;
                int cur_pointer = 1;
                while(cur_pointer < pos){
                    t = temp;
                    temp = temp->next;
                    cur_pointer++;
                }
                t->next = temp->next;
                delete temp;
                size--;
            }
        }

        void removeValue(int value){
            if(head==0) throw "Empty List, Deletion not Possible";
            Node* ptr=head;
            Node* prev=NULL;
            if (ptr->elem == value){  //For 1st Position
                head = head->next;
            }
            while(ptr !=NULL && ptr->elem!= value){
                prev=ptr;
                ptr=ptr->next;
            }
            if(ptr==NULL) throw "Invalid Value";
            //if(ptr->elem!=value) throw "Value Not Found";
            else{
                prev->next= ptr->next;
            }
            delete ptr;
            size--;
        }

        Node *get(int value) const{
            Node *temp = head;
            while (temp != NULL){
                if (temp->elem == value){
                    //cout<< temp->elem<<endl;
                    return temp;
                }
                temp = temp->next;
            }
            throw "element not found";
        }

        void display(){   
            // if(head==NULL){
            //     cout<<"Empty List";
            // }
            // else{
                Node* ptr=head;
                while(ptr!=NULL){
                    cout<<ptr->elem<<"->";
                    ptr=ptr->next;
                }cout<<"NULL";
            //}
            cout<<endl; 
        }
        int count(){
            return size;
        }
};

int main(){
    try{    
        cout<<" LinkedList l1 is: ";
	    SinglyLinkedList l1;
        l1.addFront(8);
	    l1.addFront(7);
	    l1.addFront(6);
	    l1.addFront(5);
	    l1.addFront(4);
	    l1.display();
        cout<<"(i) After adding 3 at Front is: "<<endl;
        l1.addFront(3);
        l1.display();

        cout<<"(ii) Insert an element at ith(4th) position "<<endl;
        l1.insert(10,4);
        l1.display();

        cout<<"(iii) Remove an element from Head(Front) "<<endl;
        l1.removeFront();
        l1.display();

        cout<<"(iv) Remove an element at ith(3rd) position "<<endl;
        l1.remove(3);
        l1.display();

        cout<<"(v) Search an element and return its pointer "<<endl;
        cout<<l1.get(5)<<endl<<endl;

        cout<<" Linkedlist l2 is: ";
        SinglyLinkedList l2;
        l2.addFront(13);
        l2.addFront(12);
        l2.addFront(11);
        l2.addFront(10);
        l2.addFront(9);
        l2.display();

        cout<<"(vi) After Concatenation of l2 in l1 "<<endl;
        l1.concate(l2);
        l1.display();
        cout<<"After concatenate l2 is: ";
        l2.display();
        cout<<"Size of l1: "<<l1.count()<<endl;



    }
    catch(const char* msg){
        cout << msg << endl;
    }
    return 0;
}