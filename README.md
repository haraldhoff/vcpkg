Under contruction...   

* Clone this repo to c:\dev   (so that it becomes c:\dev\vcpkg)
* Open a terminal, and go into folder c:\dev\vcpkg
* Run 'bootstrap-vcpkg.bat' and let it complete
* Enter 'install-package.bat yaml-cpp' and let complete
* Enter 'integrate-install-project.bat' and notice the output
* Open Visual Studio (2017 and up) and open the solution in the 'vs-tutorials\yaml-cpp' folder
* Go to Tools->NuGet Package Manager->Package Manager Console and paste:   
  Install-Package vcpkg.C.dev.vcpkg -Source "C:\dev\vcpkg\scripts\buildsystems"
* Build the solution, it should compile without errors (famous last words... :-)
* Run the project


Troubleshooting   
* "The Windows SDK Version .... was not found"
