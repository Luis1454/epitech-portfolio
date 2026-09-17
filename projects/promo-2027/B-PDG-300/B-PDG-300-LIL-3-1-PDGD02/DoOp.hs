{-
-- EPITECH PROJECT, 2024
-- DoOp.hs
-- File description:
-- day 2
-}

myElem :: Eq a => a -> [a] -> Bool
myElem out [] = False
myElem out (l:list) | out == l = True | otherwise = myElem out list

safeDiv :: Int -> Int -> Maybe Int
safeDiv a 0 = Nothing
safeDiv a b = Just (a `div` b)

safeNth :: [a] -> Int -> Maybe a
safeNth [] a = Nothing
safeNth (n:_) 0 = Just n
safeNth (_:end) n = safeNth end (n - 1)

safeSucc :: Maybe Int -> Maybe Int
safeSucc Nothing = Nothing
safeSucc (Just n) = Just (n + 1)

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup n ((a, b):end)
 | n == a = Just b
 | otherwise = myLookup n end

maybeDo :: (a -> b -> c) -> Maybe a -> Maybe b -> Maybe c
maybeDo a Nothing c = Nothing
maybeDo a b Nothing = Nothing
maybeDo f (Just a) (Just b) = Just (f a b)

isNum :: [Char] -> Bool
isNum [] = True
isNum (a:end)
 | myElem a "-0123456789" = isNum end
 | otherwise = False

readInt :: [Char] -> Maybe Int
readInt a
 | isNum a = Just (read a :: Int)
 | otherwise = Nothing

getLineLength :: IO Int
getLineLength = do
 line <- getLine
 return (length line)

printAndGetLength :: String -> IO Int
printAndGetLength str = putStr str >> putStr "\n" >> return (length str)

printEdge :: Int -> IO ()
printEdge 0 = return ()
printEdge n = putChar '-' >> printEdge (n - 1)

printFullEdge :: Int -> IO ()
printFullEdge 0 = return ()
printFullEdge n = putChar '+' >> printEdge (n - 2) >> putChar '+'

printMiddle :: Int -> IO ()
printMiddle 0 = return ()
printMiddle n = putStr " " >> printMiddle (n - 1)

printMiddleHandler :: Int -> Int -> IO ()
printMiddleHandler 0 _ = return ()
printMiddleHandler n x = putStr "|" >> printMiddle (x * 2 + 2)
 >> putStr "|\n" >> printMiddleHandler (n - 1) x

printBox :: Int -> IO ()
printBox n | n <= 0 = return ()
printBox 1 = putStr "+\n"
printBox n = printFullEdge (n * 2) >> putStr "\n"
 >> printMiddleHandler (n - 2) (n - 2)
 >> printFullEdge (n * 2) >> putStr "\n"

concatLines :: Int -> IO String
concatLines 0 = return ""
concatLines n = do
 line <- getLine
 content <- concatLines (n - 1)
 return (line ++ content)

getInt :: IO (Maybe Int)
getInt = do
 line <- getLine
 return (readInt line)
