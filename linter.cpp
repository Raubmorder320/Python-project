#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        std::cerr << "Необходимо указать путь к файлу" << std::endl;
        return 1;
    }

    std::string file_path = argv[1];
    std::string file_extension = file_path.substr(file_path.find_last_of('.') + 1);

    std::string linter;
    if (file_extension == "py") {
        linter = "flake8";
    } else if (file_extension == "cpp" || file_extension == "c") {
        linter = "cpplint";
    } else {
        std::cerr << "Не поддерживается расширение файла " << file_extension << std::endl;
        return 1;
    }

    std::string command = linter + " " + file_path;
    int result = system(command.c_str());

    if (result == 0) {
        std::cout << "Файл " << file_path << " прошел проверку без ошибок" << std::endl;
    }
    return 0;
}