
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = 
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/demux
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in mp4; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in mp4; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in mp4; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The mp4 plugin

if UNTRUE
Lmp4p = libmp4_plugin.a
Dmp4p = libmp4_plugin$(LIBEXT)
Lmp4b = libmp4.a
Lmp4pic = libmp4_pic.a
endif

libmp4_plugin_a_SOURCES = $(SOURCES_mp4)
libmp4_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin mp4`
libmp4_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin mp4`
libmp4_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin mp4`

libmp4_pic_a_SOURCES = $(SOURCES_mp4)
libmp4_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic mp4`
libmp4_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic mp4`
libmp4_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic mp4`

libmp4_a_SOURCES = $(SOURCES_mp4)
libmp4_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin mp4`
libmp4_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin mp4`
libmp4_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin mp4`

libvlc_LIBRARIES += $(Lmp4b) $(Lmp4pic)
libmp4_DATA = $(Dmp4p)

libmp4dir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lmp4p)
libmp4_plugin$(LIBEXT): $(libmp4_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage mp4` in \
	  c++) echo $(CXXLINK) $(libmp4_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mp4\` ; $(CXXLINK) $(libmp4_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mp4` ;; \
	  objc) echo $(OBJCLINK) $(libmp4_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mp4\` ; $(OBJCLINK) $(libmp4_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mp4` ;; \
	  c|*) echo $(LINK) $(libmp4_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin mp4\` ; $(LINK) $(libmp4_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin mp4` ;; \
	esac


