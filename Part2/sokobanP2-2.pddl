(define (problem sokobanP2-2)
	(:domain sokoban-domain)
	(:objects theBot boxA boxB c1 c2 c3 c4 c5 c6 c7 c8 c9 c10 c11 c12 c13 c14)
	(:init (bot theBot)
	       (box boxA)
	       (box boxB)
	       (cell c1) (cell c2) (cell c3) (cell c4) 
	       (cell c5) (cell c6) (cell c7) (cell c8)
	       (cell c9) (cell c10) (cell c11) (cell c12) (cell c13) (cell c14)
	       (left-right c1 c2)
	       (left-right c2 c3)
	       (left-right c4 c5)
	       (left-right c5 c6)
	       (left-right c6 c7)
	       (left-right c8 c9)
	       (left-right c9 c10)
	       (left-right c11 c12)
	       (onTop c1 c4)
	       (onTop c2 c5)
	       (onTop c5 c8)
	       (onTop c3 c6)
	       (onTop c6 c9)
	       (onTop c9 c11)
	       (onTop c7 c10)
	       (onTop c10 c12)
	       (onTop c12 c13)
	       (onTop c13 c14)
	       (empty c2) (empty c3) (empty c7) (empty c8)
	       (empty c9) (empty c10) (empty c11) (empty c12)
	       (empty c13) (empty c14)
	       (at theBot c4)
	       (at boxA c5)
	       (at boxB c6)
	 )
	 (:goal (and (at boxA c1)
	 	    (at boxB c14))))
