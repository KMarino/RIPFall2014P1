#My version of the problem.

class Box:

    def __init__(self, position):
        #position is tuple (x,y);
        self.position = position;
        
    def moveLocations(self, curMap):
        x,y = self.position;
        moves = [];
        if (curMap[y][x-1] == 0 & curMap[y][x+1]==0):
            moves.append('L');
            moves.append('R');
        if (curMap[y-1][x] == 0 & curMap([y+1][x] == 0)"
            moves.append('U');
            moves.append('D');
        return moves;
    
    def moveToLocation(self, position):
        self.position = position;
    
    