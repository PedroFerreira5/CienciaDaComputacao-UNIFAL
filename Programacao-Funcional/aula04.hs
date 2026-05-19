{- objetivo: trabalhar tipos distintos entre listas e tuplas -}

import Data.Char

------------------------------------------------------
{- 01 função que separa [(Int,Char)] em ([Int],[Char]) -}
myUnzip :: [(Int, Char)] -> ([Int], [Char])
myUnzip [] = ([], [])
myUnzip ((n, c):xs) = (n : ns, c : cs)
  where (ns, cs) = myUnzip xs

{- 02 versão em uma única função -}
myUnzipU :: [(Int, Char)] -> ([Int], [Char])
myUnzipU = foldr (\(n, c) (ns, cs) -> (n:ns, c:cs)) ([], [])

------------------------------------------------------------
{- 03 função que junta duas listas em lista de duplas -}
myZip::[Bool]->[Char] ->[(Bool,Char)]  
myZip (x:xs)(y:ys) = (x, y) : myZip xs ys 
myZip _ _ = []

{- 04 função que recebe [Char] e retorna [(Bool,Char)] 
   True se Char for alfanumérico e False, caso contrário -}
setAlfa::String -> [(Bool,Char)] 
setAlfa [] = []
setAlfa (a:b) = (((ord a) >= (ord '0')) && ((ord a) <= (ord '9')),a) : setAlfa b

{- 05 função que recebe [(Bool, Char)] e filtra alfanuméricos -}
filtraAlfa:: [(Bool,Char)] -> String
filtraAlfa [] = []
filtraAlfa (a:b)
    | fst a = snd a : filtraAlfa b
    | otherwise = filtraAlfa b 

{- 06 função transforma String de alfa em Lista de Int -}
alfaToInt::String -> [Int]
alfaToInt [] = []
alfaToInt a = (ord (head a) - (ord '0')) : alfaToInt (tail a)

{- 06b função transforma String de alfa em Int -}
alfaToIntB::String -> Int
alfaToIntB [a] = ord a - ord '0'
alfaToIntB a = (auxAlfaIntB 1 (inverteLista (alfaToInt a)))

auxAlfaIntB::Int -> [Int] -> Int
auxAlfaIntB x [a] = x*a
auxAlfaIntB x a = (x * (head a) + (auxAlfaIntB (10 * x) (tail a)))

inverteLista:: [k] -> [k]
inverteLista [] = []
inverteLista (a:b) = inverteLista b ++ [a]

{-- 07 função que gera tabela ascii -}
geraASCII::Int->[(Int,Char)]
geraASCII 0 = [(0, chr 0)]
geraASCII x
    | x > 0 && x <= 127 = geraASCII (x-1) ++ [(x, chr x)]
    |otherwise = []