module Main where

--import System.IO (hFlush, stdout)

inputNumbers :: IO [Int]
inputNumbers = do 
    --putStr "Input: "
    --hFlush stdout
    input <- getLine
    return (map read $ words input :: [Int])

outputNumbers :: [Int] -> IO ()
outputNumbers numbers = putStr $ {-"Output: " ++ -} unwords (map show numbers)

findMax :: [Int] -> Int
findMax = \list ->
    case list of
        [] -> undefined
        [first] -> first
        x:xs | x < findMax xs -> findMax xs
        x:_ -> x

removeOneElement :: [Int] -> Int -> [Int]
removeOneElement [] _ = []
removeOneElement (x:xs) value
    | value == x = xs
    | otherwise = x:removeOneElement xs value

selectionSort :: [Int] -> [Int]
selectionSort [] = []
selectionSort numbers = findMax numbers:selectionSort(removeOneElement numbers(findMax numbers))

main :: IO ()
main = do
    input <- inputNumbers
    let result = selectionSort input
    outputNumbers result