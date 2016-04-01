#include "list.hpp"
#include "node.hpp"


List::List(){

}

List::List(Person persona){
	head = new Node(persona);
}

List::~List(){

}

void List::setHead(Person persona){
	head = new Node(persona);
}

Person List::getHead(){
	return head;
}

void List::insert(int posicion, Person persona){
	int size = this->size();
	Node* temporal;
	Node* temporal2;
	if(posicion >= size || posicion < 0){
		throw "Invalid position";
	}
	
	temporal = head;
	for(int i = 0; i < size; i++){
		if(i == posicion ){
			temporal2 = temporal->getNext();
			temporal->setNext(new Node(persona));
			temporal->getNext()->setNext(temporal2);		
		}
		temporal = temporal->getNext();	
	}
}

Person List::at(int posicion){
	
}

void List::erase(int posicion){

}

void List::concat(List* lista){
		
}

int List::find(Person persona){

}

int List::size(){
	int contador = 0;
	Node* temporal;
	temporal = head->getNext();

	if(!temporal->hasNext()){
		contador+=1;
	}else{
		while(temporal->hasNext()){
			contador += 1;
			temporal = temporal->getNext();		
		}
	}
	return contador;
}

void List::push_back(Person persona){
	Node* referencia;
	if(!head->hasNext()){
		head.setNext(new(Node(persona));
	}else{
		referencia = head->getNext();
		while(referencia->hasNext()){
			referencia = referencia->getNext(); 		
		}
		referencia->setNext(new Node(persona));
	}	
}

Node* List::first(){

}
