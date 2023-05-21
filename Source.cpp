#include<iostream>
#include<iomanip>

using namespace std;
typedef int Info;

struct Node
{
	Node* next,
		* prev;
	Info info;
};

void enqueue(Node*& first, Node*& last, Info info)
{
	Node* tmp = new Node;
	tmp->info = info;
	tmp->next = NULL;
	if (last != NULL)
		last->next = tmp;
	tmp->prev = last;
	last = tmp;
	if (first == NULL)
		first = tmp;
}


bool isSublist(Node* L1, Node* L2)
{
	// якщо L1 стаЇ NULL, це означаЇ, що весь L1 був знайдений у L2
	if (L1 == NULL)
		return true;

	// якщо L2 стаЇ NULL, а L1 ще не дос€гнув к≥нц€, то L1 не Ї п≥дсписком L2
	if (L2 == NULL)
		return false;

	// якщо поточн≥ елементи L1 та L2 зб≥гаютьс€, перев≥р€Їмо наступн≥ елементи
	if (L1->info == L2->info)
		return isSublist(L1->next, L2->next);

	// якщо поточн≥ елементи L1 та L2 не зб≥гаютьс€, перев≥р€Їмо наступний елемент L2
	return isSublist(L1, L2->next);
}


void printList(Node* head) {
	if (head == NULL) {
		cout << endl;
		return;
	}
	cout << head->info << " ";
	printList(head->next);

}


int main()
{
	Node* FirstL1 = NULL; // —писок L1
	Node* LastL1 = NULL;

	Node* FirstL2 = NULL; // —писок L2
	Node* LastL2 = NULL;

	// «аповненн€ списк≥в L1 та L2
	enqueue(FirstL1, LastL1, 1);
	enqueue(FirstL1, LastL1, 2);
	enqueue(FirstL1, LastL1, 3);

	enqueue(FirstL2, LastL2, 1);
	enqueue(FirstL2, LastL2, 2);
	enqueue(FirstL2, LastL2, 3);
	enqueue(FirstL2, LastL2, 4);
	enqueue(FirstL2, LastL2, 5);

	//ƒрукуванн€ списк≥в L1 ≥ L2
	cout << "List 1: ";
	printList(FirstL1);
	cout << "List 2: ";
	printList(FirstL2);

	// ѕерев≥рка, чи Ї L1 частиною L2
	if (isSublist(FirstL1, FirstL2))
		cout << "L1 is a part of L2" << endl;
	else
		cout << "L1 is not a part of L2" << endl;

	return 0;
}