#include <iostream>
#include <memory>
#include "averager.h"
#include <gtest/gtest.h>

class AvrTest : public ::testing::Test {
protected:
    void SetUp()
    {
        atest.reset(new Averager()); ;



    }

    std::unique_ptr<Averager> atest;
};

TEST_F(AvrTest, ZeroAvgTime)
{
    atest->AddValue(531);
    atest->AddValue(685);
    atest->AddValue(739);
    auto res = atest->GetAverageSpeed();

    ASSERT_NE(0, res);
    EXPECT_LT(20, res);
}

int main() {
    /*
    std::unique_ptr<Averager> avptr(new Averager((27)));

    avptr->AddValue(531);
    avptr->AddValue(685);
    avptr->AddValue(739);

    auto avg_speed = avptr->GetAverageSpeed();
    std::cout << avg_speed << std::endl;

    avptr->SetAveragingTime(68);

    std::cout << avptr->GetAverageSpeed() << std::endl;
     */
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
    return 0;
};