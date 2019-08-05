//
// Created by Kindeep Singh Kargil on 2019-04-23.
//

#include "coordinate.h"

// def need destructor btw.

coordinate::coordinate(std::vector<int> coord) : val(coord), dimension(coord.size()) {
}

coordinate::coordinate(std::vector<int> coord, int dim) : dimension(dim) {
    val = std::vector<int>();
    val.reserve(dimension);
    for (int i = 0; i < dim; i++) {
        if (coord.size() - 1 < i) {
            val.push_back(0);
        } else {
            val.push_back(coord[i]);
        }
    }
}

coordinate::coordinate(coordinate &coordinate, int dim) : dimension(dim) {
    for (int i = 0; i < dimension; i++) {
        val.push_back(coordinate.get(i));
    }
}

coordinate::coordinate(int dim) : dimension(dim) {
    for (int i = 0; i < dimension; i++) {
        val.push_back(0);
    }
}


int coordinate::get(int index) {
    if (index >= 0 && index < val.size()) {
        return val.at(index);
    } else return 0;
}

int coordinate::dim() {
    return this->dimension;
}

void coordinate::operator++() {
//    std::cout << "Increment" << std::endl;
    for (int i = dimension - 1; i >= 0; i--) {
//        std::cout << "Val i: " << i << std::endl;
        if (val[i] < 7) {
            val[i]++;
            return;
        } else if (i == 0 && val[i] == 7) { return; }
        else { val[i] = 0; }
    }
}

bool coordinate::has_next_inc() {
    int sum = 0;
    for (int el: val) {
        sum += el;
    }
    return sum < 7 * dimension;
}

coordinate coordinate::operator+(coordinate with) {

}

coordinate coordinate::add(coordinate a, coordinate b) {
    std::vector<int> cord;
    cord.reserve(a.dim() + b.dim());
    for (int i = 0; i < a.dim(); i++) {
        cord.push_back(a.get(i));
    }
    for (int j = 0; j < b.dim(); j++) {
        cord.push_back(b.get(j));
    }
    return coordinate(cord, a.dim() + b.dim());
}

std::vector<int> coordinate::vals() {
    return val;
}

void coordinate::set(int index, int value) {
    if(index < dim()) val[index] = value;
}



