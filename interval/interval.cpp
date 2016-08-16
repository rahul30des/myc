#include<iostream>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>

using namespace std;

class Intervals {
    public:
     
    /**
      * Adds an interval [from, to) into internal structure.
      */
     virtual void addInterval(int from, int to) = 0;
 
     virtual int getTotalCoveredLength() = 0;
};

// Time Complexity O(n)
// Space Complexity O(n)
class IntervalUtil:public Intervals {
    // Private Variables
    private:
        map <int,int> hmap;

    // Public Variables
    public:
    
    void addInterval(int from, int to) {   
        hmap[from] = to;
    }

    int getTotalCoveredLength() {
        int total = 0;
        pair <int, int> hpair;
        pair <int, int> ppair;
        for(auto it = hmap.begin(); it!=hmap.end() ; it++) {
            hpair = *it;
            if (it == hmap.begin()) {
                ppair = hpair;
                total = hpair.second - hpair.first + 1;
            } else {
                if (hpair.first <= ppair.second) {
                    if(hpair.second <= ppair.second) {
                        --it;
                        // Current is subset of previous
                        hmap.erase(hpair.first);
                        continue;
                    } else { 
                        // Extend lower bound on previous
                        total += hpair.second - ppair.second;
                        ppair.second = hpair.second;
                        --it;
                        hmap.erase(hpair.first);
                        continue;
                    }
                }  
                total += (hpair.second - hpair.first + 1);
                // Update ppair
                ppair = hpair;
            }
        }
        return total;
    }
};

// Main Function
int main() {
    class IntervalUtil util;
    util.addInterval(3, 6);
    util.addInterval(8, 9);
    util.addInterval(1, 5);
    util.addInterval(2, 5);
      
    cout<<util.getTotalCoveredLength();

    return 0;
}

