# CMake generated Testfile for 
# Source directory: /home/petr/untitled1
# Build directory: /home/petr/untitled1
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(appstreamtest "/usr/bin/cmake" "-DAPPSTREAMCLI=/usr/bin/appstreamcli" "-DINSTALL_FILES=/home/petr/untitled1/install_manifest.txt" "-P" "/usr/share/ECM/kde-modules/appstreamtest.cmake")
