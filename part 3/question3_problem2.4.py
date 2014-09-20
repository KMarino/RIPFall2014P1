#state representation of 4th problem (Problem 2.4 from Homework)
#the places where the robot can move or access are E and F
world_map = ['WWWWWWW',
			 'WWWWWWW',
			 'WWWBEWW',
			 'WEBEERW',
			 'WEFFFEW',
			 'WWBEEWW',
			 'WWEEWWW',
			 'WWWWWWW'
			]


print "Here is our representation of the world for problem 2.4"
print 
print "W stands for Wall or inaccessible area"
print "B stands for Boxes"
print "F stands for Final Intended Position"
print "R stands for Robot"
print "E stands for Empty or Accessible Positions"
print 
for map_current_row in world_map:
	print map_current_row

number_of_boxes = 3
 