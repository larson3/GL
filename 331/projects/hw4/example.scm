(define (distTo3D listA listB)
	(sqrt(add(square (diff (first listB) (first listA))) 
	(square (diff (second listB) (second listA))) 
	(square (diff (third listB) (third listA))))))

(define (add a b c)
	(+ a b c))
	
(define (diff a b)
	(- a b))
	
(define (square a)
	(* a a))

	
(distTo3D '(123 456 789) '(789 456 123))
