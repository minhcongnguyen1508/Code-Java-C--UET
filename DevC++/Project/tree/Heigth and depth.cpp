#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
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
bool isLeaf(Node* v) {
    if(v->getLeft() == NULL && v->getRight() == NULL) {
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
int height(Node *v){
	if(v == NULL){
		return -1;
	}
	else return max(height(v->getLeft()), height(v->getRight())) + 1;
	
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

    cout<<" Pre order: ";
    preOrder(b);
    cout<<endl;

    cout<<" Post order: ";
    postOrder(b);
    cout<<endl;

    cout<<" In order: ";
    inOrder(b);
    cout<<endl;
    
    cout<< " Depth A is: ";
    depth(a);
    cout<<endl;
    cout<< " Depth B is: ";
    depth(b);
    cout<<endl;
    cout<< " Depth C is: ";
    depth(c);
    cout<<endl;
    cout<< " Depth D is: ";
    depth(d);
    cout<<endl;
    cout<< " Depth E is: ";
    depth(e);
    cout<<endl;
    
    cout<< " Height is: " << height(a)<< endl;
    cout<< " Height is: " << height(b)<< endl;
    cout<< " Height is: " << height(c)<< endl;
    cout<< " Height is: " << height(d)<< endl;
    cout<< " Height is: " << height(e)<< endl;
    
}

