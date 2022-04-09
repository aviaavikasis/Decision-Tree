#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Node.h"
using namespace std;
class Node; //decleration

class Answer // possible answer 
{
public:
	string Ans; // answer
	Node* Son; // pointer to next question/decision
	Answer(string s, Node* p) { Ans = s; Son = p; } //ctor
};
