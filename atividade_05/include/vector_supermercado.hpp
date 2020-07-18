#ifndef VECTOR_SUPERMERCADO_HPP
#define VECTOR_SUPERMERCADO_HPP

#include <iostream>

template <typename T>
class vector_supermercado {
  private:
    T* elementos;
    size_t qntdElementos;
    size_t capacidade;

  public:
    vector_supermercado() {
      this->capacidade = 1;
      this->qntdElementos = 0;
      this->elementos = new T[1];
    }

    ~vector_supermercado() {
      delete[] this->elementos;
    }

    T* begin() {
      return &this->elementos[0];
    }

    T* end() {
      return &this->elementos[this->qntdElementos + 1];
    }

    void push_back(T novoElemento) {
      if (this->size() == this->capacity()) {
        this->capacidade *= 2;
        T* novo_vector = new T[this->capacidade];

        for (size_t i = 0; i < this->size(); ++i) {
          novo_vector[i] = this->elementos[i];
        }

        delete[] this->elementos;
        this->elementos = novo_vector;
      }

      this->elementos[this->qntdElementos] = novoElemento;
      this->qntdElementos += 1;
    }

    size_t size() {
      return this->qntdElementos;
    }

    size_t capacity() {
      return this->capacidade;
    }

    T& operator[](size_t i) {
      if (i > this->size()) {
        std::cerr << "Índice maior que o tamanho do array";
        exit(1);
      }

      return this->elementos[i];
    }

    T& at(size_t i) {
      return this->elementos[i];
    }

    T& operator=(T outro_vector) {
      T* novo_vector = new T[outro_vector.size()];

      for (size_t i = 0; i < outro_vector.size(); ++i) {
        novo_vector[i] = outro_vector[i];
      }

      delete[] this->elementos;

      this->elementos = novo_vector;
      this->capacidade = outro_vector.capacity();
      this->qntdElementos = outro_vector.size();
    }
};

#endif
