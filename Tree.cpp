#include "Tree.h"

void Tree::deleteSubTree(Node*& current)
{
	if (current->isLeaf == true)// if it's leaf - delete it
		delete current;
	else//delete a sub tree
	{
		for (list<Answer*>::iterator it = current->Answers.begin(); it != current->Answers.end(); it++)
			deleteSubTree((*it)->Son);//delete all sons
		delete current;//delete the root of subtree
	}
}

bool Tree::addSon(string fatherQ, string answer, string newVal)
{
	Node* something = NULL;
	Node* temp = search(Root, fatherQ, something);//check if the string in the tree
	if (temp == NULL)
		return false;
	else
	{
		temp->Answers.push_back(new Answer(answer, new Node(newVal)));//create answer/son
		temp->isLeaf = false;
		return true;
	}
}

Node* Tree::search(Node* current, string val, Node*& parent)
{
	if (current->value == val && parent == NULL) // we are in the real root
		return current;
	if (current->isLeaf == true) // string not found
		return NULL;
	Node* temp = NULL;
	for (list<Answer*>::iterator it = current->Answers.begin(); it != current->Answers.end(); it++)
	{
		if ((*it)->Son->value == val)//found the string
		{
			parent = current;//parent contian the father of the string
			return (*it)->Son;//return the location of the string
		}
		temp = search((*it)->Son, val, current);//check if the string in the son
		if (temp != NULL)
			return temp;
	}
	return NULL;
}

void Tree::print(Node* p)
{
	cout << p->value << endl;//print the quention
	if (p->isLeaf)//end of the reqursion
		return;
	for (list<Answer*>::iterator it = p->Answers.begin(); it != p->Answers.end(); it++)
	{
		cout << ": " << (*it)->Ans << endl;//print the answer
		cout << " ";
		print((*it)->Son);//reqursion
	}
}

void Tree::searchAndPrint(Node* p, string val)
{
	Node* parent = NULL;
	Node* temp = search(p, val, parent);//check if the string in the tree
	if (temp == NULL)
	{
		return;
	}
	for (list<Answer*>::iterator it = p->Answers.begin(); it != p->Answers.end(); it++)
	{
		searchAndPrint((*it)->Son, val);//check every sub tree if the string in it
	}
	if (p == Root)//print the way from the string to the root
		cout << p->value;
	else
		cout << p->value << "=>";
}

void Tree::process(Node* p)
{
	string answer;
	if (p->isLeaf)//no more steps, print the final leaf that left 
	{
		cout << p->value << endl;
		return;
	}
	cout << p->value << endl; // print the question
	cin >> answer;//get answer
	for (list<Answer*>::iterator it = p->Answers.begin(); it != p->Answers.end(); it++)
		if ((*it)->Ans == answer)//find where is the answer, and move down in the tree
			process((*it)->Son);
}
