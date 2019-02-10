//
# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
struct Node{
    int value;
    Node *nextNode;
};
class SList{
	Node *head;
	public:
		SList(){
			head = NULL;
		}
	Node* addNode(int index, int value);
	Node* deleteNode(int index);
	void print(){
		Node *p = new Node;
		p  = head;
			while(p != NULL){
				cout<< p->value<<" ";
				p = p->nextNode;
			}
	}
};

int main(){
	SList *pHead = new SList();
	
	pHead->addNode(1, 1);
	pHead->addNode(1, 2);
	pHead->addNode(1, 3);
	pHead->deleteNode(2);
	pHead->print();
	

	return 0;
}

Node* SList::addNode(int index, int value){
    Node *newNode = new Node;
    newNode->value = value;
    newNode->nextNode = NULL;
  	Node *p = new Node;
  	p = head;
  	if(index == 0 || head == NULL){
  		newNode->nextNode = head;
  		head = newNode;
  		return head;
	}
	else{
		
		for(int i = 0; i < index-1; i++){
			p = p->nextNode;
		}
		newNode->nextNode = p->nextNode;
		p->nextNode = newNode;
	}
    return head;
}

Node* SList::deleteNode(int index){
    Node *p;
        p = head;
    Node *q;
        q = head->nextNode;
	if(index == 0){
		head = q;
		delete p;
	}
    else
    {
        for(int i = 0; i < index-1; i++){
        	p = p->nextNode;
        	q = q->nextNode;
		}
		p->nextNode = q->nextNode;
		delete q;
    }
    return head;
}
