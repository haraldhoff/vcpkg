@echo .
@echo .
@echo Installing packages for tutorials.
@echo Please wait... This can take a couple of hours...
@echo .
@echo .

call install-package.bat yaml-cpp
call install-package.bat gtest
call install-package.bat nana
call install-package.bat fontconfig
call install-package.bat cppzmq
call install-package.bat opencv4
call install-package.bat boost

@echo .

call integrate-install-project-level.bat > nul
