## Como compilar o programa:

Primeiro precisamos gerar os arquivos objetos. Para gerar, rode os comandos:

```
$ cd src
$ g++ -Wall -std=c++11 -c -I../include *.cpp
```

Com os arquivos objetos em mãos, hora de gerar o executável:

```
$ g++ -Wall -std=c++11 -o prog *.o
```

## Testes

Por enquanto, só estou testando o diário para evitar vazamento de memória e inserir corretamente as mensagens dentro do diário. Usei o Valgrind para checar erros de vazamento
de memória. Para executar o teste existente, compile da seguinte forma:

```
$ g++ -Wall -std=c++11 -c -I../include *.cpp ../src/Diary.cpp
$ g++ -Wall -std=c++11 -o prog *.o
```

A saída esperada é:

```
$ ./prog
51
60
```

Para executar com o Valgrind(supondo que já esteja instalado):

```
$ valgrind --leak-check=yes ./prog
```

### Observações

Retirei a ideia do readme a partir desse link: https://github.com/amelco/lp1-2020.5/blob/master/aula06/refactor/README.md
