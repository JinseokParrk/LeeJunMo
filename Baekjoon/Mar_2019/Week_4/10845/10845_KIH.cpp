/*
 풀이에 걸린 시간 : 10분
 복잡도 계산 : -
 수행 시간 : 4ms
 메모리 : 1992KB
 오답 이유 :
 풀이 방법 : Stack 했던거 조금만 고쳐서 풀었음.
 */

#include <iostream>
#include <vector>

using namespace std;

class Queue {
private:
    struct Node {
        int value;
        Node *next;
    };
    
    Node *front = nullptr;
    Node *back = nullptr;
    int size = 0;
    
public:
    //push
    void push(int val) {
        size++;
        if (front == nullptr) {
            front = new Node();
            front->value = val;
            front->next = nullptr;
            back = front;
        } else {
            Node *tmp = new Node();
            tmp->value = val;
            tmp->next = nullptr;
            back->next = tmp;
            back = tmp;
        }
    }
    
    //pop
    int pop() {
        if (front == nullptr) {
            return -1;
        } else {
            Node* tmp = front;
            front = front->next;
            
            // 가장 앞의 노드 value 저장 및 할당 해제
            int tmpVal = tmp->value;
            delete tmp;
            tmp = nullptr;
            
            // 만약 노드가 1개였을 경우
            if (front == nullptr) {
                back = nullptr;
            }
            
            size--;
            return tmpVal;
        }
    }
    
    //front
    int getFront() {
        if (front == nullptr) {
            return -1;
        } else {
            return front->value;
        }
    }
    
    //back
    int getBack() {
        if (back == nullptr) {
            return -1;
        } else {
            return back->value;
        }
    }
    
    //empty
    int empty() {
        if (front == nullptr) {
            return 1;
        } else
            return 0;
    }
    
    int getSize() {
        return size;
    }
    
    //debug
    void printQueue() {
        Node* tmp = front;
        cout << "Queue : ";
        while (tmp != nullptr) {
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }
};

void dispatcher(string input, Queue& queue, vector<int>& result) {
    if (input == "push") {
        int tmp = 0;
        cin >> tmp;
        queue.push(tmp);
    } else if (input == "pop") {
        result.push_back(queue.pop());
    } else if (input == "size") {
        result.push_back(queue.getSize());
    } else if (input == "empty") {
        result.push_back(queue.empty());
    } else if (input == "front") {
        result.push_back(queue.getFront());
    } else if (input == "back") {
        result.push_back(queue.getBack());
    } else {
        cout << "input error" << endl;
    }
    
    //queue.printQueue();
}

int main() {
    Queue queue;
    vector<int> result;
    int numQuery = 0;
    
    scanf("%d", &numQuery);
    
    for (int i = 0; i < numQuery; i++) {
        string q;
        cin >> q;
        dispatcher(q, queue, result);
    }
    
    for (auto e : result) {
        printf("%d\n", e);
    }

    return 0;
}
