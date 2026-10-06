{-
-- EPITECH PROJECT, 2024
-- Game.hs
-- File description:
-- day 03
-}

data Item = Sword | Bow | MagicWand deriving (Eq)

data Mob = Mummy | Skeleton Item | Witch (Maybe Item) deriving (Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

createMummy :: Mob
createMummy = Mummy

createArcher :: Mob
createArcher = Skeleton Bow

createKnight :: Mob
createKnight = Skeleton Sword

createWitch :: Mob
createWitch = Witch Nothing

createSorceress :: Mob
createSorceress = Witch (Just MagicWand)

create :: String -> Maybe Mob
create "mummy" = (Just createMummy)
create "doomed archer" = (Just createArcher)
create "dead knight" = (Just createKnight)
create "witch" = (Just createWitch)
create "sorceress" = (Just createSorceress)
create _ = Nothing

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip itm (Skeleton _) = Just (Skeleton itm)
equip itm (Witch Nothing) = Just (Witch (Just itm))
equip _ (Witch (Just _)) = Nothing

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton itm) = "skeleton holding a " ++ show itm
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just itm)) = "witch holding a " ++ show itm

class HasItem a where
    getItem :: a -> Maybe Item
    hasItem :: a -> Bool

instance HasItem Mob where
    getItem (Skeleton itm) = Just itm
    getItem (Witch itm) = itm
    getItem _ = Nothing

    hasItem (Skeleton itm) = True
    hasItem (Witch itm) = True
    hasItem _ = False
