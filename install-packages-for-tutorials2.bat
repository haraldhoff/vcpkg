@echo .
@echo .

call install-packages-for-tutorials.bat

call install-package.bat qt5

@echo .

call integrate-install-project-level.bat > nul
