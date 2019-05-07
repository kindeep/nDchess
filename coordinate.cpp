//
// Created by Kindeep Singh Kargil on 2019-04-23.
//

#include "coordinate.h"

coordinate::coordinate(std::vector<int> coord) : val(coord) {

}

int coordinate::get(int index) {
    if (index >= 0 && index < val.size()) {
        return val.at(index);
    } else return 0;
}
