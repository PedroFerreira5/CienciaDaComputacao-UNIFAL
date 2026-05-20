{- HLINT ignore "Use foldr" -}
{- HLINT ignore "Redundant bracket" -}
import Data.Char
import Distribution.Simple.Utils (chattyTry)
import GHC.IO.Device (IODevice(dup))
-- 1 (a)
f1 :: Float -> Float
f1 x
    |x >= 0 = (x+4)/(x+2)
    |otherwise = 2/x

-- (b)
f2 :: Int -> Int -> Int
f2 x y
    |x >= y = x + y
    |otherwise = x-y

-- (c)
f3 :: Int -> Int -> Int -> Int
f3 x y z
    |(x+y) > z = x + y + z
    |(x+y) < z = x - y - z
    |otherwise = 0

-- 2 Corrija o erro na função
fat :: Int -> Int
fat 0 = 1 -- Implementado (o codigo nao tinha condição de parada)
fat x = x * fat (x-1)

-- 3  Considere a função em Haskell soma::Int->Int->Int que retorna a soma entre os dois parâmetros. 
--Assim, faça uma função em Haskell que resulte a multiplicação de dois parâmetros
-- fazendo uso da função soma.

soma :: Int -> Int -> Int
soma x y = x + y

multi :: Int -> Int -> Int
multi x y
    |y == 0 = 0
    |y > 0 = soma x (multi x (y-1)) -- para multi (x*y) some ele pelo resultado de x*(y-1)
             -- x        y
             -- multi x y soma x com x ate que y-1 seja y == 0

-- 4 Inverta os digitos

invertInt :: Int ->  Int
invertInt n = invertaux n 0

invertaux :: Int -> Int -> Int -- 123 mod 10 = 3 && 123 div 10 = 12
invertaux 0 aux = aux -- ponto de parada
invertaux n aux = invertaux (n `div`10) (aux * 10 + (n `mod`10))
                          -- guarda o 12 // pega o 3 faz *10 = 30 / faz mod do 12, 12 vira 32 e mod do 1 (321), para em 0 (NULL) 


-- 5 Basicamente fazer x² chegar em x^4
square :: Int -> Int
square x = x * x

fourPower :: Int -> Int
fourPower x = square (square x)

-- teste x^8
eightPower :: Int -> Int
eightPower x = square (fourPower x)

-- 6 
sequencia :: Int -> Double
sequencia 0 = sqrt 6
sequencia n = sqrt (6 + sequencia (n - 1))

-- 7 
combina :: Int -> Int -> Int
combina m n
  | n == 0    = 1
  | m == n    = 1
  | otherwise = combina (m - 1) (n - 1) + combina (m - 1) n

-- 8
mdc :: Int -> Int -> Int
mdc m n
  | n == 0    = m
  | otherwise = mdc n (m `mod` n)

-- 9
howManyMultiples :: Int -> Int -> Int -> Int
howManyMultiples n inicio fim = length [x | x <- [inicio..fim], x `mod` n == 0]

-- 10 
lastDigit :: Int -> Int
lastDigit n = n `mod` 10

-- 11 
anyDigit:: Int -> Int -> Int
anyDigit x y
    | 10^x > y = -1
    |otherwise = lastDigit (invertInt y `div` (10^x))


-- 12 
allDifferent::Int->Int->Int->Bool
allDifferent m n p = (m/=n) && (n/=p) && (m/=p)

-- 13
howManyEqual::Int -> Int -> Int -> Int
howManyEqual x y z
    |allDifferent x y z = 0
    |(x==y) && (y==z)   = 3
    |otherwise          = 2


-- 14
-- tabela de vendas
vendas :: Int -> Int
vendas 0 = 1
vendas 1 = 41
vendas 2 = 72
vendas 3 = 48
vendas 4 = 0
vendas 5 = 91
vendas 6 = 55
vendas 7 = 29

howManyLess :: Int -> Int -> Int -> Int 
howManyLess valor inicio fim
    | inicio > fim = 0
    | vendas inicio < valor = 1 + howManyLess valor (inicio + 1) fim
    | otherwise = howManyLess valor (inicio + 1) fim

noZeroinPeriod :: Int -> Bool
noZeroinPeriod 0 = vendas 0 /= 0
noZeroinPeriod fim = (vendas fim /= 0) && noZeroinPeriod(fim-1)

zerosInPeriod :: Int -> [Int]
zerosInPeriod n
    | n < 0             = []   -- Caso base: paramos quando passamos do dia 0
    | vendas n == 0     = n : zerosInPeriod (n - 1) -- Adiciona o dia 'n' à lista
    | otherwise         = zerosInPeriod (n - 1)     -- Ignora o dia 'n' e continua


