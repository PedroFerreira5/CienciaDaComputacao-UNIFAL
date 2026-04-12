troca([], _ , _ , ListaResult) :- write('Lista vazia'), nl.

% cabeça a ser trocada
troca([Velha | T], Velha, Novo, [Novo, ListaResult]) :-
    troca(T, Velho, Novo, ListaResult).

% Caso 3: A cabeça da lista é diferente do elemento velho
% Usamos 'H' e 'Velho' (nomes diferentes) e confirmamos com \=
troca([H|T], Velho, Novo, [H|ListaResult]) :-
    H \= Velho,
    % Chamada recursiva para processar o resto da lista
    troca(T, Velho, Novo, ListaResult).