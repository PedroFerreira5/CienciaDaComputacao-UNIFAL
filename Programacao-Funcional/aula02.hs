{- HLINT ignore "Use foldr" -}
import System.Win32 (xBUTTON1)
{-Assunto: Litas
  Os conceitos introdutórios sobre listas foram apresentados em sala.
  Agora, considerando os casos mais simples, com apenas listas de inteiros,
  implemente as funções abaixo, considerando os operadores ++ e :
    ++ (concatena listas)
     : (insere um elemento na lista)
-}

{- 01 função que soma os elementos de uma lista -}
sumList::[Int]->Int
sumList [] = 0
sumList (x:xs) = x + sumList xs

{- 02-localiza elemento em lista -}
searchList :: Int -> [Int] -> Bool
searchList _ []       = False
searchList y (x:xs)   = x == y || searchList y xs

{-03 remove todas ocorrências de y em uma lista -}
deleteList::Int->[Int]->[Int]
deleteList _ [] = []
deleteList y (a:b)
  |a == y    = deleteList y b
  |otherwise = a : deleteList y b

{-04 informa o tamanho de uma lista -}
lenghtList::[Int]->Int
lenghtList [] = 0
lenghtList (x:xs) = 1 + lenghtList xs


{-05 conta a ocorrência de um Int em [Int] -}
contList::Int->[Int]->Int
contList _ [] = 0
contList x (a:b)
  |a == x     = 1 + contList x b -- sempre passar o parametro na recursividade (esqueci)
  |otherwise  = contList x b

{- 06 inverte a lista -}
reverseList:: [Int]->[Int]
reverseList [] = []
reverseList (x:xs) = reverseList xs ++ [x] -- [x] para concatenar lista, xs ja é [Int]
-- X sempre será elemento, e XS lista de algo nesse exemplo [Int]

{- 07 inverte elementos das listas internas -}

reverseInnerLists :: [[Int]] -> [[Int]]
reverseInnerLists [] = []
reverseInnerLists (x:xs) = reverseList x : reverseInnerLists xs

{- 08 função que exclui a penúltima ocorrência de um número na lista-}
--removePenultimateOccurrence :: Int -> [Int] -> [Int]
-- ????

-------------------------------------------------------------
{- Exercícios
     Implementar as funções: 
       myHead que recebe uma lista x e retorna a cabeça de x
       myTail que recebe uma lista x e retorna a lista x sem a cabeça
       myLast que recebe uma lista x e retorna o último elemento de x
       myInit que recebe uma lista x e retorna a lista x sem o último elemento
-}

myhead :: [a] -> a
myhead [] = error "lista vazia"
myhead (x:_) = x

mytail :: [a] -> [a]
mytail (a:b) = b
mytail [] = []

myLast :: [a] -> Maybe a
myLast []     = Nothing
myLast [x]    = Just x
myLast (_:xs) = myLast xs --descarta xs ate ter só x ai entra em Just x!

myInit :: [a] -> [a]
myInit [] = []
myInit [_] = []
myInit (x:xs) = x : myInit xs

meuLength :: [a] -> Int
meuLength []     = 0                      -- Caso Base
meuLength (x:xs) = 1 + meuLength xs       -- Passo Recursivo

{- função que gera uma lista de booleanos relativa à comparação entre os elementos e um parâmetro z -}
gBool :: [Int]->Int-> [Bool]
gBool [] _ = []
gBool (a:x) z = (a>z):gBool x z

{- função que reverte uma lista -}
reverte :: [a] -> [a]
reverte   []  = []
reverte (x:y) = reverte y ++ [x]
