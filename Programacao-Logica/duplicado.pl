% consult('c:/Users/pedro/Documents/Faculdade/CienciaDaComputacao-UNIFAL/Programacao-Logica/duplicado.pl').

% buscador manual 
esta_na_lista(X, [X|_]). 
esta_na_lista(X, [_|Cauda]) :- esta_na_lista(X, Cauda).

remove_duplicados([], []). %lista vazia

remove_duplicados([H|T], ListaResult) :-
    esta_na_lista(H, T), 
    remove_duplicados(T, ListaResult).

remove_duplicados([H|T], [H|ListaResult]) :-
    \+ esta_na_lista(H, T),
    remove_duplicados(T, ListaResult).