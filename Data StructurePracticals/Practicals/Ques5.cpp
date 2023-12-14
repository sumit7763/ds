#include<iostream>
using namespace std;

typedef string T;
class CNode{
    T elem;
    CNode*next;
    CNode(T x=0){
        elem=x;
        next=NULL;
    }
    friend class CircleList;
};

class CircleList{
    private:
        int size;
        CNode* cursor;
    public:
        CircleList(){
            size=0;
            cursor=NULL;
        }
        ~CircleList(){ 
            while(!empty()) remove();
        }
        bool empty() const{
            return cursor==NULL;
        }
        const T& Front() const{
            return cursor->next->elem;
        }
        const T& Back() const{
            return cursor->elem;
        }
        void advance(){
            cursor= cursor->next;
        }
        int count(){
            return size;
        }
        
        void add(const T &e);
        void addTail(const T& e);
        void remove();
        void removeTail();
        void insertElem(T x, T y);
        void removeElem(const T& value);
        void insertElem(T x, int pos);
        CNode* get(string value) const;
        void display();
        void concatenate(CircleList &obj);
};

void CircleList::add(const T &e){
    CNode* v= new CNode(e);
    if(empty()){
        v->next=v;
        cursor=v;
    }
    else{
        v->next=cursor->next;
        cursor->next=v;
    }
    size++;
}

void CircleList::addTail(const T& e){
    CNode* v= new CNode(e);
    if(empty()){
        v->next=v;
        cursor =v;
    }
    else{
        v->next=cursor->next;
        cursor->next=v;
        cursor=v;
    }
    size++;
}

void CircleList::remove(){
    if(empty()){ throw "Empty List";}
    CNode* old= cursor->next;
    if(old==cursor){
        cursor=NULL;
    } 
    else{
        cursor->next=old->next;
    }
    delete old;
    size--;
}

void CircleList::removeTail(){
    if(empty()){ throw "Empty List!!";}
    CNode* old= cursor->next;
    if(old==cursor){
        cursor=NULL;
    }
    else{
        while(old->next!=cursor){
            old=old->next;
        }
        cursor=old;
        old=cursor->next;
        cursor->next=old->next;
    }
    delete old;
    size--;
}

void CircleList::display(){
    if(cursor==NULL){cout<<"Empty List";}
    else{
        CNode* p= cursor->next;
        do{
            cout<<p->elem<<" ";
            p=p->next;
        }while(p!=cursor->next);
    }
    cout<<endl;
}

void CircleList::removeElem(const T& value){
    if(empty()) cout<< "Empty List!! does not delete ";
    CNode* cur_pointer = cursor->next;
    CNode* prev = cursor;

    while (cur_pointer != cursor && cur_pointer->elem != value){
        prev = cur_pointer;
        cur_pointer = cur_pointer->next;
    }
    if (cur_pointer->elem == value && cur_pointer != cursor){
        prev->next = cur_pointer->next;
        delete cur_pointer;
    }
    else if (cur_pointer == cursor && cur_pointer->elem == value){
        cursor = prev;
        prev->next = cur_pointer->next;
        delete cur_pointer;
    }
    else{
        throw "Value does not exist";
    }
    size--;
}

void CircleList::concatenate(CircleList &obj){
    if(obj.empty() && empty()) return;
    else if (obj.empty()) return;
    else if(empty()){
        cursor= obj.cursor;
    }
    else{
        CNode* temp = obj.cursor->next;
        obj.cursor->next = cursor->next;
        cursor->next = temp;
        cursor = obj.cursor;
    }
    this->size = this->size + obj.size;
    obj.cursor=NULL;
    obj.size = 0;
}








CNode* CircleList::get(string value) const{
    CNode* temp = cursor->next;
    while (temp != cursor){
        if (temp->elem == value){
            return temp;
        }
        temp = temp->next;
    }
    if (temp->elem == value){
        return temp;
    }
    // throw "element not found";
}

void CircleList:: insertElem(T x,T y){
    if(empty())throw "Empty list";
    CNode* temp= cursor->next;
    CNode* p=NULL;
    while(temp!= cursor && temp->elem!=y){
        temp= temp->next;
    }
    if(temp->elem!=y)throw "Element not found";
    p= temp;
    CNode* newY= p->next;
    newY->elem= x;
    p->next= newY;
    size++;
}







int main(){
    try{
        cout<<"List l1: ";
        CircleList l1;
        l1.add("8");
        l1.add("7");
        l1.add("6");
        l1.add("5");
        l1.add("4");
        l1.display();

        cout<<"(i) Insert an element (3) at the front: ";
        l1.add("3");
        l1.display();

        cout<<"(ii) Insert an element 19 after an element 5: ";
        l1.insertElem("19","4");
        l1.display();

        cout<<"(iii)Insert an element (9) at the back: "; 
        l1.addTail("9");
        l1.display();

        cout<<"(iv) Remove an element (9) from the back: ";
        l1.removeTail();
        l1.display();

        cout<<"(v) Remove an element (3) from the front: ";
        l1.remove();
        l1.display();

        cout<<"(vi) Remove the element (8):  ";
        l1.removeElem("8");
        l1.display();

        cout<<"(vii)Search an element 6 and return its pointer: ";
        cout<<l1.get("6")<<endl;
        cout<<l1.get("7")<<endl;
        cout<<l1.get("8")<<endl;


        cout<<"List l2: ";
        CircleList l2;
        l2.add("13");
        l2.add("12");
        l2.add("11");
        l2.add("10");
        l2.add("9");
        l2.display();
        cout<<"(viii) Concatenate two circularly linked lists: ";
        l1.concatenate(l2);
        l1.display();
        cout<<"l2 become: "; l2.display();
        cout<<"l1 become: "; l1.display();
        cout<<"size of l1: "<<l1.count()<<endl;
        cout<<"size of l2: "<<l2.count()<<endl;

        // cout<<"Back: "<<l1.Back()<<endl;
        // cout<<"Front: "<<l1.Front()<<endl;

        // cout<<"Advanced: ";
        // l1.advance();//cursor= cursor->next//Front become Back
        // l1.display();
        
    } catch(const char* msg){
        cout << "Exception occurred : " << msg << endl;
    }
    return 0;
}