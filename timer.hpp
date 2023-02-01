//
// Created by Stephane Walter on 1/20/23.
//

#ifndef FT_CONTENAIR_TIMER_HPP
#define FT_CONTENAIR_TIMER_HPP

#include <sys/time.h>
#include <time.h>

class timer {
public:
    timer();
    long get_time();
    void reset();
private:
    struct timeval stamp;


};


#endif //FT_CONTENAIR_TIMER_HPP
