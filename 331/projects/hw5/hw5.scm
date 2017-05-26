
		
(define (Towers size fromPeg toPeg)
	(define sparePeg (- 6 (+ fromPeg toPeg)))
	(when(> size 0)
		(begin
		(Towers (- size 1)fromPeg sparePeg)
		(display "Move Top Disk from peg ")(display fromPeg)(display " to Peg ")
		(display toPeg)(display ".")(newline)
		(Towers (- size 1)sparePeg toPeg))))


(Towers 1 1 2)

(Towers 2 1 2)

(Towers 3 1 2)

(Towers 4 1 2)