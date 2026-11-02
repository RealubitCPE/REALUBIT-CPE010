#include <iostream>
#include "gentree.h" 

template <typename T>
void DisplayTree(Node<T>* root, int depth = 0) {
    if (root == nullptr) return;

    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }
    std::cout << "- " << root->data << std::endl;

    DisplayTree(root->firstChild, depth + 1);
    DisplayTree(root->nextSibling, depth);
}

Node<char>* BuildTree() {
    Node<char>* root = new Node<char>('A');

    Node<char>* B = root->AddChild('B');
    Node<char>* C = root->AddChild('C');
    Node<char>* D = root->AddChild('D');
    Node<char>* E = root->AddChild('E');
    Node<char>* F = root->AddChild('F');
    Node<char>* G = root->AddChild('G');

    Node<char>* H = D->AddChild('H');

    Node<char>* I = E->AddChild('I');
    Node<char>* J = E->AddChild('J');
    Node<char>* P = J->AddChild('P');
    Node<char>* Q = J->AddChild('Q');

    Node<char>* K = F->AddChild('K');
    Node<char>* L = F->AddChild('L');
    Node<char>* M = F->AddChild('M');

    Node<char>* N = G->AddChild('N');

    return root;
}

int main() {
    Node<char>* root = BuildTree();
    
    std::cout << "\n General tree: " << std::endl;
    DisplayTree(root);

    std::cout << "Pre Order: ";
    root->preOrder();
    std::cout << std::endl;

    std::cout << "In Order: ";
    root->inOrder();
    std::cout << std::endl;

    std::cout << "Post Order: ";
    root->postOrder();
    std::cout << std::endl;

    std::cout << "Pre Order Searching Q: " << std::endl;
    root->FindData("PreOrder", 'Q');
    std::cout << std::endl;

    std::cout << "In Order Searching H: " << std::endl;
    root->FindData("InOrder", 'H');
    std::cout << std::endl;

    std::cout << "Post-Order Searching M: " << std::endl;
    root->FindData("PostOrder", 'M'); 
    std::cout << std::endl;

    std::cout << "Adding Node 'O' " << std::endl;
    root->AddNodeO();

    std::cout << "Pre Order after adding O: ";
    root->preOrder();
    std::cout << std::endl;
    
    std::cout << "New General Tree: " << std::endl;
    DisplayTree(root);

    std::cout<<"Searching for O: "<<std::endl;
    root->FindData("PreOrder", 'O');
    std::cout<<std::endl;
    
    return 0;
}
