# state representation of 1st problem (Problem 2.1 from the homework)
#the places where the robot can move or access are E and F

world_map = ['WWWWW',
	    	'WEFWWW',
	    	'WWRWWW',
	    	'WEEEEW',
	    	'WEEBEW',
	    	'WEEWWW',
	    	'WWWWWW'
	    	]

print "Here is our representation of the world for problem 2.1"
print 
print "W stands for Wall or inaccessible area"
print "B stands for Boxes"
print "F stands for Final Intended Position"
print "R stands for Robot"
print "E stands for Empty or Accessible Positions"
print 
for map_current_row in world_map:
	print map_current_row


number_of_boxes = 1 
