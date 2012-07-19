merge:: Ord a => [a]->[a] -> [a]
merge [] ys = ys
merge xs [] = xs
merge (x:xs) (y:ys) = if x <= y
                      then x : merge xs (y:ys)
                      else y : merge (x:xs) ys
                           
mergesort:: Ord a => [a] -> [a]
mergesort [] = []
mergesort [x] = [x]
mergesort xs = let (as, bs) = splitAt  (length xs `quot` 2) xs
               in merge (mergesort as) (mergesort bs)
                      


quicksort :: Ord a => [a] -> [a]
quicksort []     = []
quicksort (p:xs) = (quicksort (filter (< p) xs) ) ++ [p] ++ (quicksort (filter (>= p) xs))
    
                   
select :: Ord a => [a] -> Int -> a                   
select xs k 
  | k > (length xs) = error "k is larger than size of list"
  | k <= (length lt) = select lt k
  | (length lt) < k && k <= ((length lt) + (length eq)) = head xs
  | k > (length lt + length eq) = select gt (k - (length lt) - (length eq)) 
  where lt = filter ( < (head xs)) xs
        eq = filter ( == (head xs)) xs
        gt = filter ( > (head xs)) xs
        
        