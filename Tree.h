#pragma once

#include "Node.h"

class Tree// decision - tree
{
	Node* Root;//first qustion

	void deleteSubTree(Node*& current);//delete the sub tree of a qustion
	Node* search(Node* p, string val, Node*& parent); 	//returns node to the location of the string. and the pointer parent will contain the parent address. 
	void print(Node* p);//print all the tree
	void searchAndPrint(Node* p, string val);// find string and print all the way from the string to the root
	void process(Node* p);//operate the tree
public:
	Tree() { Root = NULL; }//ctor
	~Tree() //dtor
	{
		deleteSubTree(Root);
		Root = NULL;
	}

	void addRoot(string v)//build a tree(the first question)
	{
		Root = new Node(v);
	}
	bool addSon(string father, string answer, string newVal);//create a son(question/answer in the tree) if the father string found
	void printAllTree() { print(Root); }//call to the private function
	void searchAndPrint(string val) { searchAndPrint(Root, val); }//call to the private function 
	void deleteSubTree(string val) //delete the sub tree of a qustion
	{
		Node* parent = NULL;
		Node* p = search(Root, val, parent);
		deleteSubTree(p); //call to the private function
	}
	void process() { process(Root); }//call to the private function
};
