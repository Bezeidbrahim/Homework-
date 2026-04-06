// Задача: Бинарный журнал
// Структура с 4 полями, запись в бинарный файл, чтение и вывод

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>

// Структура записи журнала (4 поля)
struct LogEntry {
    int    id;           // номер записи
    int    year;         // год (2020-2024)
    double temperature;  // температура
    int    sensorCode;   // код датчика (1-100)
};

// Список городов для генерации
const char* cities[] = {"Москва", "Казань", "Самара", "Уфа", "Пермь"};

int main() {
    srand((unsigned int)time(nullptr));

    const char* filename = "journal.bin";
    const int COUNT = 10;

    // === Запись в бинарный файл ===
    {
        std::ofstream fout(filename, std::ios::binary);
        if (!fout) {
            std::cerr << "Ошибка открытия файла для записи!\n";
            return 1;
        }

        for (int i = 0; i < COUNT; i++) {
            LogEntry entry;
            entry.id          = i + 1;
            entry.year        = 2020 + rand() % 5;          // 2020-2024
            entry.temperature = -20.0 + (rand() % 600) / 10.0; // -20.0 до +40.0
            entry.sensorCode  = 1 + rand() % 100;           // 1-100

            fout.write(reinterpret_cast<const char*>(&entry), sizeof(LogEntry));
        }

        fout.close();
        std::cout << "10 записей успешно записаны в файл \"" << filename << "\"\n\n";
    }

    // === Чтение из бинарного файла ===
    {
        std::ifstream fin(filename, std::ios::binary);
        if (!fin) {
            std::cerr << "Ошибка открытия файла для чтения!\n";
            return 1;
        }

        // Красивый заголовок таблицы
        std::cout << "╔══════╦════════════╦═══════════════════╦═════════════╗\n";
        std::cout << "║  ID  ║    Год     ║   Температура     ║  Код датчика ║\n";
        std::cout << "╠══════╬════════════╬═══════════════════╬═════════════╣\n";

        LogEntry entry;
        while (fin.read(reinterpret_cast<char*>(&entry), sizeof(LogEntry))) {
            std::cout << "║ "
                      << std::setw(4)  << entry.id          << " ║ "
                      << std::setw(8)  << entry.year         << "   ║ "
                      << std::setw(10) << std::fixed << std::setprecision(1)
                                       << entry.temperature  << " °C      ║ "
                      << std::setw(9)  << entry.sensorCode   << "   ║\n";
        }

        std::cout << "╚══════╩════════════╩═══════════════════╩═════════════╝\n\n";

        // Получить размер файла
        fin.clear();
        fin.seekg(0, std::ios::end);
        long long fileSize = (long long)fin.tellg();
        std::cout << "Размер файла: " << fileSize << " байт\n";
        std::cout << "(Ожидается: " << COUNT * (long long)sizeof(LogEntry) << " байт = "
                  << COUNT << " записей × " << sizeof(LogEntry) << " байт)\n";

        fin.close();
    }

    return 0;
}
