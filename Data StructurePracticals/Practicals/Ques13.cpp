#include<iostream>
using namespace std;

class DaigonalMatrix{
    private:
        int n;
        int *arr;
    public:
        DaigonalMatrix(int n){
            this->n = n;
            this->arr = new int[n];
        }
        void set(int i, int j, int element){
            if (i > n || i <= 0 || j > n || j <= 0) throw "index out of range";
            if (i != j && element != 0) throw "cannot store element out of daigonal";
            else arr[i-1] = element; 
        }
        int get(int i, int j){
            if (i > n || i < 0 || j > n || j < 0) throw "index out of range";
            if (i != j) return 0;
            else return arr[i-1];
        }
        void display(){
            for (int i = 1; i <= n; i ++){
                for (int j = 1; j <= n; j ++){
                    cout << get(i, j) << " ";
                }
                cout << endl;
            }
        }
};

class LowerTriangularMatrix{
    private:
        int n;
        int *arr;
    public:
        LowerTriangularMatrix(int n){
            this->n = n;
            int size = (n*n + n)/2;
            this->arr = new int[size];
        }
        void set(int i, int j, int element){
            if (i > n || i <= 0 || j > n || j <= 0) throw "index out of range";
            if (i < j && element != 0) throw "element at position must be zero";
            arr[(i * (i - 1)) / 2 + j - 1] = element;
        }
        int get(int i, int j){
            if (i > n || i <= 0 || j > n || j <= 0) throw "index out of range";
            if (i < j) return 0;
            return this->arr[(i * (i - 1)) / 2 + j - 1];
        }
        void display(){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    cout << get(i,j) << " ";
                }
                cout << endl;
            }
        }
};

class UpperTriangularMatrix{
    private:
        int n;
        int *arr;
    public:
        UpperTriangularMatrix(int n){
            this->n = n;
            int size = (n*n + n)/2;
            this->arr = new int[size];
        }
        void set(int i, int j, int element){
            if (i > n || i <= 0 || j > n || j <= 0) throw "index out of range";
            if (i > j && element != 0) throw "element at position must be zero";
            arr[(j * (j - 1)) / 2 + i - 1] = element;
        }
        int get(int i, int j){
            if (i > n || i <= 0 || j > n || j <= 0) throw "index out of range";
            if (i > j) return 0;
            return arr[(j * (j - 1)) / 2 + i - 1];
        }
        void display(){
            for (int i = 1; i <= n; i++){
                for (int j = 1; j <= n; j++){
                    cout << get(i,j) << " ";
                }
                cout << endl;
            }
        }
};

