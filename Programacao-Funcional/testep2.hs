{- HLINT ignore "Eta reduce" -}
{- HLINT ignore "Avoid lambda" -}
import System.Win32.Automation.Input (xBUTTON1)
duplicaCuboImpar :: [Int] -> [Int]
duplicaCuboImpar xs = [ x^3 | x <- xs, x `mod` 2 /= 0 , y <- [1..2] ]

-- Insere um elemento na posição correta de uma lista já ordenada
insereOrd :: Int -> [Int] -> [Int]
insereOrd n [] = [n]
insereOrd n (x:xs)
  | n <= x    = n : x : xs
  | otherwise = x : insereOrd n xs

-- Função principal de ordenação por recursão
ordenaLista :: [Int] -> [Int]
ordenaLista []     = []
ordenaLista (x:xs) = insereOrd x xs 

ordenaListaDupla :: [(Bool, [Int])] -> [(Bool, [Int])]
ordenaListaDupla [] = []
ordenaListaDupla ((True, lista) : xs) = (False, ordenaLista lista) : ordenaListaDupla xs
ordenaListaDupla ((False, lista) : xs) = (False, lista) : ordenaListaDupla xs

processaLista :: (a -> b) -> (a -> Bool) -> [a] -> [b]
processaLista _ _ [] = []
processaLista f p (x:xs)
  | p x   = f x : processaLista f p xs
  | otherwise = processaLista f p xs

inverteLista :: [a] -> [a]
inverteLista xs = foldl (\acc x -> x : acc) [] xs