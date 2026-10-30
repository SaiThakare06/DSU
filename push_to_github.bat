@echo off
echo ====================================================
echo Pushing DSU Repository to GitHub
echo Remote: https://github.com/SaiThakare06/DSU.git
echo ====================================================

:: Initialize git repository if not already initialized
git init

:: Rename branch to main
git branch -M main

:: Configure remote origin (remove if exists, then add)
git remote remove origin 2>nul
git remote add origin https://github.com/SaiThakare06/DSU.git

:: Stage all practicals, documentation, and finder tools
git add .

:: Commit all changes
git commit -m "Add DSU lab practicals, topic finder tools, and README documentation"

:: Push to remote main branch
git push -u origin main

echo.
echo ====================================================
echo Push process completed!
echo ====================================================
pause
