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
      return &this->elementos[this->qntdElementos];
    }

    void push_back(const T& novoElemento) {
      if (this->size() == this->capacity()) {
        this->capacidade *= 2;
        T* novo_vector = new T[this->capacidade];

        for (size_t i = 0; i < this->size(); ++i) {
          novo_vector[i] = this->elementos[i];
        }

        T* aux = this->elementos;
        this->elementos = novo_vector;

        delete[] aux;
        novo_vector = nullptr;
        aux = nullptr;
      }

      this->elementos[this->qntdElementos] = novoElemento;
      this->qntdElementos += 1;
    }

    size_t size() const {
      return this->qntdElementos;
    }

    size_t capacity() const {
      return this->capacidade;
    }

    T& operator[](size_t i) const {
      return this->elementos[i];
    }

    T& at(size_t i) const {
      return this->elementos[i];
    }

    vector_supermercado<T>& operator=(const vector_supermercado<T>& outro_vector) {
      delete[] this->elementos;

      this->capacidade = outro_vector.capacity();
      this->qntdElementos = outro_vector.size();
      this->elementos = new T[this->capacidade];

      for (size_t i = 0; i < this->size(); ++i) {
        this->elementos[i] = outro_vector[i];
      }

      return *this;
    }
};

#endif
