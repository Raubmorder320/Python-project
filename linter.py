import subprocess
import sys

def lint_file(file_path):
    file_extension = file_path.split('.')[-1]
    # Проверка расширения файла
    if file_extension == 'py':
        linter = 'flake8'
    elif file_extension == 'cpp' or file_extension == 'c':
        linter = 'cpplint'
    elif file_extension == "java":
        linter = "checkstyle"
    else:
        return f"Не поддерживается расширение файла {file_extension}"
        
    # Создание команды и запуск субпроцесса с соответствующим линтером
    command = f"{linter} {file_path}"
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    print(result)
    # Проверка на наличие ошибок в загруженном файле
    if result.returncode == 0:
        return f"Файл {file_path} прошел проверку без ошибок"
    else:
        return result.stdout.decode('utf-8')
         

if __name__ == '__main__':
    if len(sys.argv)!= 2:
        print("Необходимо указать путь к файлу")
        sys.exit(1)

    file_path = sys.argv[1]
    print(lint_file(file_path))