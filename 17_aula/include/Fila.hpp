#ifndef FILA_HPP
#define FILA_HPP

/*
Funções da fila foram retiradas como ideia da especificação de "queue" da STL do C++:
http://www.cplusplus.com/reference/queue/queue/
*/

#include <iostream>

template <typename T>
struct Elemento {
  T valor;
  Elemento<T>* proximoElemento;
};

template <typename T>
class Fila {
  private:
    std::size_t qntdElementos;
    Elemento<T>* primeiroElemento;

  public:
    Fila() {
      this->qntdElementos = 0;
      primeiroElemento = nullptr;
    }

    ~Fila() {
      while (!this->vazio()) {
        this->extrair();
      }
    }

    bool vazio() {
      return qntdElementos == 0;
    }

    std::size_t tamanho() {
      return this->qntdElementos;
    }

    T primeiro() {
      if (this->vazio()) {
        throw "Não é possível percorrer uma fila vazia.";
      }

      Elemento<T>* aux = this->primeiroElemento;
      
      while (aux->proximoElemento != nullptr) {
        aux = aux->proximoElemento;
      }

      return aux->valor;
    }

    T ultimo() {
      return this->primeiroElemento->valor;
    }

    void empurrar(T valor) {
      if (this->vazio()) {
        this->primeiroElemento = new Elemento<T>;
        this->primeiroElemento->valor = valor;
        this->primeiroElemento->proximoElemento = nullptr;
      } else {
        Elemento<T>* novoElemento = new Elemento<T>;
        novoElemento->valor = valor;

        novoElemento->proximoElemento = this->primeiroElemento;
        this->primeiroElemento = novoElemento;
      }

      ++qntdElementos;
    }

    void extrair() {
      if (this->vazio()) {
        throw "Não é possível extrair elementos de uma fila vazia.";
      }

      Elemento<T>* aux = this->primeiroElemento;
      Elemento<T>* penultimo_elemento = this->primeiroElemento;

      while (aux->proximoElemento != nullptr) {
        penultimo_elemento = aux;
        aux = aux->proximoElemento;
      }

      penultimo_elemento->proximoElemento = nullptr;

      delete aux;

      this->qntdElementos -= 1;
    }
};

#endif
