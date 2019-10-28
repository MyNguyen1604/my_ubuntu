#include "test_astar.h"

//register this planner as a BaseGlobalPlanner plugin


/**** Initialize Variables ***/
/*****************************/
bool* OGM;
float* gcost;
//static const float INFINIT_COST = INT_MAX; //maximun of int type
float infinity = numeric_limits<float>::infinity(); // infinity of float type

/*********** Class Namspace *************/
/****************************************/
namespace globalplanner{
     /**** Constructor of Class GlobalPlanner****/
     /*******************************************/
     GlobalPlanner::GlobalPlanner(): initialized_(true){
         originX = 0.0;
         originY = 0.0;
              
         width = 4000;
         height = 4000;
         mapsize = width*height;
         reso = 0.05;
         OGM = new bool [mapsize];
         for (unsigned int iy = 0; iy < height; iy++){
             for (unsigned int ix = 0; ix < width; ix++){
                 OGM[iy*width + ix] = true;
                 }
         }
     }
     GlobalPlanner::~GlobalPlanner(){
         delete[] OGM;
         delete[] gcost;
     }
     
     
     
     
     
     
     /******************** makePlan function ******************/
     /*********************************************************/
     
     bool GlobalPlanner::makePlan(){


          float startX = 100.0;
          float startY = 100.0;
          
          float goalX = 2000.0;
          float goalY = 2000.0;
          
          //Convert start and goal to coordinate of costmap
          getCoordinate(startX, startY);
          getCoordinate(goalX, goalY);
          
          //cout << "Coordinate of start("<<startX<<", "<<startY<<")"<<endl;
          //cout << "Coordinate of goal("<<goalX<<", "<<goalY<<")"<<endl;
          
          int startCell;
          int goalCell;
              //Considering startCell and goalCell index in OGM[]
          startCell = converttoCellIndex(startX, startY);
          goalCell = converttoCellIndex(goalX, goalY);
          cout << "Cell index of start: "<<startCell<<endl;
          cout << "Cell index of goal: "<<goalCell<<endl;
          cout << 1<<endl;
          planner(startCell, goalCell);
          return true;
     }
     
     
     /***   Function relative with cell cooridnate **/
     /***********************************************/
     void GlobalPlanner::getCoordinate(float& x, float& y){
          x = x - originX;
          y = y - originY;
     }
     bool GlobalPlanner::iscellInsideMap(float x, float y){
          bool valid = true;
          if ((x > width*reso)||(y > height*reso))
              valid = false;
          return valid;
     }
     
     //Get cell index in OGM[]
     int GlobalPlanner::getCellIndex(int i, int j){
         return j*width + i;
     }
     int GlobalPlanner::converttoCellIndex(float x, float y){
         int cellindex;
         float X_ = x/reso;
         float Y_ = y/reso;
         cellindex = getCellIndex(static_cast<int>(X_), static_cast<int>(Y_));
         return cellindex;
     }
     
     int GlobalPlanner::getRowIndex(int index){
         return index/width;
     }
     int GlobalPlanner::getColIndex(int index){
         return index%width;
     }
     
     
     

     
     
     
     /****** Algorithm A* ******/
     /**************************/
     vector<int> GlobalPlanner::planner(int startCell, int goalCell){
        //float* gcost;
        gcost = new float [mapsize];
        //vector<float> gcost[mapsize];
        for (unsigned int i = 0; i<mapsize;i++){
             gcost[i] = infinity;//initialize gcost of cell unvisited is infinity, if visited it a specific value
        } 
        vector<int> path_;
        path_ = findpath(startCell, goalCell, gcost);
        //delete[] gcost;
        return path_;
     }
     //Function findpath of A* Algorithm//
     vector<int> GlobalPlanner::findpath(int startCell, int goalCell, float gcost[]){
        vector<int> path_;
        vector<int> neighborCell;
        multiset <cell_, cmp> OPEN;
        cell_ CE;
        
       //BEGIN
       gcost[startCell] = 0;
       CE.index = startCell;
       CE.fcost = gcost[CE.index] + calculateHcost(CE.index, goalCell);
       
       OPEN.insert(CE);
       int currentCell;
       
       while (!OPEN.empty()){
           currentCell = OPEN.begin()->index;
           OPEN.erase(OPEN.begin());
           
           if (currentCell == goalCell){
               break;
           }
           else{
               neighborCell = findNeighborCell(currentCell);
               for (unsigned int i = 0; i < neighborCell.size(); i++){
                    if (gcost[neighborCell[i]] == infinity){//neighbor is unvisited
                        gcost[neighborCell[i]] = gcost[currentCell] + getMoveCost(currentCell, neighborCell[i]);
                        addneighbortoOpen(OPEN, neighborCell[i], goalCell, gcost);
                    }//end if
               }//end for
               
           }
       
       }
       
       
       cout << "Reach Goal"<<endl;
       return path_;
        
        
     }
     //Calculate Heuristic cost
     float GlobalPlanner::calculateHcost(int Cell, int goalCell){
         int row = getRowIndex(Cell);
         int col = getColIndex(Cell);
         
         int rowg = getRowIndex(goalCell);
         int colg = getColIndex(goalCell);
         
         return sqrt((rowg - row)^2 + (colg - col)^2);
     }
     
     //Find neighborCell
     inline vector<int> GlobalPlanner::findNeighborCell(int currentIndex){
         int row = getRowIndex(currentIndex);
         int col = getColIndex(currentIndex);
         int neighborIndex;
         vector<int> neighborCell;
         
         for (int i=-1; i<2; i++){
              for(int j=-1; j<2; j++){
                   if ((row+i >= 0) && (row+i<width) && (col+j >= 0) && (col+j < height) && !(i==0 && j==0)){
                       neighborIndex = getCellIndex(col+i, row+j);
                       if (isFreeCell(neighborIndex)){
                           neighborCell.push_back(neighborIndex);
                       }//end if
                   }//end if
              }//end for
         }//end for
         return neighborCell;
     }
     bool GlobalPlanner::isFreeCell(int index){
          return OGM[index];
     }
     //Add neighborCell to OPEN list
     void GlobalPlanner::addneighbortoOpen(multiset<cell_, cmp>& OPEN, int neighborCell, int goalCell, float gcost[] ){
          cell_ CE;
          CE.index = neighborCell;
          CE.fcost = gcost[neighborCell] + calculateHcost(neighborCell, goalCell);
          OPEN.insert(CE);
     }
     
     //Get move cost of from current cell
     float GlobalPlanner::getMoveCost(int startCell, int neighborCell){
          int row = getRowIndex(startCell);
          int col = getColIndex(startCell);
          
          int rown = getRowIndex(neighborCell);
          int coln = getColIndex(neighborCell);
          
          float movecost = 1.0;
          if ((rown == row +1 && coln == col +1) || (rown == row +1 && coln == col -1) || (rown == row -1 && coln == col +1) || (rown == row -1 && coln == col -1)){
              movecost = 1.4;
          }//end if
          return movecost;
     }
     
};
using namespace globalplanner;
int main(){
    GlobalPlanner astar;
    astar.makePlan();
    return 0;
}
