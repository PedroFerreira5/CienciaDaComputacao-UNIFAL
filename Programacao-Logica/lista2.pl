% -- 1 
% forall(member(X,[1,2,3]),write(X)). = 123 True
% forall(between(1,5,I),(write(I*I),write(’ ’))). = 1*1 2*2 3*3 4*4 5*5 
% forall(between(10,20,I),write(I:’ ’)). = 10: .. 20:

% -- 2
a :- a(0).
a(X) :- X>10, !.
a(X) :- write(X), write(' '), X1 is X+1, a(X1).
% resultado = 0 .. 10

% -- 3
wN(0):-write(0),!.
wN(N):-write(N),N1 is N-1, wN(N1),write(N).

xxx(0) :- 
    wN(0), nl, !.
xxx(N) :-
    N > 0,
    N1 is N - 1,
    xxx(N1),      % Primeiro ele vai até o fundo do poço (vai até o 0)
    wN(N),        % Só na volta do desempilhamento ele desenha a linha atual
    nl.           % Solta a linha após desenhar

% 4 - Usando um acumulador, e somente as operações (+)(-)(*), desenvolva um predicado 
% Prolog para calcular X elevado a Y. Assuma X e Y inteiros.
elevado(X, Y, R) :-
    elevado(X, Y, 1, R).
elevado(_, 0, ACC, ACC).

elevado(X, Y, ACC, R) :-
    Y > 0,
    Y1 is Y - 1,
    NovoACC is ACC * X,         % 1º: Calcula o novo acumulador
    elevado(X, Y1, NovoACC, R). % 2º: Passa o valor já calculado para a recursão

% 5 - findall([A,B],(d(A),d(B)),L). = L = [[0, 0], [0, 1], [1, 0], [1, 1]].
d(0).
d(1).

% 6 - Defina o predicado palindromo/1, que é verdadeiro se a lista é um palı́ndromo,
% por exemplo, [a,b,c,d,c,b,a].
palindromo(Lista) :- reverse(Lista, Lista).

% ou

palindromo2(Lista) :-
    meu_reverse(Lista, Lista).

meu_reverse(Lista, Invertida) :-
    meu_reverse_aux(Lista, [], Invertida).

meu_reverse_aux([], Acc, Acc).

meu_reverse_aux([X|Xs], Acc, Resultado) :-
    meu_reverse_aux(Xs, [X|Acc], Resultado).

% - 7
metIguais(Lista) :-
    append(X, X, Lista).