pertence :: Int -> [Int] -> Bool
pertence _ [] = False
pertence x (y:ys) = x == y || pertence x ys

f2 :: Int -> [[Int]] -> [(Bool, [Int])]
f2 _ [] = []
f2 x (y:ys) = (pertence x y, y) : f2 x ys 

f3 :: Int -> [[Int]] -> (Int,[(Bool, [Int])])
f3 x lista = (x, f2 x lista)

f4 :: (Int, [(Bool, [Int])]) -> [[Int]]
f4 (_, boolint) = filtra boolint
  where
    filtra [] = []
    filtra ((False, sublista) : resto) = sublista : filtra resto
    filtra ((True, _) : resto) = filtra resto

f5 :: String -> String -> [Bool] 
f5 [] _ = []
f5 _ [] = []
f5 (x:xs) (y:ys) = (x == y) : f5 xs ys





