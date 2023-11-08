#pragma once
#include<iostream>
#include"Computer.h"

class Desktop : public Computer {
public:
	Desktop(string model_, string ip_, string modelofprocessor_, int cores_, int speed_, int cachememory_, int memory_, bool keyboard_, bool connect_) :Computer(model_, ip_, modelofprocessor_, cores_, speed_, cachememory_, memory_, keyboard_, connect_) {};
};