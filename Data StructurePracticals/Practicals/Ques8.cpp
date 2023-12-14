#include <iostream>
using namespace std;
class QueueArray{
    private:
        int* array;
        int front, rear;
        int max_capacity;
        int current_capacity;
    public:
        QueueArray(int capacity = 10){
            this->max_capacity = capacity;
            this->array = new int[max_capacity];
            this->front = 0;
            this->rear = 0;
            this->current_capacity = 0;
        }

        bool empty() const;
        int count();
        int dequeue();
        int frontElem() const;
        void enqueue(int element);
        void display() const;
};

bool QueueArray::empty() const{
    return (current_capacity == 0);
} 
int QueueArray:: frontElem() const{
    if(current_capacity==0) throw "Empty Queue";
    return array[front];
}

int QueueArray:: count(){
    return current_capacity;
}
int QueueArray::dequeue(){
    if (this->current_capacity == 0) throw "ArrayEmptyError";
    int ret_element = array[front];
    front = (front+1 == max_capacity)?0:front+1;
    current_capacity--;

    return ret_element;
}
void QueueArray::enqueue(int element){
    if (current_capacity == max_capacity-1) throw "ArrayIsFull";
    array[rear] = element;
    rear = (rear+1 == max_capacity)?0:rear+1;
    current_capacity++;
}

void QueueArray::display() const{
    int i = front;
    while (i % max_capacity != rear && current_capacity != 0){
        cout << array[i] << " ";
        i++;
    }
    cout << endl;
}

int main(){
    try{
        QueueArray q(10);
        q.enqueue(3);
        q.display();
        q.enqueue(4);
        q.display();
        q.enqueue(5);
        q.display();
        q.enqueue(6);
        q.display();
        q.enqueue(7);
        q.enqueue(8);
        q.enqueue(9);
        q.display();
    
        q.dequeue();
        q.display();
        q.dequeue();
        q.display();
        q.dequeue();
        q.dequeue();
        q.display();
        
        
    
        cout<<"Size: "<<q.count()<<endl;
        cout<<"Front: "<<q.frontElem()<<endl;
        cout<<"Empty: "<<q.empty()<<endl;
    }
    catch (const char* error){
        cout << "Exception occurred - " << error << endl;
    }

    return 0;
}