class ParkingSystem {
public:
    int bl,ml,sl;
    int bc,mc,sc;

    ParkingSystem(int big, int medium, int small) {
        this->bl = big;
        this->ml = medium;
        this->sl = small;

        this->bc = 0;
        this->mc = 0;
        this->sc = 0;
        
    }
    
    bool addCar(int carType) {
        if(carType == 1)
        {
            if(this->bc < this->bl)
            {
                this->bc++;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(carType == 2)
        {
            if(this->mc < this->ml)
            {
                this->mc++;
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(carType == 3)
        {
            if(this->sc < this->sl)
            {
                this->sc++;
                return true;
            }
            else
            {
                return false;
            }
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
