class Box:
	def __init__(self, row, col):
		self.row = row
		self.col = col

	def print_box_info(self):
		print "box row is ",self.row
		print "box col is", self.col

class Robot:
	def __init__(self, row, col):
		self.row = row
		self.col = col

	def print_robot_info(self):
		print "robot row number is ", self.row
		print "robot col number is", self.col

	def moveBox(self, box):
		self.print_robot_info()
		print 
		box.print_box_info()
		if self.row == box.row and self.col == box.col - 1:
			# print "right case"
			# print "check this out for right case", sokoban_problem.isAccessible(self.row, box.col + 1)
			if sokoban_problem.isAccessible(self.row, box.col + 1):
				# print "right case inner"
				sokoban_problem.world_map[self.row * sokoban_problem.number_of_columns + box.col] = 'E'
				sokoban_problem.world_map[self.row * sokoban_problem.number_of_columns + box.col + 1] = 'B'
				return True
		#if the robot is on the right side of the box
		if self.row == box.row and self.col == box.col+ 1:
			if sokoban_problem.isAccessible(self.row, box.col - 1):
				sokoban_problem.world_map[self.row * sokoban_problem.number_of_columns + box.col] = 'E'
				sokoban_problem.world_map[self.row * sokoban_problem.number_of_columns + box.col - 1] = 'B'
				return True
    	#if the robot is on the top of the box
		if self.row == box.row -1 and self.col == box.col:
			# print "yoyo"
			if sokoban_problem.isAccessible(self.row + 1, self.col):
				sokoban_problem.world_map[box.row * sokoban_problem.number_of_columns + box.col] = 'E'
				sokoban_problem.world_map[(box.row + 1) * sokoban_problem.number_of_columns + box.col] = 'B'
				return True
		#if the robot is on the bottom of the box
		if self.row == box.row + 1 and self.col == box.col:
			# print "yayyyyy"
			if sokoban_problem.isAccessible(box.row - 1, self.col):
				sokoban_problem.world_map[box.row * sokoban_problem.number_of_columns + box.col] = 'E'
				sokoban_problem.world_map[(box.row - 1) * sokoban_problem.number_of_columns + box.col] = 'B'
				return True





class Sokoban:
    
    def box_robot_finder(self):
    		for i, current_block in enumerate(self.world_map):
    			if current_block == 'B':
    				self.boxes.append(Box(int(i)/self.number_of_columns, i%self.number_of_columns))
    			if current_block == 'R':
    				self.robot = Robot(i/self.number_of_columns, i%self.number_of_columns)

    def __init__(self, number_of_boxes = 0, file_number=0):
    	if file_number == 0:
    		print "Invalid file number"
    	self.world_map = []
    	with open(str(file_number)) as f:
    		temp = f.readlines()
    		self.number_of_rows = int(temp[0].split(',')[0])
    		self.number_of_columns = int(temp[0].split(',')[1])
    		self.number_of_boxes = int(temp[0].split(',')[2])
    		
    		for t in temp[1:]:
    			print "here is the value of t", t, " and its length is " , len(t)
    			for c in t.strip().split(','):
    				self.world_map.append(c)
    				print "here are the values of C" , c


    			# self.world_map.append(t.strip().split(','))
    		print "ONLY SEE THIS"	
    		self.print_world_map()     			
    		# self.world_map = str(temp[0].strip()).split(',')	    		
    	self.boxes = []
    	self.robot = []
    	self.box_robot_finder()
    	
    	# print contents
    	# print type(contents)

    def print_world_map(self):
    	# print "type", type(self.world_map)
    	count = 0;
    	output = []
    	for i in self.world_map:
    		output.append(i)
    		count+=1
    		if count == self.number_of_columns:
    			print output
    			output = []
    			count = 0

    def printInfo(self):
    	print "Number of things in the world map : ", len(self.world_map)
    	print "Number of rows", int(self.number_of_rows)
    	print "Number of cols", int(self.number_of_columns)
    	print "number of boxes", len(self.boxes)
    	print "robot location", self.robot.row, self.robot.col


    
    def isAccessible(self, row, col):
    	# print "row being checked", row
    	# print "col being checcked", col
    	if row >= self.number_of_rows or row < 0:
    		return False
    	if col >= self.number_of_columns or col < 0:
    		return False	
    	# print self.world_map[int(row) * int(self.number_of_columns) + int(col)]
    	return self.world_map[int(row) * int(self.number_of_columns) + int(col)] != 'W'
    	




    # def isAccessible(self, row, col):
    	# self.world_map[row *  ]

file_number = raw_input("enter file number : ")
sokoban_problem = Sokoban(1, file_number)	
sokoban_problem.print_world_map()
if sokoban_problem.robot.moveBox(sokoban_problem.boxes[0]) == True:
	print "BOX MOVED"
else:
	print "BOX NOT MOVED"	
sokoban_problem.print_world_map()