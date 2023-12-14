#include<iostream>
using namespace std;

class CNode{
    int elem;
    CNode*next;
    CNode(int x=0){
        this->elem=x;
        next=NULL;
    }
    friend class CircleList;
    friend class CircularListQueue;
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
        const int& Front() const{
            return cursor->next->elem;
        }
        const int& Back() const{
            return cursor->elem;
        }
        void advance(){
            cursor= cursor->next;
        }
        int count(){
            return size;
        }
        
        void add(const int &e){
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
        void addTail(const int& e){
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
        void remove(){
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
        void removeTail(){
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
        void display(){
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
    friend class CircularListQueue;
};



class CircularListQueue{
    private:
        CircleList C;
        int n;
    public:
        CircularListQueue():C(), n(0){}
        int size() const{
            return n;
        }
        bool empty() const{
            return n==0;
        }
        const int& front() const{
            if(empty())throw "Empty Queue";
            return C.Front();
        }
        void enqueue(const int& e){
            C.add(e);
            C.advance();
            // C.cursor=C.cursor->next;// same as C.advance();
            n++;
        }
        void dequeue(){
            if(empty()) throw "Queue is Empty";
            C.remove();
            n--;
        }
        void display(){
            C.display();
        }
};
// CircularListQueue::CircularListQueue(): C(), n(0){}

int main(){
    try{
        CircularListQueue l1;
        l1.enqueue(8);
        l1.display();
        l1.enqueue(7);
        l1.display();
        l1.enqueue(6);
        l1.display();
        l1.enqueue(5);
        l1.display();
        l1.enqueue(4);
        l1.display();
        l1.enqueue(3);
        l1.display();

        l1.dequeue();
        l1.display();
        l1.dequeue();
        l1.display();
        cout<<"Size: "<<l1.size()<<endl;
        cout<<"Front: "<<l1.front()<<endl;
        cout<<"Empty: "<<l1.empty()<<endl;



    } catch(const char* msg){
        cout << "Exception occurred : " << msg << endl;
    }
    return 0;
}