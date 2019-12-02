Under contruction...   

* Clone this repo to c:\opt   (so that it becomes c:\opt\vcpkg)
* Open a terminal, and go into folder c:\opt\vcpkg
* Run 'bootstrap-vcpkg.bat' and let it complete
* Enter 'install-package.bat yaml-cpp' and let complete
* Enter 'integrate-install-project.bat' and notice the output
* Open Visual Studio (2017 and up) and open the solution in the 'vs-tutorials\yaml-cpp' folder
* Go to Tools->NuGet Package Manager->Package Manager Console and paste:   
  Install-Package vcpkg.C.opt.vcpkg -Source "C:\opt\vcpkg\scripts\buildsystems"
* Build the solution, it should compile without errors (famous last words... :-)
* Run the project

.

Troubleshooting   
* Error - "The Windows SDK Version .... was not found"
  * Right Click on the project "yaml-cpp" and select properties
  * Under "Configuration Properties / General" select the latest Windows SDK Version
  * Press OK and try to build the solution again
