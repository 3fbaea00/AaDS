module Main where

inputNumbers :: IO [Int]
inputNumbers = map read . words <$> getLine

outputNumbers :: [Int] -> IO ()
outputNumbers = putStr . unwords . map show

main :: IO ()
main = inputNumbers >>= outputNumbers . bubbleSort

sort :: ([Int], Bool) -> ([Int], Bool)
sort ([], _) = ([], False)
sort ([x], _) = ([x], False)
sort ([x, x2], _) | x >= x2 = ([x, x2], False)
sort ([x, x2], _) = ([x2, x], True)
sort (x : x2 : xs, changed)
    | x < x2 = 
        let (sa, _) = sort (x : xs, changed)
        in (x2 : sa, True)
    | otherwise =
        let (sa, schanged) = sort (x2 : xs, changed)
        in (x : sa, changed || schanged)

bubbleSort :: [Int] -> [Int]
bubbleSort [] = []
bubbleSort [x] = [x]
bubbleSort a = case sort (a, False) of
    (sa, True) -> bubbleSort sa
    (sa, False) -> sa