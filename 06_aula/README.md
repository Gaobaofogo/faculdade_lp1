##Como compilar o programa:

Primeiro precisamos gerar os arquivos objetos. Para gerar, rode os comandos:

```
$ cd src
$ g++ -Wall -std=c++11 -c -I../include *.cpp
```

Com os arquivos objetos em mãos, hora de gerar o executável:

```
$ g++ -Wall -std=c++11 -o prog *.o
```
