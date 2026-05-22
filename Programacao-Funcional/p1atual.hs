{- HLINT ignore "Use first" -}
{- HLINT ignore "Use second" -}
{- HLINT ignore "Use foldr" -}
{-# OPTIONS_GHC -Wno-tabs #-}
import Data.Char (isDigit)

{- Verifica se todos os caracteres de uma `String` são dígitos (0-9).

f1 "123" = True, SE f1 "a1" = False -}
f1 :: String -> Bool
f1 [] = True
f1 (a:as) = isDigit a && f1 as

{- 
Retorna True se todas as `String`s da lista são formadas apenas por dígitos.
Usa `f1` para testar cada elemento.

f2 ["12","34"] = True, SE f2 ["12","a3"] = False -}
f2 :: [String] -> Bool
f2 [] = True
f2 (s:ss) = f1 s && f2 ss

{- 
Para cada par consecutivo de caracteres da `String`, escolhe o
caractere de maior código ASCII. Se houver um caractere sobrando,
ele é mantido. Em empate, o primeiro do par vence (usa `>=`).

f3 "az34" = "z4" -}
f3 :: String -> String
f3 [] = []
f3 [c] = [c]
f3 (a:b:rest)
	| a >= b    = a : f3 rest
	| otherwise = b : f3 rest

{- 
Separa uma lista de pares `(Bool, String)` em um par de listas:
a primeira componente contém as `String` cujo `Bool` é True,
a segunda contém as `String` cujo `Bool` é False.
A ordem original é preservada. 

f4 [(True,"a"),(False,"b")] = (["a"],["b"]) -}
f4 :: [(Bool, String)] -> ([String], [String])
f4 [] = ([], [])
f4 ((True,s):xs)  = (s : fst (f4 xs), snd (f4 xs))
f4 ((False,s):xs) = (fst (f4 xs), s : snd (f4 xs))


{- 
Aplica `f3` a cada `String` da primeira componente de um par
e retorna a lista resultante. A segunda componente é ignorada.

f5 (["az34","b1"], ["fodase", "naoimporta"]) = ["z4","b"]`. -}
f5 :: ([String], [String]) -> [String]
f5 ([], _) = []
f5 (s:ss, ys) = f3 s : f5 (ss, ys)



