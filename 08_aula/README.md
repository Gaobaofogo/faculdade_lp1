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

Estou usando o [Catch2](https://github.com/catchorg/Catch2) para realizar os testes e o [Valgrind](https://www.valgrind.org/) para garantir que não haja vazamento de memória. Para compilar os testes de unidade:

```
$ cd test
$ g++ -Wall -std=c++11 -c -I ../include/ HourTest.cpp DateTest.cpp DiaryTest.cpp MainTest.cpp ../src/Date.cpp ../src/Hour.cpp ../src/helper_time.cpp ../src/Date.cpp ../src/Diary.cpp 
$ g++ -Wall -std=c++11 -o prog *.o
```

Para executar:

```
$ ./prog
```

Para executar com o Valgrind(supondo que já esteja instalado):

```
$ valgrind --leak-check=yes ./prog
```

### Observações

Retirei a ideia do readme a partir desse link: https://github.com/amelco/lp1-2020.5/blob/master/aula06/refactor/README.md
