#include "list.hpp"
#include "node.hpp"


List::List(){
	head = NULL;
}

List::List(Person persona){
	head = new Node(persona);
}

List::~List(){

}

void List::setHead(Person persona){
	head = new Node(persona);
	head->setNext(NULL);
}

Person List::getHead(){
	return head->getValue();
}

Person List::at(int posicion){
	int size = this->size();
	Node* temporal;
	if(posicion >= size || posicion < 0){
		throw "Invalid position";
	}	
	temporal = head;
	for(int i = 0; i < size; i++){
		if(i == posicion){
			return temporal->getValue();	
		}
		temporal = temporal ->getNext();
	}	
}

void List::erase(int posicion){
	int size = this->size();
	Node* temporal;
	Node* nonWanted;
	
	if(posicion >= size || posicion < 0){
		throw "Invalid position";
	}

	temporal = head;
	if(posicion > 0){
		for(int i = 0; i < posicion-1; i++){
			temporal = temporal->getNext();
		}
		nonWanted = temporal -> getNext();
		if(nonWanted->hasNext())
			temporal->setNext(nonWanted->getNext());
		else
			temporal -> setNext(NULL);		
	}else if(posicion == 0){
		head = head->getNext();	
	}
	
}

void List::concat(List* lista){
	int size = this->size();
	Node* temporal;
	temporal = head;

	for(int i = 0; i < size; i++){
		temporal = temporal->getNext();
	}
	
	temporal->setNext(lista->first());				
}

int List::find(Person persona){
	int size = this -> size();
	int number = 0;
	Node* temporal = head;

	for(int i = 0; i < size; i++){
		if(!strcmp(persona.getName(), (temporal->getValue()).getName())){
			number =  i;
		}
		temporal = temporal->getNext();
	}
	return number;	
}

int List::size(){
	int contador = 0;
	Node* temporal;
	temporal = head;
	if(temporal == NULL){
		contador = 0;
	}else if(!temporal->hasNext()){
		contador++;
	}else{
		contador++;
		while(temporal->hasNext()){
			contador++;
			temporal = temporal->getNext();		
		}
	}
	return contador;
}

void List::push_back(Person persona){
	Node* referencia;
	if(!head){
		this->setHead(persona);
	}else{
		if(!head->hasNext()){
			this->head->setNext(new Node(persona));
		}else{
			referencia = head->getNext();
			while(referencia->hasNext()){
				referencia = referencia->getNext(); 		
			}
			referencia->setNext(new Node(persona));
		}
	}	
}

Node* List::first(){
	return head;
}
