/*
 풀이에 걸린 시간 : 대략 1시간
 복잡도 계산 : -
 수행 시간 : 4ms
 메모리 : 1992KB
 오답 이유 : 어디가 틀린건지 모르겠음
 풀이 방법 : -
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

class BinaryTree {
private:
    struct Node {
        string val;
        string left;
        string right;
    };
    
    map<string, Node> tree;
    
public:
    void insert(string node, string left, string right) {
        Node tmp;
        tmp.val = node;
        tmp.left = left;
        tmp.right = right;
        tree[node] = tmp;
    }
    
    // root, left, right
    void preOrderTraverse(string _node) {
        auto node = tree.find(_node)->second;
        printf("%s",node.val.c_str());
        if (node.left != ".") {
            preOrderTraverse(node.left);
        }
        if (node.right != ".") {
            preOrderTraverse(node.right);
        }
    }
    
    // left, root, right
    void inOrderTraverse(string _node) {
        auto node = tree.find(_node)->second;
        
        if (node.left != ".") {
            inOrderTraverse(node.left);
        }
        
        printf("%s", node.val.c_str());
        
        if (node.right != ".") {
            inOrderTraverse(node.right);
        }
    }
    
    // left, right, root
    void postOrderTraverse(string _node) {
        auto node = tree.find(_node)->second;
        
        if (node.left != ".") {
            inOrderTraverse(node.left);
        }
        
        if (node.right != ".") {
            inOrderTraverse(node.right);
        }
        
        printf("%s", node.val.c_str());
    }
};

int main() {
    int N = 0;
    BinaryTree bt;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        string n, l, r;
        cin >> n;
        cin >> l;
        cin >> r;
        bt.insert(n,l,r);
    }
    
    bt.preOrderTraverse("A");
    cout << endl;
    bt.inOrderTraverse("A");
    cout << endl;
    bt.postOrderTraverse("A");
    
    return 0;
}
