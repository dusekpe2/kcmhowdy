#
# spec file for package kcm_howdy
#
# Copyright (c) 2019 SUSE LINUX GmbH, Nuernberg, Germany.
#
# All modifications and additions to the file contributed by third parties
# remain the property of their copyright owners, unless otherwise agreed
# upon. The license for this file, and modifications and additions to the
# file, is the same license as for the pristine package itself (unless the
# license for the pristine package is not an Open Source License, in which
# case the license is the MIT License). An "Open Source License" is a
# license that conforms to the Open Source Definition (Version 1.9)
# published by the Open Source Initiative.

# Please submit bugfixes or comments via https://bugs.opensuse.org/
#


Name:           kcmhowdy
Version:		1.0.0        
Release:        0
Summary:        KCM module for prooject Howdy
License:        GPLv2
Group:          System/Libraries
Source0:        https://github.com/dusekpe2/%{name}/%{version}.tar.gz
BuildRequires: cmake >= 3.12
BuildRequires: gcc-c++
BuildRequires: kf5-filesystem
BuildRequires: extra-cmake-modules >= 5.50.0
BuildRequires: libQt5Widgets-devel >= 5.11.0
BuildRequires: kconfigwidgets-devel >= 5.50.0
BuildRequires: libKF5Auth5 >= 5.50.0
Requires:	   howdy = 2.5.1

%description
A System Settings module for managing project Howdy - face authentication module.

%prep
%setup -q

%build
%cmake_kf5 -d build
%make_jobs


%install
%kf5_makeinstall -C build


%files
%{_kf5_plugindir}/
%{_kf5_dbuspolicydir}/org.kde.kcontrol.kcmhowdy.conf
%{_kf5_sharedir}/polkit-1/actions/org.kde.kcontrol.kcmhowdy.policy
%{_kf5_sharedir}/dbus-1/system-services/org.kde.kcontrol.kcmhowdy.service
%{_kf5_libdir}/libexec/
%{_kf5_servicesdir}/

%changelog
