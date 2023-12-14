#include<iostream>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;
// #ifndef BINARY_SEARCH_TREE
// #define BINARY_SEARCH_TREE

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data= data;
            this->left=this->right=NULL;
        }
        friend class BinaryTree;
};

class BinarySearchTree{
    Node* root;
    int index=-1;
public:
    BinarySearchTree(){ root=0; }
    ~BinarySearchTree(){clear();}
    void clear(){
        // clear(root); 
        root=0;
    }
    bool isEmpty() const{
        if(root==NULL){
            return true;
        }
        else{
            return false;
        }
    }

    Node* builtTree(int nodes[]){
        index++;
        if(nodes[index]==-1){
            return NULL;
        }
        Node* newNode= new Node(nodes[index]);
        newNode->left= builtTree(nodes);
        newNode->right= builtTree(nodes);
        return newNode;
    }

    void preorder(Node* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }

    void postorder(Node* root){
        if(root==NULL){
            return;
        }
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }

    void levelorder(Node* root){
        if(root==NULL){return;}
        queue<Node* > q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* curr= q.front();
            q.pop();
            if(curr==NULL){
                cout<<endl;
                if(q.empty()){
                    break;
                }
                else{
                    q.push(NULL);
                }
            }
            else{
                cout<<curr->data<<" ";
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }
    }


    int height(Node* root){
        if(root==NULL){ return -1;}
        int leftHeight=height(root->left);
        int rightHeight=height(root->right);
        // if (leftHeight > rightHeight)
        //     return (leftHeight + 1);
        // else
        //     return (rightHeight + 1);
        return max(leftHeight,rightHeight)+1;
    }

    int countOfNode(Node* root){
        if(root==NULL){ return 0;}
        int leftNode= countOfNode(root->left);
        int rightNode= countOfNode(root->right);
        return leftNode+rightNode+1;
    }

    int sumOfNode(Node* root){
        if(root==NULL){ return 0;}
        int leftSum= sumOfNode(root->left);
        int rightSum= sumOfNode(root->right);
        return leftSum+rightSum+root->data;
    }


    bool isIdentical(Node* root,Node* subRoot){
        if(subRoot==NULL && root==NULL){
            return true;
        }
        if(root==NULL || subRoot==NULL){
            return false;
        }
        if(root->data == subRoot->data){
            return isIdentical(root->left, subRoot->left) && isIdentical(root->right, subRoot->right);
        }
        return false;

    }

