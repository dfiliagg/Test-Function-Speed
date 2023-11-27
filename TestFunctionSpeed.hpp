#pragma once

#include <chrono>
#include <functional>
#include <vector>
#include <numeric>
#include <iostream>

template <typename F, typename... Args>
double speed_calc(F f, Args... args);
template <typename F, typename... Args>
double speed_calc_n_time(F f, int n,  Args... args);              
