//
// Created by alexi on 01.02.2021.
//
#include <iostream>
#include <numeric>
#include "averager.h"

Averager::Averager(uint32_t avg_time_s) : avg_time_(avg_time_s)
{
    std::cout << "hello averager!" << std::endl;
};

void Averager::SetAveragingTime(uint32_t avg_time_s)
{
    avg_time_ = avg_time_s;
}
float Averager::GetAverageSpeed() const
{
    std::cout << "get average speed:" << std::endl;
    auto sum = std::accumulate(values_.begin(),values_.end(),decltype(values_)::value_type(0));
    float res = static_cast<float>(sum)/avg_time_;
    return  res;
}

void Averager::AddValue(uint32_t value)
{
    std::cout << "Add value " << value << std::endl;
    values_.push_back(value);
}

Averager::~Averager()
{

}
