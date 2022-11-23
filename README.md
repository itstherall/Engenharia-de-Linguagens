# Potrex - Uma linguagem para quem precisa de expressões regulares

Linguagem desenvolvida para o curso de Engenharia-de-Linguagens do curso de Engenharia de Software da UFRN no semestre 2022.2.

(1) Introdução: visão geral do projeto

Potrex é uma linguagem de propósito geral de implementação híbrida (compilada e interpretada) que visa a simplificação do trabalho com estruturas de texto. Nesta linguagem a manipulação de estrutura de texto e recursos como os de RegEx são mais intuitivos.


(2) Design da implementação:
      (A) Transformação do código-fonte em unidades léxicas;
      (B) Representação de símbolos, tabela de símbolos e funções associadas;
      (C) Tratamento de estruturas condicionais e de repetição;
      (D) Tratamento de subprogramas;
      (E) Verificações realizadas (tipos, faixas, declaração em duplicidade, etc).


(3) Instruções de uso do compilador.

Para rodar um programa nesta linguagem primeiramente rode o analisador léxico localizado na pasta 'analisador' (arquivo 'lexer.l'):
```
lex lexer.l
```
Em seguida rode o analisador sintático localizado na mesma pasta (arquivo 'parser.y') 
 ```
yacc parser.y -d -v -g
```
onde a flag -d gera o arquivo 'y.tab.h', já a flag -v gera o arquivo 'y.output' e a flag -g gera o arquivo 'y.dot' que pode ser usado com um programa (e.g. GraphViz) para visualização do DFA do analisador.

Por fim, precisamos usar um compilador C para gerar o executável do analisador:
```
gcc lex.yy.c y.tab.c -o parser.exe 
```
Para passar um arquivo no executável gerado:
```
./parser < input.txt
```

Na pasta samples o programa 'programaTeste1.txt' pode ser analisado pelo parser gerado.
