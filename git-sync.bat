@echo off
cd /d "%~dp0"

:: Optional: Ask for custom commit message
set /p msg=Enter commit message (default: "Auto-sync"): 
if "%msg%"=="" set msg=Auto-sync

:: Add all changes
git add .

:: Commit
git commit -m "%msg%"

:: Push
git push origin
