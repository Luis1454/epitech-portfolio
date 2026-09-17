{-
-- EPITECH PROJECT, 2024
-- $MY_HS
-- File description:
-- $DESCRIPTION
-}

mySucc :: Int -> Int
mySucc n = n + 1

myIsNeg :: Int -> Bool
myIsNeg n = n < 0

myAbs :: Int -> Int
myAbs n | n < 0 = -n | otherwise = n

myMin :: Int -> Int -> Int
myMin a b | a < b = a | otherwise = b

myMax :: Int -> Int -> Int
myMax a b | a > b = a | otherwise = b

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

myFst :: (a, b) -> a
myFst (a, b) = a

mySnd :: (a, b) -> b
mySnd (a, b) = b

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

myHead :: [a] -> a
myHead [] = error "Empty array"
myHead (a:ax) = a

myTail :: [a] -> [a]
myTail [] = error "Empty array"
myTail (a:ax) = ax

myLength :: [a] -> Int
myLength [] = 0
myLength (a:ax) = 1 + myLength ax

myNth :: [a] -> Int -> a
myNth [] a = error "Empty array"
myNth (n:_) 0 = n
myNth (_:end) n = myNth end (n - 1)

myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake 0 (a:ax) = []
myTake n (a:ax) = a : myTake (n - 1) ax

myDrop :: Int -> [a] -> [a]
myDrop 0 (a:ax) = (a:ax)
myDrop _ [] = []
myDrop n (a:ax) = myDrop (n - 1) ax

myAppend :: [a] -> [a] -> [a]
myAppend [] [] = []
myAppend [] (a:ax) = a : myAppend [] ax
myAppend (a:ax) (b:bx) = a : myAppend ax (b:bx)

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a:ax) = myAppend (myReverse ax) [a]

myInit :: [a] -> [a]
myInit [] = error "Empty array"
myInit (a:ax) | myLength (a:ax) == 1 = [] | otherwise = a : myInit ax   

myLast :: [a] -> a
myLast [] = error "Empty array"
myLast (a:ax) | myLength (a:ax) == 1 = a | otherwise = myLast ax

myZip :: [a] -> [b] -> [(a, b)]
myZip [] [] = []
myZip [] (b:bx) = []
myZip (a:ax) [] = []
myZip (a:ax) (b:bx) = (a, b) : myZip ax bx

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((a, b):end) = (a : myFst (myUnzip end), b : mySnd (myUnzip end))

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (a:ax) = f a : myMap f ax

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (a:ax) | f a = a : myFilter f ax | otherwise = myFilter f ax

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ b [] = b
myFoldl f b (a:ax) = myFoldl f (f b a) ax

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ b [] = b
myFoldr f b (a:ax) = f a (myFoldr f b ax)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition f (a:ax)
 | f a = (a : myFst (myPartition f ax), mySnd (myPartition f ax))
 | otherwise = (myFst (myPartition f ax), a : mySnd (myPartition f ax))

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort f (a:ax) = myAppend (myQuickSort
 f (myFst (myPartition (f a) ax))) (a :
 myQuickSort f (mySnd (myPartition (f a) ax)))
