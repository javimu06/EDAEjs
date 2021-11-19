//
//  bintree_eda.h
//
//  Implementación de árboles binarios (con compartición de nodos)
//  con recorridos en profundidad y por niveles
//  e iterador para recorrer en inorden (basado en una pila de
//  antecesores pendientes)
//
//  Estructuras de Datos
//  Facultad de Informática
//  Universidad Complutense de Madrid
//
//  Copyright (c) 2020 Alberto Verdejo
//

#ifndef bintree_eda_h
#define bintree_eda_h

#include <memory>   // shared_ptr, make_shared
#include <stdexcept>
#include <stack>
#include <vector>
#include <queue>
#include <iostream>

template <class T>
class bintree {
protected:
	/*
	 Nodo que almacena internamente el elemento (de tipo T),
	 y punteros al hijo izquierdo y derecho, que pueden ser
	 nullptr si el hijo es vacío (no existe).
	 */
	struct TreeNode;
	using Link = std::shared_ptr<TreeNode>;
	struct TreeNode {
		TreeNode(Link const& l, T const& e, Link const& r) : elem(e), left(l), right(r) {};
		T elem;
		Link left, right;
	};

	// puntero a la raíz del árbol
	Link raiz;

	// constructora privada
	bintree(Link const& r) : raiz(r) {}

public:
	// árbol vacío
	bintree() : raiz(nullptr) {}

	// árbol hoja
	bintree(T const& e) :
		raiz(std::make_shared<TreeNode>(nullptr, e, nullptr)) {}

	// árbol con dos hijos
	bintree(bintree<T> const& l, T const& e, bintree<T> const& r) :
		raiz(std::make_shared<TreeNode>(l.raiz, e, r.raiz)) {}

	// constructora por copia, operador de asignación y destructora por defecto

	// consultar si el árbol está vacío
	bool empty() const {
		return raiz == nullptr;
	}

	// consultar la raíz
	T const& root() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene raiz.");
		else return raiz->elem;
	}

	// consultar el hijo izquierdo
	bintree<T> left() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo izquierdo.");
		else return bintree<T>(raiz->left);
	}

	// consultar el hijo derecho
	bintree<T> right() const {
		if (empty()) throw std::domain_error("El arbol vacio no tiene hijo derecho.");
		else return bintree(raiz->right);
	}


	// recorridos

	std::vector<T> preorder() const {
		std::vector<T> pre;
		preorder(raiz, pre);
		return pre;
	}

	std::vector<T> inorder() const {
		std::vector<T> in;
		inorder(raiz, in);
		return in;
	}

	std::vector<T> postorder() const {
		std::vector<T> post;
		postorder(raiz, post);
		return post;
	}

	std::vector<T> levelorder() const {
		std::vector<T> levels;
		if (!empty()) {
			std::queue<Link> pendientes;
			pendientes.push(raiz);
			while (!pendientes.empty()) {
				Link sig = pendientes.front();
				pendientes.pop();
				levels.push_back(sig->elem);
				if (sig->left != nullptr)
					pendientes.push(sig->left);
				if (sig->right != nullptr)
					pendientes.push(sig->right);
			}
		}
		return levels;
	}

	//!Declara s = 0 y lo pasa para ir sumando el numero de nodos
	int nodos() {
		int nNodos = 0;
		cuentaNodos(raiz, nNodos);
		return nNodos;
	}
	//!Va sumando los nodos que cuenta a s
	void cuentaNodos(const Link node, int& nNodos) {
		if (node != nullptr) {
			cuentaNodos(node->left, nNodos);
			cuentaNodos(node->right, nNodos);
			nNodos++;
		}
	}
	//!Metodo que crea y devuelve un vector con cada una de las hojas
	int hojas() {
		int nHojas = 0;
		cuentaHojas(raiz, nHojas);
		return nHojas;
	}
	//!Rellena el vector de las hojas si son hojas
	void cuentaHojas(const Link Node, int& nHojas) {
		if (Node != nullptr) {
			//!Si el nodo no tiene elementos a izquierda ni derecha, es porque es una hoja, la metemos en el vector
			if (Node->left == nullptr && Node->right == nullptr)
				nHojas++;
			else {
				//!Si no, comprobamos si alguna de sus hijas es hoja
				cuentaHojas(Node->left, nHojas);
				cuentaHojas(Node->right, nHojas);
			}
		}
	}

	//Duplicamos los metodos de hojas y los adaptamos para que rellenen el vector nHojas
	//Las hojas son los nodos que forman la frontera, que queremos imprimir
	//Guardamos cada hoja cuando la encontremos
	std::vector<int> hojasVector() {
		std::vector<int> nHojas;
		cuentaHojasVector(raiz, nHojas);
		return nHojas;
	}

	void cuentaHojasVector(const Link Node, std::vector<int>& nHojas) {
		if (Node != nullptr) {
			//!Si el nodo no tiene elementos a izquierda ni derecha, es porque es una hoja, la metemos en el vector
			if (Node->left == nullptr && Node->right == nullptr)
				nHojas.push_back(Node->elem);
			else {
				//!Si no, comprobamos si alguna de sus hijas es hoja
				cuentaHojasVector(Node->left, nHojas);
				cuentaHojasVector(Node->right, nHojas);
			}
		}
	}

	//!Va sumando los caminos que cuenta a s y declara max para guardar el numero maximo de caminos que cuente
	int camino() {
		int nCaminos = 0;			//Cuenta los caminos por iteracion
		int maxCamino = 0;			//Guarda el camino más largo, que seria la altura
		cuentaCaminos(raiz, nCaminos, maxCamino);
		return maxCamino;
	}
	//!Cuenta los caminos hasta que llega a un nodo nulo
	void cuentaCaminos(const Link nodo, int nCaminos, int& maxCamino) {
		//!Si el nodo no es nulo, aumenta s
		if (nodo != nullptr) {
			nCaminos++;
			cuentaCaminos(nodo->left, nCaminos, maxCamino);
			cuentaCaminos(nodo->right, nCaminos, maxCamino);
		}
		//!Si el nodo es nulo, comprueba si los caminos obtenidos para llegar a el son el numero maximo
		else {
			if (maxCamino < nCaminos) maxCamino = nCaminos;
		}
	}

	int encuentraMultiploAccesible(int& caminoMax) {
		int camino = 0;
		caminoMax;	//El camino mas largo posible esta compuesto por todos los nodos - 1
		int multiplo = 7;
		int solucion = -1;				//No hay solucion al principio
		calulaMultiploAccesible(raiz, solucion, caminoMax, camino, multiplo);
		return solucion;
	}
	bool Primo(int n) {
		int longitud = n / 2;
		for (int i = 2; i <= longitud; i++) {
			if (n % i == 0)	//Si el numero es divisible entre cualquiera del 1 hasta la mitad de su valor, no es primo
				return false;
		}
		return true;
	}
	void calulaMultiploAccesible(const Link nodo, int& solucion, int& caminoMax, int camino, const int multiplo) {
		//Si el nodo no es nulo
		if (nodo != nullptr) {
			if (!Primo(nodo->elem)) {
				//Si el numero no es primo y es multiplo de 7
				if (nodo->elem % 7 == 0) {

					//Si el caminoMaximo es mas largo que el camino actual, encontramos solucion
					if (caminoMax > camino) {
						caminoMax = camino;
						solucion = nodo->elem;
					}
				}

				calulaMultiploAccesible(nodo->left, solucion, caminoMax, camino + 1, multiplo);
				calulaMultiploAccesible(nodo->right, solucion, caminoMax, camino + 1, multiplo);
			}
		}
	}
