#include <iostream>
#include <memory>
#include <boost/program_options.hpp>
#include "averager.h"

int main() {
    std::unique_ptr<Averager> avptr(new Averager((27)));

    avptr->AddValue(531);
    avptr->AddValue(685);
    avptr->AddValue(739);

    auto avg_speed = avptr->GetAverageSpeed();
    std::cout << avg_speed << std::endl;

    avptr->SetAveragingTime(68);

    std::cout << avptr->GetAverageSpeed() << std::endl;


    return 0;
};