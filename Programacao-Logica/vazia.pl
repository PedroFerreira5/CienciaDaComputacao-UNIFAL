% consult('c:/Users/pedro/Documents/Faculdade/CienciaDaComputacao-UNIFAL/Programacao-Logica/vazia.pl').
analisa_lista([]) :- 
    write('A lista esta vazia'), nl.

analisa_lista([H|T]) :- 
    write('A cabeca é: '), write(H), nl,
    write('A cauda é: '), write(T), nl.