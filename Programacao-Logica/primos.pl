% consult('c:/Users/pedro/Documents/Faculdade/CienciaDaComputacao-UNIFAL/Programacao-Logica/primos.pl').
homem(joao).
homem(alberto).
homem(lucas).
homem(pedro).
homem(leandro).
homem(leonardo).
homem(julio).
homem(eduardo).

mulher(maria).
mulher(claudia).
mulher(regina).
mulher(jasmine).
mulher(julia).
mulher(alice).

pai(joao, claudia).
pai(joao, alberto).
pai(pedro, lucas).
pai(lucas, leandro).
pai(lucas, leonardo).
pai(julio, jasmine).
pai(alberto, eduardo).
pai(alberto, alice).

mae(maria, claudia).
mae(maria, alberto).
mae(regina, lucas).
mae(claudia, leonardo).
mae(claudia, leandro).
mae(julia, jasmine).
mae(jasmine, eduardo).
mae(jasmine, alice).

casado(joao, maria).
casado(lucas, claudia).
casado(julio, julia).
casado(pedro, regina).
casado(alberto, jasmine).

irmao(X, Y) :-
    genitor(P, X), genitor(P, Y),
    genitor(M, X), genitor(M, Y),
    X \== Y.

% 1. Criamos uma regra auxiliar: "P é genitor de X se P é pai OU P é mãe"
genitor(P, X) :- pai(P, X).
genitor(P, X) :- mae(P, X).

% 2. Agora a regra de primo fica completa e simples:
primo(X, Y) :-
    genitor(G1, X),    
    genitor(G2, Y),   
    irmao(G1, G2),    
    X \== Y.         


filho(X, P, M) :- 
    pai(P, X), 
    mae(M, X).




