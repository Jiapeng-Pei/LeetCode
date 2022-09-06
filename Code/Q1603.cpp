#include <vector>

using namespace std;

class ParkingSystem {
public:
    vector<int> spaces;
    ParkingSystem(int big, int medium, int small) {
        spaces = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if (!spaces[--carType]) return false;
        spaces[carType]--;
        return true;
    }
};
