
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = 
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/gui
include Modules.am

if BUILD_MOZILLA
if HAVE_WIN32
# There's no need for pic code on win32 so get rid of this to substantially
# reduce the compilation time.
pic = no
endif
else
pic = no
endif

clean-local:
	-rm -f *.a *.so *.dll *.sl *.dylib

all: all-modules
all-modules:
	@set fnord $$MAKEFLAGS; amf=$$2; targets=`\
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in macosx; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in macosx; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in macosx; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The macosx plugin

if UNTRUE
Lmacosxp = libmacosx_plugin.a
Dmacosxp = libmacosx_plugin$(LIBEXT)
Lmacosxb = libmacosx.a
Lmacosxpic = libmacosx_pic.a
endif

libmacosx_plugin_a_SOURCES = $(SOURCES_macosx)
libmacosx_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin macosx`
libmacosx_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin macosx`
libmacosx_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin macosx`

libmacosx_pic_a_SOURCES = $(SOURCES_macosx)
libmacosx_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic macosx`
libmacosx_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic macosx`
libmacosx_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic macosx`

libmacosx_a_SOURCES = $(SOURCES_macosx)
libmacosx_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin macosx`
libmacosx_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin macosx`
libmacosx_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin macosx`

libvlc_LIBRARIES += $(Lmacosxb) $(Lmacosxpic)
libmacosx_DATA = $(Dmacosxp)

libmacosxdir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lmacosxp)
libmacosx_plugin$(LIBEXT): $(libmacosx_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage macosx` in \
	  c++) echo $(CXXLINK) $(libmacosx_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin macosx\` ; $(CXXLINK) $(libmacosx_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin macosx` ;; \
	  objc) echo $(OBJCLINK) $(libmacosx_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin macosx\` ; $(OBJCLINK) $(libmacosx_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin macosx` ;; \
	  c|*) echo $(LINK) $(libmacosx_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin macosx\` ; $(LINK) $(libmacosx_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin macosx` ;; \
	esac


