###############################################################################
# Automake targets and declarations
###############################################################################

NULL =

# SUBDIRS stores the directories where a "make" is required when building
# something. DIST_SUBDIRS stores the directories where nothing is built but
# which have makefiles with distribution information.
#  - intl should come before modules and . because all the code uses gettext
#  - modules should come before . because vlc needs the builtins
#  - . should come before mozilla because the plugin needs libvlc_pic.a
#  - po should come before . because VLC.app needs the pofiles
SUBDIRS = intl modules po . mozilla share m4 doc
DIST_SUBDIRS = $(SUBDIRS) src debian ipkg lib

EXTRA_DIST = \
	HACKING \
	INSTALL.win32 \
	vlc.exe.manifest \
	MAINTAINERS \
	README.MacOSX.rtf \
	bootstrap \
	src/extras/COPYING \
	toolbox \
	vlc-config.in.in \
	vlc.ebuild \
	vlc.spec \
	vlc.spec.mdk \
	vlc.win32.nsi \
	$(NULL)

BUILT_SOURCES =
SUFFIXES = 

# Tell aclocal to use -I m4. Wonder if it really works.
ACLOCAL_AMFLAGS = -I m4

# XXX: these flags could be set in configure.ac, but we set them here
# because old versions of automake don't support them in configure.ac.
AUTOMAKE_OPTIONS = dist-bzip2 subdir-objects

###############################################################################
# Headers
###############################################################################

BUILT_SOURCES += \
	include/vlc_symbols.h \
	src/misc/modules_builtin.h \
	src/misc/modules_plugin.h \
	$(NULL)

pkgincludedir = $(includedir)/vlc

dist_pkginclude_HEADERS = \
	include/vlc/vlc.h \
	include/vlc/aout.h \
	include/vlc/vout.h \
	include/vlc/sout.h \
	include/vlc/decoder.h \
	include/vlc/input.h \
	include/vlc/intf.h \
	$(NULL)

noinst_HEADERS = $(HEADERS_include) $(HEADERS_include_built)

HEADERS_include = \
	include/aout_internal.h \
	include/audio_output.h \
	include/beos_specific.h \
	include/charset.h \
	include/codecs.h \
	include/configuration.h \
	include/darwin_specific.h \
	include/intf_eject.h \
	include/iso_lang.h \
	include/main.h \
	include/mmx.h \
	include/modules.h \
	include/modules_inner.h \
	include/mtime.h \
	include/network.h \
	include/osd.h \
	include/os_specific.h \
	include/snapshot.h \
	include/stream_output.h \
	include/variables.h \
	include/video_output.h \
	include/vlc_access.h \
	include/vlc_bits.h \
	include/vlc_block.h \
	include/vlc_block_helper.h \
	include/vlc_codec.h \
	include/vlc_common.h \
	include/vlc_config.h \
	include/vlc_cpu.h \
	include/vlc_demux.h \
	include/vlc_error.h \
	include/vlc_es.h \
	include/vlc_es_out.h \
	include/vlc_filter.h \
	include/vlc_help.h \
	include/vlc_httpd.h \
	include/vlc_tls.h \
	include/vlc_input.h \
	include/vlc_interface.h \
	include/vlc_keys.h \
	include/vlc_messages.h \
	include/vlc_meta.h \
	include/vlc_objects.h \
	include/vlc_playlist.h \
	include/vlc_spu.h \
	include/vlc_stream.h \
	include/vlc_threads_funcs.h \
	include/vlc_threads.h \
	include/vlc_video.h \
	include/vlc_vlm.h \
	include/vlc_vod.h \
	include/vout_synchro.h \
	include/win32_specific.h \
	$(NULL)

HEADERS_include_built = \
	include/vlc_symbols.h \
	$(NULL)

include/vlc_symbols.h: Makefile $(HEADERS_include)
	srcdir=$(srcdir) $(srcdir)/toolbox --update-includes

src/misc/modules_plugin.h: Makefile src/misc/modules_plugin.h.in $(HEADERS_include)
	srcdir=$(srcdir) $(srcdir)/toolbox --update-includes

src/misc/modules_builtin.h: Makefile src/misc/modules_builtin.h.in
	srcdir=$(srcdir) $(srcdir)/toolbox --update-includes

# These dependencies are mandatory
$(SOURCES): include/vlc_symbols.h
$(SOURCES_libvlc): src/misc/modules_plugin.h src/misc/modules_builtin.h $(LIB_intl)

###############################################################################
# Optional libintl - FIXME, bad dependencies
###############################################################################

intl/libintl.a: FORCE
	cd $(top_builddir)/intl && $(MAKE) $(AM_MAKEFLAGS)

