#include<iostream>
#include"LinkedList.h"
#include<list>

using namespace std;

int main()
{
	int val; // Value to search in the LinkedList

	// Define a NumberList object.
	LinkedList List;

	//Make nodes
	List.appendNode(2);
	List.appendNode(6);
	List.appendNode(8);
	List.appendNode(12);
	List.appendNode(14);

	//Show initial values
	cout << "Here are the initial values:\n";
	List.displayList();
	cout << endl;
	
	// Insert Node
	cout << "Now inserting a Node.\n";
	List.insertNode(7);

	//Show values
	cout << "Here are the values:\n";
	List.displayList();
	cout << endl;

	// Delete the middle node.
	cout << "Now deleting the node in the middle.\n";
	List.deleteNode(7);

	// Display the list.
	cout << "Here are the nodes left.\n";
	List.displayList();
	cout << endl;

	// Searching for a value
	cout << "What value do you want to search for:\n";
	cin >> val;
	cout << endl;
	List.search(val);
	cout << endl;

	// Reverse the nodes order
	cout << "Here are the values in reversed order:\n";
	List.reverse();
	cout << endl;

	system("pause");
	return 0;
}