# Copyright (C) 2011 Daiki Ueno <ueno@unixuser.org>
# Copyright (C) 2011 Red Hat, Inc.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

INCLUDES = -I$(top_srcdir) $(LIBSKK_CFLAGS)

TESTS_ENVIRONMENT = LIBSKK_DATA_PATH=$(top_srcdir)
TESTS = rom-kana file-dict user-dict context
noinst_PROGRAMS = $(TESTS)
noinst_HEADERS = common.h

AM_CPPFLAGS = -DLIBSKK_FILE_DICT=\"$(top_srcdir)/tests/file-dict.dat\"

rom_kana_SOURCES = rom-kana.c
rom_kana_LDADD = $(top_builddir)/libskk/libskk.la $(LIBSKK_LIBS)

# kana_kan_SOURCES = kana-kan.c
# kana_kan_LDADD = $(top_builddir)/libskk/libskk.la $(LIBSKK_LIBS)

file_dict_SOURCES = file-dict.c
file_dict_LDADD = $(top_builddir)/libskk/libskk.la $(LIBSKK_LIBS)

user_dict_SOURCES = user-dict.c common.c
user_dict_LDADD = $(top_builddir)/libskk/libskk.la $(LIBSKK_LIBS)

context_SOURCES = context.c common.c
context_LDADD = $(top_builddir)/libskk/libskk.la $(LIBSKK_LIBS)

EXTRA_DIST = file-dict.dat kana-kan.c
CLEANFILES = user-dict.dat

-include $(top_srcdir)/git.mk