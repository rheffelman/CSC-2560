#include <iostream> 
#include "BSTree.h" 
 
using namespace std; 
 
int main() 
{ 
    BSTree < int > tree; 
	// tree.insert(5);
	// tree.insert(1);
	// tree.insert(10);
	// tree.insert(11);
	// tree.insert(9);
	// if (tree.search(5))
	// printf("true\n");
	// else printf("false\n");
	//printf("numElements: %d\n", tree.numberOfElements);
    tree.insert(14); 
	tree.insert(34); 
	tree.insert(2); 
	tree.insert(12); 
	tree.insert(23); 
	tree.insert(6); 
	tree.insert(67); 
	tree.insert(45); 
	tree.insert(44); 
	tree.insert(67); 
	tree.insert(23);
	tree.insert(67);
	tree.insert(67);
	tree.insert(67);
	tree.printInOrder();
	// double y = tree.percentInterior();

	// printf("%.1f leaf!\n", y);
	// tree.printInOrder(); 
	// tree.printPreorder(); 
	// tree.printPostOrder(); 
	printf("exited\n");
    return 0; 
}

