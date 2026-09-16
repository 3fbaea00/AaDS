module Main where
    
main :: IO ()
main = do
    _ <- getLine
    nums <- map read . words <$> getLine
    let (_, swaps) = bubbleSort (nums, 0)
    putStrLn $ show swaps

bubbleSort :: ([Int], Int) -> ([Int], Int)
bubbleSort ([], swaps) = ([], swaps)
bubbleSort ([x], swaps) = ([x], swaps)
bubbleSort (arr, swaps) = case pass (arr, swaps) of
    (sarr, sswaps) | sswaps == swaps -> (sarr, swaps)
    (sarr, sswaps) -> bubbleSort (sarr, sswaps)
    where 
        pass :: ([Int], Int) -> ([Int], Int)
        pass ([], swaps) = ([], swaps)
        pass ([x], swaps) = ([x], swaps)
        pass ([x, x2], swaps) | x <= x2 = ([x, x2], swaps)
        pass ([x, x2], swaps) = ([x2, x], swaps + 1)
        pass (x : x2 : xs, swaps)
            | x > x2 = 
                let (sarr, newSwaps) = pass (x : xs, swaps)
                in (x2 : sarr, newSwaps + 1)
            | otherwise =
                let (sarr, newSwaps) = pass (x2 : xs, swaps)
                in (x : sarr, newSwaps)