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
fat x = x * fat(x-1)

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
