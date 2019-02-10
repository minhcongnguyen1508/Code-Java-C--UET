#include <iostream>
#include <string>

using namespace std;

class Node {
private:
    string data;
    Node* parent;
    Node* left;
    Node* right;

public:
    Node(string s) {
        data = s;
        parent = NULL;
        left = NULL;
        right = NULL;
    }

    void setParent(Node* p) {
        parent = p;
    }

    Node* getParent() {
        return parent;
    }

    void setLeft(Node* leftChild) {
        left = leftChild;
    }

    Node* getLeft() {
        return left;
    }

    void setRight(Node* rightChild) {
        right = rightChild;
    }

    Node* getRight() {
        return right;
    }

    string getData() {
        return data;
    }

    void print() {
        cout<<data<<" "<<left->getData()<<" "<<right->getData()<<endl;
    }
};

bool isInternal(Node* v) {
    if(v->getLeft() != NULL || v->getRight() != NULL) {
        return true;
    }
    return false;
}

void preOrder(Node* v) {
    if(v != NULL) {
        cout<<v->getData()<<" ";
        preOrder(v->getLeft());
        preOrder(v->getRight());
    }
}

void postOrder(Node* v) {
    if(v!= NULL) {
        postOrder(v->getLeft());
        postOrder(v->getRight());
        cout<<v->getData()<<" ";
    }
}

void inOrder(Node* v) {
    if(isInternal(v)) {
        inOrder(v->getLeft());
    }
    cout<<v->getData()<<" ";
    if(isInternal(v)) {
        inOrder(v->getRight());
    }
}

int main() {
    Node* a = new Node("A");
    Node* b = new Node("B");
    Node* c = new Node("C");
    Node* d = new Node("D");
    Node* e = new Node("E");

    b->setLeft(a);
    b->setRight(d);

    a->setParent(b);

    d->setParent(b);
    d->setLeft(c);
    d->setRight(e);

    c->setParent(d);

    e->setParent(d);

    cout<<" pre order: ";
    preOrder(b);
    cout<<endl;

    cout<<" post order: ";
    postOrder(b);
    cout<<endl;

    cout<<" in order: ";
    inOrder(b);
    cout<<endl;
}