daysSalesBelow :: Int -> [Int] -> [Int]
daysSalesBelow _ [] = [] 
daysSalesBelow limite (x:xs)
    | vendas x < limite = x : daysSalesBelow limite xs 
    | otherwise         = daysSalesBelow limite xs     -- caminha

-- 15
fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib (n - 1) + fib (n - 2)

-- Função principal pedida no enunciado
antFib :: Int -> Int
antFib x = buscaFib x 0  -- Dispara a busca começando do índice 0

-- guarda o índice atual
buscaFib :: Int -> Int -> Int
buscaFib x index
    | fib index == x = index  
    | fib index > x  = -1     
    | otherwise      = buscaFib x (index + 1) 

-- 16
funny :: Int -> Int -> Int -> Bool
funny x y z = (x > z) || (y < x)

-- 17
myToUpper :: Char -> Char 
myToUpper c
    | c >= 'a' && c <= 'z' = chr (ord c - 32)
    | otherwise            = c

-- 18
charToNum :: Char -> Int
charToNum c
    | c >= '0' && c <= '9' = ord c - ord '0'
    | otherwise            = -1

-- 19
duplicate :: String -> Int -> String
duplicate [] _ = []
duplicate s 0 = []
duplicate s n = s ++ duplicate s (n - 1)

-- 20
pushRight :: String -> Int -> String
pushRight s n
    | n <= length s = s  -- Se o tamanho atual já cobre ou passa de 'n', retorna s intacta
    | otherwise     = duplicate ">" (n - length s) ++ s

-- 21 
infixl 6 &-
(&-) :: Int -> Int -> Int
x &- y = x - 2 * y

-- 22 
inverte :: [Int] -> [Int]
inverte []     = []
inverte (x:xs) = inverte xs ++ [x]

-- 23 
separa :: [Int] -> ([Int], [Int])
separa [] = ([], [])
separa (x:xs)
  | x `mod` 2 == 0 = separaPar x (separa xs)
  | otherwise      = separaImpar x (separa xs)

separaPar :: Int -> ([Int], [Int]) -> ([Int], [Int])
separaPar x (impares, pares) = (impares, x : pares)

separaImpar :: Int -> ([Int], [Int]) -> ([Int], [Int])
separaImpar x (impares, pares) = (x : impares, pares)

-- 24
converte :: [Int] -> String
converte []     = ""
converte (x:xs) = chr (x + 64) : converte xs

-- 25 
{-
(a) [’a’..’g’] = "abcdefg"
(b) [0.1 ..0.9] = [0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9]
(c) [0.1,0.3 .. 0.9] = [0.1,0.3,0.5,0.7,0.9]
(d) [0.1,0.3 ..1.8] = [0.1,0.3,0.5,0.7,0.9,1.1,1.3,1.5,1.7]
(e) [0.4,0.2 ..0.8] = []
(f) [1,4..15] = [1,4,7,10,13]
-}

-- 26 
conta :: [Char] -> Char -> Int
conta [] _ = 0
conta (a:as) x   
    |(a == x) = 1 + conta as x
    |otherwise = conta as x 

-- 27 
pertence :: Int -> [Int] -> Bool
pertence _ [] = False
pertence x (y:ys) = x == y || pertence x ys

purifica:: [Int] -> [Int]
purifica [] = []
purifica (x:xs)
    | pertence x xs = purifica xs
    | otherwise = x:purifica xs

-- 28
addNaLista :: a -> Int -> [a]
addNaLista _ 0 = []
addNaLista x y = x : addNaLista x (y-1)

proliferaInt :: [Int] -> [Int]
proliferaInt [] = []
proliferaInt (x:xs) = addNaLista x x ++ proliferaInt xs

-- 29
proliferaChar :: [Char] -> [Char]
proliferaChar [] = []
proliferaChar (x:xs)
  | 'A' <= x && x <= 'Z' = addNaLista x (ord x - 64) ++ proliferaChar xs
  | 'a' <= x && x <= 'z' = addNaLista x (ord x - 96) ++ proliferaChar xs

-- 30
myToLower :: Char -> Char
myToLower x
  | 'A' <= x && x <= 'Z' = chr (ord x + 32)
  | 'a' <= x && x <= 'z' = x

mytoUpper :: Char -> Char
mytoUpper x
  | 'a' <= x && x <= 'z' = chr (ord x - 32)
  | 'A' <= x && x <= 'Z' = x

converteChar :: Char -> (Char, Char, Int)
converteChar x = (myToLower x, myToUpper x, ord x)

-- 31 
