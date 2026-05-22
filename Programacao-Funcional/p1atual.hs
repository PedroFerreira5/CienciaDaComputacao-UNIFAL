{- HLINT ignore "Use first" -}
{- HLINT ignore "Use second" -}
{- HLINT ignore "Use foldr" -}
{-# OPTIONS_GHC -Wno-tabs #-}
import Data.Char (isDigit)

f1 :: String -> Bool
f1 [] = True
f1 (a:as) = isDigit a && f1 as

f2 :: [String] -> Bool
f2 [] = True
f2 (s:ss) = f1 s && f2 ss

f3 :: String -> String
f3 [] = []
f3 [c] = [c]
f3 (a:b:rest)
	| a >= b    = a : f3 rest
	| otherwise = b : f3 rest

f4 :: [(Bool, String)] -> ([String], [String])
f4 [] = ([], [])
f4 ((True,s):xs)  = (s : fst (f4 xs), snd (f4 xs))
f4 ((False,s):xs) = (fst (f4 xs), s : snd (f4 xs))

f5 :: ([String], [String]) -> [String]
f5 ([], _) = []
f5 (s:ss, ys) = f3 s : f5 (ss, ys)