protected:
	static void preorder(Link a, std::vector<T>& pre) {
		if (a != nullptr) {
			pre.push_back(a->elem);
			preorder(a->left, pre);
			preorder(a->right, pre);
		}
	}

	static void inorder(Link a, std::vector<T>& in) {
		if (a != nullptr) {
			inorder(a->left, in);
			in.push_back(a->elem);
			inorder(a->right, in);
		}
	}

	static void postorder(Link a, std::vector<T>& post) {
		if (a != nullptr) {
			postorder(a->left, post);
			postorder(a->right, post);
			post.push_back(a->elem);
		}
	}

public:
	// iterador que recorre el árbol en inorden
	class const_iterator {
	public:
		T const& operator*() const {
			if (ptr == nullptr) throw std::out_of_range("fuera del arbol");
			return ptr->elem;
		}

		T const* operator->() const {
			return &operator*();
		}

		bool operator==(const_iterator const& other) const {
			return ptr == other.ptr;
		}
		bool operator!=(const_iterator const& other) const {
			return !(*this == other);
		}

		const_iterator& operator++() {  // ++ prefijo
			next();
			return *this;
		}

	private:
		friend class bintree;
		Link ptr;
		std::stack<Link> ancestros;

		// constructores privados
		// construye el iterador al primero
		const_iterator(Link raiz) { ptr = first(raiz); }

		// construye el iterador al último
		const_iterator() : ptr(nullptr) {}

		Link first(Link act) {
			if (act == nullptr) {
				return nullptr;
			}
			else {
				while (act->left != nullptr) {
					ancestros.push(act);
					act = act->left;
				}
				return act;
			}
		}

		void next() {
			if (ptr == nullptr) {
				throw std::range_error("El iterador no puede avanzar");
			}
			else if (ptr->right != nullptr) { // primero del hijo derecho
				ptr = first(ptr->right);
			}
			else if (ancestros.empty()) { // hemos llegado al final
				ptr = nullptr;
			}
			else { // podemos retroceder
				ptr = ancestros.top();
				ancestros.pop();
			}
		}

	};

	const_iterator begin() const {
		return const_iterator(raiz);
	}
	const_iterator end() const {
		return const_iterator();
	}

};

// lee un árbol binario de la entrada estándar
template <typename T>
//!Se pasa un elemento vacio para comprobar si la raiz es vacia, la raiz es el primer elemento que lee
inline bintree<T> leerArbol(T vacio) {
	T raiz;
	std::cin >> raiz;
	if (raiz == vacio) { // es un árbol vacío
		return {};
	}
	else { // leer recursivamente los hijos
		auto iz = leerArbol(vacio);
		auto dr = leerArbol(vacio);
		return { iz, raiz, dr };
	}
}
#endif // bintree_eda_h
