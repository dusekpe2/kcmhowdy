#
# spec file for package python-dlib
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

# Please submit bugfixes or comments via http://bugs.opensuse.org/


%{?!python_module:%define python_module() python-%{**} python3-%{**}}
Name:           python-dlib
Version:        19.17.0
Release:        0
License:        BSL-1.0
Summary:        A toolkit for making real world machine learning and data analysis applications
Url:            https://github.com/davisking/dlib
Group:          Development/Languages/Python
Source:         https://files.pythonhosted.org/packages/05/57/e8a8caa3c89a27f80bc78da39c423e2553f482a3705adc619176a3a24b36/dlib-%{version}.tar.gz

%if 0%{?suse_version} == 1500
BuildRequires:	gcc7-c++
%else
BuildRequires:  gcc8-c++
%endif
BuildRequires:  cmake
BuildRequires:  libX11-devel
BuildRequires:  cblas-devel
BuildRequires:  openblas-devel
BuildRequires:  lapack-devel
BuildRequires:  python-rpm-macros
BuildRequires:  %{python_module devel}
BuildRequires:  %{python_module setuptools}
BuildRequires:  fdupes

Recommends: cblas-devel
Recommends:	openblas-devel
Recommends:	lapack-devel

%python_subpackages

%description
A toolkit for making real world machine learning and data analysis applications using Python

%prep
%setup -q -n dlib-%{version}

%build
%if 0%{?suse_version} == 1500
export CXX=g++-7
%else
export CXX=g++-8
%endif
export CFLAGS="%{optflags}"
%python_build

%install
%python_install
%python_expand %fdupes %{buildroot}%{$python_sitearch}

%files %{python_files}
%doc README.md
%{python_sitearch}/*

%changelog