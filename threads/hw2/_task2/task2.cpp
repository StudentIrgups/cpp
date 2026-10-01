#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <atomic>
#include <iomanip>
#include <mutex>
#include <random>
#include <string>

std::mutex cout_mtx;
std::atomic<int> next_row{0};   

const int BAR_LENGTH = 40;

void worker(int thread_num) {
    // Занимаем строку в порядке запуска (0, 1, 2, ...)
    int row = next_row++;

    // Свой генератор случайных чисел — расчёт «разный» у каждого потока
    std::mt19937 gen(std::random_device{}() + thread_num);
    std::uniform_int_distribution<int> delay_dist(50, 150);

    // id текущего потока
    std::thread::id tid = std::this_thread::get_id();

    // Старт замера времени
    auto start = std::chrono::steady_clock::now();

    // Стартовый вывод строки (пустой прогресс-бар)
    {
        std::lock_guard<std::mutex> lock(cout_mtx);

        // Переходим на нужную строку экрана
        std::cout << "\033[" << (row + 1) << ";1H";
        std::cout << "# " << std::setw(2) << thread_num
                  << "  id " << std::setw(7) << tid
                  << "  [";
        for (int i = 0; i < BAR_LENGTH; ++i) std::cout << ' ';
        std::cout << "]  ";
        std::cout.flush();
    }

    // Заполняем прогресс-бар символ за символом
    for (int i = 0; i < BAR_LENGTH; ++i) {
        // Разное время на каждый символ — имитация расчёта
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_dist(gen)));

        {
            std::lock_guard<std::mutex> lock(cout_mtx);
            // Позиция внутри прогресс-бара: 
            // "  [ " уже выведено: 2 (пробел) + 2 ("# ") + ...
            // Проще перейти на строку и переписать целиком
            std::cout << "\033[" << (row + 1) << ";1H";
            std::cout << "# " << std::setw(2) << thread_num
                      << "  id " << std::setw(7) << tid
                      << "  [";
            for (int j = 0; j < BAR_LENGTH; ++j) {
                std::cout << (j <= i ? '#' : ' ');
            }
            std::cout << "]  ";
            std::cout.flush();
        }
    }

    // Конец замера
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed = end - start;

    // Финальный вывод с временем
    {
        std::lock_guard<std::mutex> lock(cout_mtx);
        std::cout << "\033[" << (row + 1) << ";1H";
        std::cout << "# " << std::setw(2) << thread_num
                  << "  id " << std::setw(7) << tid
                  << "  [";
        for (int j = 0; j < BAR_LENGTH; ++j) std::cout << '#';
        std::cout << "]  "
                  << std::fixed << std::setprecision(5)
                  << elapsed.count() << "s"
                  << std::endl;
    }
}

int main() {
    const int NUM_THREADS = 5;    // количество потоков
    const int CALC_LENGTH = 10;   // «длина» расчёта (условная)

    // Очистить экран и спрятать курсор
    std::cout << "\033[2J\033[H\033[?25l";

    // Шапка
    std::cout << "#  id      Progress Bar"
              << std::string(BAR_LENGTH - 10, ' ')
              << "  Time" << std::endl;

    // Резервируем строки под каждый поток
    for (int i = 0; i < NUM_THREADS; ++i) std::cout << std::endl;
    std::cout.flush();

    // Запускаем потоки
    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(worker, i);
    }

    // Ждём завершения всех
    for (auto& t : threads) t.join();

    // Перемещаем курсор ниже таблицы и показываем его
    std::cout << "\033[" << (NUM_THREADS + 3) << ";1H";
    std::cout << "\033[?25h";
    std::cout.flush();

    return 0;
}