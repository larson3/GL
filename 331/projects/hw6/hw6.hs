
merge6 :: Ord a => [a] -> [a] -> [a]
--cases for empty lists in any position
merge6 [] 	 [] 	= []
merge6 x     []     = x
merge6 []     x     = x
merge6 (x:xs) (y:ys) =
--picking out an item from each list and adding it to new list recursively
	if x > y then y : merge6 (x:xs) ys
	else x : merge6 (y:ys) xs


		
halve6' :: [a] -> Int -> ([a], [a])
halve6 :: [a] -> ([a],[a])

halve6' xs 0 = ([],xs)
halve6' (x:xs) n = (x:ys,zs)
	where
		(ys,zs) = halve6' xs (n-1)

halve6[] = ([],[])
halve6(x) = halve6' x themid
	where 
		themid = checkEven(x)

--will return a different middle for an odd length to split correctly
checkEven :: [a] -> Int
checkEven(x) = 
	if length x `mod` 2 == 1
		then (length x `div` 2)+1
		else (length x `div` 2)
		

	
