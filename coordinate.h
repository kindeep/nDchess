//
// Created by Kindeep Singh Kargil on 2019-04-23.
//

#ifndef NDCHESS_COORDINATE_H
#define NDCHESS_COORDINATE_H

#include <vector>
#include <string>
#include <iostream>

class coordinate {
private:
    std::vector<int> val;
    int dimension;
public:
    coordinate(std::vector<int> coord);

//    coordinate(int coord[]);

    coordinate(std::vector<int> coord, int dim);

    coordinate(coordinate &coordinate, int dim);

    coordinate(int dim);

    /**
     *
     * @param index
     * @return
     */
    int get(int index);

    std::vector<int> vals();

    int dim();

    void operator++();

    coordinate operator+(coordinate with);

    bool has_next_inc();

    static coordinate add(coordinate a, coordinate b);

    std::string to_string() {
//        std::cout<< "dimension: " << dim() << std::endl;
        std::string result;
        for (int i = 0; i < dim(); i++) {
            result += std::to_string(i) +  ": " + std::to_string(get(i)) + " ";
        }
        return result;
    }

    typedef int * iterator;
    typedef const int * const_iterator;
    iterator begin() {
        return &val[0];
    }
    iterator end() {
        return &val[dim() - 1];
    }

};


#endif //NDCHESS_COORDINATE_H
