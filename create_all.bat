@echo off
echo ====================================
echo Timirbaev Project - Documentation
echo ====================================

echo Checking Doxygen installation...
where doxygen >nul 2>nul
if %errorlevel% neq 0 (
    echo ERROR: Doxygen not found!
    echo Download from: https://www.doxygen.nl/download.html
    echo Add to PATH: C:\Program Files\doxygen\bin
    pause
    exit /b 1
)

echo Checking Graphviz installation...
where dot >nul 2>nul
if %errorlevel% neq 0 (
    echo WARNING: Graphviz not found. Diagrams will be missing.
    echo Download from: https://graphviz.org/download/
    timeout /t 3
)

echo Cleaning old documentation...
if exist docs rmdir /s /q docs
mkdir docs

echo Generating documentation with Doxygen...
doxygen Doxyfile

if exist docs\html\index.html (
    echo SUCCESS: Documentation generated!
    echo Opening in browser...
    start docs\html\index.html
) else (
    echo ERROR: Documentation generation failed!
    echo Check Doxyfile configuration
)

pause