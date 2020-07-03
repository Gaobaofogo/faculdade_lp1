## Como compilar o programa:

Para gerar o executável:

```
$ make
```

Para rodar o programa, execute a linha a seguir:

```
$ ./prog
```

## Testes

Estou usando o [Catch2](https://github.com/catchorg/Catch2) para realizar os testes e o [Valgrind](https://www.valgrind.org/) para garantir que não haja vazamento de memória. Para compilar os testes de unidade:

```
$ make test
```

Para rodas os testes:

```
$ ./prog_test
```

Para executar com o Valgrind(supondo que o programa já esteja instalado e os testes foram compilados):

```
$ valgrind --leak-check=yes ./prog_test
```

### Observações

Retirei a ideia do readme a partir desse link: https://github.com/amelco/lp1-2020.5/blob/master/aula06/refactor/README.md
