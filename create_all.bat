@echo off
echo ====================================
echo Генерация документации Doxygen
echo ====================================

REM Проверяем установлен ли Doxygen
where doxygen >nul 2>nul
if errorlevel 1 (
    echo Ошибка: Doxygen не установлен или не добавлен в PATH
    echo Скачайте с: https://www.doxygen.nl/download.html
    pause
    exit /b 1
)

REM Проверяем Graphviz для диаграмм
where dot >nul 2>nul
if errorlevel 1 (
    echo Внимание: Graphviz не установлен. Диаграммы не будут созданы.
    echo Скачайте с: https://graphviz.org/download/
    timeout /t 3
)

REM Очищаем старую документацию
if exist docs\html rmdir /s /q docs\html

REM Генерируем документацию
echo Генерация документации...
doxygen Doxyfile

if exist docs\html\index.html (
    echo Документация успешно сгенерирована!
    echo Открываю в браузере...
    start docs\html\index.html
) else (
    echo Ошибка при генерации документации
    pause
)