-- 6 
sequencia :: Int -> Double
sequencia 0 = sqrt 6
sequencia n = sqrt (6 + sequencia (n - 1))