#include "leaderboard.h"
const int MAX_POSITION = 10;
void Leaderboard::load_from_file()
{
    in.open(path);
    if (!(in.is_open())) {
        std::cout << "File Not Found\n";
    } else {
        int i = 0;
        std::string str;
        while (getline(in, str)) {
            if (!is_data_valid(str)) {
                continue;
            }
            records[i].first = str;
            int space = str.find(" ");
            records[i].first.erase(space, str.length());
            str.erase(0, space + 1);
            for (unsigned int j = 0; j < str.length(); ++j) {
                records[i].second *= 10;
                records[i].second += str[j] - 48;
            }
            i++;
        }
        in.close();
    }
}
void Leaderboard::save_to_file()
{
    std::fstream out;
    out.open(path);
    if (!(out.is_open())) {
        std::cout << "File Not Found\n";
    } else {
        for (int i = 0; i < MAX_POSITION; i++) {
            std::string str;
            str += records[i].first;
            str += " ";
            str += std::to_string(records[i].second);
            str += "\n";
            out << str;
        }
        out.close();
    }
}
Leaderboard::Leaderboard()
{
    clear();
    Leaderboard::load_from_file();
}

Leaderboard::~Leaderboard()
{
}

void Leaderboard::show_leader_board()
{
    for (int i = 0; i < MAX_POSITION; ++i) {
        if (records[i].second == 0) {
            break;
        }
        std::cout << i + 1 << ") " << records[i].first << " "
                  << records[i].second << std::endl;
    }
    std::cout << std::endl;
}

std::pair<std::string, int> Leaderboard::get_record(int pos)
{
    std::pair<std::string, int> out;
    if (pos < 0 || pos > 9) {
        out.first = " ";
        out.second = 0;
        return out;
    }
    out.first = records[pos].first;
    out.second = records[pos].second;
    return out;
}

void Leaderboard::clear()
{
    for (int i = 0; i < MAX_POSITION; ++i) {
        records[i].first = " ";
        records[i].second = 0;
    }
}

bool Leaderboard::is_data_valid(std::string str)
{
    int space = str.find(" ");
    if (space < 1) {
        return false;
    }
    for (unsigned int i = space + 1; i < str.length(); ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool Leaderboard::is_name_valid(std::string name)
{
    if (name.size() == 0 || name.size() > 12) {
        return false;
    }
    if (name.find(" ") != std::string::npos) {
        return false;
    }
    return true;
}

std::string Leaderboard::get_name()
{
    std::cout << "Введите имя(не более 12 символов): \n";
    std::string name;
    do {
        getline(std::cin, name);
        if (!is_name_valid(name)) {
            std::cout << "Некорректный ввод\n";
            continue;
        }
    } while (!is_name_valid(name));
    return name;
}

void Leaderboard::insert(std::string name, int turns, int pos)
{
    std::pair<std::string, int> buffer;
    buffer.first = records[pos].first;
    buffer.second = records[pos].second;
    records[pos].first = name;
    records[pos].second = turns;
    pos++;
    while (pos < MAX_POSITION) {
        if (records[pos].second == 0) {
            records[pos].first = buffer.first;
            records[pos].second = buffer.second;
            break;
        }
        std::string tmp_str = records[pos].first;
        int tmp_int = records[pos].second;

        records[pos].first = buffer.first;
        records[pos].second = buffer.second;

        buffer.first = tmp_str;
        buffer.second = tmp_int;

        ++pos;
    }
}

int Leaderboard::is_new_record(int turns)
{
    for (int i = 0; i < MAX_POSITION; ++i) {
        if (records[i].second == 0) {
            return i;
        }
        if (records[i].second > turns) {
            return i;
        }
    }
    return -1;
}