% consult('c:/Users/pedro/Documents/Faculdade/CienciaDaComputacao-UNIFAL/Programacao-Logica/compara.pl').
compara([], []). %lista vazia

% Passo Recursivo: Se as duas listas têm pelo menos um elemento,
compara([_|Resto1], [_|Resto2]) :- 
    compara(Resto1, Resto2).