
# Autogenerated by bootstrap - DO NOT EDIT - edit Modules.am instead

NULL =
libvlc_LIBRARIES =
noinst_LIBRARIES =
noinst_HEADERS =
EXTRA_DIST = Modules.am
BUILT_SOURCES =
SUBDIRS = 
#DIST_SUBDIRS = $(SUBDIRS)
libvlcdir = $(libdir)/vlc/access
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in v4l; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in v4l; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in v4l; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The v4l plugin

if UNTRUE
Lv4lp = libv4l_plugin.a
Dv4lp = libv4l_plugin$(LIBEXT)
Lv4lb = libv4l.a
Lv4lpic = libv4l_pic.a
endif

libv4l_plugin_a_SOURCES = $(SOURCES_v4l)
libv4l_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin v4l`
libv4l_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin v4l`
libv4l_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin v4l`

libv4l_pic_a_SOURCES = $(SOURCES_v4l)
libv4l_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic v4l`
libv4l_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic v4l`
libv4l_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic v4l`

libv4l_a_SOURCES = $(SOURCES_v4l)
libv4l_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin v4l`
libv4l_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin v4l`
libv4l_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin v4l`

libvlc_LIBRARIES += $(Lv4lb) $(Lv4lpic)
libv4l_DATA = $(Dv4lp)

libv4ldir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lv4lp)
libv4l_plugin$(LIBEXT): $(libv4l_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage v4l` in \
	  c++) echo $(CXXLINK) $(libv4l_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin v4l\` ; $(CXXLINK) $(libv4l_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin v4l` ;; \
	  objc) echo $(OBJCLINK) $(libv4l_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin v4l\` ; $(OBJCLINK) $(libv4l_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin v4l` ;; \
	  c|*) echo $(LINK) $(libv4l_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin v4l\` ; $(LINK) $(libv4l_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin v4l` ;; \
	esac


