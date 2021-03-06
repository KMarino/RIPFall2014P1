(define (domain sokoban-domain)
	(:requirements :equality)
	(:predicates (bot ?x) (cell ?x) (box ?x) (empty ?x) (left-right ?x ?y) (onTop ?x ?y) (at ?x ?y))
	(:action move-bot-up
		 :parameters (?bot ?from ?to)
		 :precondition (and (bot ?bot)
		 	       	    (cell ?from)
				    (cell ?to)
		 	       	    (at ?bot ?from)
				    (onTop ?to ?from)
				    (empty ?to))
		 :effect (and (at ?bot ?to)
		 	      (not (at ?bot ?from))
			      (empty ?from)
			 )
	)
	(:action move-bot-down
		 :parameters (?bot ?from ?to)
		 :precondition (and (bot ?bot)
		 	       	    (cell ?from)
				    (cell ?to)
		 	       	    (at ?bot ?from)
				    (onTop ?from ?to)
				    (empty ?to))
		 :effect (and (at ?bot ?to)
		 	      (not (at ?bot ?from))
			      (empty ?from)
			 )
	)
	(:action move-bot-left
		 :parameters (?bot ?from ?to)
		 :precondition (and (bot ?bot)
		 	       	    (cell ?from)
				    (cell ?to)
		 	       	    (at ?bot ?from)
				    (left-right ?to ?from)
				    (empty ?to))
		 :effect (and (at ?bot ?to)
		 	      (not (at ?bot ?from))
			      (empty ?from)
			 )
	)
	(:action move-bot-right
		 :parameters (?bot ?from ?to)
		 :precondition (and (bot ?bot)
		 	       	    (cell ?from)
				    (cell ?to)
		 	       	    (at ?bot ?from)
				    (left-right ?from ?to)
				    (empty ?to))
		 :effect (and (at ?bot ?to)
		 	      (not (at ?bot ?from))
			      (empty ?from)
			 )
	)
	(:action move-box-up
		 :parameters (?bot ?box ?botIniPos ?boxFrom ?boxTo)
		 :precondition (and (bot ?bot)
		 	       	    (box ?box)
		 	       	    (cell ?botIniPos)
				    (cell ?boxFrom)
				    (cell ?boxTo)
		 	       	    (at ?bot ?botIniPos)
		 	       	    (at ?box ?boxFrom)
				    (empty ?boxTo)
				    (onTop ?boxFrom ?botIniPos)
				    (onTop ?boxTo ?boxFrom)
		 	       )
	         :effect (and (at ?box ?boxTo)
		 	      (not (at ?box ?boxFrom))
			      (at ?bot ?boxFrom)
			      (not (at ?bot ?botIniPos))
			      (empty ?botIniPos)
			      (empty ?boxFrom)
			      (not (empty ?boxTo)) 
			 )
	)
	(:action move-box-down
		 :parameters (?bot ?box ?botIniPos ?boxFrom ?boxTo)
		 :precondition (and (bot ?bot)
		 	       	    (box ?box)
		 	       	    (cell ?botIniPos)
				    (cell ?boxFrom)
				    (cell ?boxTo)
		 	       	    (at ?bot ?botIniPos)
		 	       	    (at ?box ?boxFrom)
				    (empty ?boxTo)
				    (onTop ?botIniPos ?boxFrom)
				    (onTop ?boxFrom ?boxTo)
		 	       )
	         :effect (and (at ?box ?boxTo)
		 	      (not (at ?box ?boxFrom))
			      (at ?bot ?boxFrom)
			      (not (at ?bot ?botIniPos))
			      (empty ?botIniPos)
			      (empty ?boxFrom)
			      (not (empty ?boxTo)) 
			 )
	)
	(:action move-box-right
		 :parameters (?bot ?box ?botIniPos ?boxFrom ?boxTo)
		 :precondition (and (bot ?bot)
		 	       	    (box ?box)
		 	       	    (cell ?botIniPos)
				    (cell ?boxFrom)
				    (cell ?boxTo)
		 	       	    (at ?bot ?botIniPos)
		 	       	    (at ?box ?boxFrom)
				    (empty ?boxTo)
				    (left-right ?botIniPos ?boxFrom)
				    (left-right ?boxFrom ?boxTo)
		 	       )
	         :effect (and (at ?box ?boxTo)
		 	      (not (at ?box ?boxFrom))
			      (at ?bot ?boxFrom)
			      (not (at ?bot ?botIniPos))
			      (empty ?botIniPos)
			      (empty ?boxFrom)
			      (not (empty ?boxTo)) 
			 )
	)
	(:action move-box-left
		 :parameters (?bot ?box ?botIniPos ?boxFrom ?boxTo)
		 :precondition (and (bot ?bot)
		 	       	    (box ?box)
		 	       	    (cell ?botIniPos)
				    (cell ?boxFrom)
				    (cell ?boxTo)
		 	       	    (at ?bot ?botIniPos)
		 	       	    (at ?box ?boxFrom)
				    (empty ?boxTo)
				    (left-right ?boxFrom ?botIniPos)
				    (left-right ?boxTo ?boxFrom)
		 	       )
	         :effect (and (at ?box ?boxTo)
		 	      (not (at ?box ?boxFrom))
			      (at ?bot ?boxFrom)
			      (not (at ?bot ?botIniPos))
			      (empty ?botIniPos)
			      (empty ?boxFrom)
			      (not (empty ?boxTo)) 
			 )
	)
	
)
