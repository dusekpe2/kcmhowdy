# Copyright 2019 Gentoo Authors
# Distributed under the terms of the GNU General Public License v2

EAPI=7
PYTHON_COMPAT=( python3_{5,6,7} )
inherit python-single-r1


DESCRIPTION="Windows Hello for Linux"
HOMEPAGE="https://github.com/dusekpe2/howdy/"
SRC_URI="https://github.com/dusekpe2/howdy/releases/download/v${PV}/${P}.tar.gz"

LICENSE="MIT"
SLOT="0"
KEYWORDS="~amd64 ~x86"
IUSE=""

RDEPEND="
		${PYTHON_DEPS}
		sci-libs/dlib[jpeg,png,python]
		dev-python/numpy
		media-libs/opencv[python,v4l]"


src_install() {
	insinto /lib/security/${PN}
	doins -r ${WORKDIR}/${P}/src/*
	dosym ${D}/lib/security/${PN}/cli.py /usr/bin/howdy
	fperms 0555 /lib/security/${PN}/cli.py

	dodoc ${WORKDIR}/${P}/LICENSE
	dodoc ${WORKDIR}/${P}/README.md
}

pkg_postinst() {
	elog "Review settings in /usr/lib/security${D}/config.ini. Option device_path must be set to an existing device."
	elog "Add PAM configuration to /etc/pam.d, e.g.:"
	elog "auth sufficient pam_python.so /usr/lib/secutiry${P}/pam.py"
	ewarn "This package requires environment variable ``SUDO_USER'' set even if ``sudo'' is not used."
}
