#import player.py;
#import box.py;
import Queue;
import string; 
import s4 as sp;

                 

curMap = sp.curMap;
boxLocations = sp.boxLocations;
playerLocation = sp.playerLocation;
goalLocations = sp.goalLocations;

class planner:
    

    def movePlayer(location, curLocation, boxLocations):
        x,y = location;
        curX, curY = curLocation;
        if curMap[y][x] == 1:
            return False;
        if (abs(curY-y) <2 and abs(curX-x)<2 and location not in boxLocations):
            #self.playerLocation = location;
            return True;
        else:
            return False;
    
    def canMoveBox(boxLocation, boxLocations, playerLocation):
        px, py = playerLocation;
        bx, by = boxLocation;
        posMoves = []
        if (px - bx == 1 and py-by == 0):
            posMoves = (-1,0);
        elif (px - bx == -1 and py-by == 0): 
            posMoves = (1,0);
        elif (py - by == 1 and px-bx == 0): 
            posMoves = (0,-1);   
        elif (py - by == -1 and px-bx == 0): 
            posMoves = (0,1);   
        moves = []
        if curMap[by+1][bx] == 0 and curMap[by-1][bx] == 0 and (bx,by+1) not in boxLocations and (bx, by-1) not in boxLocations:
            moves.append((0, -1));
            moves.append((0,1));
        if curMap[by][bx+1] ==0 and curMap[by][bx-1] == 0 and (bx+1,by) not in boxLocations and (bx-1,by) not in boxLocations:
            moves.append((-1, 0));
            moves.append((1,0));
        #print str(moves);
        if posMoves in moves:
            return posMoves;
        return [];
    
    def getPriorty(curState):
        boxes = curState[1];
        totalDist = 0;
        for box in boxes:
            x,y = box;
            curDist = -1;
            for goal in goalLocations:
                gx,gy = goal;
                distance = abs(x-gx) + abs(y-gy);
                if distance < curDist or curDist < 0:
                    curDist = distance;
            totalDist+=curDist;
        return totalDist;
        
    numStatesVisited = 0
    statesVisited = []
    curState = [playerLocation, boxLocations];
    #stateQ = Queue.Queue();
    stateQ = Queue.PriorityQueue();
    stateQ.put((getPriorty(curState),curState));
    
    while not stateQ.empty():
        numStatesVisited +=1;
        p,curState = stateQ.get();
        statesVisited.append(curState);
        curPlayerLoc = curState[0];
        x, y = curPlayerLoc
        curBoxLocs = curState[1];

        if all(box in goalLocations for box in curBoxLocs):
            print "Found Goal State: \n"
            print "Map: "
            for row in curMap:
                print str(row);
            print "PlayerLocation: ", str(curPlayerLoc);
            print "Box Locations: ", str(curBoxLocs);
            print "Goal Location: ", str(goalLocations);
           # print "States Visited: ", str(statesVisited);
            print "Num States Visited: ", str(numStatesVisited);
            break;
        if movePlayer((x+1, y),curPlayerLoc, curBoxLocs):
            newState = [(x+1, y), curBoxLocs];
            if newState not in statesVisited:
                #print "x: ", str(x+1), "  y: ", str(y);
                stateQ.put((getPriorty(newState),newState));
        if movePlayer((x-1, y),curPlayerLoc, curBoxLocs):
            newState = [(x-1, y), curBoxLocs];
            if newState not in statesVisited:
               # print "x: ", str(x-1), "  y: ", str(y);
                stateQ.put((getPriorty(newState),newState));
        if movePlayer((x, y+1),curPlayerLoc, curBoxLocs):
            newState = [(x,y+1), curBoxLocs];
            if newState not in statesVisited:
               # print "x: ", str(x), "  y: ", str(y+1);
                stateQ.put((getPriorty(newState),newState));
        if movePlayer((x, y-1),curPlayerLoc, curBoxLocs):
            newState = [(x,y-1), curBoxLocs];
            if newState not in statesVisited:
                #print "x: ", str(x), "  y: ", str(y-1);
                stateQ.put((getPriorty(newState),newState));
        for ind in range(len(curBoxLocs)):
            curBoxLoc = curBoxLocs[ind];
            dir = canMoveBox(curBoxLoc, curBoxLocs, curPlayerLoc);
            if not dir == []:
                addX, addY = dir;
                #print str(curBoxLoc)
                bx,by = curBoxLoc
                newLocs = list(curBoxLocs);
                newLocs[ind] = (bx+addX, by+addY);
                newState = [(x+addX,y+addY),newLocs];

                if newState not in statesVisited:
                    #print "x: ", str(x+addX), "  y: ", str(y+addY);
                    #print "Box x: ", str(bx+addX), "  Box y: ", str(by+addY), "\n";
                    stateQ.put((getPriorty(newState),newState));
            
                
    
    
        
            
        
            

 
 
 
 
 
 
 
 
 
 
 
 
 