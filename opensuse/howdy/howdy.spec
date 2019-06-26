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
Requires:	python3
Requires:   python3-dlib
Requires:	python3-opencv
Requires:	pam-python
Requires:	python3-numpy

%description
Howdy provides Windows Hello™ style authentication for Linux.

%prep
%setup -q

%install
mkdir -p %{buildroot}/lib/security/%{name}
cp -pr src/* %{buildroot}/lib/security/%{name}

mkdir -p %{buildroot}%{_datadir}/bash-completion/completions
install -Dm 644 autocomplete/%{name} %{buildroot}%{_datadir}/bash-completion/completions

mkdir -p %{buildroot}%{_bindir}
chmod 0755 %{buildroot}/lib/security/%{name}/cli.py
ln -s /lib/security/howdy/cli.py %{buildroot}%{_bindir}/%{name}

%post
echo "Review settings in /usr/lib/security${D}/config.ini. Option device_path must be set to an existing device."
echo "Add PAM configuration to /etc/pam.d, e.g.:common-auth"
echo "auth sufficient pam_python.so /usr/lib/secutiry${P}/pam.py"
echo "This package requires environment variable ``SUDO_USER'' set even if ``sudo'' is not used."


%files
%license LICENSE
%doc README.md
%{_bindir}/%{name}
/lib/security
%{_datadir}/bash-completion/completions/%{name}

%changelog