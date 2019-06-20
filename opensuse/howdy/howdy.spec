#
# spec file for package howdy
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


Name:           howdy
Version:        2.5.1
Release:        0
Summary:        Windows Hello style authentication for Linux
License:        MIT
Group:          System/Libraries
URL:            https://github.com/dusekpe2/%{name}
Source0:        https://github.com/dusekpe2/%{name}/releases/download/v%{version}/%{name}-%{version}.tar.gz
#BuildRequires:  python3
#BuildRequires:  wget
#BuildRequires:       python3-pip
#BuildRequires:       python3-setuptools
#BuildRequires:       python3-opencv
BuildRequires:       python3-devel
BuildRequires:	python3-opencv
Requires:	%{python_module opencv}
#Requires:       pam-python
#Requires:       cmake
#Requires:       gcc-c++
#Requires:       v4l-tools

%description

%prep
%setup -q

%build
#nothing

%install
mkdir -p %{buildroot}/lib/security/%{name}
cp -pr src/* %{buildroot}/lib/security/%{name}

#sh %{buildroot}/lib/security/%{name}/dlib-data/install.sh
#mv *.dat %{buildroot}/lib/security/%{name}/dlib-data

mkdir -p %{buildroot}%{_datadir}/bash-completion/completions
install -Dm 644 autocomplete/%{name} %{buildroot}%{_datadir}/bash-completion/completions

mkdir -p %{buildroot}%{_bindir}
chmod +x %{buildroot}/lib/security/%{name}/cli.py
ln -s /lib/security/howdy/cli.py %{buildroot}%{_bindir}/%{name}

#%post
#pip3 install --upgrade pip
#pip3 install opencv-python
#pip3 install dlib 

%files
%license LICENSE
%doc README.md
%{_bindir}/%{name}
/lib/security
#/lib/security/howdy
%{_datadir}/bash-completion/completions/%{name}

%changelog
