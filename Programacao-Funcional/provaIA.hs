{- HLINT ignore "Use foldr" -}
menor2 :: Int -> Int -> Int
menor2 x y 
    |x < y = x 
    |otherwise = y

pertence3 :: Int -> [Int] -> Bool
pertence3 _ [] = False
pertence3 x (y:ys) = x == y || pertence3 x ys

f2 :: Int -> [[Int]] -> [(Bool, [Int])]
f2 _ [] = []
f2 x (y:ys) = (pertence3 x y, y) : f2 x ys 

f4 :: (Int, [(Bool, [Int])]) -> [[Int]]
f4 (_, []) = []
f4 (x, (False, sublista) : resto) = sublista : f4 (x, resto)
f4 (x, (True, _) : resto) = f4 (x, resto)

f5 :: String -> String -> [Bool]
f5 [] _ = []
f5 _ [] = []
f5 (x:xs) (y:ys) = (x == y) : f5 xs ys 

-- Insertion Sort
ordena1 :: [Int] -> [Int]
ordena1 [] = []
ordena1 (a:b) = insereOrdenado a (ordena1 b)

insereOrdenado :: Int -> [Int] -> [Int]
insereOrdenado x [] = [x]
insereOrdenado x (y:ys)
   | x <= y = x : y : ys
   | otherwise = y : insereOrdenado x ys


