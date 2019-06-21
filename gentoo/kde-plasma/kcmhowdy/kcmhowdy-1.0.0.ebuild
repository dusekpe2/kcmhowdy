# Copyright 2019 Gentoo Authors
# Distributed under the terms of the GNU General Public License v2

EAPI=7

inherit kde5

#KDE_FRAMEWORKS_MINIMAL=5.60.0
#QT_MINIMAL=5.11.0
#CMAKE_MIN_VERSION=3.12

DESCRIPTION="KDE Plasma 5 control module for for Howdy"

HOMEPAGE="https://github.com/dusekpe2/${PN}.git"
SRC_URI="https://github.com/dusekpe2/${PN}/archive/v${PV}.tar.gz"

LICENSE="GPL-2+"
SLOT="0"
KEYWORDS="~amd64 ~x86"
IUSE=""

DEPEND="
	$(add_frameworks_dep kauth)
	$(add_frameworks_dep kconfigwidgets)
	$(add_qt_dep qtwidgets)
	>=dev-util/cmake-3.12
"

RDEPEND=" ${DEPEND}
	=sys-auth/howdy-2.5.1
"

src_configure() {
	kde5_src_configure 
}

pkg_postinst() {
	kde5_pkg_postinst
	elog "Complete"
}
