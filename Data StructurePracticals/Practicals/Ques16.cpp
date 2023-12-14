#include<iostream>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;

//"46+2/5*7+"
// int prec(char c){
//     if(c=='^'){
//         return 3;
//     }
//     else if(c=='*'||c=='/'){
//         return 2;
//     }
//     else if(c=='+'||c=='-'){
//         return 1;
//     }
//     else{
//         return -1;
//     }
// }

int PostfixEvaluation(string s){
    stack<int>st;
    for(int i=0; i<s.length(); i++){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            switch(s[i]){
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}


// "-+7*45+20"
int prefixEvaluation(string s){
    stack<int>st;
    for(int i=s.length()-1; i>=0; i--){
        if(s[i]>='0'&& s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();

            switch(s[i]){
                // case '(':
                //     st.push('(');
                // case ')':
                //     st.pop();
                //     break;
                case '+':
                    st.push(op1+op2);
                    break;
                case '-':
                    st.push(op1-op2);
                    break;
                case '*':
                    st.push(op1*op2);
                    break;
                case '/':
                    st.push(op1/op2);
                    break;
                case '^':
                    st.push(pow(op1,op2));
                    break;
            }
        }
    }
    return st.top();
}

int main(){
// Infix === "(((4+6)/2)*5)+7" 
// Postfix== "46+2/5*7+"
// Infix  == "+*/+46257"

    cout<<"Ans of Postfix: "<<PostfixEvaluation("46+2/5*7+")<<endl;//Ans 32

    cout<<"Prefix Answer: "<<prefixEvaluation("-+7*45+20")<<endl;


    // cout<<"Prefix Answer: "<<prefixEvaluation("((7+(4*5))-(2+0))")<<endl;
    // cout<<"Postfix to Infix: "<<postfixToPrefix("46+2/5*7+")<<endl;
    
    return 0;
}