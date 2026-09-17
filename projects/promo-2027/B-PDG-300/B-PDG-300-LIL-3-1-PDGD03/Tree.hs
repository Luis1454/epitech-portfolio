{-
-- EPITECH PROJECT, 2024
-- Tree.hs
-- File description:
-- day 03
-}

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Eq, Show)

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree val Empty = Node Empty val Empty
addInTree val (Node l head r)
    | val == head = Node l head r
    | val < head = Node (addInTree val l) head r
    | val > head = Node l head (addInTree val r)

instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node l head r) = Node (fmap f l) (f head) (fmap f r)

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (n:end) = addInTree n (listToTree end)
