{- HLINT ignore "Use foldr" -}
{- HLINT ignore "Redundant list comprehension" -}
{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
{- HLINT ignore "Move map inside list comprehension" -}
{- HLINT ignore "Use even" -}
{- HLINT ignore "Use map" -}
import Prelude
import Data.Char
import Distribution.Compat.Lens (_1)
import System.Win32 (xBUTTON1)

-- 1
soma :: [Int] -> Int
soma [] = 0
soma (x:xs) = x + soma xs

somaquadrados :: Int
somaquadrados = soma [ x^2 | x <- [1..100]]

-- 2
myreplicate :: Int -> a -> [a]
myreplicate n x = [ x | _ <- [1..n]]

-- 3
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

-- 6
positions :: Eq a => a-> [a]-> [Int]
positions x xs = find x (zip xs [0..n])
    where n = (length xs)- 1

find :: Eq a => a -> [(a, Int)] -> [Int]
find x pairs = [i | (a, i) <- pairs, a == x]

-- 7 
scalarproduct :: [Int]-> [Int]-> Int
scalarproduct [] [] = 0
scalarproduct as bs = soma [ a*b | (a,b) <- myZip as bs ] -- (produto cartesiano) [ (a,b) | a <- as, b <- bs ] todos com todos
                                                       -- posição com posição [ a*b | (a,b) <- zip as bs ] 

myZip :: [a] -> [b] -> [(a,b)]
myZip (x:xs) (y:ys) = (x,y) : myZip xs ys
myZip _ _ = []

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
