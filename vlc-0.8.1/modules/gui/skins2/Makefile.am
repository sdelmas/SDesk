
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in skins2; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in skins2; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in skins2; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The skins2 plugin

if UNTRUE
Lskins2p = libskins2_plugin.a
Dskins2p = libskins2_plugin$(LIBEXT)
Lskins2b = libskins2.a
Lskins2pic = libskins2_pic.a
endif

libskins2_plugin_a_SOURCES = $(SOURCES_skins2)
libskins2_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin skins2`
libskins2_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin skins2`
libskins2_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin skins2`

libskins2_pic_a_SOURCES = $(SOURCES_skins2)
libskins2_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic skins2`
libskins2_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic skins2`
libskins2_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic skins2`

libskins2_a_SOURCES = $(SOURCES_skins2)
libskins2_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin skins2`
libskins2_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin skins2`
libskins2_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin skins2`

libvlc_LIBRARIES += $(Lskins2b) $(Lskins2pic)
libskins2_DATA = $(Dskins2p)

libskins2dir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lskins2p)
libskins2_plugin$(LIBEXT): $(libskins2_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage skins2` in \
	  c++) echo $(CXXLINK) $(libskins2_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin skins2\` ; $(CXXLINK) $(libskins2_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin skins2` ;; \
	  objc) echo $(OBJCLINK) $(libskins2_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin skins2\` ; $(OBJCLINK) $(libskins2_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin skins2` ;; \
	  c|*) echo $(LINK) $(libskins2_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin skins2\` ; $(LINK) $(libskins2_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin skins2` ;; \
	esac


