#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <limits>

using namespace std;
using std::string;

#ifndef GLOBALPLANNER_CPP
#define GLOBALPLANNER_CPP
typedef struct {
    int index;
    float fcost;
} cell_;
struct cmp{
    bool operator()(cell_ a, cell_ b) {return a.fcost < b.fcost;}
};
namespace globalplanner{
    class GlobalPlanner{
        public:
        GlobalPlanner();
        ~GlobalPlanner();
        
        float calculateHcost(int Cell, int goalCell);
        void addneighbortoOpen(multiset<cell_, cmp>& OPEN, int neighborCell, int goalCell, float gcost[]);
        float getMoveCost(int startCell, int neighborCell);
        
        vector<int> planner(int startCell, int goalCell);
        vector<int> findpath(int startCell, int goalCell, float gcost[]);
        vector<int> findNeighborCell(int currentIndex);
        
        int converttoCellIndex(float x, float y);
        int getCellIndex(int i, int j);
        int getRowIndex(int index);
        int getColIndex(int index);
        void getCoordinate(float& x, float& y);
        
        
        bool makePlan();
        bool iscellInsideMap(float x, float y);
        bool isFreeCell(int index);
        float originX, originY;
        float reso; //resolution of costmap
        int width;
        int height;
        int mapsize;
        bool initialized_;
        
        
    }; 

};
#endif
