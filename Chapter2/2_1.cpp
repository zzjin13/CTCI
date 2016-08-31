#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
  Node* next;
  int data;
};

void del(Node* head){
	unordered_map<int, bool> map;
	
	Node* cur = head;
	while(cur -> next){
		if(map[cur -> next -> data]){
			cur -> next = cur -> next -> next;
		}else{
			map[cur -> next -> data] = 1;
			cur = cur -> next;
		}
	}
}

int main() {
	// your code goes here
	Node n1;
	Node n2;
	Node n3;
	Node n4;
	Node n5;
	n1.next = &n2;
	n1.data = 1;
	n2.next = &n3;
	n2.data = 2;
	n3.next = &n4;
	n3.data = 2;
	n4.next = &n5;
	n4.data = 3;
	n5.next = NULL;
	n5.data = 3;
	
	del(&n1);
	
	Node* cur = &n1;
	while(cur){
		cout << cur -> data << endl;
		cur = cur -> next;
	}
	return 0;
}