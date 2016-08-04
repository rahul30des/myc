#include<iostream>
#include<vector>

using namespace std;

class Intervals {
    public:
     
    /**
      * Adds an interval [from, to) into internal structure.
      */
     virtual void addInterval(int from, int to) = 0;
 
     virtual int getTotalCoveredLength() = 0;
};

// Class for the tuple/pair
class tpair {
public:
    int from;
    int to;
    tpair(int x1, int x2) {
        from = x1;
        to = x2;
    }
};

// Time Complexity O(n)
// Space Complexity O(n)
class IntervalUtil:public Intervals {
    // Private Variables
    private:
        vector<tpair> tpset;

    // Public Variables
    public:
    
    void addInterval(int from, int to) {  
        bool flag = false;
        // Go over all the pairs and find intersection
        // Modify bounds of existing entry if intersects
        for(auto it = tpset.begin(); it != tpset.end(); it++) { 
            // Edit by reference
            tpair &pair = *it;
            flag = true;
            // Superset of existing pair
            if((from <= pair.from) && (to >= pair.to)) {
                pair.from = from;
                pair.to = to;
                break;
            } else if (((pair.from <= from) && (from <= pair.to)) &&
                ((pair.from < to) && (to < pair.to))) {
                // Subset of existing pair
                break;
            } else if ((from <= pair.from) && ((to >= pair.from) && (to <= pair.to))) {
                // Lower Bound increases
                pair.from = from;
                break;
            } else if(((pair.from < from) && (from < pair.to)) && (pair.to < to)) {
                // Upper Bound Increases
                pair.to = to;
                break;
            } 
            flag = false;
        }
        if(flag == false) {
            tpair npair(from,to);
            tpset.push_back(npair);
        }
           
    }

    int getTotalCoveredLength() {
        int tsize = 0;
        for(auto it = tpset.begin(); it!=tpset.end() ; it++) {
                tpair pair = *it;
                tsize += (pair.to - pair.from);
        }
        return tsize;
    }
};

int main() {
    class IntervalUtil util;
    util.addInterval(3, 6);
    util.addInterval(8, 9);
    util.addInterval(1, 5);
      
    cout<<util.getTotalCoveredLength();

    return 0;
}
