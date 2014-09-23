(define (domain sokoban-domain)
	(:requirements :equality :strips)
	(:predicates (bot ?x) (cell ?x) (box ?x) (empty ?x) (left-right ?x ?y) (onTop ?x ?y) (at ?x ?y))
	(:action move-bot
		 :parameters (?bot ?from ?to)
		 :precondition (and (bot ?bot)
		 	       	    (cell ?from)
				    (cell ?to)
		 	       	    (at ?bot ?from)
				    (not (and 
				        (not (left-right ?from ?to))
				    	(not (left-right ?to ?from))
					(not (onTop ?to ?from))
					(not (onTop ?from ?to))))
				    (empty ?to))
		 :effect (and (at ?bot ?to)
		 	      (not (at ?bot ?from))
			      (empty ?from)
			      (not (empty ?to))
			 )
	)
	(:action move-box
		 :parameters (?bot ?box ?botIniPos ?boxFrom ?boxTo)
		 :precondition (and (bot ?bot)
		 	       	    (box ?box)
		 	       	    (cell ?botIniPos)
				    (cell ?boxFrom)
				    (cell ?boxTo)
		 	       	    (at ?bot ?botIniPos)
		 	       	    (at ?box ?boxFrom)
				    (empty ?boxTo)
				    (not (and (not (and (onTop ?botIniPos ?boxFrom)
				    	     (onTop ?boxFrom ?boxTo)))
				       	(not (and (onTop ?boxFrom ?botIniPos)
					     (onTop ?boxTo ?boxFrom)))
					(not (and (left-right ?botIniPos ?boxFrom)
					     (left-right ?boxFrom ?boxTo )))
					(not (and (left-right ?boxFrom ?botIniPos)
					     (left-right ?boxTo ?boxFrom)))
				    ))
		 	       )
	         :effect (and (at ?box ?boxTo)
		 	      (not (at ?box ?boxFrom))
			      (at ?bot ?boxFrom)
			      (not (at ?bot ?botIniPos))
			      (empty ?botIniPos)
			      (not (empty ?boxTo)) 
			 )
	)
)
