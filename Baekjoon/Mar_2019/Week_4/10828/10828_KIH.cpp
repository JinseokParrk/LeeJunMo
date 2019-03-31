/*
 풀이에 걸린 시간 : 27
 복잡도 계산 : -
 수행 시간 : 4ms
 메모리 : 1992KB
 오답 이유 :
 풀이 방법 : 그냥 풀었음
 */

#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    struct Node {
        int value;
        Node *before;
    };
    
    Node *topNode = nullptr;
    int size = 0;
    
public:
    //push
    void push(int val) {
        size++;
        if (topNode == nullptr) {
            topNode = new Node();
            topNode->value = val;
            topNode->before = nullptr;
        } else {
            Node *tmp = new Node();
            tmp->value = val;
            tmp->before = topNode;
            topNode = tmp;
        }
    }
    
    //pop
    int pop() {
        if (topNode == nullptr) {
            return -1;
        } else {
            Node* tmp = topNode;
            topNode = tmp->before;
            int tmpVal = tmp->value;
            delete tmp;
            tmp = nullptr;
            size--;
            return tmpVal;
        }
    }
    
    //top
    int top() {
        if (topNode == nullptr) {
            return -1;
        } else {
            return topNode->value;
        }
    }
    
    //empty
    int empty() {
        if (topNode == nullptr) {
            return 1;
        } else
            return 0;
    }
    
    int getSize() {
        return size;
    }
    
    //debug
    void printStack() {
        Node* tmp = topNode;
        cout << "Stack : ";
        while (tmp != nullptr) {
            cout << tmp->value << " ";
            tmp = tmp->before;
        }
        cout << endl;
    }
};

void dispatcher(string input, Stack& stack, vector<int>& result) {
    if (input == "push") {
        int tmp = 0;
        cin >> tmp;
        stack.push(tmp);
    } else if (input == "pop") {
        result.push_back(stack.pop());
    } else if (input == "top") {
        result.push_back(stack.top());
    } else if (input == "empty") {
        result.push_back(stack.empty());
    } else if (input == "size") {
        result.push_back(stack.getSize());
    } else {
        cout << "input error" << endl;
    }
    
    //stack.printStack();
}

int main() {
    Stack stack;
    vector<int> result;
    int numQuery = 0;
    
    scanf("%d", &numQuery);
    
    for (int i = 0; i < numQuery; i++) {
        string q;
        cin >> q;
        dispatcher(q, stack, result);
    }
    
    for (auto e : result) {
        printf("%d\n", e);
    }

    return 0;
}
