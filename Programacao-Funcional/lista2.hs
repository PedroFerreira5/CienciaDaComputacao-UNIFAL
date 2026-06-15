{- HLINT ignore "Use foldr" -}
{- HLINT ignore "Redundant list comprehension" -}
import Prelude

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