if BUILD_INTL
LIB_intl = intl/libintl.a
endif

###############################################################################
# MacOS X project
###############################################################################

EXTRA_DIST += \
	extras/MacOSX/Resources/English.lproj/MainMenu.nib/classes.nib \
	extras/MacOSX/Resources/English.lproj/MainMenu.nib/info.nib \
	extras/MacOSX/Resources/English.lproj/MainMenu.nib/objects.nib \
	extras/MacOSX/Resources/English.lproj/InfoPlist.strings \
	extras/MacOSX/Resources/English.lproj/vlc.scriptTerminology \
	extras/MacOSX/Resources/a52.icns \
	extras/MacOSX/Resources/aac.icns \
	extras/MacOSX/Resources/asf.icns \
	extras/MacOSX/Resources/asx.icns \
	extras/MacOSX/Resources/avi.icns \
	extras/MacOSX/Resources/bin.icns \
	extras/MacOSX/Resources/cue.icns \
	extras/MacOSX/Resources/dat.icns \
	extras/MacOSX/Resources/divx.icns \
	extras/MacOSX/Resources/dv.icns \
	extras/MacOSX/Resources/generic.icns \
	extras/MacOSX/Resources/m3u.icns \
	extras/MacOSX/Resources/mov.icns \
	extras/MacOSX/Resources/mp3.icns \
	extras/MacOSX/Resources/mp4.icns \
	extras/MacOSX/Resources/mpeg.icns \
	extras/MacOSX/Resources/mpeg1.icns \
	extras/MacOSX/Resources/mpeg2.icns \
	extras/MacOSX/Resources/mpeg4.icns \
	extras/MacOSX/Resources/mpg.icns \
	extras/MacOSX/Resources/ogg.icns \
	extras/MacOSX/Resources/ogm.icns \
	extras/MacOSX/Resources/pls.icns \
	extras/MacOSX/Resources/srt.icns \
	extras/MacOSX/Resources/sub.icns \
	extras/MacOSX/Resources/vlc.icns \
	extras/MacOSX/Resources/vob.icns \
	extras/MacOSX/Resources/wma.icns \
	extras/MacOSX/Resources/wmv.icns \
	extras/MacOSX/Resources/pause.png \
	extras/MacOSX/Resources/pause_blue.png \
	extras/MacOSX/Resources/play.png \
	extras/MacOSX/Resources/play_blue.png \
	extras/MacOSX/Resources/stop.png \
	extras/MacOSX/Resources/stop_blue.png \
	extras/MacOSX/Resources/display.png \
	extras/MacOSX/Resources/display_slider.png \
	extras/MacOSX/Resources/display_track.png \
	extras/MacOSX/Resources/equalizerdrawer_active.png \
	extras/MacOSX/Resources/equalizerdrawer_blue.png \
	extras/MacOSX/Resources/fullscreen_active.png \
	extras/MacOSX/Resources/fullscreen_blue.png \
	extras/MacOSX/Resources/next_active.png \
	extras/MacOSX/Resources/next_blue.png \
	extras/MacOSX/Resources/playlistdrawer_active.png \
	extras/MacOSX/Resources/playlistdrawer_blue.png \
	extras/MacOSX/Resources/previous_active.png \
	extras/MacOSX/Resources/previous_blue.png \
	extras/MacOSX/Resources/skip_forward_active.png \
	extras/MacOSX/Resources/skip_forward_blue.png \
	extras/MacOSX/Resources/skip_previous_active.png \
	extras/MacOSX/Resources/skip_previous_blue.png \
	extras/MacOSX/Resources/volume_high.png \
	extras/MacOSX/Resources/volume_low.png \
	extras/MacOSX/Resources/volumeslider_blue.png \
	extras/MacOSX/Resources/volumeslider_normal.png \
	extras/MacOSX/Resources/volumetrack.png \
	extras/MacOSX/Resources/about_bg.png \
	extras/MacOSX/Resources/vlc.scriptSuite \
	extras/MacOSX/Resources/README \
	extras/MacOSX/vlc.pbproj/project.pbxproj \
	extras/MacOSX/macosx-dmg \
	$(NULL)

###############################################################################
# MS Visual Studio and eMbedded Visual Studio projects
###############################################################################

EXTRA_DIST += \
	msvc/vlc.dsw \
	msvc/libvlc.dsp.in \
	msvc/plugins.dsp.in \
	msvc/vlc.dsp.in \
	msvc/config.h.in \
	msvc/modules_builtin_msvc.h \
	evc/vlc.vcw \
	evc/libvlc.vcp.in \
	evc/vlc.vcp.in \
	evc/plugins.vcp.in \
	evc/errno.h \
	evc/config.h.in \
	evc/modules_builtin_evc.h \
	$(NULL)

