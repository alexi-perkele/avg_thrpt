#pragma once

#include <cstdint>
#include <vector>

class Averager {
public:
    explicit Averager(uint32_t avg_time_s=60);
    void SetAveragingTime(uint32_t avg_time_s); /* Меняем время усреднения в процессе работы */
    float GetAverageSpeed() const; /* Возвращается среднее значение скорости */
    void AddValue(uint32_t value); /* Добавлем информацию о получении value байтов */

    ~Averager();
private:
    uint32_t avg_time_;
    std::vector<uint32_t> values_;
};

