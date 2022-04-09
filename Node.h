#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Answer.h"
using namespace std;

class Answer; // decleration
class Node // Node of decision tree
{

public:
	list<Answer*> Answers;//list of answer
	string value;// the question/decision of the nod
	bool isLeaf;//check if it is a leaf
	Node(string v) { isLeaf = true;  value = v; }//ctor

	friend class Tree;// for class tree. to access the field in node class
};
