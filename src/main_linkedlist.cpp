#include <iostream>

#include "LinkedList.hpp"

int main() {
    LinkedList<int> llist;

    llist.printAllNodes();

    llist.insertAtTheEnd(1);
    llist.insertAtTheFront(7);
    llist.insertAtTheEnd(4);
    llist.insertAtTheEnd(8);

    llist.printAllNodes();

    std::cout << "finding node and printing" << llist.findNode(4) << std::endl;


    llist.printAllNodes();

    std::cout << "removeall nodes" << std::endl;
    llist.removeAllNodes();
    llist.printAllNodes();
    std::cout << "should have printed NULL" << std::endl;


    return 0;
}