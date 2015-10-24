#include <iostream>
using namespace std;


// Linked list
struct Node {
public:
	int data;
	Node* next;
	Node* prev;
};

// count is the index of bottom of "heap"
// size is the size of the linked list
// list is the beginning pointer to the list.
// currentPointer = end of list.
// countpointer = count

int main() {

	const int NUM = 1500;
	
	int size = 1; 
	Node* list = new Node();
	Node* current = list;
	Node* count = list;
	int countnum = 1;
	list->data = 1; // Constant 
	list->next = 0; // Will be changed
	list->prev = 0; // Constant

	while(countnum <= NUM) {
		int x = count->data;
		int array[3] = { 2*x, 3*x, 5*x };
		Node* check = list;
		int index = 0;
		while (check != current->next) {
			if (array[index] > check->data) {
				check = check->next;
			}
			else if (array[index] < check->data){
				// Scenario here -> insert node B in between A and C ->Check is in C

				// B is after A 
				check->prev->next = new Node(); size++;

				// A is behind B
				check->prev->next->prev = check->prev;

				// B is behind C
				check->prev = check->prev->next;

				// C is after B
				check->prev->next = check;

				// Data of B is array x.
				check->prev->data = array[index++];
	
			}
			else { index++; }

			if (index > 2) { break; }
		}
		
		while (index < 3) {
			current->next = new Node(); size++;
			current->next->prev = current;
			current = current->next;
			current->next = 0;
			current->data = array[index++];
		}
		
		count = count->next; countnum++;
		
	}

	int i = size - NUM;
	while (i--) {
		current = current->prev;
	}
	cout <<  "The 1500'th ugly number is "<< current->data << "." << endl;

	return 0;
}
