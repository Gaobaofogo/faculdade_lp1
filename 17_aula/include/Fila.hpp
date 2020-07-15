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
  Elemento<T>* elementoAnterior;
};

template <typename T>
class Fila {
  private:
    std::size_t qntdElementos;
    Elemento<T>* primeiroElemento;
    Elemento<T>* ultimoElemento;

  public:
    Fila() {
      this->qntdElementos = 0;
      primeiroElemento = nullptr;
      ultimoElemento = nullptr;
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
      return primeiroElemento->valor;
    }

    T ultimo() {
      return ultimoElemento->valor;
    }

    void empurrar(T valor) {
      Elemento<T>* novoElemento = new Elemento<T>;
      novoElemento->valor = valor;
      novoElemento->proximoElemento = nullptr;
      novoElemento->elementoAnterior = nullptr;

      if (this->vazio()) {
        primeiroElemento = novoElemento;
        ultimoElemento = novoElemento;

        this->primeiroElemento->proximoElemento = this->ultimoElemento;
        this->ultimoElemento->elementoAnterior = this->primeiroElemento;
      } else {
        this->primeiroElemento->elementoAnterior = novoElemento;
        novoElemento->proximoElemento = this->primeiroElemento;

        this->primeiroElemento = novoElemento;
      }
    }

    void extrair() {
      if (this->vazio()) {
        throw "Não é possível extrair elementos de uma fila vazia.";
      }

      T valorDoUltimoElemento = this->ultimoElemento->valor;
      Elemento<T>* aux = this->ultimoElemento;

      this->ultimoElemento = this->ultimoElemento->elementoAnterior;

      delete aux;
    }
};

#endif
