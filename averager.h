//
// Created by alexi on 01.02.2021.
//

#ifndef AVERAGER_AVERAGER_H
#define AVERAGER_AVERAGER_H

#include <cstdint>
#include <vector>

class Averager {
public:
    explicit Averager(uint32_t avg_time_s);
    void SetAveragingTime(uint32_t avg_time_s); /* Меняем время усреднения в процессе работы */
    float GetAverageSpeed() const; /* Возвращается среднее значение скорости */
    void AddValue(uint32_t value); /* Добавлем информацию о получении value байтов */
    ~Averager();
private:
    uint32_t avg_time_; // seconds
    std::vector<uint32_t> values_;
};


#endif //AVERAGER_AVERAGER_H
