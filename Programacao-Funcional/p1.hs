pertence :: Int -> [Int] -> Bool
pertence _ [] = False
pertence x (y:ys) 
    |x /= y    = pertence x ys
    |otherwise = True
 
pertence2 :: Int -> [Int] -> Bool
pertence2 _ [] = False
pertence2 x (y:ys)
  | x == y    = True
  | otherwise = pertence2 x ys

--

f2 :: Int -> [[Int]] -> [(Bool, [Int])]
f2 _ [] = [(False, [])]
