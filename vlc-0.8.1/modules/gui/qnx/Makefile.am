
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
	if test "$(plugin)" != "no"; then z=$$($(VLC_CONFIG) --target plugin); for mod in qnx; do case "$$z" in */lib$${mod}_plugin*) echo lib$${mod}_plugin$(LIBEXT);; esac; done; fi; \
	if test "$(builtin)" != "no"; then z=$$($(VLC_CONFIG) --target builtin); for mod in qnx; do case "$$z" in */lib$${mod}.a*) echo lib$${mod}.a;; esac; done; fi; \
	if test "$(pic)" != "no"; then z=$$($(VLC_CONFIG) --target builtin pic); for mod in qnx; do case "$$z" in */lib$${mod}_pic.a*) echo lib$${mod}_pic.a;; esac; done; fi; \
	`; case "$$targets" in *lib*) $(MAKE) $(AM_MAKEFLAGS) $$targets || case "$$amf" in *=*) exit 1;; *k*) fail=yes;; *) exit 1;; esac; ;; esac; \
	test -z "$$fail"

# The qnx plugin

if UNTRUE
Lqnxp = libqnx_plugin.a
Dqnxp = libqnx_plugin$(LIBEXT)
Lqnxb = libqnx.a
Lqnxpic = libqnx_pic.a
endif

libqnx_plugin_a_SOURCES = $(SOURCES_qnx)
libqnx_plugin_a_CFLAGS = `$(VLC_CONFIG) --cflags plugin qnx`
libqnx_plugin_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags plugin qnx`
libqnx_plugin_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags plugin qnx`

libqnx_pic_a_SOURCES = $(SOURCES_qnx)
libqnx_pic_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin pic qnx`
libqnx_pic_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin pic qnx`
libqnx_pic_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin pic qnx`

libqnx_a_SOURCES = $(SOURCES_qnx)
libqnx_a_CFLAGS = `$(VLC_CONFIG) --cflags builtin qnx`
libqnx_a_CXXFLAGS = `$(VLC_CONFIG) --cxxflags builtin qnx`
libqnx_a_OBJCFLAGS = `$(VLC_CONFIG) --objcflags builtin qnx`

libvlc_LIBRARIES += $(Lqnxb) $(Lqnxpic)
libqnx_DATA = $(Dqnxp)

libqnxdir = $(libdir)/vlc/
noinst_LIBRARIES += $(Lqnxp)
libqnx_plugin$(LIBEXT): $(libqnx_plugin_a_OBJECTS)
	@case `$(VLC_CONFIG) --linkage qnx` in \
	  c++) echo $(CXXLINK) $(libqnx_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin qnx\` ; $(CXXLINK) $(libqnx_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin qnx` ;; \
	  objc) echo $(OBJCLINK) $(libqnx_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin qnx\` ; $(OBJCLINK) $(libqnx_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin qnx` ;; \
	  c|*) echo $(LINK) $(libqnx_plugin_a_OBJECTS) \`$(VLC_CONFIG) --libs plugin qnx\` ; $(LINK) $(libqnx_plugin_a_OBJECTS) `$(VLC_CONFIG) --libs plugin qnx` ;; \
	esac


