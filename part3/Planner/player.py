
class Player:
    
    def __init__(self, position):
        self.position = position;
    
    def moveLocations(self, curMap):
        x,y = self.position;
        moves = [];
        if (curMap[y][x-1] == 0):
            moves.append('L');
        if (curMap[y][x+1] == 0):
            moves.append('R');
        if (curMap[y+1][x] == 0):
            moves.append('D');
        if (curMap[y-1][x] == 0):
            moves.append('U');
            
        return moves;
    def moveBoxLocations(self, box, curMap):
        xb,yb = box.position
        x,y = self.position
        moveLocations = box.moveLocations(curMap);
        boxLoc = [];
        for loc in moveLocations:
            if loc == 'L' & (x-xb ==1):
                boxLoc.append('L');
            if loc == 'R' & (x - xb == -1):
                boxLoc.append('R');
            if loc == 'U' & (y-yb) ==-1:
                boxLoc.append('U');
            if loc == 'D' & (y-yb == 1):
                boLoc.append('D');
        return boxLoc;
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
            
        
    def moveToLocation(self, position):
        self.position = position;
    