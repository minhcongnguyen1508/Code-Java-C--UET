#ifndef Node_H
#define Node_H
#include <iostream>
#include <string>

using namespace std;
class Node {
private:
   	int data;
    Node* parent;
    Node* left;
    Node* right;

public:
    Node(int s) {
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

    int getData() {
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
void depth(Node *v){
	int depth = 0;
	while(v->getParent() != NULL)
	{
		depth++;
		v = v->getParent();
	}
	cout<< depth;
}

#endif
