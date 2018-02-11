#include "timer.h"

float delta_time;
float fps;
std::chrono::time_point<std::chrono::system_clock> time1;
std::chrono::time_point<std::chrono::system_clock> time2;

void start_timer()
{
    time1 = std::chrono::system_clock::now();
    time2 = std::chrono::system_clock::now();
}

void update_timer()
{
    time2 = std::chrono::system_clock::now();
    std::chrono::duration<float> elapsed_time = time2 - time1;
    time1 = time2;
    delta_time = elapsed_time.count();
    fps = 1/delta_time;
}