{- HLINT ignore "Use foldr" -}
{- HLINT ignore "Redundant list comprehension" -}
{-# OPTIONS_GHC -Wno-overlapping-patterns #-}
import Prelude
import Data.Char
import Distribution.Compat.Lens (_1)

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