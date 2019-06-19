Kcm howdy
===========

Systemd control module for KDE Plasma 5. Provides a graphical frontend for the Howdy
project, which allows authentication to system through face recognition.
Integrates in the System Settings dialogue in KDE Plasma 5.


Installation
------------
    mkdir build  
    cd build  
    cmake .. -DCMAKE_INSTALL_PREFIX=`kf5-config --prefix` ..  
    make  
    make install  

Dependencies
------------
*   Qt >= 5.11.0
*   KF5Auth >= 5.50.0
*   KF5ConfigWidgets >= 5.50.0
*   cmake >= 3.12

Execution
---------
Kcm howdy can be accessed through System Settings, or by issuing the command:
`kcmshell5 kcm_howdy`

Developed by:
* Petr Dusek <dusekpe2@fit.cvut.cz>