class SymmetricMatrix{
    private:
        int n;
        int *arr;
    public:
        SymmetricMatrix(int n){
            this->n = n;
            int size = (n*n + n)/2;
            this->arr = new int[size];
        }
        void set(int i, int j, int element){
            cout << i << j << endl;
            if (i > n || i <= 0 || j > n || j <= 0) throw "index out of range";
            if (i < j){
                set(j,i, element);
                return;
            }
            arr[(i * (i - 1)) / 2 + j - 1] = element;
        }
        int get(int i, int j){
            if (i > n || i <= 0 || j > n || j <= 0) throw "index out of range";
            if (i < j) return get(j,i);
            return arr[(i * (i - 1)) / 2 + j - 1];
        }
        void display(){
            for (int i = 1; i <= n; i ++){
                for (int j = 1; j <= n; j++){
                    cout << get(i,j) << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    int matrix_choice = 1;
    cout <<"1 - Daigonal Matrix\n2 - Lower Triangular Matrix\n3 - Upper Triangular Matrix\n4 - Symmetric Matrix"<<endl;;
    cout<<"Enter Choice of which type of matrix you will Perform: ";
    cin >> matrix_choice;
    int n;
    cout << "Enter order of matrix : ";
    cin >> n;
    try{
        if (matrix_choice == 1){
            DaigonalMatrix a(n);
            cout << "Diagonal matrix with garbage value is" << endl;
            a.display();
            cout << endl;
            while (true){
                int operation_choice;
                cout << "Operations are:\n1 - insert element at given position\n2 - retrieve element from that position\n3 - display the matrix\n4 - exit the program\n ";
                cout<<"Enter your operation: ";
                cin >> operation_choice;
                if (operation_choice == 1){
                    int i, j, element;
                    cout << "Enter row & column which you wants to change: ";
                    cin >> i;
                    cin >> j;
                    cout << "Enter element at ("<<i<<","<<j<<") position: ";
                    cin >> element;
                    a.set(i,j,element);
                }
                else if (operation_choice == 2){
                    int i, j;
                    cout << "Enter row and column which index you get: ";
                    cin >> i;
                    cin >> j;
                    cout << "Element at position ("<< i << ","<< j << ") is: " << a.get(i,j)<<endl;
                }
                else if (operation_choice == 3){
                    cout << "Matrix is: " << endl;
                    a.display();
                }
                else if(operation_choice == 4) break;
                else throw "invalid choice";
                cout << endl;
            }
        }
        else if (matrix_choice == 2){
            //cout<<"You choose Lower Triangular Matrix"<<endl;
            LowerTriangularMatrix b(n);
            cout << "Lower Triangular Matrix with garbage value is" << endl;
            b.display();
            cout << endl;
            while (true){
                int operation_choice;
                cout << "Operations are:\n1 - insert element at given position\n2 - retrieve element from that position\n3 - display the matrix\n4 - exit the program\n ";
                cout<<"Enter your operation: ";
                cin >> operation_choice;
                if (operation_choice == 1){
                    int i, j, element;
                    cout << "Enter row & column which you wants to change: ";
                    cin >> i;
                    cin >> j;
                    cout << "Enter element at ("<<i<<","<<j<<") position: ";
                    cin >> element;
                    b.set(i,j,element);
                }
                else if (operation_choice == 2){
                    int i, j;
                    cout << "Enter row and column which index you get: ";
                    cin >> i;
                    cin >> j;
                    cout << "Element at position ("<< i << ","<< j << ") is: " << b.get(i,j)<<endl;
                }
                else if (operation_choice == 3){
                    cout << "Matrix is: "  << endl;
                    b.display();
                }
                else if(operation_choice == 4) break;
                else throw "invalid choice";
                cout << endl;
            }
                cout<<endl;
        } 
        else if (matrix_choice ==  3){
            UpperTriangularMatrix c(n);
            cout << "Upper Triangular Matrix with garbage value is" << endl;
            c.display();
            cout << endl;
            while (true){
                int operation_choice;
                cout << "Operations are:\n1 - insert element at given position\n2 - retrieve element from that position\n3 - display the matrix\n4 - exit the program\n ";
                cout<<"Enter your operation: ";
                cin >> operation_choice;
                if (operation_choice == 1){
                    int i, j, element;
                    cout << "Enter row & column which you wants to change: ";
                    cin >> i;
                    cin >> j;
                    cout << "Enter element at ("<<i<<","<<j<<") position: ";
                    cin >> element;
                    c.set(i,j,element);
                }
                else if (operation_choice == 2){
                    int i, j;
                    cout << "Enter row and column which index you get: ";
                    cin >> i;
                    cin >> j;
                    cout << "Element at position ("<< i << ","<< j << ") is: " << c.get(i,j)<<endl;
                }
                else if (operation_choice == 3){
                    cout << "Matrix is: "  << endl;
                    c.display();
                }
                else if(operation_choice == 4) break;
                else throw "invalid choice";
                cout << endl;
            }
        }
        else if (matrix_choice == 4){
            SymmetricMatrix d(n);
            cout << "the symmetric matrix with garbage value" << endl;
            d.display();
            cout << endl;
            while (true){
                int operation_choice;
                cout << "Operations are:\n1 - insert element at given position\n2 - retrieve element from that position\n3 - display the matrix\n4 - exit the program\n ";
                cout<<"Enter your operation: ";
                cin >> operation_choice;
                if (operation_choice == 1){
                    int i, j, element;
                    cout << "Enter row & column which you wants to change: ";
                    cin >> i;
                    cin >> j;
                    cout << "Enter element at ("<<i<<","<<j<<") position: ";
                    cin >> element;
                    d.set(i,j,element);
                }
                else if (operation_choice == 2){
                    int i, j;
                    cout << "Enter row and column which index you get: ";
                    cin >> i;
                    cin >> j;
                    cout << "Element at position ("<< i << ","<< j << ") is: " << d.get(i,j)<<endl;
                }
                else if (operation_choice == 3){
                    cout << "Matrix is: "  << endl;
                    d.display();
                }
                else if(operation_choice == 4) break;
                else throw "invalid choice";
                cout << endl;
            }
        }
        else{
            throw "invalid choice";
        }
    }
    catch(const char* msg){
        cout << msg;
    }
    cout << "\nexiting the program" << endl;
    return 0;
}