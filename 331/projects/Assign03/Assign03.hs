

class Grp where
	assign03 :: Grp g => Int -> Int -> [[g]]
	
	
	
--import Data.List (permutations)

--choose n list = concatMap permutations $ choose' list [] where
 -- choose' []     r = if length r == n then [r] else []
 -- choose' (x:xs) r | length r == n = [r]
  --                 | otherwise     = choose' xs (x:r) 
    --                              ++ choose' xs r