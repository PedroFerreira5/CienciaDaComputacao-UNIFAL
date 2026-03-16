-- Crivo de Eratóstenes em Haskell

primes :: [Integer]
primes = sieve [2..]

sieve :: [Integer] -> [Integer]
sieve (p:xs) = p : sieve [x | x <- xs, x `mod` p /= 0]

main :: IO ()
main = print (take 50 primes)
