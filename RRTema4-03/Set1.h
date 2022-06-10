
//  Implementación del TAD Set con array dinámico no ordenado y con repeticiones

#ifndef SET1_H
#define SET1_H

#include <utility>    // std::move

template <class T>
class Set1 {
protected:
    static const int TAM_INICIAL = 10; // tamaño inicial del array dinámico

    // número de elementos del array
    int nelems;

    // tamaño del array
    int capacidad;

    // puntero al array que contiene los datos (redimensionable)
    T* array;

public:

    // constructor: conjunto vacío
    Set1() : nelems(0), capacidad(TAM_INICIAL), array(new T[capacidad]) {}

    // destructor
    ~Set1() {
        libera();
    }

    // constructor por copia
    Set1(Set1<T> const& other) {
        copia(other);
    }

    // operador de asignación
    Set1<T> & operator=(Set1<T> const& other) {
        if (this != &other) {
            libera();
            copia(other);
        }
        return *this;
    }

    // Añadir un elemento
    void add(T const& elem) {
        array[nelems] = elem;
        ++nelems;
        if (nelems == capacidad)
            amplia();
    }

    void remove(T const& elem){
        bool found;
        int pos;
        linSearch(elem,0,nelems,found,pos);
        while (found){
            --nelems;
            array[pos] = array[nelems];
            linSearch(elem,pos,nelems,found,pos);
        }
    }

    bool contains(T const& x) const {
        bool found;
        int pos;

        linSearch(x,0,nelems,found,pos);
        return found;
    }

    // consultar si el conjunto está vacío
    bool empty() const {
        return nelems == 0;
    }

    // consultar el tamaño del array (que no tiene por que ser el tamaño del conjunto en realidad!)
    int size() const {
        return nelems;
    }

    // Devuelve el puntero del array para poder consultar desde fuera su contenido (por ej. para imprimirlo)
    const T* toArray() const{
        return array;
    }


protected:

    void libera() {
        delete[] array;
    }

    // this está sin inicializar
    void copia(Set1 const& other) {
        capacidad = other.nelems + TAM_INICIAL;
        nelems = other.nelems;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = other.array[i];
    }

    void amplia() {
        T * viejo = array;
        capacidad *= 2;
        array = new T[capacidad];
        for (int i = 0; i < nelems; ++i)
            array[i] = std::move(viejo[i]);
        delete[] viejo;
    }

    void linSearch(T const& x, int left, int right, bool& found, int& pos) const {
        // P: array tiene al menos right elementos

        int i;

        if (left >= right) {
            found = false;
            pos = right;
        } else {
            found = false;
            i = left;
            while (!found && (i < right)) {
                found = array[i] == x;
                if (!found)
                    i++;
            }
            pos = i;
        }

        // Q :  found es true si existe un i en el intervalo left..right-1
        //        tal que array[i] == x
        //      si found es true entonces pos = el minimo i en
        //        el intervalo left..right-1 tal que array[i] == x
        //      si no found entonces pos == right
    }

};

#endif //SET1_H
