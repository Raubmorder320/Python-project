import subprocess
import sys

def lint_file(file_path):
    file_extension = file_path.split('.')[-1]

    if file_extension == 'py':
        linter = 'flake8'
    elif file_extension == 'cpp' or file_extension == 'c':
        linter = 'cpplint'
    else:
        print(f"Не поддерживается расширение файла {file_extension}")
        return

    command = f"{linter} {file_path}"
    result = subprocess.run(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

    if result.returncode == 0:
        print(f"Файл {file_path} прошел проверку без ошибок")
    else:
        print(f"Файл {file_path} содержит ошибки")
        print(result.stderr.decode('utf-8'))

if __name__ == '__main__':
    if len(sys.argv)!= 2:
        print("Необходимо указать путь к файлу")
        sys.exit(1)

    file_path = sys.argv[1]
    lint_file(file_path)