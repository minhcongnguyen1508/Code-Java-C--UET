#include <iostream>
#include <string>

using namespace std;

template <class tree>

class binaryTree
{	
private:
	tree data;
	tree *parent;
	tree *leftChild;
	tree *rightChild;	
public:
	binaryTree(tree dataNew){
		data = dataNew;
		parent = NULL;
		leftChild = NULL;
		rightChild = NULL;
	}
	~binaryTree();
	tree* getParent(){
		return parent;
	}
	tree* getLeft(){
		return leftChild;
	}
	tree* getRight(){
		return rightChild;
	}
	tree getData(){
		return data;
	}
	void setLeft(tree *left){
		leftChild = left;
	}
	void setRight(tree *right){
		rightChild = right;
	}
	void setParent(tree *internal){
		internal = parent;
	}
};
bool isInternal(binaryTree* v) {
	if(v->getLeft != NULL || v->getRight != NULL){
		return true;
	}
	return false;
}
void preOrder(tree *v){
	if(v != NULL){
		cout<< v->getData()<< " ";
		preOrder(v->getLeft());
		preOrder(v->getRight());
	}
}
void postOrder(tree *v){
	if(v != NULL){
		postOrder(v->getLeft());
		postOrder(v->getRight());
		cout<< v->getData()<< " ";
	}
}
void inOrder(tree *v){
	if(isInternal(v)){
		inOrder(v->getLeft());
	}
	cout<< v->getData()<<" ";
	if(isInternal(v)){
		inOrder(v->getRight());
	}
}

int main() {
    tree* a = new tree("A");
    tree* b = new tree("B");
    tree* c = new tree("C");
    tree* d = new tree("D");
    tree* e = new tree("E");

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
