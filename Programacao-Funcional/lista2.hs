{- HLINT ignore "Use foldr" -}
{- HLINT ignore "Redundant list comprehension" -}
{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
{- HLINT ignore "Avoid lambda" -}
{- HLINT ignore "Use concat" -}
{- HLINT ignore "Move map inside list comprehension" -}
{- HLINT ignore "Use even" -}
{- HLINT ignore "Use map" -}
import Prelude
import Data.Char
import Distribution.Compat.Lens (_1)
import System.Win32 (xBUTTON1, UnicodeSubsetBitfield)
import Language.Haskell.TH.PprLib (sep)

-- 1 -- SOMAR TODOS QUADRADOS DE 1..100
soma :: [Int] -> Int
soma [] = 0
soma (x:xs) = x + soma xs

somaquadrados :: Int 
somaquadrados = soma [ x^2 | x <- [1..100]]

-- 2 REPLICAR ALGO X n vezes
myreplicate :: Int -> a -> [a]
myreplicate n x = [ x | _ <- [1..n]]

-- 3 SAIR TODAS COMBINAÇOES POSSIVEIS DE X^2 + Y^2 = Z^2
mypyths :: Int-> [(Int, Int, Int)] 
mypyths n = [ (x, y, z) | x <- [1..n], y <- [1..n], z <- [1..n], x^2 + y^2 == z^2 ]

-- 4
divisores :: Int -> [Int]
divisores x = [d | d <- [1..x-1], x `mod` d == 0]

myperfects :: Int -> [Int]
myperfects n = [ x | x <- [1..n], soma (divisores x) == x]

-- 5
-- Reescrita de [(x,y) | x <- [1,2,3], y <- [4,5,6]] usando concat
pairsConcat :: [(Int, Int)]
pairsConcat = concat [ [(x,y) | y <- [4,5,6]] | x <- [1,2,3]]

-- 6 -- encontra todas posiçoes de X em XS
positions :: Eq a => a-> [a]-> [Int]
positions x xs = find x (zip xs [0..n])
    where n = (length xs)- 1

find :: Eq a => a -> [(a, Int)] -> [Int]
find x pairs = [i | (a, i) <- pairs, a == x]

-- 7 
scalarproduct :: [Int]-> [Int]-> Int
scalarproduct [] [] = 0
scalarproduct as bs = soma [ a*b | (a,b) <- zip as bs ] -- (produto cartesiano) [ (a,b) | a <- as, b <- bs ] todos com todos
                                                       -- posição com posição [ a*b | (a,b) <- zip as bs ] 

-- 8 
infixr 8 &!
(&!) :: Int -> Int -> Int  
(&!) x 0 = 1                                -- ou usa (&!) só no parametro e coloca entre x e 0 (x &! 0) ou (&! x 0)
(&!) x n | n > 0 = x * (x &! (n - 1))

-- 9
-- Main> [(+7) x | x <- [1..10], odd x].
f9 :: (a -> b) -> (a -> Bool) -> [a] -> [b]
f9 f p xs = [ f x | x <- xs, p x ]

f9b :: (a -> b) -> (a -> Bool) -> [a] -> [b]
f9b f p xs = map f (filter p xs)

-- 10 
dec2int :: [Int] -> Int
dec2int [] = 0
dec2int (d:ds) = d * 10 ^ myLength ds + dec2int ds

myLength :: [a] -> Int
myLength [] = 0
myLength (a:as) = 1 + myLength as 

-- 11
--           parada(p)      h11(h)      (*2)(t)   1(x)  = lista de pot^2 ate 2^10
myunfold :: (t -> Bool) -> (t -> a) -> (t -> t) -> t -> [a]
myunfold p h t x
    | p x = []
    | otherwise = h x : myunfold p h t (t x)

parada :: Int -> Bool
parada x = x > 1024

h11 :: Int -> Int
h11 x = x

potencias2 :: [Int]
potencias2 = myunfold parada h11 (*2) 1

-- 12 
evenCubes :: Int -> [Int]
evenCubes n = mycubo [y | y <- [1..n-1], y `mod` 2 == 0]

mycubo :: [Int] -> [Int]
mycubo [] = []
mycubo (a:as) = a^3 : mycubo as

evenCubes2 :: Int -> [Int]
evenCubes2 n = map (^3) [y | y <- [1..n-1], y `mod` 2 == 0]

-- 13
insertOrd :: Int -> [Int] -> [Int]
insertOrd n xs = [x | x <- xs, x < n] ++ [n] ++ [x | x <- xs, x >= n]

-- 14
-- howManyMultiples 4 1 10 = 2
howManyMultiples :: Int -> Int -> Int -> Int
howManyMultiples x min max = myLength (filter (isMultiple x) [y | y <- [min..max]]) -- filter (a -> Bool) -> [a] - [a] /// pode usar isMultiple pois "fixamos" x ai fica (a -> Bool)

isMultiple :: Int -> Int -> Bool
isMultiple x y = y `mod` x == 0

--------------------------------------------------
-- 15
duplicate :: String -> Int -> String
duplicate s n
    | n <= 0 = "."
    | otherwise = foldr (++) "  " [s | _ <- [1..n]]

myfoldR :: (t -> u -> u) -> u -> [t] -> u 
myfoldR f s [] = s 
myfoldR f s (a:as) = f a (myfoldR f s as)

myfoldL :: (u -> t -> u) -> u -> [t] -> u 
myfoldL f s [] = s 
myfoldL f s (a:as) = myfoldL f (f s a) as 

-- 16
-- pushRight "abc" 5 = ">>abc"
pushRight :: String -> Int -> String
pushRight s n
    | n <= myLength s = s
    | otherwise = ['>' | _ <- [1..(n - myLength s)]] ++ s   

-- 17
-- inverte [1,2,3,4,5,6,150] = [150,6,5,4,3,2,1]
inverte :: [Int] -> [Int]
inverte xs = [x | x <- foldl (\acc y -> y : acc) [] xs]

-- 18
-- Main> separa [1,4,3,4,6,7,9,10] = ([1,3,7,9],[4,4,6,10])
separa :: [Int] -> ([Int], [Int])
separa as = ([ x | x <- as, x `mod` 2 == 1] , [ y | y <- as, y `mod` 2 == 0])

-- 19 
--Main> converte [1,2,6,1,9] = "ABFAI"
--Main> converte [ ] = "".
converte :: [Int] -> String
converte as = [ chr (x + 64) | x <- as ] -- chr 1 + 64 = A... e por ai vai

-- 20
-- Main> conta "ABCAABCDDA" "B" = 2
conta :: String -> Char -> Int 
conta as x = soma [ 1 | y <- as, y == x]

-- Main> proliferaInt [3,0,2,4,0,1] = [3,3,3,2,2,4,4,4,4,1]
proliferaInt :: [Int] -> [Int]
proliferaInt as = [ y | x <- as, y <- myreplicate x x]

-- 21
-- Main> proliferaChar [C,B,D] = "CCCBBDDDD"
proliferaChar :: String -> String
proliferaChar as = [ y | x <- as, y <- myreplicate2 alfabeto x]

alfabeto :: Char -> Int
alfabeto x = ord x - 64 

myreplicate2 :: (a -> Int) -> a -> [a]
myreplicate2 n x = [ x | _ <- [1..n x]]

--------------------------------- OUTRA OPÇÃO

proliferaChar2 :: String -> String
proliferaChar2 as = [ x | x <- as, _ <- [1 .. ord x - 64] ]

-- 22 
procuraElemento :: Int-> [Int]-> Bool
procuraElemento n (x:xs) = n == x || procuraElemento n xs

procuraElemento2 :: Int-> [Int]-> Bool
procuraElemento2 n (x:xs) = procuraElemento n xs || n == x

-- a) As duas estão erradas pois nao tem caso base, se nao tem n na [] da erro.
-- b) A primeira seria mais eficaz pois se n == x já da True e acaba o teste.

-- 23
checkEqual :: Eq a => a-> [a]-> Bool
checkEqual _ [] = True
checkEqual y (z:zs) = (y == z) && checkEqual y zs

allEqual :: Eq a => [a]-> Bool
allEqual [] = True
allEqual (x:xs) = checkEqual x xs

-- a) Ambas precisam de Eq para garantir que elementos comparados sejam comparaveis entre si! Sem da erro de compilação
-- b) Se fosse removida, o código não compilaria, pois a classe Eq é obrigatória para permitir que os elementos da lista sejam comparados entre si.