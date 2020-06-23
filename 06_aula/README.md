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

### Observações

Retirei a ideia do readme a partir desse link: https://github.com/amelco/lp1-2020.5/blob/master/aula06/refactor/README.md
