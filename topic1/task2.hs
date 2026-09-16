module Main where

inputNumbers :: IO [Int]
inputNumbers = map read . words <$> getLine

outputNumbers :: [Int] -> IO ()
outputNumbers = putStr . unwords . map show

main :: IO ()
main = inputNumbers >>= outputNumbers . insertionSort

findMin :: [Int] -> Int
findMin [] = undefined
findMin [x] = x
findMin (x:xs)
    | let tailMin = findMin xs, x > tailMin = tailMin
    | otherwise = x

cyclicShiftTo :: [Int] -> Int -> [Int]
cyclicShiftTo [] _ = []
cyclicShiftTo [x] _ = [x]
cyclicShiftTo a val = after ++ before
    where (before, after) = break (== val) a

insertionSort :: [Int] -> [Int]
insertionSort [] = []
insertionSort [x] = [x]
insertionSort a = case cyclicShiftTo a $ findMin a of
    (x:xs) -> x : insertionSort xs
    [] -> []