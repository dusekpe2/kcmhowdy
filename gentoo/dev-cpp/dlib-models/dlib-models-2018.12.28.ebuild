# Copyright 2019 Gentoo Authors
# Distributed under the terms of the GNU General Public License v2

EAPI=7

DESCRIPTION="Trained models created by Davis King."
HOMEPAGE="https://github.com/davisking/${PN}"
SRC_URI="https://github.com/davisking/${PN}/archive/2018-12-28.tar.gz -> 
${P}.tar.gz"

LICENSE="CC0-1.0"
SLOT="0"
KEYWORDS="~amd64"
IUSE=""

DEPEND=""
RDEPEND="${DEPEND}"

src_install() {
	insinto /lib/security/howdy/dlib-data
	doins ${WORKDIR}/${P}/dlib_face_recognition_resnet_model_v1.dat.bz2
	doins ${WORKDIR}/${P}/shape_predictor_5_face_landmarks.dat.bz2
	doins ${WORKDIR}/${P}/mmod_human_face_detector.dat.bz2
	bzip2 -d  /lib/security/howdy/dlib-data/*.bz2
}
