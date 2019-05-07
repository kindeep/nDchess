//
// Created by Kindeep Singh Kargil on 2019-04-23.
//

#ifndef NDCHESS_COORDINATE_H
#define NDCHESS_COORDINATE_H

#include <vector>

class coordinate {
private:
   std::vector<int> val;
public:
    coordinate(std::vector<int> coord);

    /**
     *
     * @param index
     * @return
     */
    int get(int index);

};


#endif //NDCHESS_COORDINATE_H