dist-hook:
	cp $(distdir)/vlc.ebuild $(distdir)/vlc-${VERSION}.ebuild
	cd $(distdir) && srcdir=$(srcdir) $(srcdir)/toolbox --update-vc

###############################################################################
# Building libvlc
###############################################################################

bin_SCRIPTS = vlc-config

lib_LIBRARIES = lib/libvlc.a $(LIBRARIES_libvlc_pic)

lib_libvlc_a_SOURCES = $(SOURCES_libvlc)
dist_lib_libvlc_a_SOURCES = src/misc/modules_plugin.h
lib_libvlc_a_CFLAGS = `$(VLC_CONFIG) --cflags vlc`
lib_libvlc_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags vlc`
lib_libvlc_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags vlc`

lib_libvlc_pic_a_SOURCES = $(SOURCES_libvlc)
lib_libvlc_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags vlc pic`
lib_libvlc_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags vlc pic`
lib_libvlc_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags vlc pic`

if HAVE_BEOS
OPT_SOURCES_libvlc_beos = $(SOURCES_libvlc_beos)
endif
if HAVE_DARWIN
OPT_SOURCES_libvlc_darwin = $(SOURCES_libvlc_darwin)
endif
if HAVE_WIN32
OPT_SOURCES_libvlc_win32 = $(SOURCES_libvlc_win32)
endif
if BUILD_DIRENT
OPT_SOURCES_libvlc_dirent = $(SOURCES_libvlc_dirent)
endif
if BUILD_GETOPT
OPT_SOURCES_libvlc_getopt = $(SOURCES_libvlc_getopt)
endif
if BUILD_MOZILLA
if !HAVE_WIN32
LIBRARIES_libvlc_pic = lib/libvlc_pic.a
endif
endif

EXTRA_DIST += \
	$(SOURCES_libvlc_beos) \
	$(SOURCES_libvlc_darwin) \
	$(SOURCES_libvlc_win32) \
	$(SOURCES_libvlc_dirent) \
	$(SOURCES_libvlc_getopt) \
	$(NULL)

SOURCES_libvlc_beos = \
	src/misc/beos_specific.cpp \
	$(NULL)

SOURCES_libvlc_darwin = \
	src/misc/darwin_specific.m \
	$(NULL)

SOURCES_libvlc_win32 = \
	src/misc/win32_specific.c \
	$(NULL)

SOURCES_libvlc_dirent = \
	src/extras/dirent.c \
	src/extras/dirent.h \
	$(NULL)

SOURCES_libvlc_getopt = \
	src/extras/getopt.c \
	src/extras/getopt.h \
	src/extras/getopt1.c \
	$(NULL)

SOURCES_libvlc_common = \
	src/libvlc.c \
	src/libvlc.h \
	src/interface/interface.c \
	src/interface/intf_eject.c \
	src/playlist/playlist.c \
	src/playlist/sort.c \
	src/playlist/loadsave.c \
	src/playlist/group.c \
	src/playlist/item.c \
	src/playlist/item-ext.c \
	src/playlist/info.c \
	src/input/access.c \
	src/input/clock.c \
	src/input/control.c \
	src/input/decoder.c \
	src/input/demux.c \
	src/input/es_out.c \
	src/input/input.c \
	src/input/input_internal.h \
	src/input/stream.c \
	src/input/subtitles.c \
	src/input/var.c \
	src/video_output/video_output.c \
	src/video_output/vout_pictures.c \
	src/video_output/vout_pictures.h \
	src/video_output/video_text.c \
	src/video_output/video_widgets.c \
	src/video_output/vout_subpictures.c \
	src/video_output/vout_synchro.c \
	src/video_output/vout_intf.c \
	src/audio_output/common.c \
	src/audio_output/dec.c \
	src/audio_output/filters.c \
	src/audio_output/input.c \
	src/audio_output/mixer.c \
	src/audio_output/output.c \
	src/audio_output/intf.c \
	src/stream_output/stream_output.c \
	src/stream_output/announce.c \
	src/stream_output/sap.c \
	src/misc/charset.c \
	src/misc/httpd.c \
	src/misc/tls.c \
	src/misc/mtime.c \
	src/misc/block.c \
	src/misc/modules.c \
	src/misc/threads.c \
	src/misc/cpu.c \
	src/misc/configuration.c \
	src/misc/iso_lang.c \
	src/misc/iso-639_def.h \
	src/misc/messages.c \
	src/misc/objects.c \
	src/misc/variables.c \
	src/misc/error.c \
	src/misc/net.c \
	src/misc/vlm.c \
	src/extras/libc.c \
	$(NULL)

SOURCES_libvlc = \
	$(SOURCES_libvlc_common) \
	$(OPT_SOURCES_libvlc_beos) \
	$(OPT_SOURCES_libvlc_darwin) \
	$(OPT_SOURCES_libvlc_win32) \
	$(OPT_SOURCES_libvlc_dirent) \
	$(OPT_SOURCES_libvlc_getopt) \
	$(NULL)

###############################################################################
# Building vlc
###############################################################################

bin_PROGRAMS = vlc

vlc_SOURCES = src/vlc.c

vlc_LDFLAGS = `$(VLC_CONFIG) --libs vlc builtin`
vlc_LDADD = lib/libvlc.a $(DATA_win32_rc) $(LIB_intl)
vlc_CFLAGS = `$(VLC_CONFIG) --cflags vlc`

# We use DEPENDENCIES_vlc instead of vlc_DEPENDENCIES because of an
# old automake-1.5 bug (automake/279).
DEPENDENCIES_vlc = lib/libvlc.a $(DATA_win32_rc) $(LIB_intl)

vlc$(EXEEXT): $(vlc_OBJECTS) $(DEPENDENCIES_vlc) stamp-builtin
	@rm -f $(top_builddir)/vlc$(EXEEXT)
	@case `$(VLC_CONFIG) --linkage vlc builtin` in \
	  c++) echo $(CXXLINK) $(vlc_OBJECTS) $(vlc_LDADD) $(vlc_LDFLAGS) $(LIBS) ; $(CXXLINK) $(vlc_OBJECTS) $(vlc_LDADD) $(vlc_LDFLAGS) $(LIBS) ;; \
	  objc) echo $(OBJCLINK) $(vlc_OBJECTS) $(vlc_LDADD) $(vlc_LDFLAGS) $(LIBS) ; $(OBJCLINK) $(vlc_OBJECTS) $(vlc_LDADD) $(vlc_LDFLAGS) $(LIBS) ;; \
	  c|*) echo $(LINK) $(vlc_OBJECTS) $(vlc_LDADD) $(vlc_LDFLAGS) $(LIBS) ; $(LINK) $(vlc_OBJECTS) $(vlc_LDADD) $(vlc_LDFLAGS) $(LIBS) ;; \
	esac

if HAVE_BEOS
noinst_DATA = vlc-bundle
vlc-bundle: vlc
	rm -Rf $(top_builddir)/vlc-bundle ; mkdir -p $(top_builddir)/vlc-bundle
	cp $(top_builddir)/vlc $(top_builddir)/vlc-bundle/
	xres -o $(top_builddir)/vlc-bundle/vlc $(srcdir)/share/vlc_beos.rsrc
	for i in "" `$(VLC_CONFIG) --target plugin` ; do \
	  if test -n "$$i" ; then \
	    mkdir -p $(top_builddir)/vlc-bundle/plugins ; \
	    cp "$$i$(LIBEXT)" $(top_builddir)/vlc-bundle/plugins/ ; \
	  fi ; \
	done
	if test -d $(top_builddir)/extras/contrib/vlc-lib ; then \
	  mkdir -p $(top_builddir)/vlc-bundle/lib ; \
	  for i in $(top_builddir)/extras/contrib/vlc-lib/*.so ; do \
	    cp $$i $(top_builddir)/vlc-bundle/lib/ ; \
	  done ; \
	fi
	for i in $(ALL_LINGUAS); do \
	  mkdir -p "$(top_builddir)/vlc-bundle/locale/$$i/LC_MESSAGES" ; \
	  cp "$(top_builddir)/po/$$i.gmo" \
	    "$(top_builddir)/vlc-bundle/locale/$$i/LC_MESSAGES/vlc.mo" || true ; \
	done
	find $(top_builddir)/vlc-bundle -type f -exec mimeset -f "{}" \;
endif

# Install the modules and the symlinks
install-exec-local:
	for i in "" `$(VLC_CONFIG) --target plugin` ; do if test -n "$$i" ; then \
	  echo $(INSTALL) -m 755 "$$i$(LIBEXT)" "$(DESTDIR)$(libdir)/vlc/`echo $$i | sed -e 's,.*modules/\([^/]*\).*,\1,'`" ; \
	  $(INSTALL) -m 755 "$$i$(LIBEXT)" "$(DESTDIR)$(libdir)/vlc/`echo $$i | sed -e 's,.*modules/\([^/]*\).*,\1,'`" ; \
	fi ; done
	for i in "" `$(VLC_CONFIG) --target builtin` ; do if test -n "$$i" ; then \
	  echo $(INSTALL) -m 644 "$$i" "$(DESTDIR)$(libdir)/vlc" ; \
	  $(INSTALL) -m 644 "$$i" "$(DESTDIR)$(libdir)/vlc" ; \
	fi ; done
if BUILD_MOZILLA
	for i in "" `$(VLC_CONFIG) --target builtin pic` ; do if test -n "$$i" ; then \
	  echo $(INSTALL) -m 644 "$$i" "$(DESTDIR)$(libdir)/vlc" ; \
	  $(INSTALL) -m 644 "$$i" "$(DESTDIR)$(libdir)/vlc" ; \
	fi ; done
endif
	for i in "" $(ALIASES) ; do if test -n "$$i" ; then \
	  rm -f "$(DESTDIR)$(bindir)/$$i" && \
	  ln -s vlc "$(DESTDIR)$(bindir)/$$i" ; \
	fi ; done

if HAVE_DARWIN
# Create the MacOS X app
vlc_app_DATA = VLC.app
vlc_appdir = $(bindir)
VLC.app: vlc
	@if test -e "$(top_builddir)/tmp"; then \
	  echo "Error: please remove $(top_builddir)/tmp, it is in the way"; \
	  false; \
	else \
	  echo "OK."; mkdir -p "$(top_builddir)/tmp/extras"; \
	fi
	rm -Rf $(top_builddir)/VLC.app
	cp -r $(srcdir)/extras/MacOSX $(top_builddir)/tmp/extras
	for i in AUTHORS COPYING README.MacOSX.rtf THANKS; do \
	  cp "$(srcdir)/$$i" $(top_builddir)/tmp; \
	done
	mkdir -p $(top_builddir)/tmp/modules/audio_output
	cp $(srcdir)/modules/audio_output/coreaudio.c \
	   $(top_builddir)/tmp/modules/audio_output/coreaudio.c
	mkdir -p $(top_builddir)/tmp/modules/gui/macosx
	for i in \
	    about.h \
	    about.m \
	    applescript.h \
	    applescript.m \
	    controls.h \
	    controls.m \
	    equalizer.h \
	    equalizer.m \
	    intf.h \
	    intf.m \
	    macosx.m \
	    misc.h \
	    misc.m \
	    open.h \
	    open.m \
	    output.h \
	    output.m \
	    playlist.h \
	    playlist.m \
	    playlistinfo.h \
	    playlistinfo.m \
	    prefs_widgets.h \
	    prefs_widgets.m \
	    prefs.h \
	    prefs.m \
	    vout.h \
	    voutqt.m \
	    voutgl.m \
	    vout.m; do \
	  cp "$(srcdir)/modules/gui/macosx/$$i" \
             $(top_builddir)/tmp/modules/gui/macosx; \
	done
	cd $(top_builddir)/tmp/extras/MacOSX && xcodebuild -target vlc | grep -v '^\([ \t]\|$$\)'
	cp -r $(top_builddir)/tmp/extras/MacOSX/build/vlc.bundle \
	      $(top_builddir)/VLC.app
	rm -Rf $(top_builddir)/tmp
	$(INSTALL) -d $(top_builddir)/VLC.app/Contents/MacOS
	$(INSTALL) $(top_builddir)/vlc \
		   $(top_builddir)/VLC.app/Contents/MacOS/VLC
	ln -sf ./VLC $(top_builddir)/VLC.app/Contents/MacOS/clivlc
	$(INSTALL) -d $(top_builddir)/VLC.app/Contents/MacOS/modules
	for i in "" `$(VLC_CONFIG) --target plugin` ; do \
	  if test -n "$$i" ; \
	    then $(INSTALL) "$$i$(LIBEXT)" \
			   "$(top_builddir)/VLC.app/Contents/MacOS/modules" ; \
	  fi ; done
	if test -d $(top_builddir)/extras/contrib/vlc-lib; then \
	  mkdir -p $(top_builddir)/VLC.app/Contents/MacOS/lib ; \
	  for i in $(top_builddir)/extras/contrib/vlc-lib/*.dylib ; do \
	    $(INSTALL) -m 644 $${i} $(top_builddir)/VLC.app/Contents/MacOS/lib/vlc_`basename $${i}` ; \
	  done ; \
	fi
	$(INSTALL) -d $(top_builddir)/VLC.app/Contents/MacOS/share
	$(INSTALL) -d $(top_builddir)/VLC.app/Contents/MacOS/share/http
	for i in $(srcdir)/share/http/* ; do \
	  $(INSTALL) -m 644 $${i} $(top_builddir)/VLC.app/Contents/MacOS/share/http/`basename $${i}` ; \
	done ; \
	$(INSTALL) -d $(top_builddir)/VLC.app/Contents/MacOS/share/http/vlm
	for i in $(srcdir)/share/http/vlm/* ; do \
	  $(INSTALL) -m 644 $${i} $(top_builddir)/VLC.app/Contents/MacOS/share/http/vlm/`basename $${i}` ; \
	done ; \
	$(INSTALL) -d $(top_builddir)/VLC.app/Contents/MacOS/share/http/admin
	for i in $(srcdir)/share/http/admin/* ; do \
	  $(INSTALL) -m 644 $${i} $(top_builddir)/VLC.app/Contents/MacOS/share/http/admin/`basename $${i}` ; \
	done ; \
	$(INSTALL) -m 644 $(srcdir)/share/http/admin/.access $(top_builddir)/VLC.app/Contents/MacOS/share/http/admin/.access
	$(INSTALL) -d $(top_builddir)/VLC.app/Contents/MacOS/locale
	for i in $(ALL_LINGUAS); do \
	  mkdir -p $(top_builddir)/VLC.app/Contents/MacOS/locale/$${i}/LC_MESSAGES ; \
	  cp $(srcdir)/po/$${i}.gmo $(top_builddir)/VLC.app/Contents/MacOS/locale/$${i}/LC_MESSAGES/vlc.mo || true ; \
	  mkdir -p $(top_builddir)/VLC.app/Contents/Resources/$${i}.lproj ; \
	  ln -sf ../English.lproj/InfoPlist.strings \
	      $(top_builddir)/VLC.app/Contents/Resources/$${i}.lproj ; \
	  ln -sf ../English.lproj/MainMenu.nib \
	      $(top_builddir)/VLC.app/Contents/Resources/$${i}.lproj ; \
	  ln -sf ../English.lproj/vlc.scriptTerminology \
	      $(top_builddir)/VLC.app/Contents/Resources/$${i}.lproj ; \
	done
	printf "APPLVLC#" >| $(top_builddir)/VLC.app/Contents/PkgInfo
endif

if HAVE_WIN32
DATA_win32_rc = $(noinst_share_vlc_win32_rc_DATA)
noinst_share_vlc_win32_rc_DATA = share/vlc_win32_rc.$(OBJEXT)
noinst_share_vlc_win32_rcdir = $(libdir)
share/vlc_win32_rc.$(OBJEXT): share/vlc_win32_rc.rc
	$(WINDRES) -DVERSION=$(VERSION) -DVERSION_NUMBER=`echo $(VERSION).0.0.0 | sed 's/\([0-9]*\)[^.]*\.*\([0-9]*\)[^.]*\.*\([0-9]*\)[^.]*\.*\([0-9]*\).*/\1,\2,\3,\4/'` --include-dir $(srcdir)/share -i $< -o $@
endif

###############################################################################
# Building specific source packages
###############################################################################

dist-woody: distdir
	$(remove_distdir_woody)
	mv $(distdir) $(PACKAGE)-woody-$(VERSION)
	$(srcdir)/toolbox --make-woody $(PACKAGE)-woody-$(VERSION)
	$(AMTAR) chof - $(PACKAGE)-woody-$(VERSION) \
	  | GZIP=$(GZIP_ENV) gzip -c >$(PACKAGE)-woody-$(VERSION).tar.gz
	$(remove_distdir_woody)

remove_distdir_woody = \
  { test ! -d $(PACKAGE)-woody-$(VERSION) \
    || { find $(PACKAGE)-woody-$(VERSION) -type d ! -perm -200 \
           -exec chmod u+w {} ';' \
         && rm -fr $(PACKAGE)-woody-$(VERSION); }; }

###############################################################################
# Building architecture-specific binary packages
###############################################################################

# XXX: this rule is probably only useful to you if you have exactly
# the same setup as me. Contact sam@zoy.org if you need to use it.
#
package-win32-base:
# Check that tmp isn't in the way
	@if test -e "$(srcdir)/vlc-${VERSION}"; then \
	  echo "Error: please remove $(srcdir)/vlc-${VERSION}, it is in the way"; \
	  false; \
	else \
	  echo "OK."; mkdir -p "$(srcdir)/vlc-${VERSION}"; \
	fi

# Copy relevant files
	cp "$(srcdir)/vlc.win32.nsi" "$(srcdir)/vlc-${VERSION}/"
	cp "$(top_builddir)/vlc$(EXEEXT)" "$(srcdir)/vlc-${VERSION}/"
	cp "$(top_builddir)/vlc.exe.manifest" "$(srcdir)/vlc-${VERSION}/"
	$(STRIP) "$(srcdir)/vlc-${VERSION}/vlc$(EXEEXT)"

	for file in AUTHORS MAINTAINERS THANKS NEWS COPYING README ; \
	  do sed 's/@/_AT_/' < "$(srcdir)/$$file" > "$(srcdir)/vlc-${VERSION}/$${file}.txt" ; \
	  unix2dos "$(srcdir)/vlc-${VERSION}/$${file}.txt" ; done

	mkdir -p "$(srcdir)/vlc-${VERSION}/plugins"
	for i in "" `$(VLC_CONFIG) --target plugin` ; do \
	  if test -n "$$i" ; then \
	    $(INSTALL) "$(srcdir)/$$i$(LIBEXT)" \
            "$(srcdir)/vlc-${VERSION}/plugins/" ; \
	  fi ; done

	for i in "" $(srcdir)/vlc-${VERSION}/plugins/*$(LIBEXT) ; \
	  do if test -n "$$i" ; then $(STRIP) "$$i" ; fi ; done

	mkdir $(srcdir)/vlc-${VERSION}/locale
	for i in $(ALL_LINGUAS); do \
	  mkdir -p "$(srcdir)/vlc-${VERSION}/locale/$${i}/LC_MESSAGES" ; \
	  cp "$(srcdir)/po/$${i}.gmo" \
	    "$(srcdir)/vlc-${VERSION}/locale/$${i}/LC_MESSAGES/vlc.mo" \
            || true ; \
	done

	mkdir -p $(srcdir)/vlc-${VERSION}/skins/fonts
	for i in $(srcdir)/share/skins2/fonts/*.*; do \
	  cp $$i $(srcdir)/vlc-${VERSION}/skins/fonts/ || true ; \
	done
	for i in $(srcdir)/share/skins2/*.*; do \
	  cp $$i $(srcdir)/vlc-${VERSION}/skins/ || true ; \
	done

	mkdir -p "$(srcdir)/vlc-${VERSION}/http/admin"
	mkdir -p "$(srcdir)/vlc-${VERSION}/http/vlm"
	cp $(srcdir)/share/http/*.html $(srcdir)/vlc-${VERSION}/http/ ;
	cp $(srcdir)/share/http/*.css $(srcdir)/vlc-${VERSION}/http/ ;
	cp $(srcdir)/share/http/admin/*.html \
           $(srcdir)/vlc-${VERSION}/http/admin/ ;
	cp $(srcdir)/share/http/admin/.access \
           $(srcdir)/vlc-${VERSION}/http/admin/ ;
	cp $(srcdir)/share/http/vlm/*.html \
           $(srcdir)/vlc-${VERSION}/http/vlm/ ;

	cp $(srcdir)/share/vlc48x48.ico $(srcdir)/vlc-${VERSION}/ ;

	mkdir -p "$(srcdir)/vlc-${VERSION}/mozilla"
if BUILD_MOZILLA
	cp $(srcdir)/mozilla/*$(LIBEXT) $(srcdir)/vlc-${VERSION}/mozilla/ ;
	$(STRIP) $(srcdir)/vlc-${VERSION}/mozilla/*$(LIBEXT);
	cp $(srcdir)/mozilla/vlcintf.xpt  $(srcdir)/vlc-${VERSION}/mozilla/ ;
endif

package-win32-base-exe:
# Create package 
	wine ~/.wine/fake_windows/Program\ Files/NSIS/makensis.exe \
             /DVERSION=${VERSION} $(srcdir)/vlc-${VERSION}/vlc.win32.nsi

package-win32-base-zip:
# Create package 
	zip -r vlc-${VERSION}-win32.zip vlc-${VERSION}

package-win32-exe: package-win32-base package-win32-base-exe
# Clean up
	rm -Rf $(srcdir)/vlc-${VERSION}

package-win32-zip: package-win32-base package-win32-base-zip
# Clean up
	rm -Rf $(srcdir)/vlc-${VERSION}

package-win32: package-win32-base package-win32-base-exe package-win32-base-zip
# Clean up
	rm -Rf $(srcdir)/vlc-${VERSION}

package-beos:
# Check that tmp isn't in the way
	@if test -e $(srcdir)/tmp; then \
	  echo "Error: please remove $(srcdir)/tmp, it is in the way"; \
	  false ; \
	else \
	  echo "OK." ; mkdir $(srcdir)/tmp ; \
	fi

# Copy relevant files
	mkdir -p $(srcdir)/tmp/vlc ;
	cd $(srcdir) && cp -R vlc-bundle/* AUTHORS COPYING ChangeLog README \
	  THANKS NEWS tmp/vlc/ ;

# Create debug package
	xres -o $(srcdir)/tmp/vlc/vlc $(srcdir)/share/vlc_beos.rsrc ;
	find $(srcdir)/tmp/vlc -exec mimeset -f {} \; ;
	mv $(srcdir)/tmp/vlc $(srcdir)/tmp/vlc-${VERSION} ;
	(cd $(srcdir)/tmp ; zip -9 -r vlc-${VERSION}-BeOS-debug.zip vlc-${VERSION} )
	mv $(srcdir)/tmp/vlc-${VERSION}-BeOS-debug.zip $(srcdir)/ ;
	mv $(srcdir)/tmp/vlc-${VERSION} $(srcdir)/tmp/vlc ;

# Create normal package
	strip --strip-debug --strip-unneeded $(srcdir)/tmp/vlc/vlc ;
	find $(srcdir)/tmp/vlc -name 'lib*.so' -exec strip \
	  --strip-debug --strip-unneeded "{}" \; ;
	xres -o $(srcdir)/tmp/vlc/vlc $(srcdir)/share/vlc_beos.rsrc ;
	find $(srcdir)/tmp/vlc -exec mimeset -f {} \; ;
	mv $(srcdir)/tmp/vlc $(srcdir)/tmp/vlc-${VERSION} ;
	(cd $(srcdir)/tmp ; zip -9 -r vlc-${VERSION}-BeOS.zip vlc-${VERSION} )
	mv $(srcdir)/tmp/vlc-${VERSION}-BeOS.zip $(srcdir)/ ;

# Clean up
	rm -Rf $(srcdir)/tmp ;

package-macosx:
# Check that tmp isn't in the way
	@if test -e "$(top_builddir)/tmp"; then \
	  echo "Error: please remove $(top_builddir)/tmp, it is in the way"; \
	  false; \
	else \
	  echo "OK."; mkdir -p "$(top_builddir)/tmp"; \
	fi

# Copy relevant files 
	cp -R "$(top_builddir)/VLC.app" "$(top_builddir)/tmp/"
	cd "$(srcdir)" && cp AUTHORS COPYING ChangeLog README README.MacOSX.rtf THANKS NEWS $(top_builddir)/tmp/

# Create disk image 
	$(srcdir)/extras/MacOSX/macosx-dmg "vlc-${VERSION}" $(top_builddir)/tmp

# Clean up
	rm -Rf $(top_builddir)/tmp

package-translations:
	@if test -e "$(srcdir)/vlc-translations-${VERSION}"; then \
	  echo "Error: please remove $(srcdir)/vlc-translations-${VERSION}, it is in the way"; \
	  false; \
	else \
	  echo "OK."; mkdir -p "$(srcdir)/vlc-translations-${VERSION}"; \
	fi
# Copy translations
	for i in $(ALL_LINGUAS); do \
	  cp "$(srcdir)/po/$${i}.po" \
	    "$(srcdir)/vlc-translations-${VERSION}/$${i}.po" \
	    || true ; \
	done
	cp "$(srcdir)/doc/translations.txt" \
	  "$(srcdir)/vlc-translations-${VERSION}/README.txt"

	echo "#!/bin/sh" >>"$(srcdir)/vlc-translations-$(VERSION)/convert.po.sh"
	echo "" >>"$(srcdir)/vlc-translations-$(VERSION)/convert.po.sh"
	echo 'if test $$# != 1; then' >>"$(srcdir)/vlc-translations-$(VERSION)/convert.po.sh"
	echo "	echo \"Usage: convert-po.sh <.po file>\"" >>"$(srcdir)/vlc-translations-$(VERSION)/convert.po.sh"
	echo "	exit 1" >>"$(srcdir)/vlc-translations-$(VERSION)/convert.po.sh"
	echo "fi" >>"$(srcdir)/vlc-translations-$(VERSION)/convert.po.sh"
	echo "" >>"$(srcdir)/vlc-translations-$(VERSION)/convert.po.sh"
	echo 'msgfmt --statistics -o vlc.mo $$1' >>"$(srcdir)/vlc-translations-$(VERSION)/convert.po.sh"

	$(AMTAR) chof - $(srcdir)/vlc-translations-$(VERSION) \
	  | GZIP=$(GZIP_ENV) gzip -c >$(srcdir)/vlc-translations-$(VERSION).tar.gz

###############################################################################
# Stamp rules
###############################################################################
clean: clean-stamp
clean-stamp:
	rm -f stamp-builtin

stamp-builtin: FORCE
	@for dep in "" `$(VLC_CONFIG) --target builtin`; do \
	  if test "$${dep}" -nt "$(top_builddir)/vlc$(EXEEXT)"; then \
	    rm -f $@; \
	    break; \
	  fi; \
	done
	@if test ! -f $@; then printf "" > $@; fi

###############################################################################
# Force rule
###############################################################################
FORCE:
