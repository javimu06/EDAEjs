//
//  queue_eda.h
//
//  Implementación del TAD cola con nodos enlazados
//  y punteros al primero y al último nodo
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef queue_eda_h
#define queue_eda_h

#include <stdexcept>  // std::domain_error
#include <iostream>
template <class T>
class queue {
protected:

	/*
	 Nodo que almacena internamente el elemento (de tipo T),
	 y un puntero al nodo siguiente, que puede ser nullptr si
	 el nodo es el último de la lista enlazada.
	 */
	struct Nodo {
		Nodo() : sig(nullptr) {}
		Nodo(T const& el, Nodo* si = nullptr) : elem(el), sig(si) {}
		T elem;
		Nodo* sig;
	};

	// punteros al primer y último elemento
	Nodo* prim;
	Nodo* ult;

	// número de elementos en la cola
	int nelems;

public:

	// constructor: cola vacía
	queue() : prim(nullptr), ult(nullptr), nelems(0) {}

	// destructor
	~queue() {
		libera();
	}

	// constructor por copia
	queue(queue<T> const& other) {
		copia(other);
	}

	// operador de asignación
	queue<T>& operator=(queue<T> const& other) {
		if (this != &other) {
			libera();
			copia(other);
		}
		return *this;
	}

	// añadir un elemento al final de la cola
	void push(T const& elem) {
		Nodo* nuevo = new Nodo(elem);

		if (ult != nullptr)
			ult->sig = nuevo;
		ult = nuevo;
		if (prim == nullptr) // la cola estaba vacía
			prim = nuevo;
		++nelems;
	}

	// consultar el primero de la cola
	T const& front() const {
		if (empty())
			throw std::domain_error("la cola vacia no tiene primero");
		return prim->elem;
	}

	// eliminar el primero de la cola
	void pop() {
		if (empty())
			throw std::domain_error("eliminando de una cola vacia");
		Nodo* a_borrar = prim;
		prim = prim->sig;
		if (prim == nullptr) // la cola se ha quedado vacía
			ult = nullptr;
		delete a_borrar;
		--nelems;
	}

	// consultar si la cola está vacía
	bool empty() const {
		return nelems == 0;
	}

	// consultar el tamaño de la cola
	int size() const {
		return nelems;
	}

	void print() {
		Nodo* aux = prim;
		while (aux != nullptr) {
			std::cout << aux->elem << " ";
			aux = aux->sig;
		}
		std::cout << "\n";
	}

	//Recorremos toda la cola con 4 pasos
		//Creamos un nodo nuevo con el elemento actual
		//Asignamos como siguiente de ese nodo al siguiente del actual
		//Cambiamos el siguiente del actual al nuevo nodo
		//Avanzamos en la cola
	void duplicar() {
		Nodo* aux = prim;
		while (aux != nullptr)
		{
			Nodo* duplicado = new Nodo(aux->elem);
			duplicado->sig = aux->sig;
			aux->sig = duplicado;
			aux = aux->sig->sig;
		}
	}

	void invertir() {
		Nodo* aux = prim;
		Nodo* anterior = nullptr;
		Nodo* anteriorAnterior = nullptr;

		while (aux != nullptr) {
			//Primer caso
			if (aux == prim) {
				anterior = aux;
			}
			//Resto de casos (a partir de 2 nodos)
			else {
				if (anteriorAnterior != nullptr) {
					anterior->sig = anteriorAnterior;	//Cambiamos la direccion del anterior
					anteriorAnterior = anterior;		//Actualizamos el anterior del anterior al anterior
					anterior = aux;						//Y actualizamos el anterior a este nodo actual
				}
				else {
					anteriorAnterior = anterior;	//El primer nodo seria el anterior del anterior
					anterior = anterior->sig;		//El segundo nodo seria el anterior
					anteriorAnterior->sig = nullptr;
					//anterior->sig = anteriorAnterior;
				}
			}
			//Ultimo caso
			if (aux->sig == nullptr) {
				Nodo* auxEnd = ult;
				ult->sig = prim;
				ult = prim;	//Cambiamos el orden el primer y ultimo nodo
				prim = auxEnd;
				anterior->sig = anteriorAnterior;
				aux = nullptr;
			}
			else
				aux = aux->sig;
		}
	}

	void colar(int pringao, queue<int>& chavales) {
		Nodo* aux = prim;
		Nodo* pringaoNode = nullptr;
		bool searching = true;
		//Buscamos el nodo del pringao y lo guardamos
		while (searching && aux != nullptr) {
			if (aux->elem == pringao) {
				searching = false;
				pringaoNode = aux;
			}
			aux = aux->sig;
		}
		if (!searching) {
			//Conectamos el final de chavales con la continuacion del pringao
			if (pringaoNode->sig != nullptr) {
				chavales.ult->sig = pringaoNode->sig;
			}
			else {
				ult->sig = chavales.ult;
				ult = chavales.ult;
			}
			//Enlazamos pringao con el principio de chavales, donde empiezan a colarse
			pringaoNode->sig = chavales.prim;
		}

		//Borro chavales
		chavales.nelems = 0;
		chavales.prim = nullptr;
		chavales.ult = nullptr;
	}
protected:

	void libera() {
		while (prim != nullptr) {
			Nodo* a_borrar = prim;
			prim = prim->sig;
			delete a_borrar;
		}
		ult = nullptr;
	}

	// this está sin inicializar
	void copia(queue const& other) {
		if (other.empty()) {
			prim = ult = nullptr;
			nelems = 0;
		}
		else {
			Nodo* act = other.prim; // recorre la cola original
			Nodo* ant = new Nodo(act->elem); // último nodo copiado
			prim = ant;
			while (act->sig != nullptr) {
				act = act->sig;
				ant->sig = new Nodo(act->elem);
				ant = ant->sig;
			}
			ult = ant;
			nelems = other.nelems;
		}
	}


};

#endif // queue_eda_h