    bool isSubtree(Node* root, Node* subRoot) {
        if(subRoot==NULL){
            return true;
        }
        if(root==NULL){
            return false;
        }
        if(isIdentical(root, subRoot)){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    Node* search(Node* p, int e){//Recursive Call
        if(p==NULL){return p;}
        if(p->data==e){
            return p;

        }
        else{
            if(e<p->data){
                return search(p->left, e);
            }
            else{
                return search(p->right, e);
            }
        }
    }

    Node*search2(int e){//Iterative Call
        Node* p=root;
        while(p!=NULL){
            if(p->data==e)break;
            else{
                if(e<p->data){
                    p=p->left;
                }
                else p=p->right;
            }
        }
        return p;
    }


    // Node* newNode(int data){
    //     Node* temp= new Node(data);
    //     temp->data=data;
    //     temp->left=NULL;
    //     temp->right=NULL;
    //     return temp;
    // }
    Node* insert(Node* p,int e){
        if(p==NULL){
            p= new Node(e);
            return p;
        }
        if(e<p->data){
            p->left= insert(p->left,e);
        }
        else if(e>p->data){
            p->right= insert(p->right,e);
        }
        return p;
    }
    
    Node* deleteNode(Node*root,int e){
        if(root==NULL){
            return root;
        }
        if(e< root->data){ 
            root->left= deleteNode(root->left,e);
        }
        else if(e> root->data){
            root->right= deleteNode(root->right,e);
        }
        else{
            if(root->left==NULL){
                Node* temp= root->right;
                free(root);
                return temp;
            }
            else if(root->right==NULL){
                Node* temp= root->left;
                free(root);
                return temp;
            }

            Node* temp=MinVal(root->right);
            root->data= temp->data;
            root->right= deleteNode(root->right, temp->data);
        }
        return root;
    }

    int FindMin(Node*p){
        Node* current = p;
        // p= root;
        if(p==NULL) throw "NULL Tree";
        while(current->left!=NULL){
            current=current->left;
        }
        return current->data;
    }
    Node* MinVal(Node*p){//
        Node* current = p;
        // p= root;
        if(p==NULL) throw "NULL Tree";
        while(current->left!=NULL){
            current=current->left;
        }
        return current;
    }

    void breadthFirst();
    void insert(const int& e);
};

void BinarySearchTree::breadthFirst(){/////////
    queue<Node*> queue;
    Node *p=root;
    if(p!=0){
        queue.push(p);
        while(!queue.empty()){
            p=queue.front();
            // visit(p);
            if(p->left!=0)
                queue.push(p->left);
            if(p->right!=0)
                queue.push(p->right);
        }
    }
}

void BinarySearchTree::insert(const int& e){
    Node* z=new Node(e);
    Node* y=NULL;
    Node* x=root;
    while(x!=NULL){
        y = x;
        if(z->data < x->data){ 
            x=x->left;
        }
        else{
            x= x->right;
        }
    }
    if(y==NULL)  root=z;
    else if(z->data < y->data){
        y->left= z;
    }
    else y->right= z;
    z->left=z->right=NULL;
}


// #endif
int main(){
try{
    // int nodes[]={1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    int nodes[]={5,3,2,-1,-1,4,-1,-1,7,-1,8,-1,-1};
    BinarySearchTree tree;
    Node* root= tree.builtTree(nodes);
    cout<<"Root is: "<<root->data<<endl;
    cout<<"Pre Order: ";
    tree.preorder(root);


    cout<<"(i) Insert an element x (ie=6): "<<endl;
    tree.insert(root,6);
    tree.insert(root,1);
    tree.insert(9);
    tree.insert(10);
    cout<<endl;
    tree.preorder(root);

    cout<<"(ii) Delete an element x (7): "<<endl;
    tree.deleteNode(root, 7);
    tree.preorder(root);

    cout<<"(iii) Search for an element x in the BST: ";
    cout<<"Search 2 and return address: "<<tree.search(root,2)<<endl;

    cout<<"(iv) Display elements of the BST by following Traversals:"<<endl;
    cout<<"Pre Order: ";
    tree.preorder(root);
    cout<<endl<<"In Order: ";
    tree.inorder(root);
    cout<<endl<<"Post Order: ";
    tree.postorder(root);
    cout<<"\n(v) Display elements of the BST by- "<<endl;
    cout<<endl<<"Level Order: ";
    tree.levelorder(root);
    cout<<"\n(vi) Display Height of BST: "<<tree.height(root);










    // cout<<"Minimum: "<<tree.FindMin(root)<<endl;
    // cout<<endl<<"Height of Tree: "<<tree.height(root);
    // cout<<endl<<"Count of Nodes: "<<tree.countOfNode(root);
    // cout<<endl<<"Sum of Nodes: "<<tree.sumOfNode(root)<<endl;
    // //     // cout<<"Breadth First: ";
    // //     // tree.breadthFirst();

    // cout<<"Search 2 and return address: "<<tree.search(root,2)<<endl;
    // cout<<"Search 5 and return address: "<<tree.search(root,5)<<endl;
    // cout<<"Search2 2 and return address: "<<tree.search2(2)<<endl;
    // cout<<"Search2 5 and return address: "<<tree.search2(5)<<endl;


    // int nodes2[]={1,2,3,-1,-1,5,-1,-1,3,-1,6,-1,-1};
    // BinaryTree tree2;
    // Node* root2= tree2.builtTree(nodes2);
    // cout<<"\nIs Subtree: "<<tree.isSubtree(root,root2);
    // cout<<"\nIs Subtree: "<<tree.isSubtree(root,root);
    // cout<<"\nIs Identical: "<<tree.isIdentical(root,root2);
    // cout<<"\nIs Identical: "<<tree.isIdentical(root,root);

}
catch(char const msg){
    cout<<msg<<endl;
}
return 0;
}