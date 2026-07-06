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

% - 8 
insOrd(X, [H|T], [X, H|T]) :- X =< H, !.

insOrd(X, [], [X]).
insOrd(X, [H|T], [H|Resultado]) :- insOrd(X, T, Resultado).

% - 9
particiona([], [], []).

particiona([X], [X], []). % Impar

% Caso Recursivo: Tira dois elementos (X e Y) da lista original.
% Coloca X na primeira lista, Y na segunda lista e continua para o resto (T).
particiona([X, Y | T], [X | L1], [Y | L2]) :- 
    particiona(T, L1, L2).

% - 10
% Casos Base: Se uma das listas estiver vazia, o resultado é a outra lista.
merge([], Lista2, Lista2).
merge(Lista1, [], Lista1).

% Se o topo da primeira lista (H1) for menor ou igual ao topo da segunda (H2)
merge([H1|T1], [H2|T2], [H1|Result]) :-
    H1 =< H2, !,
    merge(T1, [H2|T2], Result).

% Se o topo da segunda lista (H2) for menor que o da primeira (H1)
merge([H1|T1], [H2|T2], [H2|Result]) :-
    merge([H1|T1], T2, Result).

% - 11 Resposta = O cut deve ser colocado após a condição de teste
max(X, Y, X) :- X > Y, !.
max(X, Y, Y) :- X =< Y.

% - 14
transforma('encher o jarro 1', [X, Y], [3, Y]) :- X < 3.
transforma('encher o jarro 2', [X, Y], [X, 4]) :- Y < 4.

% 2. Esvaziar os jarros
transforma('esvaziar o jarro 1', [X, Y], [0, Y]) :- X > 0.
transforma('esvaziar o jarro 2', [X, Y], [X, 0]) :- Y > 0.

% 3. Transferir até ESVAZIAR o jarro de origem (tudo cabe no destino)
transforma('transferir do jarro 1 para o 2', [X, Y], [0, N_Y]) :- 
    X > 0, Y < 4,
    N_Y is X + Y, N_Y =< 4.

transforma('transferir do jarro 2 para o 1', [X, Y], [N_X, 0]) :- 
    Y > 0, X < 3,
    N_X is X + Y, N_X =< 3.

% 4. Transferir onde AINDA RESTARÁ água no jarro de origem (o destino enche até o topo)
transforma('transferir do jarro 1 para o 2', [X, Y], [N_X, 4]) :- 
    X > 0, Y < 4,
    N_X is X - (4 - Y), N_X >= 0.

transforma('transferir do jarro 2 para o 1', [X, Y], [3, N_Y]) :- 
    Y > 0, X < 3,
    N_Y is Y - (3 - X), N_Y >= 0.

