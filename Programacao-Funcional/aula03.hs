{- HLINT ignore "Use foldr" -}
import Prelude hiding (head, tail)
import System.Win32 (xBUTTON1)
{- Assunto: listas e tuplas -}

periodo::Int
periodo = 7

maxi :: Int -> Int -> Int
maxi m n
   |m >= n = m
   |otherwise = n


-- tabela de vendas
vendas :: Int -> Int
vendas 0 = 0
vendas 1 = 41
vendas 2 = 72
vendas 3 = 48
vendas 4 = 0
vendas 5 = 91
vendas 6 = 55
vendas 7 = 29

{- 01 função que retorna uma lista de vendas -}
listaVendas :: Int-> [Int]
listaVendas 0 = []
listaVendas x = vendas x : listaVendas (x-1)


{- 02 função que retorna [[Int]] com listas de dia e venda -}

f2L::Int->[[Int]]
f2L 0 = []
f2L x = [x,vendas x]:f2L (x-1)  
----------------------------------------------------------
{- 03 função que ordena uma lista de inteiros -}

ordenaLista :: [Int] -> [Int]
ordenaLista [] = []
ordenaLista (a:b) = insereOrdenado a (ordenaLista b)

insereOrdenado :: Int -> [Int] -> [Int]
insereOrdenado x [] = [x]
insereOrdenado x (y:ys)
   | x <= y = x : y : ys
   | otherwise = y : insereOrdenado x ys



-------------------------------------------------------------------------
{- 04 função que ordena [[Int]] pelo primeiro Int de cada lista  -}
ordenaListaLista::[[Int]]->[[Int]]
ordenaListaLista [] = []
ordenaListaLista (x:xs) = insereListaLista x (ordenaListaLista xs)

insereListaLista :: [Int] -> [[Int]] -> [[Int]]
insereListaLista x [] = [x]
insereListaLista x (y:ys)
   | comparaHead x y = x : y : ys
   | otherwise = y : insereListaLista x ys

comparaHead :: [Int] -> [Int] -> Bool
comparaHead (x:_) (y:_) = x <= y
comparaHead [] _ = True
comparaHead _ [] = False

---------------------------------------------------------------------------
{- 05 função que ordena as listas internas de [[Int]] e, em seguida, ordena a [[Int]] -}
--ordenaLILE::[[Int]] ->[[Int]]
-----------  tuplas --------------------------------------------------------
{- 06 função que gera uma lista de tuplas com dia e venda -}
f6T :: Int-> [(Int, Int)]
f6T 0 = []
f6T x = (x,vendas x):f6T (x-1)

{- 07 função que gera o total de vendas-}
--totalVendasT::[(Int, Int)] -> Int



{- 08 função que retorna a maior venda -}
 
--maiorVendasT8a::Int-> [(Int, Int)] -> Int 
  
{- 08-b como implementar com apenas os parâmetros? -}
maiorVendaT8b::[(Int, Int)] -> Int    
maiorVendaT8b [] = 0
maiorVendaT8b ((a,b):c) = maxi b (maiorVendaT8b c)

maiorVendaT8c::[(Int, Int)] -> Int    
maiorVendaT8c [] = 0
maiorVendaT8c (a:c) = maxi (snd a) (maiorVendaT8c c)

tail :: [a] -> [a]
tail (a:b) = b
tail [] = []

head :: [a] -> a
head [] = error "lista vazia"
head (x:_) = x

maiorVendaT8d :: [(Int, Int)] -> Int
maiorVendaT8d [] = 0
maiorVendaT8d c = maxi (snd (head c)) (maiorVendaT8d (tail c))
{- 09 função que retorna os dias das maiores vendas -}



