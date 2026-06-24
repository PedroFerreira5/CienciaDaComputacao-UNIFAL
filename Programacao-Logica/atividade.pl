% ============================================
% Atividade 1 - Ordenacao de listas de listas
% lsort/2  -> ordena pelo TAMANHO das sublistas
% lfsort/2 -> ordena pela FREQUENCIA do tamanho
%
% ============================================

tamanho([], 0).
tamanho([_|T], N) :- tamanho(T, N1), N is N1 + 1.

insere(P, [], [P]).
insere(C-L, [C2-L2|Resto], [C-L, C2-L2|Resto]) :-
    C =< C2.
insere(C-L, [C2-L2|Resto], [C2-L2|NovoResto]) :-
    C > C2,
    insere(C-L, Resto, NovoResto).

% Ordena uma lista de pares Chave-Valor
ordena_pares([], []).
ordena_pares([P|Ps], Ordenada) :-
    ordena_pares(Ps, OrdenadaResto),
    insere(P, OrdenadaResto, Ordenada).

remove_chave([], []).
remove_chave([_-L|Resto], [L|RestoL]) :-
    remove_chave(Resto, RestoL).

% PARTE A
associa_tamanho([], []).
associa_tamanho([L|Ls], [T-L|Resto]) :-
    tamanho(L, T),
    associa_tamanho(Ls, Resto).

lsort(InList, OutList) :-
    associa_tamanho(InList, Pares),
    ordena_pares(Pares, ParesOrdenados),
    remove_chave(ParesOrdenados, OutList).

% PARTE B

comprimento(_, [], 0).
comprimento(T, [L|Ls], N) :-
    tamanho(L, T2),
    comprimento(T, Ls, N1),
    ( T == T2 -> N is N1 + 1 ; N = N1 ).

frequencia(_, [], []).
frequencia(InList, [L|Ls], [F-L|Resto]) :-
    tamanho(L, T),
    comprimento(T, InList, F),
    frequencia(InList, Ls, Resto).

lfsort(InList, OutList) :-
    frequencia(InList, InList, Pares),
    ordena_pares(Pares, ParesOrdenados),
    remove_chave(ParesOrdenados, OutList).
