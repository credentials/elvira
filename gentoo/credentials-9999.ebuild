# Copyright 1999-2012 Gentoo Foundation
# Distributed under the terms of the GNU General Public License v2
# $Header: $

EAPI=4

inherit cmake-utils git-2

DESCRIPTION="Fast and portable C library which provides both high-level and low-level (cryptographic) credential operations"
HOMEPAGE="https://github.com/credentials/clib"
EGIT_REPO_URI="git://github.com/credentials/clib.git"

LICENSE="CC0-1.0"
SLOT="0"
KEYWORDS=""
IUSE=""

RDEPEND="
	dev-libs/gmp"
DEPEND="${RDEPEND}"

pkg_setup() {
	DOCS=( README LICENSE AUTHORS )
}
