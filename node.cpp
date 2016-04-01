#include "node.hpp"

Node::Node(){

}

Node::Node(Person persona):persona(persona){

}

~Node(){

}
	
Person getValue(){
	return persona;
}

Node* getNext(){
	return next;	
}

void setValue(Person persona){
	this ->persona = persona;
}

void setNext(Node* next){
	this -> next = next;
}

bool hasNext(){
	if(next){
		return true;
	}else{
		return false;
	}
}
