//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
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

//
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
//
void printExpression(Node *v){
	if(v->getLeft()){
		cout<< '(';
		printExpression(v->getLeft());
	}
		
	cout<< v->getData();
	if(v->getRight()){
		printExpression(v->getRight());
		cout<< ')';
	}
		
}
//
int toInt(string s)
{
    int num = 0;
    for (int i=0; i<s.length();  i++)
        num = num*10 + (int(s[i])-48);
    return num;
}
bool isOperator(string s){
	
}
//
int main(){
	Node *a = new Node ("2");
	Node *b = new Node ("*");
	Node *c = new Node ("5");
	Node *d = new Node ("1");
	Node *e = new Node ("-");
	Node *f = new Node ("+");
	Node *g = new Node ("*");
	Node *h = new Node ("3");
	Node *i = new Node ("2");
	f->setLeft(b);
	f->setRight(g);
	
	b->setParent(f);
	b->setLeft(a);
	b->setRight(e);
	
	a->setParent(b);
	
	e->setParent(b);
	e->setLeft(c);
	e->setRight(d);
	
	c->setParent(e);
	d->setParent(e);
	
	g->setParent(f);
	g->setLeft(h);
	g->setRight(i);
	
	h->setParent(g);
	i->setParent(g);
	
	printExpression(f);
	cout << " = "<< 14;
	return 0;
}

