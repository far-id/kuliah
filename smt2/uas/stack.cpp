#include <iostream>
#include <stack>
using namespace std;

int prioritas(char oprator){
    if (oprator == '+' || oprator == '-')return 1;
    if(oprator == '*' || oprator == '/')return 2;
    return 0;
}

void convertInfixToPostfix(string infix){
    int i = 0;
    string postfix= "";
    stack<int> stack;

    while (infix[i] != '\0')
    {
        if (infix[i] >= 'a' && infix[i] <= 'z' || infix[i] >= 'A' && infix[i] <= 'Z' || infix[i] >= '0' && infix[i] <= '9')
        {
            postfix += infix[i];
            i++;
        }else if(infix[i] == '('){
            stack.push(infix[i]);
            i++;
        }else if(infix[i] == ')'){
            while (stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
            i++;
        }else {
            while (!stack.empty() && prioritas(infix[i]) <= prioritas(stack.top()))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(infix[i]);
            i++;
        }
    }
    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }

    cout<<"Postfix : "<<postfix;
    
}

int main(){
    string infix = "A+(B*C)/(D-E)";
    cout<<"Infix : "<< infix<<endl;
    convertInfixToPostfix(infix);
    return 0;
}