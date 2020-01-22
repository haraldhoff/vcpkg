First time usage:

* Clone this repo to c:\opt   
  (So that it becomes c:\opt\vcpkg -- strongly recommended to use this to avoid problems)
* Open a terminal, and go into folder c:\opt\vcpkg
* Run 'bootstrap-vcpkg.bat' and let it complete
* Enter 'list-all-available.bat' to show all packages that are available
* Enter 'install-package.bat yaml-cpp' and let complete
* Enter 'list-installed.bat' to show all installed packages
* Enter 'integrate-install-project.bat' and notice the output
* Open Visual Studio (2017/2019) and open the solution in the 'vs-tutorials\yaml-cpp' folder
* Go to Tools->NuGet Package Manager->Package Manager Console and paste:   
  Install-Package vcpkg.C.opt.vcpkg -Source "C:\opt\vcpkg\scripts\buildsystems"
* Build the solution, it should compile without errors (famous last words... :-)  (Se troubleshooting if not)
* Run the project

.

Add vcpkg to Visual Studio Nuget package sources
* In Visual Studio - select Tools / Options / Nuget Package Manager / Package Sources
* Click the + button to add a new source
* Enter Name   : vcpkg
* Enter Source : C:\opt\vcpkg\scripts\buildsystems
* Click OK
* All vcpkg packages should now work with Nuget package restore etc.

.

Troubleshooting   
* Error - "The Windows SDK Version .... was not found"
  * Right-click on the project (e.g yaml-cpp) and select properties
  * Under "Configuration Properties / General" select the latest Windows SDK Version
  * Press OK and try to build the solution again

* Error - "NuGet Package restore failed for project ..."
  * Click on packages.config
  * Press DEL/Delete button
  * Choose Delete to permanently delete
  * Go to Tools->NuGet Package Manager->Package Manager Console and paste:   
    Install-Package vcpkg.C.opt.vcpkg -Source "C:\opt\vcpkg\scripts\buildsystems"

