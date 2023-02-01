//
// Created by Stephane Walter on 1/20/23.
//

#include "timer.hpp"

#include <cstdlib>

timer::timer() {
    reset();
}

long timer::get_time() {
    timeval now;
    timeval diff;

    gettimeofday(&now, NULL);
    timersub(&now, &stamp, &diff);
    return diff.tv_sec * 1000 + diff.tv_usec / 1000;
}

void timer::reset() {
    gettimeofday(&stamp, NULL);
}