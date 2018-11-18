#pragma once
#include<chrono>
#include<iostream>

class SimpleTimer {
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;
public:
	SimpleTimer();
	~SimpleTimer();
};