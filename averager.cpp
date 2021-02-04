//
// Created by alexi on 01.02.2021.
//
#include <iostream>
#include <numeric>
#include "averager.h"

Averager::Averager(uint32_t avg_time_s) : avg_time_(avg_time_s)
{
};

void Averager::SetAveragingTime(uint32_t avg_time_s)
{
    avg_time_ = avg_time_s;
}
float Averager::GetAverageSpeed() const
{
    auto sum = std::accumulate(values_.begin(),values_.end(),decltype(values_)::value_type(0));
    float res =0;
    if(avg_time_!=0)
    {
        float res = static_cast<float>(sum)/avg_time_;
    }

    return  res;
}

void Averager::AddValue(uint32_t value)
{
    values_.push_back(value);
}

Averager::~Averager()
{

}
